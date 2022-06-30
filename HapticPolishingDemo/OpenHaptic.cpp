#include "stdafx.h"
#include "OpenHaptic.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "HomogeneousTransform.h"

// Prototype Function
HDCallbackCode HDCALLBACK DeviceStateCallback(void * pUserData);
HDCallbackCode HDCALLBACK frictionlessPlaneCallback(void * pUserData);
HDCallbackCode HDCALLBACK HapticForceCallback(void * pUserData);

hduVector3Dd global_haptic_forces;
OmniState * state;

void RotationTransform(double* haptic, double angles[3]){
	double R[16];
	R[4] = haptic[2];
	R[5] = haptic[0];
	R[6] = haptic[1];
	R[0] = haptic[6];
	R[1] = haptic[4];
	R[2] = haptic[5];
	R[8] = -haptic[10];
	R[9] = -haptic[8];
	R[10] = -haptic[9];

	float z1 = atan2(R[1], R[0]);
	float z2 = -PI + z1;
	if (z2 < -PI) z2 = 2 * PI + z2;
	float y1 = atan2(-R[2], (R[0] * cos(z1) + R[1] * sin(z1)));
	float y2 = atan2(-R[2], (R[0] * cos(z2) + R[1] * sin(z2)));
	float x1 = atan2((-R[9] * cos(z1) + R[8] * sin(z1)), (R[5] * cos(z1) - R[4] * sin(z1)));
	float x2 = atan2((-R[9] * cos(z2) + R[8] * sin(z2)), (R[5] * cos(z2) - R[4] * sin(z2)));

	if (true)
	{
		angles[0] = x1 * 180 / PI;
		angles[1] = y1 * 180 / PI;
		angles[2] = z1 * 180 / PI;
	}
	else
	{
		angles[0] = x2 * 180 / PI;
		angles[1] = y2 * 180 / PI;
		angles[2] = z2 * 180 / PI;
	}

}


// Haptic device initialization
int OpenHaptic::init()
{
	HDErrorInfo error;
	hHD = hdInitDevice(HD_DEFAULT_DEVICE);
	// Initialize the default haptic device
	if (HD_DEVICE_ERROR(error = hdGetError())){
		hduPrintError(stderr, &error, "Failed to initialize haptic device. ");
		return -1;
	}
	printf("> ___HAPTIC___ :Connected to a haptic device. Device name: %s \n", hdGetString(HD_DEVICE_MODEL_TYPE));
	
	// Start the servo scheduler and enable forces
	
	hdStartScheduler();
	hdScheduleAsynchronous(HapticForceCallback, 0 , HD_MAX_SCHEDULER_PRIORITY);

	hHLRC = hlCreateContext(hHD);
	hlMakeCurrent(hHLRC);
	hdMakeCurrentDevice(hHD);
	gEffect = hlGenEffects(1);
	hdEnable(HD_FORCE_OUTPUT);
	//hdStartScheduler();
	
	this->inverse_frame = true;
	this->connected = true;
	return 1;
}

// Disconnect haptic connection
void OpenHaptic::close()
{
	hlDeleteEffects(gEffect, 1);
	hlMakeCurrent(NULL);
	hlDeleteContext(hHLRC);
	hdDisableDevice(hHD);
	this->connected = false;
}

// Haptic Effect :
void OpenHaptic::effect_friction(float gain, float magnitude)
{
	effect_stop();
	hlBeginFrame();
	hlStartEffect(HL_EFFECT_FRICTION, gEffect);
	hlEndFrame();
	effect_update(gain, magnitude);
}
// Set the initial position and generate spring effect to the haptic
void OpenHaptic::effect_spring(hduVector3Dd position, float gain, float magnitude)
{
	effect_stop();
	hlBeginFrame();
	hlEffectdv(HL_EFFECT_PROPERTY_POSITION, position);
	hlStartEffect(HL_EFFECT_SPRING, gEffect);
	hlEndFrame();
	effect_update(gain, magnitude);
}
// Stop the haptic attached effect
void OpenHaptic::effect_stop()
{
	hlBeginFrame();
	HLboolean bActive = false;
	hlGetEffectbv(gEffect, HL_EFFECT_PROPERTY_ACTIVE, &bActive);
	if (bActive)
		hlStopEffect(gEffect);
	hlEndFrame();
}
void OpenHaptic::effect_update(float gain, float magnitude)
{
	hlBeginFrame();
	HLboolean bActive = false;
	hlGetEffectbv(gEffect, HL_EFFECT_PROPERTY_ACTIVE, &bActive);
	if (bActive) {
		hlEffectd(HL_EFFECT_PROPERTY_GAIN, gain);
		hlEffectd(HL_EFFECT_PROPERTY_MAGNITUDE, magnitude);
		hlUpdateEffect(gEffect);
	}
	hlEndFrame();
}

// -- Read Haptic Device State --						
// ///////////////////////////////////////////////////////

void OpenHaptic::read_state(DeviceStateStruct * state){
	DeviceStateStruct pState;

	hdScheduleSynchronous(DeviceStateCallback, &pState, HD_DEFAULT_SCHEDULER_PRIORITY);

	Matrix3d R_inv;
	R_inv <<
		-1, 0, 0,
		0, -1, 0,
		0, 0, 1;

	MatrixXd RA = get_matrix(pState);
	Vector3d Pos (-pState.position[0], -pState.position[1], pState.position[2]);
	MatrixXd R_XYZ = getEulerMatrix(Vector3d(90, 0, 90));
	MatrixXd RB = RA * R_XYZ;

	if (inverse_frame) {
		RB = RB * R_inv;
		Pos = R_inv * Pos;
	}

	Vector3d tetha = getRotationAngle(RB);
	// Convert from euler to Rotation matrix:
	tetha = euler2rot(tetha);

	state->position[0] = Pos(2);
	state->position[1] = Pos(0);
	state->position[2] = Pos(1);
	state->orientation[0] = tetha(0);
	state->orientation[1] = tetha(1);
	state->orientation[2] = tetha(2);
	
	state->button = pState.button;
	state->force = pState.force;
}

// Haptic Callback
HDCallbackCode HDCALLBACK DeviceStateCallback(void * pUserData)
{
	DeviceStateStruct *pState = (DeviceStateStruct *)pUserData;
	hdBeginFrame(hdGetCurrentDevice());
	hdGetIntegerv(HD_CURRENT_BUTTONS, &pState->button);
	hdGetDoublev(HD_CURRENT_POSITION, pState->position);
	hdGetDoublev(HD_CURRENT_TRANSFORM, pState->transform);
	hdGetDoublev(HD_CURRENT_FORCE, pState->force);
	hdGetDoublev(HD_CURRENT_VELOCITY, pState->velocity);
	hdGetDoublev(HD_CURRENT_GIMBAL_ANGLES, pState->orientation);
	hdEndFrame(hdGetCurrentDevice());
	return HD_CALLBACK_DONE;
}

HDCallbackCode HDCALLBACK HapticForceCallback(void * pUserData)
{
	hduVector3Dd feedback_forces;

	hdBeginFrame(hdGetCurrentDevice());
	feedback_forces[0] = global_haptic_forces[0];
	feedback_forces[1] = global_haptic_forces[1];
	feedback_forces[2] = global_haptic_forces[2];
	hdSetDoublev(HD_CURRENT_FORCE, feedback_forces);
	hdEndFrame(hdGetCurrentDevice());
	return HD_CALLBACK_CONTINUE;

}

void OpenHaptic::setForces(float real_forces[3]) {
	hduVector3Dd pDataForces;
	pDataForces[0] = real_forces[1];
	pDataForces[1] = real_forces[2];
	pDataForces[2] = real_forces[0];
	hdScheduleSynchronous(HapticForceCallback, &pDataForces, HD_DEFAULT_SCHEDULER_PRIORITY);
}

// Haptic Force Feedback Callback
///////////////////////////////////////////////////////////////
HDCallbackCode HDCALLBACK frictionlessPlaneCallback(void *pUserData) 
{
	hduVector3Dd position;
	const double planeStiffness = 0.25;
	const double popthroughForceThreshold = 5.0;
	hdBeginFrame(hdGetCurrentDevice());
	hdGetDoublev(HD_CURRENT_POSITION, position);
	hduVector3Dd feedback_forces;
	feedback_forces[0] = (global_haptic_forces[0] / 100) * 1.25;
	feedback_forces[1] = (global_haptic_forces[1] / 100) * 1.25;
	feedback_forces[2] = (global_haptic_forces[2] / 100) * 1.25;
	hdSetDoublev(HD_CURRENT_FORCE, feedback_forces);
	hdEndFrame(hdGetCurrentDevice());
	return HD_CALLBACK_CONTINUE;
}

// New method using Eigen lib :
MatrixXd OpenHaptic::get_matrix(DeviceStateStruct pState)
{
	MatrixXd M(3, 3);
	M(0, 0) = pState.transform[0];
	M(0, 1) = pState.transform[1];
	M(0, 2) = pState.transform[2];
	M(1, 0) = pState.transform[4];
	M(1, 1) = pState.transform[5];
	M(1, 2) = pState.transform[6];
	M(2, 0) = pState.transform[8];
	M(2, 1) = pState.transform[9];
	M(2, 2) = -pState.transform[10];
	return M;
}






// New haptic library:
// ////////////////////////////////////////
void OpenHaptic::new_init(OmniState *s)
{
	state = s;
	state->buttons[0] = 0;
	state->buttons[1] = 0;
	state->button_prev[0] = 0;
	state->button_prev[1] = 0;
	hduVector3Dd zeros(0, 0, 0);
	state->velocity = zeros;
	state->inp_vel1 = zeros;
	state->inp_vel2 = zeros;
	state->inp_vel3 = zeros;
	state->out_vel1 = zeros;
	state->out_vel2 = zeros;
	state->out_vel3 = zeros;
	state->pos_hist1 = zeros;
	state->pos_hist2 = zeros;
	state->lock = false;
	state->close_gripper = false;
	state->lock_pos = zeros;
}
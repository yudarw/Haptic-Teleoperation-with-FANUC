#include "Haptic.h"
#include "main.h"
#include <Windows.h>

HDCallbackCode HDCALLBACK	jointTorqueCallback(void * data);
float hapticfeedbackrate = 0.01;

int force_axis;
double joint_torque[3];
double last_position[3];

void RotationTransform(double* haptic, double angles[3])
{
	double R[16];
	R[4] = haptic[2];
	R[5] = haptic[0];
	R[6] = haptic[1];
	R[0] = haptic[6];
	R[1] = haptic[4];
	R[2] = haptic[5];
	R[8] =  -haptic[10];
	R[9] =  -haptic[8];
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

void rotation_transform_2(double* transform, double angle[3])
{
	double r11 = transform[0];
	double r12 = transform[1];
	double r13 = transform[2];

	double r21 = transform[4];
	double r22 = transform[5];
	double r23 = transform[6];
	
	double r31 = transform[8];
	double r32 = transform[9];
	double r33 = transform[10];

	double roll = atan2(r21, r11);
	double pitch = atan2(-r31, sqrt((r32 * r32) + (r33 * r33)));
	double yaw = atan2(r32, r33);

	angle[1] = yaw * 180 / PI;
	angle[0] = pitch * 180 / PI;
	angle[2] = roll * 180 / PI;

	double angle2[3];
	RotationTransform(transform, angle2);
	printf("Orientation (yaw, pitch, roll) = %.2f %.2f %.2f       %.2f %.2f %.2f \n", angle[0], angle[1], angle[2], angle2[0], angle2[1], angle2[2]);
	
	Sleep(100);
}

void PhantomOmniHaptic::hl_init()
{
	HDErrorInfo	error;
	hHD = hdInitDevice(HD_DEFAULT_DEVICE);
	if (HD_DEVICE_ERROR(error = hdGetError()))
	{
		printf(">Failed to connect to the haptic device. \n");
		return;
	}
	HHLRC hHLRC;
	hHLRC = hlCreateContext(hHD);
	hlMakeCurrent(hHLRC);
	hlBeginFrame();
}


// Haptic device initialization
// Return if there is no valid device detected
int PhantomOmniHaptic::init()
{
	HDErrorInfo	error;
	hHD = hdInitDevice(HD_DEFAULT_DEVICE);
	if (HD_DEVICE_ERROR(error = hdGetError()))
	{
		hduPrintError(stderr, &error, "Failed to initialize haptic device");
		return -1;
	}

	printf("Connected to a haptic device. Device name: %s \n", hdGetString(HD_DEVICE_MODEL_TYPE));

	hHLRC = hlCreateContext(hHD);
	hlMakeCurrent(hHLRC);
	hdMakeCurrentDevice(hHD);
	gEffect = hlGenEffects(1);
	hdStartScheduler();
	return 1;
}

void PhantomOmniHaptic::close()	
{
	//hdStopScheduler();
	hlDeleteEffects(gEffect, 1);
	hlMakeCurrent(NULL);
	hlDeleteContext(hHLRC);
	hdDisableDevice(hHD);
}

// Haptic Effect function :
// Friction Effect
void PhantomOmniHaptic::effect_friction(float gain, float magnitude)
{
	stop_effect();
	hlBeginFrame();
	hlStartEffect(HL_EFFECT_FRICTION, gEffect);
	hlEndFrame();
	update_effect(gain, magnitude);
}

// Set the initial position and generate spring effect to the haptic
void PhantomOmniHaptic::effect_spring(hduVector3Dd position, float gain, float magnitude)
{
	stop_effect();
	hlBeginFrame();
	hlEffectdv(HL_EFFECT_PROPERTY_POSITION, position);
	hlStartEffect(HL_EFFECT_SPRING, gEffect);
	hlEndFrame();
	update_effect(gain, magnitude);
}

// Stop the haptic attached effect
void PhantomOmniHaptic::stop_effect()
{
	hlBeginFrame();
	HLboolean bActive = false;
	hlGetEffectbv(gEffect, HL_EFFECT_PROPERTY_ACTIVE, &bActive);
	if (bActive)
		hlStopEffect(gEffect);
	hlEndFrame();
}

void PhantomOmniHaptic::update_effect(float gain, float magnitude)
{
	hlBeginFrame();
	HLboolean bActive = false;
	hlGetEffectbv(gEffect, HL_EFFECT_PROPERTY_ACTIVE, &bActive);
	if (bActive) {
		hlEffectd(HL_EFFECT_PROPERTY_GAIN, gain);
		hlEffectd(HL_EFFECT_PROPERTY_MAGNITUDE, magnitude);
		hlUpdateEffect(gEffect);
		console_print("Update effect success.");
	}
	hlEndFrame();
}


HDCallbackCode HDCALLBACK DevicePositionCallback(void * pUserData)
{
	DeviceStateStruct *pState = (DeviceStateStruct *)pUserData;
	hdBeginFrame(hdGetCurrentDevice());
	hdGetDoublev(HD_CURRENT_POSITION, pState->pos);
	hdGetDoublev(HD_CURRENT_TRANSFORM, pState->transform);
	hdGetDoublev(HD_CURRENT_FORCE, pState->force);
	hdEndFrame(hdGetCurrentDevice());
	return HD_CALLBACK_DONE;
}

HDCallbackCode HDCALLBACK DeviceStateCallback(void * pUserData)
{
	DeviceStateStruct *pState = (DeviceStateStruct *)pUserData;
	hdBeginFrame(hdGetCurrentDevice());
	hdGetIntegerv(HD_CURRENT_BUTTONS,		&pState->button);
	hdGetDoublev(HD_CURRENT_POSITION,		pState->pos);
	hdGetDoublev(HD_CURRENT_POSITION,		pState->position);
	hdGetDoublev(HD_CURRENT_TRANSFORM,		pState->transform);
	hdGetDoublev(HD_CURRENT_JOINT_ANGLES,	pState->joint);
	hdGetDoublev(HD_CURRENT_FORCE,			pState->force);
	hdGetDoublev(HD_CURRENT_GIMBAL_ANGLES,	&pState->joint[3]);
	hdGetDoublev(HD_CURRENT_VELOCITY,		pState->velocity);
	hdGetDoublev(HD_CURRENT_GIMBAL_ANGLES,  pState->angle);
	hdEndFrame(hdGetCurrentDevice());
	return HD_CALLBACK_DONE;
}

HDCallbackCode HDCALLBACK jointTorqueCallback(void * data)
{
	double hfx, hfy, hfz;
	HDErrorInfo error;
	hduVector3Dd jointTorque;
	hduVector3Dd hapticforce;
	hduVector3Dd f;
	int i;

	double force[3] = { 0.0, 0.0, 0.0 };
	double position[3];

	HHD hHD = hdGetCurrentDevice();
	hdBeginFrame(hHD);
	
	// get current position
	hdGetDoublev(HD_CURRENT_POSITION, position);
	
	force[0] = (last_position[0] - position[0]) * 0.15;
	force[1] = (last_position[1] - position[1]) * 0.15;
	force[2] = (last_position[2] - position[2]) * 0.15;

	last_position[0] = position[0];
	last_position[1] = position[1];
	last_position[2] = position[2];
	
	hdSetDoublev(HD_CURRENT_FORCE, force);
	hdEndFrame(hHD);

	return HD_CALLBACK_CONTINUE;
}

HDCallbackCode HDCALLBACK DeviceForceCallback(void * pUserData)
{
	HDdouble baseTorque[3];
	DeviceStateStruct *pState = (DeviceStateStruct *)pUserData;

	float calibrate_force[6] = { 81.671 + 9, 60.503 + 14, 988.618 + 38, 1.342, -5.438, -22.459 };

	baseTorque[2] = (pState->force[0] - calibrate_force[0]) * 0.2;
	baseTorque[0] = (pState->force[1] - calibrate_force[1]) * 0.2;
	baseTorque[1] = (pState->force[2] - calibrate_force[2]) * 0;

	printf("Set torque : %.2f %.2f %.2f \n", baseTorque[0], baseTorque[1], baseTorque[2]);

	hdBeginFrame(hdGetCurrentDevice());
	hdSetDoublev(HD_CURRENT_FORCE, baseTorque);
	hdEndFrame(hdGetCurrentDevice());
	
	return HD_CALLBACK_DONE;
}


void PhantomOmniHaptic::readPosition(double pos[3])
{	
	double transform[6];
	double force[3];
	readState(pos, transform, force);
}

void PhantomOmniHaptic::readTransform(double transform[16])
{
	DeviceStateStruct state;
	hdScheduleSynchronous(DevicePositionCallback, &state, HD_DEFAULT_SCHEDULER_PRIORITY);
	printf("> Forces : %.2f %.2f %.2f", state.force[0], state.force[1], state.force[2]);

	for (int i = 0; i < 16; i++) {
		transform[i] = state.transform[i];
	}
}

void PhantomOmniHaptic::readState(double pos[6], double force[3], double transform[16])
{
	double velocity[3];
	readState(pos, force, transform, velocity);
}

void PhantomOmniHaptic::readState(double pos[6], double force[3], double transform[16], double velocity[3])
{
	double rot[3];

	DeviceStateStruct state;
	hdScheduleSynchronous(DeviceStateCallback, &state, HD_DEFAULT_SCHEDULER_PRIORITY);
	RotationTransform(state.transform, rot);
	//pos[0] = state.position[2] - state.transform[10] * GIMBAL;
	//pos[1] = state.position[0] - state.transform[8] * GIMBAL;
	//pos[2] = state.position[1] - state.transform[9] * GIMBAL;
	pos[0] = state.position[2];
	pos[1] = state.position[0];
	pos[2] = state.position[1];

	pos[3] = rot[0];
	pos[4] = rot[1];
	pos[5] = rot[2];
	//pos[3] = state.angle[0] * (180 / PI);
	//pos[4] = state.angle[1] * (180 / PI);
	//pos[5] = state.angle[2] * (180 / PI);

	force[0] = state.force[0];
	force[1] = state.force[1];
	force[2] = state.force[2];
	velocity[0] = state.velocity[0];
	velocity[1] = state.velocity[1];
	velocity[2] = state.velocity[2];
	
	for (int i = 0; i < 16; i++) {
		transform[i] = state.transform[i];
	}
}


void PhantomOmniHaptic::readState(DeviceStateStruct * pState)
{
	double rot[3];
	DeviceStateStruct state;
	hdScheduleSynchronous(DeviceStateCallback, &state, HD_DEFAULT_SCHEDULER_PRIORITY);
	//rotation_transform_2(state.transform, rot);
	RotationTransform(state.transform, rot);
	pState->pos[0]		= state.position[2] - state.transform[10] * GIMBAL;
	pState->pos[1]		= state.position[0] - state.transform[8] * GIMBAL;
	pState->pos[2]		= state.position[1] - state.transform[9] * GIMBAL;

	pState->pos[0]		= state.position[2];
	pState->pos[1]		= state.position[0];
	pState->pos[2]		= state.position[1];

	pState->pos[3]		= rot[0];	
	pState->pos[4]		= rot[1];
	
	// Mode 1:
	int direction;
	if (rot[2] > 0) direction = 1; else direction = -1;
	pState->pos[5]		= (180 * direction) - rot[2];

	pState->button		= state.button;
	pState->force[0]	= state.force[0];
	pState->force[1]	= state.force[1];
	pState->force[2]	= state.force[2];

	pState->angle[0] = state.angle[0] * (180 / PI);
	pState->angle[1] = state.angle[1] * (180 / PI); 
	pState->angle[2] = state.angle[2] * (180 / PI);

	current_pos.X = pState->pos[0];
	current_pos.Y = pState->pos[1];
	current_pos.Z = pState->pos[2];
	current_pos.W = pState->pos[3];
	current_pos.P = pState->pos[4];
	current_pos.R = pState->pos[5];
}


void PhantomOmniHaptic::readForce(double force[3])
{
	hdScheduleSynchronous(DeviceForceCallback, force, HD_DEFAULT_SCHEDULER_PRIORITY);
	printf("Current force: %.2f %.2f %.2f \n", force[0], force[1], force[2]);
}

void PhantomOmniHaptic::setJointTorque(int joint, double torque)
{
	DeviceStateStruct state;

	for (int i = 0; i < 3; i++) {
		joint_torque[i] = 0;
	}
	joint_torque[joint] = torque;
	
	hdScheduleAsynchronous(DeviceForceCallback, &state, HD_MAX_SCHEDULER_PRIORITY);
}

void PhantomOmniHaptic::setForce(float force[6])
{
	DeviceStateStruct state;
	state.force[0] = force[0];
	state.force[1] = force[1];
	state.force[2] = force[2];
	//hdScheduleAsynchronous(DeviceForceCallback, &state, HD_MAX_SCHEDULER_PRIORITY);
	hdScheduleSynchronous(DeviceForceCallback, &state, HD_MAX_SCHEDULER_PRIORITY);
}


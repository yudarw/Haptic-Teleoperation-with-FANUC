#pragma once
#ifndef __HAPTIC_H__
#define __HAPTIC_H__

#include "Fanuc.h"
#include "HD\hd.h"
#include "HL\hl.h"
#include "HDU\hduError.h"
#include "HDU\hduVector.h"

#include <stdlib.h>

#define MAX_INPUT_DOF	6
#define MAX_OUTPUT_DOF	6
#define SENSE_RATE		1.0
#define PI				3.1415926
#define GIMBAL			42

typedef struct
{
	HDint			button;
	HDint			buttons[1];
	hduVector3Dd	position;
	HDdouble		transform[16];
	HDdouble		joint[6];
	HDdouble		force[3];
	HDdouble		pos[3];
	HDdouble		velocity[3];
	HDdouble		angle[3];
	HDlong			encoder_values[MAX_INPUT_DOF];
	HDlong			motor_dac_values[MAX_OUTPUT_DOF];
} DeviceStateStruct;


typedef struct
{
	float x;
	float y;
	float z;
	float Rx;
	float Ry;
	float Rz;
} t_pose;


class PhantomOmniHaptic
{
public:
	int		init();
	void	close();
	void	readPosition(double pos[3]);
	void	readTransform(double transform[16]);
	void	readState(double pos[6], double force[3], double transform[16]);
	void	readState(double pos[6], double force[3], double transform[16], double velocity[3]);
	void	readState(DeviceStateStruct * pState);
	void	readForce(double force[3]);
	void	setJointTorque(int joint, double torque);
	void	hl_init();
	void	setForce(float force[6]);
	void	setPosition(float position[3]);

	// Haptic Effect :
	void	effect_friction(float gain, float magnitute);
	void	effect_spring(hduVector3Dd position, float gain, float magnitude);
	void	update_effect(float gain, float magnitude);
	void	stop_effect();

public:
	HHD		hHD;
	HHLRC	hHLRC;
	HLuint	gEffect;
	float	gGain;
	float	gMagnitude;
	DataPos	current_pos;
};
#endif
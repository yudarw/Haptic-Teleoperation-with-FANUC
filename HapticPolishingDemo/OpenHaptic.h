#pragma once
#ifndef __OPEN_HAPTIC__
#define __OPEN_HAPTIC__

#include "HD\hd.h"
#include "HL\hl.h"
#include "HDU\hduError.h"
#include "HDU\hduVector.h"
#include "Eigen/Dense"
#include <stdlib.h>
#include <iostream>

#define PI				3.1415926
#define GIMBAL			42

extern hduVector3Dd global_haptic_forces;
// Haptic State Struct:
typedef struct
{
	HDint			button;
	hduVector3Dd	position;
	hduVector3Dd	orientation;
	hduVector3Dd	force;
	hduVector3Dd	velocity;
	HDdouble		transform[16];
}DeviceStateStruct;


typedef struct
{
	hduVector3Dd position;
	hduVector3Dd velocity;
	hduVector3Dd inp_vel1;
	hduVector3Dd inp_vel2;
	hduVector3Dd inp_vel3;
	hduVector3Dd out_vel1;
	hduVector3Dd out_vel2;
	hduVector3Dd out_vel3;
	hduVector3Dd pos_hist1;
	hduVector3Dd pos_hist2;
	hduVector3Dd joints;
	hduVector3Dd force;
	float tethas[7];
	int buttons[2];
	int button_prev[2];
	bool lock;
	bool close_gripper;
	hduVector3Dd lock_pos;
	double units_ratio;

}OmniState;



// Class OpenHaptic:
class OpenHaptic
{
public:

	// Haptic connection :
	int  init();
	void close();
	void read_state(DeviceStateStruct * pState);

	// Haptic force effect
	void effect_friction(float gain, float magnitude);
	void effect_spring(hduVector3Dd position, float gain, float magnitude);
	void effect_update(float gain, float magnitude);
	void effect_stop();
	void setForces(float forces[3]);

	Eigen::MatrixXd get_matrix(DeviceStateStruct state);


	// New lib function:
	void new_init(OmniState *s);
public:
	HHD		hHD;
	HHLRC	hHLRC;
	HLuint	gEffect;
	float	gGain;
	float	gMagnitude;
	bool	connected;
	float	forces[3];
	float	org_matrix[4][4];
	bool	inverse_frame;
};
#endif

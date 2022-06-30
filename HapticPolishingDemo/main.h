#pragma once
#include "StdAfx.h"
#include "Fanuc.h"
#include "OpenHaptic.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <process.h>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>

#define MAX_SCALE			5.0
#define MAX_TRAJECRORY_NUM  1000
#define RAD_TO_DEG (180/3.141592)
#define DEG_TO_RAD (3.141592/180)

using namespace std;

extern bool trajectory_form_isOpen;
extern bool robotControl_form_isOpen;
extern bool custom_form_isOpen;
extern bool force_calibration_form_isOpen;
extern bool coppelia_form_isOpen;
extern bool myform_isOpen;

extern void console_print(string text);
extern void console_print_error(string text);
extern char * convert_doubleToString(float data);

extern Fanuc			robot;
extern OpenHaptic		haptic;

extern DataPos			global_robot_pos;
extern DataPos			global_moving_pos;
extern DataPos			global_teaching_pos;
extern DataPos			global_haptic_pos;
extern DataForce		global_forces;
extern DataForce		offset_forces;
extern DataForce		current_force;
extern DataForce		temp;
extern DataForce		calibrated_forces;

extern int prog_state;
extern bool robotIsMoving;
extern int wait_move_delay;
extern double scale_factor;
extern bool jog_isRunning;
extern int timer2_interval;
extern int delay_jog_mode;
extern int haptic_button;

extern bool flag_haptic_connected;
extern bool flag_robot_connected;
extern bool flag_haptic_jog_mode;
extern bool flag_teachingmode;
extern bool inverse_workspace;
extern bool simulation_mode;

extern float trajectory[MAX_TRAJECRORY_NUM][15];
extern float tp_points[MAX_TRAJECRORY_NUM][12];
extern int index;

extern void robot_updateData();
extern void move_L(DataPos pos, int acc, int motion_type);
extern void move_L(DataPos pos, int acc, int motion_type, int cnt);
extern void move_L2(float pos[12], int acc, int motion_type);
extern void move_L2(float pos[12], int acc, int motion_type, int cnt);
extern void move_J(DataPos pos, int acc, int motion_type, int cnt_val);
extern void move_J2(float pos[12], int acc, int motion_type, int cnt);
extern void move_J2(float pos[12], int acc, int motion_type);
extern void joint_copy(float src[6], float dst[6]);
extern bool isMovingFinish(DataPos pos);
extern void setOverride(int _override);
extern void ATC_lock();
extern void ATC_unlock();
extern void gripper_OPEN();
extern void gripper_CLOSE();
extern void robot_attach_gripper(void *);
extern void robot_release_gripper(void *);
extern void load_trajectory(string filepath, float point[][12], int * total_point);
extern void save_trajectory(string filepath, float p[][12]);
extern void record_current_point();

extern float initPos[12];
extern float stanbyPos[12];

extern string currentDateTime;


extern void calibrate_offset_force(void *);
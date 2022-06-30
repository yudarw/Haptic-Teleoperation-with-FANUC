#include "main.h"
#include "Eigen\Dense"

using namespace Eigen;
using namespace std;

Fanuc		robot;

// Process flag :
bool flag_haptic_connected = false;
bool flag_robot_connected = false;
bool flag_haptic_jog_mode = false;
bool flag_teachingmode = false;
bool inverse_workspace = false;
bool simulation_mode = false;


DataPos			global_robot_pos;
DataPos			global_moving_pos;
DataPos			global_teaching_pos;
DataPos			global_haptic_pos;
DataForce		global_forces;
DataForce		offset_forces;
DataForce		current_force;
DataForce		temp;
DataForce		calibrated_forces;

// Stanby Pos
float stanbyPos[12] = { -752.075, 946.029, 426.524, -172.925, -4.987, 63, _N_, _U_, _T_, 0, 0, 0 };
// -- Recorded Points --
float initPos[12] = { 800.000, 0.000, 300.000, -180.000, 0.000, -104.921, _N_, _U_, _T_, 0, 0, 0 };

// Position Tool 1: 
float tool1_point[12] = { 496.945, 112.711, -314.630, -179.431, 0.105, -104.938, _N_, _U_, _T_, 0, 0, 0 };
float tool1_point_up[12] = { 496.602, 112.861, -278.239, -179.432, 0.100, -104.938, _N_, _U_, _T_, 0, 0, 0 };
float tool1_point_up2[12] = { 496.418, 120.093, -065.439, -179.362, 0.200, -104.921, _N_, _U_, _T_, 0, 0, 0 };

// Position Tool 2;
float tool2_point[12] = { 496.344, 369.961, -315.439, -179.604, 0.200, -105.476, _N_, _U_, _T_, 0, 0, 0 };
float tool2_point_up[12] = { 496.344, 369.961, -265.439, -179.604, 0.200, -105.476, _N_, _U_, _T_, 0, 0, 0 };
float tool2_point_up2[12] = { 496.344, 369.961, -065.439, -179.604, 0.200, -105.476, _N_, _U_, _T_, 0, 0, 0 };

// Wood Picking Point
float woodpick_step1[12] = { 1461.618, 745.037, 34.938, -98.428, 17.317, -0.484, 0,	1, 1, 0, 0, 0 };
float woodpick_step2[12] = { 1460.984, 809.073, 16.212, -98.44,  17.322, -0.5,	 0,	1, 1, 0, 0,	0 };
float woodpick_step3[12] = { 1462.597, 764.197, 22.499, -98.444, 17.323, -0.504, 0, 1, 1, 0, 0, 0 };
float woodpick_step4[12] = { 1461.667, 791.578, 18.515, -98.45,  17.325, -0.51,  0, 1, 1, 0, 0, 0 };
float woodpick_step5[12] = { 1475.155, 444.663, 71.618, -98.454, 17.33, -0.511,  0, 1, 1, 0, 0, 0 };
float woodpick_step6[12] = { 1185.178, 237.802, 426.563, -172.901,-4.785,-53.299,0, 1, 1, 0, 0, 0 };

float woodrelease_point_rotate[12] = { 1076.901, 390.841, 324.980, -133.714, 45.435, -34.218, 0, 1, 1, 0, 0, 0 };
float woodrelease_point_up[12] = { 1457.913, 859.140, 447.272, -133.714, 45.435, -34.218, 0, 1, 1, 0, 0, 0 };
float woodrelease_point[12] = { 1457.913, 859.140, 247.272, -133.714, 45.435, -34.218, 0, 1, 1, 0, 0, 0 };

//float P1[12] = { 1105.089, 519.246, -316.561, -176.555, 2.207, 15.516, N_, U_, T_, 0, 0, 1 };
//float P2[12] = { 1105.089, 706.445, -316.561, -176.555, 2.207, 15.516, N_, U_, T_, 0, 0, 1 };
//float P3[12] = { 590.051,  706.445, -316.561, -176.555, 2.207, 15.516, N_, U_, T_, 0, 0, 1 };
//float P4[12] = { 590.051,  510.606, -316.561, -176.555, 2.207, 15.516, N_, U_, T_, 0, 0, 1 };

// ///////////////////////////////////////////////////////
// -- Point to Point Moving Functions --
// Main function for moving the robot
// Add these following function in every new project
// to conveniently move the robot using timer.
// ////////////////////////////////////////////////////////
void joint_copy(float src[6], float dst[6])
{
	for (int i = 0; i < 6; i++) dst[i] = src[i];
}

bool isMovingFinish(DataPos pos)
{
	bool state = false;
	if ((pos.X == robot.current_pos.X) && (pos.Y == robot.current_pos.Y) && (pos.Z == robot.current_pos.Z))
	{
		state = true;
	}
	return state;
}
void move_L2(float pos[12], int acc, int motion_type)
{
	DataPos new_pos = convert_to_datapos(pos);
	move_L(new_pos, acc, motion_type);
}
void move_L2(float pos[12], int acc, int motion_type, int cnt_val)
{
	DataPos new_pos = convert_to_datapos(pos);
	move_L(new_pos, acc, motion_type, cnt_val);
}
void move_J2(float pos[12], int acc, int motion_type)
{
	DataPos new_pos = convert_to_datapos(pos);
	move_J(new_pos, acc, motion_type, 100);
}
void move_J2(float pos[12], int acc, int motion_type, int cnt_val)
{
	DataPos new_pos = convert_to_datapos(pos);
	move_J(new_pos, acc, motion_type, cnt_val);
}
void move_L(DataPos pos, int acc, int motion_type)
{
	robot._moving_mode = MOVE_L;
	robot.goal_position = pos;
	robot._motion_type = motion_type;
	robot._acc_val = acc;
	robot._cnt_val = 100;
	robot.doMoving = true;
	Sleep(wait_move_delay);

	while (robotIsMoving);
	/*
	bool wait = true;
	while (wait) {
	if (isMovingFinish(pos))wait = false;
	}
	*/
}
void move_L(DataPos pos, int acc, int motion_type, int cnt_val)
{
	robot._moving_mode = MOVE_L;
	robot.goal_position = pos;
	robot._motion_type = motion_type;
	robot._acc_val = acc;
	robot._cnt_val = cnt_val;
	robot.doMoving = true;
	Sleep(wait_move_delay);

	while (robotIsMoving);
	/*
	bool wait = true;
	while (wait) {
	if (isMovingFinish(pos))wait = false;
	}
	*/
}
void move_J(DataPos pos, int acc, int motion_type, int cnt_val)
{
	robot._moving_mode = MOVE_J;
	robot.goal_position = pos;
	robot._motion_type = motion_type;
	robot._acc_val = acc;
	robot._cnt_val = cnt_val;
	robot.doMoving = true;
	Sleep(wait_move_delay);
	while (robotIsMoving);
}
void move_jointmode(float joint[6], int acc)
{
	robot._moving_mode = MOVE_JOINT;
	robot._acc_val = acc;
	joint_copy(joint, robot.dst_joint);
	robot.doMoving = true;
	Sleep(wait_move_delay);
	while (robotIsMoving);
}

// Robot TOOl functions:
void ATC_lock() {
	robot.doAttachTool = true;
}
void ATC_unlock() {
	robot.doDetacthTool = true;
}
void gripper_OPEN() {
	robot.doGripperON = true;
}
void gripper_CLOSE() {
	robot.doGripperOFF = true;
}

// Set Override :
void setOverride(int _override)
{
	robot._override_val = _override;
	Sleep(100);
	robot.doSetOvrr = true;
}
// - End of Moving Functions -
////////////////////////////////////////////////////////////




// -- Steps Attach Tool 1 --
void robot_attach_gripper(void *)
{
	setOverride(70);

	move_J2(initPos, 50, CNT);
	move_J2(tool1_point_up, 50, FINE);	// Above the picking point	

	ATC_unlock();						// Unlock Hand Tool Port

	move_L2(tool1_point, 30, FINE);		// Move Down to picking point

	Sleep(500);
	ATC_lock();						// Lock the Hand Tool
	Sleep(500);

	move_L2(tool1_point_up2, 50, CNT, 30);
	move_J2(initPos, 50, CNT);

	printf("___TOOL____: Attach Gripper done. \n");

}

// -- Steps Release Tool 1 --
void robot_release_gripper(void *)
{
	setOverride(60);
	move_J2(initPos, 50, FINE);
	move_J2(tool1_point_up, 50, CNT);	// Above the picking point
	move_L2(tool1_point, 20, FINE);		// Move Down to picking point

	Sleep(500);
	ATC_unlock();
	Sleep(500);

	move_L2(tool1_point_up2, 50, FINE, 30);
	ATC_lock();

	move_J2(initPos, 50, CNT);
	printf("___TOOL____: Release Gripperdone. \n");
}

// -- Workpiece Picking --
void robot_workpiece_picking(void *)
{
	setOverride(40);
	move_J2(initPos, 50, CNT, 20);
	gripper_OPEN();
	move_L2(woodpick_step1, 100, FINE);
	move_L2(woodpick_step2, 40, FINE);

	Sleep(250);
	gripper_CLOSE();
	Sleep(250);

	move_L2(woodpick_step3, 100, FINE);

	Sleep(250);
	gripper_OPEN();
	Sleep(250);

	move_L2(woodpick_step4, 40, FINE);

	Sleep(250);
	gripper_CLOSE();
	Sleep(250);

	move_L2(woodpick_step5, 100, FINE);
	move_L2(woodpick_step6, 100, FINE);
}

void robot_workspace_release(void *)
{
	//move_L2(initPos, 50, CNT, 100);
	//move_L2(woodrelease_point_rotate, 100, CNT, 30);
	move_L2(woodrelease_point_up, 100, CNT);
	move_L2(woodrelease_point, 50, FINE);

	gripper_OPEN();
}

// -- Play Trajectory File --
void play_trajectory(string filepath, int acc)
{
	float point[MAX_TRAJECRORY_NUM][12];
	int max;
	load_trajectory(filepath, point, &max);
	for (int i = 0; i < max; i++)
		move_L2(point[i], acc, CNT, 100);
}


void robot_updateData() 
{
	if (robot.connected)
	{
		robot.refresh();
		global_robot_pos = robot.read_currentPos();
		prog_state = robot.read_programState();
		current_force = robot.read_forces();

		//robot.read_currentJointUF(robot.current_joint);
		//global_robot_pos = robot.read_currentPosUF();
		//robot.check_moving_status();
		//robot.read_sdo(20);
	}
}

// Thread for teaching mode -> Controlling the arm robot using haptic: 
/*
void thread_haptic_jog_mode(void * data)
{
	// optional configuration:
	bool invers = false;
	int  invers_state = -1;
	int control_mode = 0;
	DataPos initial_pos;
	DataPos haptic_inital_pos;

	// Set current position as initial pos:
	initial_pos = global_robot_pos;
	haptic_inital_pos = global_haptic_pos;
	global_teaching_pos = global_robot_pos;

	//	getpos_flag = false;
	simulation_mode = true;

	bool run = false;

	while (flag_haptic_jog_mode == true)
	{
		if (haptic_button == 2) {
			if (!jog_isRunning) jog_isRunning = true;
			else jog_isRunning = false;
			Sleep(200);
		}

		// Roboguide simulation mode:
		if (jog_isRunning)
		{
			global_teaching_pos.X = initial_pos.X + ((global_haptic_pos.X - haptic_inital_pos.X) * scale_factor);
			global_teaching_pos.Y = initial_pos.Y + ((global_haptic_pos.Y - haptic_inital_pos.Y) * scale_factor);
			global_teaching_pos.Z = initial_pos.Z + ((global_haptic_pos.Z - haptic_inital_pos.Z) * scale_factor);
			global_teaching_pos.W = global_haptic_pos.W;
			global_teaching_pos.P = global_haptic_pos.P;
			global_teaching_pos.R = global_haptic_pos.R;
		}
		else {
			initial_pos			= global_robot_pos;
			haptic_inital_pos	= global_haptic_pos;
			Sleep(50);
		}

		Sleep(delay_jog_mode);
	}
	console_print("Haptic jog stopped.");
}
*/
// -- End of Haptic Jog Mode Functions --
// /////////////////////////////////////////////////////////////

void copy_pos(DataPos pos, Vector3d & new_pos, Vector3d & new_ori) {
	new_pos[0] = pos.X;
	new_pos[1] = pos.Y;
	new_pos[2] = pos.Z;
	new_ori[0] = pos.W;
	new_ori[1] = pos.P;
	new_ori[2] = pos.R;
}

void setHapticForce(Vector3d f) {
	global_haptic_forces[2] = f(0);
	global_haptic_forces[0] = f(1);
	global_haptic_forces[1] = f(2);
}

void setRobotPos(Vector3d pos, Vector3d orient, bool orientation_lock)
{
	global_teaching_pos.X = pos(0);
	global_teaching_pos.Y = pos(1);
	global_teaching_pos.Z = pos(2);

	if (!orientation_lock) {
		global_teaching_pos.W = orient(0);
		global_teaching_pos.P = orient(1);
		global_teaching_pos.R = orient(2);
	}
}

void thread_haptic_jog_mode(void * data)
{
	Vector3d Xs, Xs_orient;
	Vector3d Xh, Xh_orient;
	Vector3d Xs0, Xs0_orient;
	Vector3d Xh0, Xh0_orient;
	Vector3d Xm, Xm_orient;
	Vector3d err, d_err_m, d_err_s, Fcm, Fcs;
	Vector3d Xsc, new_Xs;
	
	global_teaching_pos = global_robot_pos;

	bool orientation_lock = true;

	while (flag_haptic_jog_mode == true) {
		copy_pos(global_robot_pos, Xs, Xs_orient);
		copy_pos(global_haptic_pos, Xh, Xh_orient);
		
		
		// Check the stylus button to attach and detach the haptic:
		if (haptic_button == 2) {
			if (!jog_isRunning) {
				jog_isRunning = true;
				copy_pos(global_robot_pos, Xs0, Xs0_orient);
				copy_pos(global_haptic_pos, Xh0, Xh0_orient);
			}
			else {
				jog_isRunning = false;
				setHapticForce(Vector3d(0, 0, 0));
				//haptic.effect_stop();
			}
			Sleep(500);
		}

		if (haptic_button == 1) {
			if (!orientation_lock) orientation_lock = true;
			else orientation_lock = false;
			Sleep(500);
		}
		

		//  -- Haptic teleoperation mode --
		// /////////////////////////////////////////
		if (jog_isRunning) 
		{
			Xm = Xs0 + ((Xh - Xh0));
			Xm_orient = Xh_orient;

			// 1. Guidance controller :

			// 2. Master controller :
			double Km = 0.030;
			double Bm = 0.025;
			
			err = Xs - Xm;
			Fcm = (err * Km) + ((err - d_err_m) * Bm);
			d_err_m = err;

			// 3. Slave controller :
			double Ks = 0.050;
			double Bs = 0.010;
			err = Xm - Xs;
			Fcs = (err * Ks) + ((err - d_err_s) * Bs);
			d_err_s = err;

			// Position controller:
			double Ksc = 10.0;
			Xsc = (Fcs * Ksc);
			new_Xs = Xs + Xsc;

			// Set robot position
			setRobotPos(new_Xs, Xm_orient, orientation_lock);

			// Set robot position with direct control with haptic position:
			setRobotPos(Xm, Xm_orient, orientation_lock);

			setHapticForce(Fcm);

			Vector3d targetpos(-129.352, -963.113, 674.953);

			Vector3d diffPos = targetpos - Xm;
			//printf("Fcm: %.3f   %.3f   %.3f \n", Fcm(0), Fcm(1), Fcm(2));
			printf("Pos Error: %.3f, %.3f, %.3f \n", diffPos[0], diffPos[1], diffPos[2]);
		}

		//Sleep(50);
	}
}
#include "main.h"
#include "stdafx.h"
#include "CoppeliaForm.h"
#include "coppeliasim.h"
#include "HomogeneousTransform.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;

CoppeliaRobot	robotSim("FanucM20_respondable");
CoppeliaForce	ft_sensor;
int ftHandle, robotHandle, tipHandle;

float current_robot_pos[6];
float current_sim_force[6];
float calibrated_sim_force[3];

bool sim_jog_mode = false;
bool run = false;
void sim_haptic_jog_mode_thread(void *);
void sim_force_calibration();
void thread_main_program(void *);

void CoppeliaForm::test()
{
	printf(">> Current robot position : %.3f   %.3f   %.3f \n", global_robot_pos.X, global_robot_pos.Y, global_robot_pos.Z);
}


// -- On Timer function : Update the UI data --
// ///////////////////////////////////////////////
void CoppeliaForm::on_timer() {

	// Update currrent position data 
	tb_out_posx->Text = gcnew String(convert_doubleToString(current_robot_pos[0]));
	tb_out_posy->Text = gcnew String(convert_doubleToString(current_robot_pos[1]));
	tb_out_posz->Text = gcnew String(convert_doubleToString(current_robot_pos[2]));
	tb_out_posw->Text = gcnew String(convert_doubleToString(current_robot_pos[3]));
	tb_out_posp->Text = gcnew String(convert_doubleToString(current_robot_pos[4]));
	tb_out_posr->Text = gcnew String(convert_doubleToString(current_robot_pos[5]));

	// Update current force data
	label_fx->Text = gcnew String(convert_doubleToString(current_sim_force[0]));
	label_fy->Text = gcnew String(convert_doubleToString(current_sim_force[1]));
	label_fz->Text = gcnew String(convert_doubleToString(current_sim_force[2]));
	label_mx->Text = gcnew String(convert_doubleToString(current_sim_force[3]));
	label_my->Text = gcnew String(convert_doubleToString(current_sim_force[4]));
	label_mz->Text = gcnew String(convert_doubleToString(current_sim_force[5]));
	
	int max_force = 100;
	int force_tmp;
	force_tmp = (current_sim_force[0] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fx_bar->Value = abs(force_tmp);
	force_tmp = (current_sim_force[1] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fy_bar->Value = abs(force_tmp);
	force_tmp = (current_sim_force[2] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fz_bar->Value = abs(force_tmp);
	force_tmp = (current_sim_force[3] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	mx_bar->Value = abs(force_tmp);
	force_tmp = (current_sim_force[4] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	my_bar->Value = abs(force_tmp);
	force_tmp = (current_sim_force[5] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	mz_bar->Value = abs(force_tmp);

	// Update calibrated force data
	sim_force_calibration();
	
	label_fx1->Text = gcnew String(convert_doubleToString(calibrated_sim_force[0]));
	label_fy1->Text = gcnew String(convert_doubleToString(calibrated_sim_force[1]));
	label_fz1->Text = gcnew String(convert_doubleToString(calibrated_sim_force[2]));

	force_tmp = (calibrated_sim_force[0] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fx_bar1->Value = abs(force_tmp);
	force_tmp = (calibrated_sim_force[1] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fy_bar1->Value = abs(force_tmp);
	force_tmp = (calibrated_sim_force[2] / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fz_bar1->Value = abs(force_tmp);
}

void sim_read_data(void *) {
	while (1) {

		if (robotSim.connected && !sim_jog_mode) {
			//robotSim.readCurrentPosition(current_robot_pos);
			ft_sensor.read(current_sim_force);
		}

		Sleep(200);
	}
}

void CoppeliaForm::sim_connect()
{
	if (!robotSim.connected) {
		bool state = robotSim.connect(19999);
		if (state) {
			btnSimConnect->Text = "Sim Disconnect";
			ft_sensor.init(robotSim.clientID, "FanucM20_forceSensor");
			robotSim.init();
			simxGetObjectHandle(robotSim.clientID, "FanucM20_forceSensor", &ftHandle, simx_opmode_oneshot_wait);
			simxGetObjectHandle(robotSim.clientID, "FanucM20_respondable", &robotHandle, simx_opmode_oneshot_wait);
			simxGetObjectHandle(robotSim.clientID, "FanucM20_ikTip", &tipHandle, simx_opmode_oneshot_wait);
			
			//ft_sensor.read(current_sim_force);
			_beginthread(sim_read_data, 0, NULL);
		}
	}
	else {
		robotSim.disconnect(robotSim.clientID);
		btnSimConnect->Text = "SIM Connect";
	}
}
void CoppeliaForm::sim_haptic_jog(){

	if (!sim_jog_mode) {
		if (!haptic.connected) {
			printf("___ERROR___: Haptic device is not connected \n");
			return;
		}
		printf(">> Start haptic jog mode... \n");
		sim_jog_mode = true;
		btnHapticJog->Text = "Stop Jog";
		_beginthread(sim_haptic_jog_mode_thread, 0, NULL);
	}
	else {
		printf(">> Stopping haptic jog mode... \n");
		sim_jog_mode = false;
		btnHapticJog->Text = "Haptic Jog";
	}
}

void CoppeliaForm::get_current_position()
{
	char str[200];
	tb_pos_x->Text = tb_out_posx->Text;
	tb_pos_y->Text = tb_out_posy->Text;
	tb_pos_z->Text = tb_out_posz->Text;
	tb_pos_w->Text = tb_out_posw->Text;
	tb_pos_p->Text = tb_out_posp->Text; 
	tb_pos_r->Text = tb_out_posr->Text;

	float pos[6];
	robotSim.readCurrentPosition(pos);

	sprintf(str, "%.3f", pos[0]); tb_pos_x->Text = gcnew String(str);
	sprintf(str, "%.3f", pos[1]); tb_pos_y->Text = gcnew String(str);
	sprintf(str, "%.3f", pos[2]); tb_pos_z->Text = gcnew String(str);
	sprintf(str, "%.3f", pos[3]); tb_pos_w->Text = gcnew String(str);
	sprintf(str, "%.3f", pos[4]); tb_pos_p->Text = gcnew String(str);
	sprintf(str, "%.3f", pos[5]); tb_pos_r->Text = gcnew String(str);
}

void CoppeliaForm::sim_set_position()
{
	float x, y, z, w, p, r;
	x = Convert::ToDouble(tb_pos_x->Text);
	y = Convert::ToDouble(tb_pos_y->Text);
	z = Convert::ToDouble(tb_pos_z->Text);
	w = Convert::ToDouble(tb_pos_w->Text);
	p = Convert::ToDouble(tb_pos_p->Text);
	r = Convert::ToDouble(tb_pos_r->Text);
	robotSim.setSpeed(50);
	robotSim.setPosition(x, y, z, w, p, r);
	//printf("__INFO__: sim.setPosition(%.3f, %.3f, %.3f, %.3f, %.3f, %.3f) \n", x, y, z, w, p, r);
}



// -- Sim Haptic Jog Mode --
// /////////////////////////////////////////////////////////
void sim_haptic_jog_mode_thread(void *)
{
	int scale_factor = 1;
	float robot_initial_pos[6];
	float haptic_initial_pos[6];
	float haptic_teaching_pos[6];
	run = false;
	bool gripper_isOpen = false;

	robotSim.readCurrentPosition(robot_initial_pos);
	robotSim.setSpeed(80);
	
	while (sim_jog_mode) {
		// -- Check haptic button mode --
		if (haptic_button == 2) {
			if (!run) run = true;
			else run = false;
			Sleep(500);
		}

		// -- If the haptic in running --
		if (run) {
			Vector3d robot_orient(global_haptic_pos.W, global_haptic_pos.P, global_haptic_pos.R);
			Vector3d norm_orient = rot2euler(robot_orient);
			haptic_teaching_pos[0] = robot_initial_pos[0] + ((global_haptic_pos.X - haptic_initial_pos[0]) * (scale_factor));
			haptic_teaching_pos[1] = robot_initial_pos[1] + ((global_haptic_pos.Y - haptic_initial_pos[1]) * (scale_factor));
			haptic_teaching_pos[2] = robot_initial_pos[2] + ((global_haptic_pos.Z - haptic_initial_pos[2]) * (scale_factor));
			haptic_teaching_pos[3] = norm_orient(0);
			haptic_teaching_pos[4] = norm_orient(1);
			haptic_teaching_pos[5] = norm_orient(2);
			robotSim.setPosition(haptic_teaching_pos, false);
		}
		else {
			robotSim.readCurrentPosition(current_robot_pos);
			robot_initial_pos[0] = current_robot_pos[0];
			robot_initial_pos[1] = current_robot_pos[1];
			robot_initial_pos[2] = current_robot_pos[2];
			haptic_initial_pos[0] = global_haptic_pos.X;
			haptic_initial_pos[1] = global_haptic_pos.Y;
			haptic_initial_pos[2] = global_haptic_pos.Z;
		}
		
		ft_sensor.read(current_sim_force);

		// -- Gripper --
		if (haptic_button == 1) {
			if (!gripper_isOpen) gripper_isOpen = true;
			else gripper_isOpen = false;

			if (gripper_isOpen) robotSim.gripperCatch();
			else robotSim.gripperRelease();
			Sleep(500);
		}

		// -- Calculate force sensor calibration --
		// Force sensor calibration

		Sleep(10);
	}
}



// -- Sim force calibration --
// ////////////////////////////////////////////////////
void sim_force_calibration()
{
	Vector3d offset_force(0, 0, 52);
	Vector3d sim_robot_orient(global_haptic_pos.W, global_haptic_pos.P, global_haptic_pos.R);
	Vector3d norm_orient = rot2euler(sim_robot_orient);
	Vector3d temp(norm_orient(2), norm_orient(1), norm_orient(0));
	MatrixXd R_XYZ = getEulerMatrix(temp);
	Vector3d f_current(current_sim_force[0], current_sim_force[1], current_sim_force[2]);
	Vector3d f_calibrated = R_XYZ * f_current;
	
	calibrated_sim_force[0] = f_calibrated(0);
	calibrated_sim_force[1] = f_calibrated(1);
	calibrated_sim_force[2] = f_calibrated(2);

	//printf(">> orientation")
}

bool Busy = false;
void thread_move_point(void *)
{
	Busy = true;
	float start_pos[6];
	float stop_pos[6];

	robotSim.readObjectPosition("start", start_pos);
	robotSim.readObjectPosition("stop", stop_pos);

	robotSim.setSpeed(1);
	robotSim.setPosition(start_pos, true);
	robotSim.setPosition(stop_pos, true);
	Busy = false;
}



void force_control(void *);

// -- Main Form : Edit your main program here. --
// /////////////////////////////////////////////////////
void CoppeliaForm::main_program()
{
	if (!Busy)
		_beginthread(thread_main_program, 0, NULL);
		//_beginthread(thread_move_point, 0, NULL);
		//_beginthread(force_control, 0, NULL);
}



// -- Force sensor calibration procedure : --
// ///////////////////////////////////////////////////////
void calibrate_offset_force(void *) 
{
	if (!robotSim.connected) {
		cout << currentDateTime << " Error!!! Simulation is not connected" << endl;
		return;
	}

	// Rotate the orientation of the robot 90 degree:
	float calibration_pos[6] = { 700, 0, 500, 90, 0, 0 };
	float calibration_pos2[6] = { 700, 0, 500, 180, 0, 0 };

	robotSim.setSpeed(10);
	robotSim.setPosition(calibration_pos, true);

	float sim_force[6];
	ft_sensor.read(sim_force);

	float gravity_force = Math::Abs(sim_force[1]);
	cout << "> gravity force = " << gravity_force << endl;

	robotSim.setPosition(calibration_pos2, true);
	ft_sensor.read(sim_force);

	float Fz = sim_force[2] - gravity_force;
	cout << "> Fz = " << Fz << endl;
}

void force_control(void *) 
{
	float cur_pos[6];
	float new_pos[6];
	float fs[6];
	double fe, last_fe;
	double fd = 10;
	double kp = 0.5;
	double kd = 0.5;
	double fz, fzd;
	double fz_offset = 2.9;

	while (1){
		ft_sensor.read(current_sim_force);
		robotSim.readCurrentPosition(current_robot_pos);

		for (int i = 0; i < 6; i++)
			cur_pos[i] = current_robot_pos[i];

		fz = current_sim_force[2] - fz_offset;
		
		fe = fd - fz;
		fzd = fe - last_fe;

		double pd_z = ((kp * fe) + (kd * fzd)) * 0.01;

		cur_pos[2] = cur_pos[2] - pd_z;
		robotSim.setPosition(cur_pos, true);
		last_fe = fe;

		Sleep(10);
	}
}

/*
	Step for trajectory calibration:
	1. Read position from robot 1
	2. Read position from robot 2

*/
void thread_main_program(void *) {
	


}
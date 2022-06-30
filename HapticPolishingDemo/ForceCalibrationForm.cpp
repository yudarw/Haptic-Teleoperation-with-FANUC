#include <iostream>
#include "main.h"
#include "stdafx.h"
#include "ForceCalibrationForm.h"
#include "HomogeneousTransform.h"

using namespace std;
using namespace msclr::interop;

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;

bool trajectory_isRunning = false;
DataPos temp_pos;

// =============================================================== //
//			  Force Sensor Calibration Procedure				   //
// =============================================================== //
void calculate_gravity_compensation(DataForce original_forces, DataForce * calibrated_force)
{
	Vector3d offset_force(0, 0, -60);

	Vector3d sim_robot_orient(global_robot_pos.W, global_robot_pos.P, global_robot_pos.R);
	Vector3d norm_orient = rot2euler(sim_robot_orient);

	Vector3d temp(norm_orient(2), norm_orient(1), norm_orient(0));
	MatrixXd R_XYZ = getEulerMatrix(temp);

	Vector3d f_current(original_forces.Fx, original_forces.Fy, original_forces.Fz);
	Vector3d f_calibrated = R_XYZ * f_current;

	calibrated_force->Fx = f_calibrated(0) - offset_force(0);
	calibrated_force->Fy = f_calibrated(1) - offset_force(1);
	calibrated_force->Fz = f_calibrated(2) - offset_force(2);
	/*
	float __original_forces[3];
	__original_forces[0] = original_forces.Fx;
	__original_forces[1] = original_forces.Fy;
	__original_forces[2] = original_forces.Fz;

	// Normalize the force sensor:
	float __normalized_forces;
	for (int i = 0; i < 3; i++)
	__normalized_forces += (__original_forces[i] * __original_forces[i]);
	__normalized_forces = sqrt(__normalized_forces);

	// Tool zero force
	float f_zero[3] = { 0, 0, __normalized_forces };

	// Calculate the expected force due to gravity and robot orientation:
	float __current_orientation[3];
	__current_orientation[0] = global_robot_pos.W;
	__current_orientation[1] = global_robot_pos.P;
	__current_orientation[2] = global_robot_pos.R;


	float __final_forces[3] = { 0, 0, 0 };
	float __rotation_matrix[4][4];
	float __transposed_matrix[4][4];
	getInverseMatrix2(__current_orientation, __rotation_matrix);
	//	transpose_matrix(__rotation_matrix, __transposed_matrix);

	//print_matrix(__transposed_matrix);

	for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	//__final_forces[i] += (__rotation_matrix[i][j] * f_zero[j]);
	__final_forces[i] += (__rotation_matrix[i][j] * f_zero[j]);
	}
	}

	calibrated_force->Fx = __final_forces[0];
	calibrated_force->Fy = __final_forces[1];
	calibrated_force->Fz = __final_forces[2];
	*/
}

// =============================================================== //
//					Force Calibration Dialog					   //
// =============================================================== //
float __position[1000][6];
float __force[1000][3];
int		total_step = 0;
int		cnt = 0;
void ForceCalibrationForm::display_force_data()
{
	// Display the original force data
	char str[32];
	sprintf(str, "%.3f", global_forces.Fx);
	label_fx->Text = gcnew String(str);
	sprintf(str, "%.3f", global_forces.Fy);
	label_fy->Text = gcnew String(str);
	sprintf(str, "%.3f", global_forces.Fz);
	label_fz->Text = gcnew String(str);
	sprintf(str, "%.3f", global_forces.Mx);
	label_mx->Text = gcnew String(str);
	sprintf(str, "%.3f", global_forces.My);
	label_my->Text = gcnew String(str);
	sprintf(str, "%.3f", global_forces.Mz);
	label_mz->Text = gcnew String(str);

	// Update force bar :
	int max_force = 100;
	int force_tmp;
	force_tmp = (global_forces.Fx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fx_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Fy / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fy_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Fz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fz_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Mx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	mx_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.My / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	my_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Mz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	mz_bar->Value = abs(force_tmp);



	// calculate gravity compensation:
	//calculate_gravity_compensation(global_forces, &calibrated_forces);

	// Display the original force data
	sprintf(str, "%.3f", calibrated_forces.Fx);
	calibrated_fx_tb->Text = gcnew String(str);
	sprintf(str, "%.3f", calibrated_forces.Fy);
	calibrated_fy_tb->Text = gcnew String(str);
	sprintf(str, "%.3f", calibrated_forces.Fz);
	calibrated_fz_tb->Text = gcnew String(str);


	// Update force bar :
	force_tmp = (calibrated_forces.Fx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	calibrated_fx_bar->Value = abs(force_tmp);
	force_tmp = (calibrated_forces.Fy / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	calibrated_fy_bar->Value = abs(force_tmp);
	force_tmp = (calibrated_forces.Fz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	calibrated_fz_bar->Value = abs(force_tmp);

	if (trajectory_isRunning) {
		tb_pos_x->Text = gcnew String(convert_doubleToString(temp_pos.X));
		tb_pos_y->Text = gcnew String(convert_doubleToString(temp_pos.Y));
		tb_pos_z->Text = gcnew String(convert_doubleToString(temp_pos.Z));
		tb_pos_w->Text = gcnew String(convert_doubleToString(temp_pos.W));
		tb_pos_p->Text = gcnew String(convert_doubleToString(temp_pos.P));
		tb_pos_r->Text = gcnew String(convert_doubleToString(temp_pos.R));
	}

}
void ForceCalibrationForm::robot_set_position()
{
	if (!robot.connected)
		return;
	// Get initial position:
	DataPos pos;
	pos = global_robot_pos;	// Get current robot setting
	pos.X = Convert::ToDouble(tb_pos_x->Text);
	pos.Y = Convert::ToDouble(tb_pos_y->Text);
	pos.Z = Convert::ToDouble(tb_pos_z->Text);
	pos.W = Convert::ToDouble(tb_pos_w->Text);
	pos.P = Convert::ToDouble(tb_pos_p->Text);
	pos.R = Convert::ToDouble(tb_pos_r->Text);
	robot.moveJ(pos, 100, CNT);
	console_print("___INFO___: Robot set position.");
}
void ForceCalibrationForm::robot_set_force()
{
	current_force.Fx = Convert::ToDouble(tb_force_x->Text);
	current_force.Fy = Convert::ToDouble(tb_force_y->Text);
	current_force.Fz = Convert::ToDouble(tb_force_z->Text);

	global_forces = current_force;
}
void ForceCalibrationForm::load_file()
{
	string filepath = "LOG_FORCE_12.csv";
	//string filepath = "force_rotate_2.csv";
	char str[200];
	string line;
	const char * delim = ",";
	int start_index = 0;
	int step = 0;
	ifstream file(filepath);

	if (file.is_open())
	{
		printf("\n___START___: Loading trajectory file from %s ... \n", filepath);
		while (getline(file, line)) {
			start_index++;
			if (start_index > 1) {
				int i = 0;
				char *token = strtok(const_cast<char*>(line.c_str()), delim);

				while (token != nullptr) {
					if (i < 3)
						__force[step][i] = stof(token);
					if (i > 6 && i < 13)
						__position[step][i - 7] = stof(token);
					token = strtok(nullptr, delim);
					i++;
				}
				printf("[%i]> Force: %.3f  %.3f  %.3f  Pos: %.3f  %.3f  %.3f \n", step,
					__force[step][0], __force[step][1], __force[step][2],
					__position[step][3], __position[step][4], __position[step][5]);
				step++;
			}
			total_step = step;
		}
		printf("___END_____: Loading successs. \n");
	}
	else
		printf("___ERROR___: Error when opening the .CSV file \n");

	file.close();
}
void ForceCalibrationForm::move_step_up()
{
	if (!robot.connected)
		return;

	DataPos pos;
	pos = global_robot_pos;	// Get current robot setting
	pos.X = __position[cnt][0];
	pos.Y = __position[cnt][1];
	pos.Z = __position[cnt][2];
	pos.W = __position[cnt][3];
	pos.P = __position[cnt][4];
	pos.R = __position[cnt][5];
	global_forces.Fx = __force[cnt][0];
	global_forces.Fy = __force[cnt][1];
	global_forces.Fz = __force[cnt][2];

	tb_pos_x->Text = gcnew String(convert_doubleToString(pos.X));
	tb_pos_y->Text = gcnew String(convert_doubleToString(pos.Y));
	tb_pos_z->Text = gcnew String(convert_doubleToString(pos.Z));
	tb_pos_w->Text = gcnew String(convert_doubleToString(pos.W));
	tb_pos_p->Text = gcnew String(convert_doubleToString(pos.P));
	tb_pos_r->Text = gcnew String(convert_doubleToString(pos.R));

	calculate_gravity_compensation(global_forces, &calibrated_forces);

	if (prog_state == 2) {
		robot.moveJ(pos, 100, CNT);
		printf(">> Move position : %.3f  %.3f  %.3f  %.3f  %.3f  %.3f \n", pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);
	}
	else {
		printf("__ERROR___: Roboguide cycle program is not running! \n");
	}
	if (cnt < total_step) cnt++;

}
void ForceCalibrationForm::move_step_down()
{
	if (!robot.connected)
		return;
	DataPos pos;
	pos = global_robot_pos;	// Get current robot setting
	pos.X = __position[cnt][0];
	pos.Y = __position[cnt][1];
	pos.Z = __position[cnt][2];
	pos.W = __position[cnt][3];
	pos.P = __position[cnt][4];
	pos.R = __position[cnt][5];
	global_forces.Fx = __force[cnt][0];
	global_forces.Fy = __force[cnt][1];
	global_forces.Fz = __force[cnt][2];

	tb_pos_x->Text = gcnew String(convert_doubleToString(pos.X));
	tb_pos_y->Text = gcnew String(convert_doubleToString(pos.Y));
	tb_pos_z->Text = gcnew String(convert_doubleToString(pos.Z));
	tb_pos_w->Text = gcnew String(convert_doubleToString(pos.W));
	tb_pos_p->Text = gcnew String(convert_doubleToString(pos.P));
	tb_pos_r->Text = gcnew String(convert_doubleToString(pos.R));

	calculate_gravity_compensation(global_forces, &calibrated_forces);

	if (prog_state == 2) {
		robot.moveJ(pos, 100, CNT);
		printf(">> Move position : %.3f  %.3f  %.3f  %.3f  %.3f  %.3f \n", pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);
	}
	else {
		printf("__ERROR___: Roboguide cycle program is not running! \n");
	}

	if (cnt >= 0)
		cnt--;
}


void play_trajectory_2(void *) 
{
	if (prog_state != 2) {
		printf("___ERROR___: Robotguide cycle program is not running \n");
		return;
	}
	int cnt = 0;
	temp_pos = global_robot_pos;	// Get current robot setting

	trajectory_isRunning = true;

	while (cnt < total_step) {
		temp_pos = global_robot_pos;	// Get current robot setting
		temp_pos.X = __position[cnt][0];
		temp_pos.Y = __position[cnt][1];
		temp_pos.Z = __position[cnt][2];
		temp_pos.W = __position[cnt][3];
		temp_pos.P = __position[cnt][4];
		temp_pos.R = __position[cnt][5];
		global_forces.Fx = __force[cnt][0];
		global_forces.Fy = __force[cnt][1];
		global_forces.Fz = __force[cnt][2] + 30;
		calculate_gravity_compensation(global_forces, &calibrated_forces);
		move_L(temp_pos, 100, CNT, 100);
		
		cnt++;
		Sleep(100);
	}

	trajectory_isRunning = false;
}

void stream_force(void *);
void ForceCalibrationForm::main_program() 
{
	_beginthread(play_trajectory_2, 0, NULL);
	_beginthread(stream_force, 0, NULL);
}


void stream_force(void *) 
{
	while (1) 
	{
		calculate_gravity_compensation(global_forces, &calibrated_forces);
	}

}
////////////////////////////////////////////////////////////////////////
//  Robot Polishing Project
//
//  Devices :
//  1. Fanuc Robot M20-ia/35M
//  2. 3DS Touch haptic controller
//  3. Compiled using VS2015, platform toolset = VS2010 (v100)
// 
//  Author : Yuda Risma Wahyudi
////////////////////////////////////////////////////////////////////////

#include "Fanuc.h"
#include "MainForm.h"
#include "HapticForm.h"
#include "Haptic.h"
#include "CoppeliaSim.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <fstream>
#include <string>

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;
using namespace std;

#define MAX_TRAJECRORY_NUM	20000

CoppeliaSim			sim;
PhantomOmniHaptic	haptic;
Fanuc				robot;

// Process flag :
bool programIsRunning	= false;
bool getpos_flag		= false;
bool getforce_flag		= false;
bool teachingmode_flag	= false;
bool haptic_connected	= false;
bool hapticRecordFlag	= false;
bool taskIsRunning		= false;
bool haptic_control_mode  = false;
bool play_trajectory_mode = false;
bool simulation_mode    = false;
bool inverse_workspace	= false;

int btnTeaching_state   = 0;
int control_mode		= 0;
int global_steps		= 0;

DeviceStateStruct	global_haptic_state;
DataPos				global_robot_pos;
DataPos				global_teaching_pos;
DataPos				global_haptic_pos;
DataPos				last_global_robot_pos;
DataForce			global_forces;

float				global_force[6];
float				scale_factor = 1.0;
int					haptic_button;
int					global_robot_speed = 20;

float calibrate_force[6] = { 81.671 + 9, 60.503 + 14, 988.618 + 38 + 27, 1.342, -5.438, -22.459 };

double	haptic_trajectory[MAX_TRAJECRORY_NUM][6];
double	fanuc_trajectory[MAX_TRAJECRORY_NUM][15];
double	haptic_pos[6];
float	robot_position[6];
short	robot_config[9];

// Global Function :
void load_config_file();
void thread_haptic_control_mode(void * data);
void thread_robotRecordPos_2(void * data);
void thread_robotRecordPos(void * data);


/////////////////////////////////////////////////////////////////
// System init
// Put all your initialization code here : 
/////////////////////////////////////////////////////////////////
void MainForm::system_init()
{
	// Read Config File :
	timer1->Interval = 50;
	timer1->Enabled = true;

	timer2->Interval = 50;
	timer2->Enabled = true;

	// Program Select :
	rb_simulator->Checked = true;
	simulation_mode = true;
	tb_ipaddress->Text = "127.0.0.21";

	// Load Config file:
	String ^ name = System::Configuration::ConfigurationManager::AppSettings["name"];
	
	System::Configuration::Configuration ^ config = System::Configuration::ConfigurationManager::OpenExeConfiguration(System::Configuration::ConfigurationUserLevel::None);
	config->AppSettings->Settings->Remove("name");
	config->AppSettings->Settings->Add("name", "yudarw21");
	config->Save(System::Configuration::ConfigurationSaveMode::Modified);
	System::Configuration::ConfigurationManager::RefreshSection("appSettigs");
}


// Load Configuration File:
void load_config_file()
{
	
}

// Save configuration File:
void save_config_file() {
	
}

///////////////////////////////////////////////////////////////////
// Timer 1 Tick : Routine for read the force and current position of the robot.
// The haptic controller mode is updated using timer 1
///////////////////////////////////////////////////////////////////
void MainForm::OnTimer1()
{
	if (check_inverse->Checked)
		inverse_workspace = true;
	else
		inverse_workspace = false;

	// Program Select :
	if (rb_real_robot->Checked) 
	{
		tb_ipaddress->Text = "192.168.0.100";
		simulation_mode = false;
	}
	else if (rb_simulator->Checked)
	{
		tb_ipaddress->Text = "127.0.0.21";
		simulation_mode = true;
	}

	if (getpos_flag == true)
	{
		robot.readCurrentPosition(COORD_WORLD, &global_robot_pos);
		display_position(global_robot_pos);
	}

	if (getforce_flag == true)
	{
		robot.readForce(global_force);
		display_force_data(global_force);
	}

	if (haptic_connected) {

		haptic.readState(&global_haptic_state);
		//haptic.setForce(global_force);
		global_haptic_pos.X = global_haptic_state.pos[0];
		global_haptic_pos.Y = global_haptic_state.pos[1];
		global_haptic_pos.Z = global_haptic_state.pos[2];
		global_haptic_pos.W = global_haptic_state.pos[3];
		global_haptic_pos.P = global_haptic_state.pos[4];
		global_haptic_pos.R = global_haptic_state.pos[5];

		// Haptic button state:
		haptic_button = global_haptic_state.button;
		
		display_haptic(global_haptic_state);
	}

	// control mode :
	if (rb_xyzwpr->Checked == true) control_mode = 0;
	if (rb_xyz->Checked == true)	control_mode = 1;
	if (rb_wpr->Checked == true)	control_mode = 2;
}


///////////////////////////////////////////////////////////////////
// Timer 2 Tick : Routine for read the force and current position of the robot.
// The haptic controller mode is updated using timer 1
///////////////////////////////////////////////////////////////////
void MainForm::on_timer_2()
{
	// Update position register in play trajectory mode:
	if (play_trajectory_mode == true)
	{
		haptic_control_mode = false;
		btnTeaching->Text = "Connect";

		if (robot.read_sdo(ROBOT_POS_SDO) == OFF)
		{
			robot.movePosition(global_teaching_pos);
			programIsRunning = false;
			global_steps++;
			Sleep(200);
		}
		else
		{
			programIsRunning = true;
		}

	}

	// Update the position on haptic_control_mode :
	if (haptic_control_mode == true)
	{
		play_trajectory_mode = false;

		if (haptic_button == 2) robot.movePosition(global_teaching_pos);

		// If the main program is not connect, stop the teaching mode
		if (robot.getProgramState() != 2) {
			haptic_control_mode = false;
			btnTeaching->Text = "Connect";
			MessageBox::Show("Fanuc Task program is stopped!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			btnTeaching_state = 0;
		}
		
	}
}



/////////////////////////////////////////////////////////////////////
////			        Update UI Function	     				 ////
/////////////////////////////////////////////////////////////////////
void MainForm::display_position(DataPos pos)
{
	char str[100];
	// Position :
	sprintf(str, "%.3f", pos.X);
	tbPosX->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.Y);
	tbPosY->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.Z);
	tbPosZ->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.W);
	tbPosRx->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.P);
	tbPosRy->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.R);
	tbPosRz->Text = gcnew String(str);

	// Configuration :
	label_uf->Text = "" + pos.UF;
	label_ut->Text = "" + pos.UT;

	char conf[7];
	if (pos.C1) conf[0] = 'F'; else conf[0] = 'N';
	if (pos.C2) conf[1] = 'L'; else conf[1] = 'R';
	if (pos.C3) conf[2] = 'U'; else conf[2] = 'D';
	if (pos.C4) conf[3] = 'T'; else conf[3] = 'B';
	
	sprintf(str, "%c %c %c %c %d %d %d", conf[0], conf[1], conf[2], conf[3], pos.C5, pos.C6, pos.C7);
	label_config->Text = gcnew String(str);
}

void MainForm::display_force_data(float force[6])
{
	global_forces.Fx = force[0] - calibrate_force[0];
	global_forces.Fy = force[1] - calibrate_force[1];
	global_forces.Fz = force[2] - calibrate_force[2];
	global_forces.Mx = force[3] - calibrate_force[3];
	global_forces.My = force[4] - calibrate_force[4];
	global_forces.Mz = force[5] - calibrate_force[5];

	//float calibrate_force[6] = { 0, 0, 0, 0, 0, 0 };
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
	int max_force = 200;
	int force_tmp;
	force_tmp = (global_forces.Fx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	force_x_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Fy / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	force_y_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Fz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	force_z_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Mx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	force_mx_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.My / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	force_my_bar->Value = abs(force_tmp);
	force_tmp = (global_forces.Mz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	force_mz_bar->Value = abs(force_tmp);
}

void MainForm::display_haptic(DeviceStateStruct pState)
{
	char str[32];
	sprintf(str, "%d", (int) pState.pos[0]);
	tbHapticX->Text = gcnew String(str);
	sprintf(str, "%d", (int) pState.pos[1]);
	tbHapticY->Text = gcnew String(str);
	sprintf(str, "%d", (int) pState.pos[2]);
	tbHapticZ->Text = gcnew String(str);
	sprintf(str, "%.2f", pState.pos[3]);
	tbHapticW->Text = gcnew String(str);
	sprintf(str, "%.2f", pState.pos[4]);
	tbHapticP->Text = gcnew String(str);
	sprintf(str, "%.2f", pState.pos[5]);
	tbHapticR->Text = gcnew String(str);
}


//////////////////////////////////////////////////////////
////		  Fanuc Robot Connection				  ////
//////////////////////////////////////////////////////////

int btnConnectState = 0;
void MainForm::robot_connect()
{
	if (btnConnectState == 0) {
		btnConnectState = 1;
		//btnConnect->Text = "Disconnect";

		int hr = robot.connect(tb_ipaddress->Text);

		if (!hr) {
			label_status->Text = "> Connection Failed!!!";
			return;
		}

		// Activate the trigger for timer 1
		getpos_flag		= true;
		getforce_flag	= true;

		labelRobotConnState->Text = "Connected";
		labelRobotConnState->BackColor = System::Drawing::Color::LimeGreen;
		label_status->Text = "Connected to " + tb_ipaddress->Text;
		tb_ipaddress->Enabled = false;

	}

	else
	{
		robot.disconnect();

		getpos_flag = false;
		getforce_flag = false;
		btnConnectState = 0;
		//btnConnect->Text = "Connect";
		labelRobotConnState->Text = "Disconnected";
		labelRobotConnState->BackColor = System::Drawing::Color::Red;
		label_status->Text = "Fanuc robot connection disconnected ";
		tb_ipaddress->Enabled = true;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Button Haptic Control mode
// Make the following devices are ready before connecting the haptic and 
// Fanuc robot:
// 1. Haptic is connected
// 2. Fanuc program task is running
////////////////////////////////////////////////////////////////////////////
void MainForm::start_teaching_mode()
{
	// Button Connect:
	if (btnTeaching_state == 0) {

		// Return if the fanuc task program is not running
		if (robot.getProgramState() != 2)
		{
			MessageBox::Show(
				"Fanuc program task isn't running. Please run the program!",
				"Connect to Haptic Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// Return if the haptic device is not connected
		if (!haptic_connected)
		{
			MessageBox::Show(
				"Haptic is not connected!",
				"Connect to Haptic Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			return;
		}

		btnTeaching_state = 1;
		//btnTeaching->Text = "Disconnect";
		label_haptic_control_state->Text = "Connected";
		label_haptic_control_state->BackColor = System::Drawing::Color::LimeGreen;

		// The Fanuc function is handled by timer 1
		// The robot postion is updated by thread function
		haptic_control_mode = true;
		if (check_inverse->Checked) inverse_workspace = true;
		else inverse_workspace = false;
		_beginthread(thread_haptic_control_mode, 0, NULL);
	}

	// Button Disconnect
	else
	{
		btnTeaching_state = 0;

		label_haptic_control_state->Text = "Disconnected";
		label_haptic_control_state->BackColor = System::Drawing::Color::Red;

		// Stop timer 1 :
		haptic_control_mode = false;
	}
}

// Move the robot to initial position
// The fanuc data position register is saved in PR[3]
void MainForm::robot_move_to_home()
{

	// initial pos 1 : 
	// {-210.065, 94.62, 127.414, 58.231, -41.662, -68.227}

	DataPos initial_pos = global_robot_pos;
	// move to initial pos:
	initial_pos.X = 927.916;
	initial_pos.Y = -5.642;
	initial_pos.Z = 72.480;
	initial_pos.W = 178.217;
	initial_pos.P = -0.638;
	initial_pos.R = 0;
	robot.movePosition(initial_pos, 30);
}

// Robot Set Joint Mode :
// Set robot position through joint mode
// Use PR[2] and DO[2]
void MainForm::robot_set_joint()
{
	DataPos joint_pos;
	joint_pos.J1 = Convert::ToDouble(tb_joint1->Text);
	joint_pos.J2 = Convert::ToDouble(tb_joint2->Text);
	joint_pos.J3 = Convert::ToDouble(tb_joint3->Text);
	joint_pos.J4 = Convert::ToDouble(tb_joint4->Text);
	joint_pos.J5 = Convert::ToDouble(tb_joint5->Text);
	joint_pos.J6 = Convert::ToDouble(tb_joint6->Text);

	robot.moveJoint(joint_pos);
}

void MainForm::robot_read_joint()
{
	DataPos joint_pos;
	char str[100];
	robot.readCurrentPosition(0, &joint_pos);
	sprintf(str, "%.2f", joint_pos.J1);
	tb_joint1->Text = gcnew String(str);
	sprintf(str, "%.2f", joint_pos.J2);
	tb_joint2->Text = gcnew String(str);
	sprintf(str, "%.2f", joint_pos.J3);
	tb_joint3->Text = gcnew String(str);
	sprintf(str, "%.2f", joint_pos.J4);
	tb_joint4->Text = gcnew String(str);
	sprintf(str, "%.2f", joint_pos.J5);
	tb_joint5->Text = gcnew String(str);
	sprintf(str, "%.2f", joint_pos.J6);
	tb_joint6->Text = gcnew String(str);
}


void MainForm::button_scale_up()
{
	scale_factor += 0.5;
	if (scale_factor > 4.0) {
		scale_factor = 4.0;
	}
	label_scale_factor->Text = "" + scale_factor;
}

void MainForm::button_scale_down()
{
	scale_factor -= 0.5;
	if (scale_factor < 0.5) {
		scale_factor = 0.5;
	}
	label_scale_factor->Text = "" + scale_factor;
}


//////////////////////////////////////////////////////////////
////			       Haptic Connection                  ////
//////////////////////////////////////////////////////////////
int btnHapticConnectState = 0;
void MainForm::haptic_connect()
{
	if (btnHapticConnectState == 0)
	{
		if (haptic.init() == -1) return;
		haptic_connected = true;
		btnHapticConnectState = 1;
		//btnHapticConnect->Text = "Disconnect";
		label_haptic_conenction->Text = "Connected";
		label_haptic_conenction->BackColor = System::Drawing::Color::LimeGreen;
	}
	else
	{
		btnHapticConnectState = 0;
		//btnHapticConnect->Text = "Connect";
		label_haptic_conenction->Text = "Disconnected";
		label_haptic_conenction->BackColor = System::Drawing::Color::Red;
		haptic_connected = false;
		haptic.close();
	}

}

// Thread for teaching mode -> Controlling the arm robot using haptic: 
void thread_haptic_control_mode(void * data)
{
	// optional configuration:
	bool invers = false;
	int  invers_state = -1;

	DataPos initial_pos;
	DataPos haptic_inital_pos;

	float delta[6]	= { 0, 0, 0, 0, 0, 0 };
	float pose[6]	= { 0, 0, 0, 0, 0, 0 };
	float newPos[6] = { 0, 0, 0, 0, 0, 0 };

	// Set current position as initial pos:
	initial_pos			= global_robot_pos;
	haptic_inital_pos	= global_haptic_pos;
	global_teaching_pos = global_robot_pos;
	
//	getpos_flag = false;

	while (haptic_control_mode == true)
	{	
		// Roboguide simulation mode:
		if (simulation_mode == true)
		{
			global_teaching_pos.X = initial_pos.X + ((global_haptic_pos.X - haptic_inital_pos.X) * scale_factor) * 1;
			global_teaching_pos.Y = initial_pos.Y + ((global_haptic_pos.Y - haptic_inital_pos.Y) * scale_factor) * 1;
			global_teaching_pos.Z = initial_pos.Z + ((global_haptic_pos.Z - haptic_inital_pos.Z) * scale_factor) * 1;
			global_teaching_pos.W = global_haptic_pos.W * -1;
			global_teaching_pos.P = global_haptic_pos.P * -1;
			global_teaching_pos.R = global_haptic_pos.R * -1;
		
		}
		
		// Robot Real Mode:
		else 
		{
			if (control_mode == 0) {
				
				if (inverse_workspace) {
					//cout << "Control mode 0" << endl;
					global_teaching_pos.X = initial_pos.X + ((global_haptic_pos.X - haptic_inital_pos.X) * scale_factor) * invers_state;
					global_teaching_pos.Y = initial_pos.Y + ((global_haptic_pos.Y - haptic_inital_pos.Y) * scale_factor) * invers_state;
					global_teaching_pos.Z = initial_pos.Z + ((global_haptic_pos.Z - haptic_inital_pos.Z) * scale_factor) * 1;
					global_teaching_pos.W = global_haptic_pos.P * 1;
					global_teaching_pos.P = global_haptic_pos.W * 1;
					global_teaching_pos.R = (-106 + (-global_haptic_pos.R)) * 1;
				}
				else
				{
					global_teaching_pos.X = initial_pos.X + ((global_haptic_pos.X - haptic_inital_pos.X) * scale_factor) * 1;
					global_teaching_pos.Y = initial_pos.Y + ((global_haptic_pos.Y - haptic_inital_pos.Y) * scale_factor) * 1;
					global_teaching_pos.Z = initial_pos.Z + ((global_haptic_pos.Z - haptic_inital_pos.Z) * scale_factor) * 1;
					global_teaching_pos.W = global_haptic_pos.P * -1;
					global_teaching_pos.P = global_haptic_pos.W * -1;
					global_teaching_pos.R = (-106 + (-global_haptic_pos.R)) * 1;
				}
			}

			else if (control_mode == 1)
			{
				//cout << "Control mode 1" << endl;
				global_teaching_pos.X = initial_pos.X + ((global_haptic_pos.X - haptic_inital_pos.X) * scale_factor) * invers_state;
				global_teaching_pos.Y = initial_pos.Y + ((global_haptic_pos.Y - haptic_inital_pos.Y) * scale_factor) * invers_state;
				global_teaching_pos.Z = initial_pos.Z + ((global_haptic_pos.Z - haptic_inital_pos.Z) * scale_factor) * 1;
			}

			else if (control_mode == 2)
			{
				//cout << "Control mode 2" << endl;
				global_teaching_pos.W = global_haptic_pos.P * 1;
				global_teaching_pos.P = global_haptic_pos.W * 1;
				global_teaching_pos.R = (-106 + (-global_haptic_pos.R)) * 1;
			}
		}

		Sleep(10);
	}

	//getpos_flag = true;
}





// ===================================================== //
//					Coppelia Sim						 //
// ===================================================== //
void MainForm::coppeliasim_connect()
{
	int err = sim.connect(19999);
	printf("%d", err);
}

void thread_robotRecordPos(void * data);

int btnState = 0;
bool recording_flag = false;

void MainForm::robot_record()
{
	if (btnState == 0)
	{
		btnState = 1;
		button7->Text = "Stop";
		recording_flag = true;
		_beginthread(thread_robotRecordPos_2, 0, NULL);
	}
	else {
		btnState = 0;
		button7->Text = "Record";
		recording_flag = false;
	}
}


///////////////////////////////////////////////////////////////////////
////					Recording Procedure					       ////
///////////////////////////////////////////////////////////////////////

// Thread for recording mode
void thread_robotRecordPos(void * data)
{
	char str[300];
	float pos[6];
	short config[9];
	ofstream file;
	file.open("fanuc_trajectory_sim.txt");
	while (recording_flag == true) {
		sprintf(str, "%.3f %.3f %.3f %.3f %.3f %.3f %d %d %d %d %d %d %d %d %d",
			global_robot_pos.X, global_robot_pos.Y, global_robot_pos.Z, global_robot_pos.W, global_robot_pos.P, global_robot_pos.R,
			global_robot_pos.C1, global_robot_pos.C2, global_robot_pos.C3, global_robot_pos.C4, global_robot_pos.C5, global_robot_pos.C6, global_robot_pos.C7, global_robot_pos.UF, global_robot_pos.UT
		);
		/*
		sprintf(str, "%.3f %.3f %.3f %.3f %.3f %.3f",
			robot_position[0], robot_position[1], robot_position[2], robot_position[3], robot_position[4], robot_position[5]
		);
		*/
		file << str << endl;
		Sleep(200);
	}
	file.close();
}

// Thread recording method 2 :
void thread_robotRecordPos_2(void * data)
{
	char str[300];
	float pos[6];
	short config[9];
	ofstream file;
	file.open("simulation_polishing_trajectory.txt");
	int step = 0;
	while (recording_flag == true) {
		
		// Record the pose if button 1 is pressed :
		if (haptic_button == 1)
		{
			sprintf(str, "%.3f %.3f %.3f %.3f %.3f %.3f %d %d %d %d %d %d %d %d %d",
				global_robot_pos.X, global_robot_pos.Y, global_robot_pos.Z, global_robot_pos.W, global_robot_pos.P, global_robot_pos.R,
				global_robot_pos.C1, global_robot_pos.C2, global_robot_pos.C3, global_robot_pos.C4, global_robot_pos.C5, global_robot_pos.C6, global_robot_pos.C7, global_robot_pos.UF, global_robot_pos.UT
			);
			cout << "Position " << step << " recorded : " << str << endl;
			file << str << endl;
			step++;
			Sleep(300);
		}

		sprintf(str, "%.3f %.3f %.3f %.3f %.3f %.3f %d %d %d %d %d %d %d %d %d",
			global_robot_pos.X, global_robot_pos.Y, global_robot_pos.Z, global_robot_pos.W, global_robot_pos.P, global_robot_pos.R,
			global_robot_pos.C1, global_robot_pos.C2, global_robot_pos.C3, global_robot_pos.C4, global_robot_pos.C5, global_robot_pos.C6, global_robot_pos.C7, global_robot_pos.UF, global_robot_pos.UT
		);
		cout << "Position " << step << " recorded : " << str << endl;
		file << str << endl;
		step++;
		Sleep(300);
		
	}
	file.close();
}

void thread_play_motion(void * data)
{
	
	//ifstream file("fanuc_trajectory_sim_2.txt");
	ifstream file("fanuc_trajectory_paper_2.txt");

	string line = "";
	string pos_str;
	int step = 0;
	const char* delim = " ";
	if (file.is_open())
	{
		printf("Open trajectory file : fanuc_trajectory_sim_2.txt \n");
		while (getline(file, line))
		{
			int i = 0;
			char *token = strtok(const_cast<char*>(line.c_str()), delim);

			while (token != nullptr)
			{
				fanuc_trajectory[step][i] = stof(token);
				token = strtok(nullptr, delim);
				i++;
			}

			step++;
		}

	}
	file.close();
	long t_start = GetTickCount64();
	float pos[6]; short config[9];

	printf("Read trajectory success \n");
	printf("Start play the trajectory \n");

	while (1) {
		for (int i = 0; i < step; i++)
		{
			global_teaching_pos.X = fanuc_trajectory[i][0];
			global_teaching_pos.Y = fanuc_trajectory[i][1];
			global_teaching_pos.Z = fanuc_trajectory[i][2];
			global_teaching_pos.W = fanuc_trajectory[i][3];
			global_teaching_pos.P = fanuc_trajectory[i][4];
			global_teaching_pos.R = fanuc_trajectory[i][5];

			global_teaching_pos.C1 = fanuc_trajectory[i][6];
			global_teaching_pos.C2 = fanuc_trajectory[i][7];
			global_teaching_pos.C3 = fanuc_trajectory[i][8];
			global_teaching_pos.C4 = fanuc_trajectory[i][9];
			global_teaching_pos.C5 = fanuc_trajectory[i][10];
			global_teaching_pos.C6 = fanuc_trajectory[i][11];
			global_teaching_pos.C7 = fanuc_trajectory[i][12];
			global_teaching_pos.UF = fanuc_trajectory[i][13];
			global_teaching_pos.UT = fanuc_trajectory[i][14];

			//robot.moveWaitPosition(global_teaching_pos);
			while (programIsRunning);
			printf(".\n");
			Sleep(300);
		}
	}

	printf("Finished! \n");
	play_trajectory_mode = false;
}

void MainForm::robot_play_motion()
{
	play_trajectory_mode = true;
	/*
	for (int i = 0; i < 5; i++)
	{
		thread_play_motion();
	}
	*/
	
	_beginthread(thread_play_motion, 0, NULL);
}






void HapticForm::haptic_begin()
{
	if (haptic.init() != -1)
	{
		labelConnection->Text = "Connected";
		labelConnection->ForeColor = System::Drawing::Color::Green;
	}
	else
	{
		labelConnection->Text = "Connection Failed!";
		labelConnection->ForeColor = System::Drawing::Color::Red;
	}

}
void HapticForm::read_haptic_position()
{
}

void HapticForm::read_haptic_force() 
{
	double force[3];
	haptic.readForce(force);

}

void HapticForm::HapticOnTimer1()
{
	char str[32];
	double pos[6];
	double transform[16];
	double force[3];
	double velocity[3];

	//haptic.readTransform(transform);
	haptic.readState(pos, force, transform, velocity);

	for (int i = 0; i < 6; i++) {
		haptic_pos[i] = pos[i];
	}
	
	// Transform :
	sprintf(str, "%.3f", transform[0]);
	t11->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[1]);
	t12->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[2]);
	t13->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[3]);
	t14->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[4]);
	t21->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[5]);
	t22->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[6] );
	t23->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[7]);
	t24->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[8]);
	t31->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[9]);
	t32->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[10] );
	t33->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[11]);
	t34->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[12]);
	t41->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[13]);
	t42->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[14]);
	t43->Text = gcnew String(str);
	sprintf(str, "%.3f", transform[15]);
	t44->Text = gcnew String(str);

	sprintf(str, "%.1f", pos[0]);
	textbox_posX->Text = gcnew String(str);
	sprintf(str, "%.1f", pos[1]);
	textbox_posY->Text = gcnew String(str);
	sprintf(str, "%.1f", pos[2]);
	textbox_posZ->Text = gcnew String(str);
	sprintf(str, "%.2f", pos[3]);
	textbox_posRx->Text = gcnew String(str);
	sprintf(str, "%.2f", pos[4]);
	textbox_posRy->Text = gcnew String(str);
	sprintf(str, "%.2f", pos[5]);
	textbox_posRz->Text = gcnew String(str);

	// Forces :
	sprintf(str, "%.2f", force[0]);
	textbox_forceX->Text = gcnew String(str);
	sprintf(str, "%.2f", force[1]);
	textbox_forceY->Text = gcnew String(str);
	sprintf(str, "%.2f", force[2]);
	textbox_forceZ->Text = gcnew String(str);

	// Velocity :
	sprintf(str, "%.2f", velocity[0]);
	tbV1->Text = gcnew String(str);
	sprintf(str, "%.2f", velocity[1]);
	tbV2->Text = gcnew String(str);
	sprintf(str, "%.2f", velocity[2]);
	tbV3->Text = gcnew String(str);
}

void MainForm::robot_test_move()
{
	float force[6];
	float pos[6];
	short config[9];

	/*
	pos[0] = Convert::ToDouble(tbPosX->Text);
	pos[1] = Convert::ToDouble(tbPosY->Text);
	pos[2] = Convert::ToDouble(tbPosZ->Text);
	pos[3] = Convert::ToDouble(tbPosRx->Text);
	pos[4] = Convert::ToDouble(tbPosRy->Text);
	pos[5] = Convert::ToDouble(tbPosRz->Text);

	DataPos joint;
	joint.J1 = 0;
	joint.J2 = 0;
	joint.J3 = 0;
	joint.J4 = 0;
	joint.J5 = -90;
	joint.J6 = 0;

	//robot.moveJoint(joint);
	
	joint.J5 = -80; joint.J6 = 90;
	//robot.moveJoint(joint);

	joint.J5 = -80; joint.J6 = 90;
	//robot.moveJoint(joint);

	//robot.setPosReg(1, pos, robot_config);
	DataPos newPos;
	short current_config[9];
	robot.getRobotConfig(current_config);

	//float goal_pos[6] = { 1010, 0, 500, 180, 0, 0 };
	//robot.setDataPosition(&newPos, goal_pos, current_config);
	//robot.movePosition(newPos);
	
	robot.readCurrentPosition(1, &newPos);
	float pose[6], pose1[6];
	float delta[6] = { 0, 0, 0, 0, 0, 0 };
	pose[0] = newPos.X;
	pose[1] = newPos.Y;
	pose[2] = newPos.Z;
	pose[3] = newPos.W;
	pose[4] = newPos.P;
	pose[5] = newPos.R;

	delta[0] = -100;
	delta[5] = 90;
	robot.Homogenious(pose, pose1, delta);
	robot.setDataPosition(&newPos, pose1, current_config);
	robot.movePosition(newPos);
	*/

	DataPos point1;
	point1.X = 927.916;
	point1.Y = -5.642;
	point1.Z = 72.480;
	point1.W = 178.217;
	point1.P = 0;
	point1.R = 0;

	DataPos point2;
	point2.X = 927.916;
	point2.Y = -50.642;
	point2.Z = 72.480;
	point2.W = 178.217;
	point2.P = 0;
	point2.R = 0;

	DataPos point3;
	point3.X = 927.916;
	point3.Y = 50.642;
	point3.Z = 72.480;
	point3.W = 178.217;
	point3.P = 0;
	point3.R = 0;

	//robot.movePosition(point1);
	//Sleep(1000);
	//robot.movePosition(point2);
	//Sleep(1000);
	//robot.movePosition(point3);
	//Sleep(1000);
	robot.set_rdo(4, ON);
	Sleep(100);
	robot.set_rdo(4, OFF);

	long val[100];
	robot.readNumRegister(val);
	robot.setNumRegister(88, 44);
}

void robot_read_position(void * pUserData)
{
	DataPos *pos = (DataPos *) pUserData;
	while (1) {
		robot.readCurrentPosition(1, pos);
		printf("%.2f \n", pos->X);
		Sleep(1000);
	}
}
void MainForm::robot_readpos()
{
	float force[6];
	float pos[6];
	short config[9];
	
	int state = robot.getProgramState();
	printf("Program state: %d", state);

	robot.setNumRegister(2, 40);
	//_DataPos currentpos;
	//robot.readCurrentPos(robot_position, robot_config);
	//robot.setPosReg(1, robot_position, robot_config);
	//display_position(robot_position);
	//robot.readRegPos(1, robot_position, robot_config);
	//printf("Current Pos : %.2f \n", robot_position[0]);
}

void thread_hapticRecord(void * pUserData);


void HapticForm::haptic_start_record()
{
	hapticRecordFlag = true;
	_beginthread(thread_hapticRecord, 0, NULL);
}

void HapticForm::haptic_stop_record()
{
	hapticRecordFlag = false;
}

void thread_hapticRecord(void * pUserData) 
{
	int sample_delay = 100;
	int step = 0;
	while (hapticRecordFlag)
	{
		haptic_trajectory[step][0] = haptic_pos[0];
		haptic_trajectory[step][1] = haptic_pos[1];
		haptic_trajectory[step][2] = haptic_pos[2];
		haptic_trajectory[step][3] = haptic_pos[3];
		haptic_trajectory[step][4] = haptic_pos[4];
		haptic_trajectory[step][5] = haptic_pos[5];
		step++;
		Sleep(sample_delay);
	}

	ofstream record_file;
	record_file.open("haptic_trajectory.txt");
	char temp[200];
	for (int i = 0; i < step; i++)
	{
		sprintf(temp, "%3.3f %.3f %.3f %.3f %.3f %.3f", 
			haptic_trajectory[i][0],
			haptic_trajectory[i][1],
			haptic_trajectory[i][2],
			haptic_trajectory[i][3],
			haptic_trajectory[i][4],
			haptic_trajectory[i][5]);

		record_file << temp << endl;
	}
	record_file.close();
}

bool force_record_flag = false;
void thread_record_force(void * data)
{
	ofstream file;
	file.open("force_data_record.txt");
	char temp[200];
	float current_force[6];

	// Reset Force:
	calibrate_force[0] = global_force[0];
	calibrate_force[1] = global_force[1];
	calibrate_force[2] = global_force[2];
	calibrate_force[3] = global_force[3];
	calibrate_force[4] = global_force[4];
	calibrate_force[5] = global_force[5];

	while (force_record_flag)
	{
		for (int i = 0; i < 6; i++)
			current_force[i] = global_force[i] - calibrate_force[i];

		sprintf(temp, "%.2f %.2f %.2f %.2f %.2f %.2f", current_force[0], current_force[1], current_force[2], current_force[3], current_force[4], current_force[5]);
		file << temp << endl;
		Sleep(100);
	}

}

void MainForm::record_force()
{
	force_record_flag = true;
	_beginthread(thread_record_force, 0, NULL);
}

void MainForm::record_force_stop()
{
	force_record_flag = false;
}
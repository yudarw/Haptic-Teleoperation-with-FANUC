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

#include "main.h"
#include "MainFormDlg.h"
#include "RobotControllerDlg.h"
#include "ForceCalibrationForm.h"
#include "CoppeliaForm.h"
#include "coppeliasim.h"
#include <stdlib.h>
#include <stdio.h>
#include "HomogeneousTransform.h"

#include "MyForm.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Configuration;
using namespace HapticPolishingDemo; 
using namespace std;
using namespace msclr::interop;

OpenHaptic		haptic;

// -- Trajectory variables -- 


// -- Delay for haptic jog mode -- 
int	timer2_interval		= 10;
int	delay_jog_mode		= 10;

// -- Main OnTimer moving variable --
int		wait_move_delay = 300;
int		prog_state;
bool	robotIsMoving = false;
double	scale_factor;
bool	jog_isRunning;


DeviceStateStruct	global_haptic_state;
DataForce			real_forces;
hduVector3Dd		current_haptic_pos;
hduVector3Dd		haptic_init_pos;


bool flag_show_image = false;

// Trigger flag for timer 1:
bool flag_getpos = false;
bool flag_getforce = false;

double		Gain, Magnitude;
int			effect_type;
int			robot_override;

int			haptic_button;

int			index;

string	currentDateTime;

// --- Prototype Functions ---
// //////////////////////////////////////////////////////////////////
void calibrate_force(DataForce inForce, DataForce * outForce);
void load_force_offset();
void thread_haptic_jog_mode(void * data); 
void Main_Program(void * data);

//////////////////////////////////////////////////////////////////////
////						App Config							  ////
//////////////////////////////////////////////////////////////////////
double config_getDouble(String ^ key)
{
	String ^ str = System::Configuration::ConfigurationManager::AppSettings[key];
	return Convert::ToDouble(str);
}
int config_getInt(String ^ key)
{
	String ^ str = System::Configuration::ConfigurationManager::AppSettings[key];
	return Convert::ToInt16(str);
}
String ^ config_getString(String ^ key)
{
	return  System::Configuration::ConfigurationManager::AppSettings[key];
}

// Load deafault configuration File:
void load_config_file()
{
	haptic_init_pos[0] = config_getDouble("haptic_initpos_x");
	haptic_init_pos[1] = config_getDouble("haptic_initpos_y");
	haptic_init_pos[2] = config_getDouble("haptic_initpos_z");
	scale_factor = config_getDouble("scale_factor");
}
// Save file config
void save_config(String ^ key, String ^ value)
{
	System::Configuration::Configuration ^ config = System::Configuration::ConfigurationManager::OpenExeConfiguration(System::Configuration::ConfigurationUserLevel::None);
	config->AppSettings->Settings->Remove(key);
	config->AppSettings->Settings->Add(key, value);
	config->Save(System::Configuration::ConfigurationSaveMode::Modified);
	System::Configuration::ConfigurationManager::RefreshSection("appSettigs");
}
void save_robot_initPos(DataPos initPos)
{
	System::String ^ str;
	str = Convert::ToString(initPos.X); save_config("robot_initpos_x", str);
	str = Convert::ToString(initPos.Y); save_config("robot_initpos_y", str);
	str = Convert::ToString(initPos.Z); save_config("robot_initpos_z", str);
	str = Convert::ToString(initPos.W); save_config("robot_initpos_w", str);
	str = Convert::ToString(initPos.P); save_config("robot_initpos_p", str);
	str = Convert::ToString(initPos.R); save_config("robot_initpos_r", str);
}
void load_robot_initPos(DataPos * initPos)
{
	String ^ temp;
	temp = System::Configuration::ConfigurationManager::AppSettings["robot_initpos_x"];
	initPos->X = Convert::ToDouble(temp);
	temp = System::Configuration::ConfigurationManager::AppSettings["robot_initpos_y"];
	initPos->Y = Convert::ToDouble(temp);
	temp = System::Configuration::ConfigurationManager::AppSettings["robot_initpos_z"];
	initPos->Z = Convert::ToDouble(temp);
	temp = System::Configuration::ConfigurationManager::AppSettings["robot_initpos_w"];
	initPos->W = Convert::ToDouble(temp);
	temp = System::Configuration::ConfigurationManager::AppSettings["robot_initpos_p"];
	initPos->P = Convert::ToDouble(temp);
	temp = System::Configuration::ConfigurationManager::AppSettings["robot_initpos_r"];
	initPos->R = Convert::ToDouble(temp);
}


//  --- Load and Save .CSV trajectory file ---           
//////////////////////////////////////////////////////////////////////
void save_trajectory(string filepath, float p[][12])
{
	ofstream file(filepath);

	char str[200];
	int step = 0;

	if (file.is_open())
	{
		cout << currentDateTime << "___START___: Loading trejactory file from " << filepath << endl;
		file << "X,Y,Z,W,P,R,C1,C3,C4,C5,C6,C7 " << endl;
		for (int i = 0; i < index; i++) {
			sprintf(str, "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%d,%d,%d,%d,%d,%d",
				p[i][0], p[i][1], p[i][2], p[i][3], p[i][4], p[i][5], 
				(int)p[i][6], (int)p[i][7], (int)p[i][8], (int)p[i][9], (int)p[i][10], (int)p[i][11]);
			file << str << endl;
		}
		file.close();
	}
	else 
	{
		cout << currentDateTime << "___ERROR___: Error when opening the CSV file \n" << endl;
	}

	file.close();
}
void load_trajectory(string filepath, float point[][12], int * total_point)
{
	char str[200];
	string line;
	const char * delim = ",";
	int start_index = 0;
	int step = 0;

	ifstream file(filepath);
	
	if (file.is_open())
	{
		cout << currentDateTime << "___START___: Loading trejactory file from " << filepath << endl;
		while (getline(file, line)) {
			start_index++;
			if (start_index > 1) {
				int i = 0;
				cout << "Step " << step << ": " << line << endl;
				char *token = strtok(const_cast<char*>(line.c_str()), delim);
				while (token != nullptr) {
					point[step][i] = stof(token);
					token = strtok(nullptr, delim);
					i++;
				}
				step++;
			}
			*total_point = step;
		}
		cout << currentDateTime << " ___END____: Load success. " << endl;
	}
	else
		cout << currentDateTime << "___ERROR___: Error when opening the CSV file \n" << endl;
	
	file.close();
}

void MainFormDlg::save_system_trajectory()
{
	char str[200];

	saveFileDialog1->Filter = ".csv files (*.csv)|*.csv";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String ^ Filepath = saveFileDialog1->FileName;
		std::string path = marshal_as<std::string>(Filepath);
		save_trajectory(path, tp_points);
	}
}


bool isPointRecording = false;


void record_robot_points(void *) {

	while (isPointRecording) {
		record_current_point();
		Sleep(30);
	}
}

void MainFormDlg::record_point()
{
	isPointRecording = true;
	_beginthread(record_robot_points, 0, NULL);
}
void MainFormDlg::stop_record_point() {
	isPointRecording = false;
}


// -- End of load and save .CSV trajectory file function --           
//////////////////////////////////////////////////////////////////////

// Convert map to Hbitmap to update image in the picture box:
/*
Bitmap ^ MatToHbitmap(cv::Mat inputImg) {
	cv::Mat dst;
	cv::cvtColor(inputImg, dst, CV_BGR2BGRA);
	HBITMAP hBit = CreateBitmap(dst.cols, dst.rows, 1, 32, dst.data);
	Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);
	return bmp;
}
*/


void MainFormDlg::show_video_preview()
{
	flag_show_image = true;
	//_beginthread(cv_load_video, 0, NULL);
}

// =============================================================== //
//						Main Form Dialog						   //
// =============================================================== //

char * convert_doubleToString(float data) 
{
	char str[200];
	sprintf(str, "%.3f", data);
	return str;
}
// Initialize all components :
void MainFormDlg::on_init()
{
	timer1->Enabled = true;
	console_print("Timer 1 Enabled.");

	ip_address_box->Text = config_getString("ip_address");
	ip_address_box->Items->Add("192.168.0.100");
	ip_address_box->Items->Add("127.0.0.21");
	
	panel_jog->Visible = false;

	// Update UI parameter settings:
	load_config_file();
	tb_haptic_initX->Text = "" + haptic_init_pos[0];
	tb_haptic_initY->Text = "" + haptic_init_pos[1];
	tb_haptic_initZ->Text = "" + haptic_init_pos[2];
	char str[32];

	DataPos initPos;
	load_robot_initPos(&initPos);

	tb_robot_initX->Text = gcnew String(convert_doubleToString(initPos.X));
	tb_robot_initY->Text = gcnew String(convert_doubleToString(initPos.Y));
	tb_robot_initZ->Text = gcnew String(convert_doubleToString(initPos.Z));
	tb_robot_initW->Text = gcnew String(convert_doubleToString(initPos.W));
	tb_robot_initP->Text = gcnew String(convert_doubleToString(initPos.P));
	tb_robot_initR->Text = gcnew String(convert_doubleToString(initPos.R));
	label_scale_factor->Text = gcnew String(convert_doubleToString(scale_factor));
	
	// Load Force sensor calibration data:
	load_force_offset();
}

// Main Timer 1 for Update the UI and FANUC Data Table           
void MainFormDlg::on_timer()
{
	DateTime now = DateTime::Now;
	String^ timestamp = now.ToString("yyyy-MM-dd  HH:mm:ss");
	label_datetime->Text = timestamp;
	String^ text_time = now.ToString("yyyy/MM/dd HH:mm:ss ");
	currentDateTime = marshal_as<std::string>(text_time);

	// --------------------------------------
	// 1. Haptic state and position update:
	// --------------------------------------	
	// Update the haptic position when device is connected
	if (flag_haptic_connected) {
		//haptic.inverse_frame = false;
		haptic.read_state(&global_haptic_state);
		global_haptic_pos.X = global_haptic_state.position[0];
		global_haptic_pos.Y = global_haptic_state.position[1];
		global_haptic_pos.Z = global_haptic_state.position[2];
		global_haptic_pos.W = global_haptic_state.orientation[0];
		global_haptic_pos.P = global_haptic_state.orientation[1];
		global_haptic_pos.R = global_haptic_state.orientation[2];

		haptic_display_pos(global_haptic_pos);

		// For updating haptic force position:
		current_haptic_pos[0] = global_haptic_pos.X;
		current_haptic_pos[1] = global_haptic_pos.Y;
		current_haptic_pos[2] = global_haptic_pos.Z;
		
		// Haptic button state:
		haptic_button = global_haptic_state.button;
	}

	// --------------------------------------
	// 2. FANUC DataTable Update:
	// --------------------------------------
	
	if (robot.connected)
	{
		robot_updateData();
		calibrate_force(current_force, &global_forces);

		// Update UI info:
		display_position(robot.current_pos);
		display_force(global_forces);
		//display_force(calibrated_forces);
		display_progState(prog_state);

		// Moving Status:
		if (robot.isMoving) {
			panel_move->BackColor = System::Drawing::Color::Lime;
			robotIsMoving = true;
		}
		else {
			panel_move->BackColor = System::Drawing::Color::Red;
			robotIsMoving = false;
		}
	}
}
// End Of Timer 1 Update
////////////////////////////////////////////////////////////////////

// Display FANUC program status: 
void MainFormDlg::display_progState(int state)
{
	// Program State:
	if (state == 0) {
		panel_prog->BackColor = System::Drawing::Color::Red;
	}
	else if (state == 1) {
		panel_prog->BackColor = System::Drawing::Color::Gold;
	}
	else if (state == 2) {
		panel_prog->BackColor = System::Drawing::Color::Lime;
	}
}

// Display update haptic position:
void MainFormDlg::haptic_display_pos(DataPos pos)
{
	char str[32];
	tb_hapticX->Text = gcnew String(convert_doubleToString((int)pos.X));
	tb_hapticY->Text = gcnew String(convert_doubleToString((int)pos.Y));
	tb_hapticZ->Text = gcnew String(convert_doubleToString((int)pos.Z));
	tb_hapticW->Text = gcnew String(convert_doubleToString(pos.W));
	tb_hapticP->Text = gcnew String(convert_doubleToString(pos.P));
	tb_hapticR->Text = gcnew String(convert_doubleToString(pos.R));
}

// Display FANUC Robot Position:
void MainFormDlg::display_position(DataPos pos)
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
	tbPosW->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.P);
	tbPosP->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.R);
	tbPosR->Text = gcnew String(str);

	char conf[7];
	if (pos.C1) conf[0] = 'F'; else conf[0] = 'N';
	if (pos.C2) conf[1] = 'L'; else conf[1] = 'R';
	if (pos.C3) conf[2] = 'U'; else conf[2] = 'D';
	if (pos.C4) conf[3] = 'T'; else conf[3] = 'B';
	sprintf(str, "%c%c%c%c %d %d %d", conf[0], conf[1], conf[2], conf[3], pos.C5, pos.C6, pos.C7);
	label_config->Text = gcnew String(str);
}

// Display Force Sensor Value:
void MainFormDlg::display_force(DataForce force)
{
	char str[32];
	sprintf(str, "%.3f", force.Fx);
	label_fx->Text = gcnew String(str);
	sprintf(str, "%.3f", force.Fy);
	label_fy->Text = gcnew String(str);
	sprintf(str, "%.3f", force.Fz);
	label_fz->Text = gcnew String(str);
	sprintf(str, "%.3f", force.Mx);
	label_mx->Text = gcnew String(str);
	sprintf(str, "%.3f", force.My);
	label_my->Text = gcnew String(str);
	sprintf(str, "%.3f", force.Mz);
	label_mz->Text = gcnew String(str);

	// Update force bar :
	int max_force = 100;
	int force_tmp;
	force_tmp = (force.Fx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fx_bar->Value = abs(force_tmp);
	force_tmp = (force.Fy / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fy_bar->Value = abs(force_tmp);
	force_tmp = (force.Fz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	fz_bar->Value = abs(force_tmp);
	force_tmp = (force.Mx / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	mx_bar->Value = abs(force_tmp);
	force_tmp = (force.My / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	my_bar->Value = abs(force_tmp);
	force_tmp = (force.Mz / max_force) * 100;
	if (abs(force_tmp) > 100) force_tmp = 100;
	mz_bar->Value = abs(force_tmp);
}
// End of Windows Form Update function
////////////////////////////////////////////////////////////////////


// =============================================================== //
//					Button Handle Functions						   //
// =============================================================== //

// Button haptic connect:
void MainFormDlg::haptic_connect()
{
	if (flag_haptic_connected == false)
	{
		// Connect to haptic device:
		if (haptic.init() == -1) {
			MessageBox::Show("Haptic device not found","Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			console_print_error("Haptic device not found.");
			return;
		}
		console_print("Haptic device connection success");
		btn_haptic_connect->Text = "Disconnect";
		haptic_connect_indicator->BackColor = System::Drawing::Color::Lime;

		panel_haptic->BackColor = System::Drawing::Color::Lime;
		//haptic_initpos();
		flag_haptic_connected = true;
	}
	else
	{
		// Discard haptic configuration:
		haptic.close();
		btn_haptic_connect->Text = "Connect";
		haptic_connect_indicator->BackColor = System::Drawing::Color::Red;
		panel_haptic->BackColor = System::Drawing::Color::Red;
		flag_haptic_connected = false;
	}
}
// Button Haptic Update:
void MainFormDlg::haptic_update()
{
	if (!flag_haptic_connected) {
		MessageBox::Show("Haptic device not found", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		console_print_error("Haptic device not found.");
		return;
	}

	DeviceStateStruct state;
	hduVector3Dd position;

	Gain = Convert::ToDouble(gain_box->Value);
	Magnitude = Convert::ToDouble(magnitude_box->Value);
	if (rb_friction->Checked)
		haptic.effect_friction(float(Gain), float(Magnitude));
	if (rb_spring->Checked) 
	{
		haptic.read_state(&state);
		position[2] = state.position[0];
		position[0] = state.position[1];
		position[1] = state.position[2];
		haptic.effect_spring(position, float(Gain), float(Magnitude));
	}
		
	if (rb_noeffect->Checked)
		haptic.effect_stop();
}
// Button move haptic to initial position
void MainFormDlg::haptic_initpos()
{
	if (!flag_haptic_connected) {
		MessageBox::Show("Haptic device not found", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		console_print_error("Haptic device not found.");
		return;
	}
	DeviceStateStruct state;
	hduVector3Dd haptic_pos;
	hduVector3Dd position;

	// Read the UI parameter
	haptic_pos[2] = Convert::ToDouble(tb_haptic_initX->Text);
	haptic_pos[0] = Convert::ToDouble(tb_haptic_initY->Text);
	haptic_pos[1] = Convert::ToDouble(tb_haptic_initZ->Text);
	
	// Save last configuration:
	save_config("haptic_initpos_x", tb_haptic_initX->Text);
	save_config("haptic_initpos_y", tb_haptic_initY->Text);
	save_config("haptic_initpos_z", tb_haptic_initZ->Text);

	haptic.effect_spring(haptic_pos, 1.0, 0.6);
}

// Button reset center pos:
void MainFormDlg::haptic_reset_center_pos()
{
	
}

// Button show trajectory form
void MainFormDlg::trajectory_form_setting()
{
	if (trajectory_form_isOpen) {
		return;
	}
	else
	{
		myform = gcnew TrajectoryForm;
		myform->Show(this);
	}
}

// -- Show Robot Control Form --
void MainFormDlg::show_robot_control_form()
{
	if (robotControl_form_isOpen)
		return;
	else 
	{
		RobotControllerDlg ^ controlForm = gcnew RobotControllerDlg;
		controlForm->Show(this);
	}
}
// -- Show Coppliasim Form --
void MainFormDlg::show_coppelia_form()
{
	if (coppelia_form_isOpen)
		return;
	else
	{
		CoppeliaForm ^ mainForm = gcnew CoppeliaForm;
		mainForm->Show(this);
	}
}


// Show custom form --
void MainFormDlg::show_new_custom_form() {
	if (myform_isOpen)
		return;
	else {
		MyForm ^ myform = gcnew MyForm;
		myform->Show(this);
	}
}

void MainFormDlg::show_menu()
{
	if (custom_form_isOpen) {
		customForm->Close();
		return;
	}
	customForm = gcnew CustomFormDlg;
	customForm->Show(this);
}
void MainFormDlg::close_form()
{
	if (custom_form_isOpen)
		customForm->Close();
}
void MainFormDlg::show_force_calibration_menu()
{
	if (force_calibration_form_isOpen) {
		force_calibration_form->Close();
	}

	force_calibration_form = gcnew ForceCalibrationForm;
	force_calibration_form->Show(this);
}
// Scaling Factor Update
void MainFormDlg::scale_up()
{
	char str[32];
	scale_factor += 0.5;
	if (scale_factor > MAX_SCALE)
		scale_factor = (double) MAX_SCALE;

	sprintf(str, "%.2f", (float)scale_factor);
	label_scale_factor->Text = gcnew String(str);
}

void MainFormDlg::scale_down()
{
	char str[32];
	scale_factor -= 0.5;
	if (scale_factor < 0.5)
		scale_factor = 0.5;
	sprintf(str, "%.2f", scale_factor);
	label_scale_factor->Text = gcnew String(str);
}

// -- Fanuc robot connection --
void MainFormDlg::robot_connect()
{
	if (!robot.connected)
	{
		int hr = robot.connect(ip_address_box->Text);
		if (!hr) {
			MessageBox::Show(
				"Fanuc robot connection failed!",
				"Connection error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// save the last ipAddress:
		save_config("ip_address", ip_address_box->Text);

		// Set default speed (override):
		robot_override = 30;
		robot.set_override(robot_override);
		label_override->Text = "" + robot_override + "%";

		btn_robot_connect->Text = "Disconnect";
		robot_connect_indicator->BackColor = System::Drawing::Color::Lime;
		panel_robot->BackColor = System::Drawing::Color::Lime;
		ip_address_box->Enabled = false;
	}
	else
	{
		robot.disconnect();

		flag_getpos = false;
		flag_getforce = false;
		ip_address_box->Enabled = true;
		btn_robot_connect->Text = "Connect";
		robot_connect_indicator->BackColor = System::Drawing::Color::Red;
		panel_robot->BackColor = System::Drawing::Color::Red;
	}
}
// -- Set Override --
void MainFormDlg::set_override(int _override)
{
	if (_override > 100) _override = 100;
	if (_override < 0)   _override = 0;
	label_override->Text = "" + _override + "%";
	robot.set_override(_override);
}
// -- Button Override Up --
void MainFormDlg::override_up()
{
	robot_override += 5;
	if (robot_override > 100) robot_override = 100;
	set_override(robot_override);
}
// -- Button Override Down --
void MainFormDlg::override_down()
{
	robot_override -= 5;
	if (robot_override < 0)   robot_override = 0;
	set_override(robot_override);
}
// -- Button Robot move to Initial Pos --
void MainFormDlg::robot_move_toInitPos()
{
	if (!robot.connected)
		return;
	// Get initial position:
	DataPos pos;
	pos = global_robot_pos;	// Get current robot setting
	pos.X = Convert::ToDouble(tb_robot_initX->Text);
	pos.Y = Convert::ToDouble(tb_robot_initY->Text);
	pos.Z = Convert::ToDouble(tb_robot_initZ->Text);
	pos.W = Convert::ToDouble(tb_robot_initW->Text);
	pos.P = Convert::ToDouble(tb_robot_initP->Text);
	pos.R = Convert::ToDouble(tb_robot_initR->Text);
	robot.moveJ(pos, 30, CNT);
	console_print("___INFOR___: Robot moves to initial position.");
}
void MainFormDlg::get_current_position()
{
	char str[200];
	sprintf(str, "%.3f", global_robot_pos.X); tb_robot_initX->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.Y); tb_robot_initY->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.Z); tb_robot_initZ->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.W); tb_robot_initW->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.P); tb_robot_initP->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.R); tb_robot_initR->Text = gcnew String(str);

}

// >>>> Button START <<<<
void MainFormDlg::start_program()
{
	/*
	if (prog_state != 2) {
		MessageBox::Show("Cycle program is not running.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	_beginthread(Main_Program, 0, NULL);
	*/
	//Main_Program(NULL);
	_beginthread(Main_Program, 0, NULL);
}


// Force Sensor Calibration:
void calibrate_force(DataForce inForce, DataForce * outForce)
{
	DataForce offset;

	// Default offset_value:
	offset.Fx = 81.671  + 9;
	offset.Fy = 60.503  + 14;
	offset.Fz = 988.618 + 38;
	offset.Mx = 1.342;
	offset.My = -5.438;
	offset.Mz = -22.459;

	Vector3d sim_robot_orient(global_robot_pos.W, global_robot_pos.P, global_robot_pos.R);
	Vector3d norm_orient = rot2euler(sim_robot_orient);

	Vector3d temp(norm_orient(2), norm_orient(1), norm_orient(0));
	MatrixXd R_XYZ = getEulerMatrix(temp);

	Vector3d f_current(inForce.Fx, inForce.Fy, inForce.Fz);
	Vector3d f_calibrated = R_XYZ * f_current;

	
	outForce->Fx = inForce.Fx - offset_forces.Fx;
	outForce->Fy = inForce.Fy - offset_forces.Fy;
	outForce->Fz = inForce.Fz - offset_forces.Fz;
	outForce->Mx = inForce.Mx - offset_forces.Mx;
	outForce->My = inForce.My - offset_forces.My;
	outForce->Mz = inForce.Mz - offset_forces.Mz;
	

	//outForce->Fx = f_calibrated(0) + offset_forces.Fx;
	//outForce->Fy = f_calibrated(1) + offset_forces.Fy;
	//outForce->Fz = f_calibrated(2) + offset_forces.Fz;
}

void load_force_offset() {
	ifstream file("offset_force.ini");
	string line;
	float fc[6];
	int cnt = 0;

	if (file.is_open())
	{
		console_print("Load force config file.");
		while (getline(file, line)) {
			fc[cnt] = stof(line);
			cout << fc[cnt] << endl;
			cnt++;
		}

		offset_forces.Fx = fc[0];
		offset_forces.Fy = fc[1];
		offset_forces.Fz = fc[2];
		offset_forces.Mx = fc[3];
		offset_forces.My = fc[4];
		offset_forces.Mz = fc[5];
	}
	else {
		console_print_error("Open force config file failed!");
	}
}
void MainFormDlg::force_sensor_calibration()
{
	offset_forces.Fx = current_force.Fx;
	offset_forces.Fy = current_force.Fy;
	offset_forces.Fz = current_force.Fz;
	offset_forces.Mx = current_force.Mx;
	offset_forces.My = current_force.My;
	offset_forces.Mz = current_force.Mz;

	// Save Offset_force config:
	ofstream file("offset_force.ini");
	if (file.is_open()) 
	{
		file << offset_forces.Fx << endl;
		file << offset_forces.Fy << endl;
		file << offset_forces.Fz << endl;
		file << offset_forces.Mx << endl;
		file << offset_forces.My << endl;
		file << offset_forces.Mz << endl;
		file.close();
	}
}

// //////////////////////////////////////////////////////////
// Modify Time: August 31, 2020
// Recording Force Sensor Data
// //////////////////////////////////////////////////////////
void force_recording(void *);
void force_recording_2(void *);
string force_filename;
// Button handle :
bool isRecording = false;
void MainFormDlg::record_force()
{
	/*
	if (!isRecording)
	{
		String ^ filename = tb_filename->Text;
		force_filename = marshal_as<std::string>(filename);
		isRecording = true;
		Sleep(50);
		_beginthread(force_recording_2, 0, NULL);
		//btnRecord->Text = "Stop Record";
		btn_recordForce->Enabled = false;
		btn_stopRecordForce->Enabled = true;
		
	}
	*/
}
void MainFormDlg::stop_record_force()
{

	//isRecording = false;
	//btn_recordForce->Enabled = true;
	//btn_stopRecordForce->Enabled = false;
}
void force_recording_2(void *) 
{
	char str[200];
	long t_start, t_stop, t_max;

	t_max = 10 * (60 * 1000); // ms
							  // File name:
	ofstream file(force_filename);

	if (file.is_open()) {
		t_start = GetTickCount64();
		printf("Start Recording ... (Wait)\n");

		int cnt = 0;
		file << "Fx,Fy,Fz,Mx,My,Mz, ,X,Y,Z,W,P,R" << endl;
		while (isRecording)
		{
			sprintf(str, "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,    ,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f",
				global_forces.Fx,
				global_forces.Fy,
				global_forces.Fz,
				global_forces.Mx,
				global_forces.My,
				global_forces.Mz,
				robot.current_pos.X,
				robot.current_pos.Y,
				robot.current_pos.Z,
				robot.current_pos.W,
				robot.current_pos.P, 
				robot.current_pos.R);

			file << str << endl;	// Write force data into .csv file
			cout << cnt << " -> " << str << endl;
			cnt++;
			Sleep(500);
		}
		printf("Force Recording FINISH! \n");
		return;
	}
}

void force_recording(void *)
{
	char str[200];
	long t_start, t_stop, t_max;

	t_max = 10 * (60 * 1000); // ms

	// File name:
	ofstream file("ft_side_touch.csv");

	if (file.is_open()) {
		t_start = GetTickCount64();
		printf("Start Recording ... (Wait)\n");
		
		int cnt = 0;
		while (GetTickCount64() - t_start < t_max)
		{

			// If force recording is stopped:
			if (isRecording == false) 
			{
				printf("Force Recording FINISH! \n");
				return;
			}

			sprintf(str, "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f",
				global_forces.Fx,
				global_forces.Fy,
				global_forces.Fz,
				global_forces.Mx,
				global_forces.My,
				global_forces.Mz);

			file << str << endl;	// Write force data into .csv file
			cout << cnt << " -> " << str << endl;
			cnt++;
			Sleep(1000);
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// Button Haptic Jogging mode (on timer 2 Handle)
// Make the following devices are ready before connecting the haptic and 
// Fanuc robot:
// 1. Haptic is connected
// 2. Fanuc program task is running
////////////////////////////////////////////////////////////////////////////
void MainFormDlg::robot_move_handle() // on_timer2();
{
	// ------------------------------------------
	// 1. Update the position on haptic_JOG_mode 
	// ------------------------------------------
	if (flag_haptic_jog_mode == true)
	{
		if (jog_isRunning)
			robot.moveL(global_teaching_pos, 100, CNT, 70);
		
		// If the main program is not connected, stop the teaching mode
		if (prog_state != 2) {
			flag_haptic_jog_mode = false;
			btn_haptic_jog->Text = "Haptic Jog";
			btn_haptic_jog->BackColor = System::Drawing::Color::Gold;
			panel_jog->Visible = false;

			// Lock the haptic position
			//haptic.effect_spring(current_haptic_pos, 1.0, 1.0);
			MessageBox::Show("Fanuc Task program is stopped!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// ------------------------------------------
	// 2. Trigger for sequential moving mode
	// ------------------------------------------
	if (robot.doMoving) {
		robot.doMoving = false;
		if (robot._moving_mode == MOVE_L) {
			robot.moveL(robot.goal_position, robot._acc_val, robot._motion_type, robot._cnt_val);
		}
		else if (robot._moving_mode == MOVE_J) {
			robot.moveJ(robot.goal_position, robot._acc_val, robot._motion_type, robot._cnt_val);
		}
		else if (robot._moving_mode == MOVE_JOINT) {
			robot.move_joint(robot.dst_joint, robot._acc_val);
		}
	}

	// ------------------------------------------
	// 3. Trigger tool functions
	// ------------------------------------------
	if (robot.doAttachTool) {
		robot.doAttachTool = false;
		robot.ATC_lock();
	}
	if (robot.doDetacthTool) {
		robot.doDetacthTool = false;
		robot.ATC_unlock();
	}
	if (robot.doGripperON) {
		robot.doGripperON = false;
		robot.gripper_ON();
	}
	if (robot.doGripperOFF) {
		robot.doGripperOFF = false;
		robot.gripper_OFF();
	}
	// Set Override :
	if (robot.doSetOvrr){
		robot.doSetOvrr = false;
		set_override(robot._override_val);
	}
}
// -- End of on_timer2() Function --
///////////////////////////////////////////////////////////////////////


// -- Button haptic JOG handle --
void MainFormDlg::haptic_jog_mode()
{
	// If jog mode is not running:
	if (!flag_haptic_jog_mode){
		// Return if the fanuc task program is not running
		if (prog_state != 2){
			MessageBox::Show(
				"Fanuc program task isn't running. Please run the program!",
				"Connect to Haptic Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// Return if the haptic device is not connected
		if (!flag_haptic_connected){
			MessageBox::Show(
				"Haptic is not connected!",
				"Connect to Haptic Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// The Fanuc function is handled by timer 1
		// The robot postion is updated by thread function
		flag_haptic_jog_mode = true;
		haptic_initpos();
		Sleep(1000);
		//haptic.effect_friction(1.0, 0.3);
		
		btn_haptic_jog->Text = "Stop Jog";
		btn_haptic_jog->BackColor = System::Drawing::Color::Red;
		panel_jog->Visible = true;

		set_override(55);
		_beginthread(thread_haptic_jog_mode, 0, NULL);
	}

	// if jof mode is running stop the program:
	else
	{
		haptic.effect_spring(current_haptic_pos, 1.0, 1.0);
		set_override(10);
		btn_haptic_jog->Text = "Haptic Jog";
		btn_haptic_jog->BackColor = System::Drawing::Color::Gold;
		flag_haptic_jog_mode = false;
		panel_jog->Visible = false;
	}
}




void polishing_path_1(void *) {
	float delta[6] = { 0, 0, 0, 0, 0, 0 };

	//float tp1[12] = { 1023.073, 491.477, -489.218, -136.510, -7.604, 4.239, _N_, _U_, _T_, 0, 0 ,1 };
	//float tp2[12] = { 1017.352, 519.861, -462.203, -136.510, -7.604, 4.239, _N_, _U_, _T_, 0, 0 ,1 };
	//float tp3[12] = { 1014.259, 446.599, -398.542, -136.510, -7.604, 4.239, _N_, _U_, _T_, 0, 0 ,1 };
	//float tp4[12] = { 1008.071, 384.957, -318.194, -136.510, -7.604, 4.239, _N_, _U_, _T_, 0, 0 ,1 };
	//float tp5[12] = { 1003.427, 306.851, -251.796, -134.064, -7.360, 4.335, _N_, _U_, _T_, 0, 0 ,1 };

	float tp1[12] = { -1028.75, 875.067, 19.558, 135.208, -35.222, -67.712, 0, 1, 1, 0, 0, -1 };
	float tp2[12] = { -1171.64, 680.366, -177.793, 135.564, -35.733, -69.610, 0, 1, 1, 0, 0, -1 };
	float tp3[12] = { -1216.00, 643.665, -127.198, 139.548, -31.878, -70.199, 0, 1, 1, 0, 0, -1 };
	float tp4[12] = { -1206.58, 687.100, -98.107, 139.907, -32.314, -70.389, 0, 1, 1, 0, 0, -1 };
	float tp5[12] = { -1174.03, 733.706, -38.143, 140.127, -32.610, -70.506, 0, 1, 1, 0, 0, -1 };

	for (int i = 0; i < 6; i++) {
		setOverride(50);
		robot.Homogenious(tp1, tp1, delta);
		robot.Homogenious(tp2, tp2, delta);
		robot.Homogenious(tp3, tp3, delta);
		robot.Homogenious(tp4, tp4, delta);
		robot.Homogenious(tp5, tp5, delta);

		move_L(convert_to_datapos(tp1), 10, CNT, 20);
		move_L(convert_to_datapos(tp2), 10, CNT, 20);
		move_L(convert_to_datapos(tp3), 10, CNT, 20);
		move_L(convert_to_datapos(tp4), 10, CNT, 20);
		move_L(convert_to_datapos(tp5), 10, CNT, 20);
		delta[5] = 30;
		Sleep(1000);
	}
}



// ============================================================ //
//					--- Main Program ---					  	//
// ============================================================ //
void Main_Program(void * data){
	//play_trajectory("circular_path.csv", 100);
	//play_trajectory("square_path1.csv", 100);
	//	printf("Current Forces: %.3f   %.3f   %.3f \n", real_force[0], real_force[1], real_force[2]);
	//printf("Current Forces: %.3f   %.3f   %.3f \n", real_force[0], real_force[1], real_force[2]);
	
	setOverride(60);
	float tp1[12] = { 1000, 0, 100, -180.405, -1.604, 4.239, _N_, _U_, _T_, 0, 0 ,0 };
	float tp2[12] = { -1028.75, 875.067, 19.558, 135.208, -35.222, -67.712, 0, 1, 1, 0, 0, -1 };
	move_J(convert_to_datapos(tp1), 10, CNT, 20);
	move_J2(stanbyPos, 50, CNT, 100);
	move_J(convert_to_datapos(tp2), 10, CNT, 20);

	polishing_path_1(NULL);
	
	//robot_workspace_release(NULL);
	
	printf("___INFO___: Main program FINISH \n");	
	
	/*
	float offset_rz = 108;
	float rot[3];
	float M[4][4];
	rot[0] = robot.current_pos.W;
	rot[1] = robot.current_pos.P;
	rot[2] = robot.current_pos.R - offset_rz;
	printf("Robot Orientation: %.2f, %.2f, %.2f \n", rot[0], rot[1], rot[2]);
	getInverseMatrix2(rot, M);
	//print_matrix(M);

	float offset_rot[3] = { 0, 0, -30 };
	float normal_matrix[4][4];
	matrix_rotate(M, normal_matrix, offset_rot);

	print_matrix(normal_matrix);
	float newRot[3];
	get_orientation(normal_matrix, newRot);
	printf("Robot Orientation: %.2f, %.2f, %.2f \n", newRot[0], newRot[1], newRot[2]);
	*/
	
}
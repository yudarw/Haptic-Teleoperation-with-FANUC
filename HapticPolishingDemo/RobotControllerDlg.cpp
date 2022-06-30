#include "main.h"
#include "stdafx.h"
#include "RobotControllerDlg.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;

Fanuc * robot2;
DataPos _pos;

void RobotControllerDlg::update_position()
{
	read_position(&_pos);

	char temp[32];
	sprintf(temp, "%.3f", _pos.X);
	tb_robotX->Text = gcnew String(temp);
	sprintf(temp, "%.3f", _pos.Y);
	tb_robotY->Text = gcnew String(temp);
	sprintf(temp, "%.3f", _pos.Z);
	tb_robotZ->Text = gcnew String(temp);
	sprintf(temp, "%.3f", _pos.W);
	tb_robotW->Text = gcnew String(temp);
	sprintf(temp, "%.3f", _pos.P);
	tb_robotP->Text = gcnew String(temp);
	sprintf(temp, "%.3f", _pos.R);
	tb_robotR->Text = gcnew String(temp);
}

void RobotControllerDlg::set_sdo_on()
{
	int num = Convert::ToInt16(tb_DO->Text);
	robot.set_sdo(num, ON);
}
void RobotControllerDlg::set_sdo_off()
{
	int num = Convert::ToInt16(tb_DO->Text);
	robot.set_sdo(num, OFF);
}

void RobotControllerDlg::posX_up()
{
	DataPos new_pos;
	new_pos = _pos;
	new_pos.X += 10;
	//set_position(new_pos);
//	robot.movePosition(new_pos);
}

// =============================================================== //
//					Robot Controller Dialog						   //
// =============================================================== //
void RobotControllerDlg::read_position(DataPos * current_pos)
{
	current_pos->X = global_robot_pos.X;
	current_pos->Y = global_robot_pos.Y;
	current_pos->Z = global_robot_pos.Z;
	current_pos->W = global_robot_pos.W;
	current_pos->P = global_robot_pos.P;
	current_pos->R = global_robot_pos.R;
	current_pos->C1 = global_robot_pos.C1;
	current_pos->C2 = global_robot_pos.C2;
	current_pos->C3 = global_robot_pos.C3;
	current_pos->C4 = global_robot_pos.C4;
	current_pos->C5 = global_robot_pos.C5;
	current_pos->C6 = global_robot_pos.C6;
	current_pos->C7 = global_robot_pos.C7;
	current_pos->UF = global_robot_pos.UF;
	current_pos->UT = global_robot_pos.UT;
}
void RobotControllerDlg::set_sdo(int num, int val)
{
	printf("tes");
	robot.set_sdo(num, val);
}
void RobotControllerDlg::set_position(DataPos pos)
{
	robot.moveL(pos, 30, FINE);
}
void RobotControllerDlg::load_configuration(Fanuc _robot)
{
	_robot = robot;
}

// -- TOOLS --
void RobotControllerDlg::attach_gripper()
{
	if (prog_state != 2) return;
	_beginthread(robot_attach_gripper, 0, NULL);
}
void RobotControllerDlg::release_gripper()
{
	if (prog_state != 2) return;
	_beginthread(robot_release_gripper, 0, NULL);
}
void RobotControllerDlg::gripper_open() {
	gripper_OPEN();
}
void RobotControllerDlg::gripper_close() {
	gripper_CLOSE();
}
// - End of Robot Controller form Functions -
// =============================================================== //

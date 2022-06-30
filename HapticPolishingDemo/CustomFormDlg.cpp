#include "stdafx.h"
#include "CustomFormDlg.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;

#define SDO_LEGAUTO		1
#define SDO_SEATAUTO	2
#define SDO_LEG_STOP	3
#define SDO_SEAT_STOP	4
#define SDO_HANDON		5
#define SDO_HANDOFF		6
#define SDO_GRNDON		7
#define SDO_GRNDOFF		8
#define SDO_AUTO		11
#define SDO_PAPER_CHANGE 10
#define SDO_HOME		9
#define SDO_HAND_STATUS	20
#define SDO_GRND_STATUS 19
#define SDO_SEAT_STATUS	17
#define SDO_LEG_STATUS	18

bool hand_on_state = false;
bool grnd_on_state = false;

void CustomFormDlg::on_timer1()
{
	if (robot.current_status == 2) {
		label_cycle->Text = "Running";
		label_cycle->BackColor = System::Drawing::Color::LimeGreen;
	}
	else if (robot.current_status == 1)
	{
		label_cycle->Text = "Paused";
		label_cycle->BackColor = System::Drawing::Color::Orange;
	}
	else if (robot.current_status == 0)
	{
		label_cycle->Text = "Stoped";
		label_cycle->BackColor = System::Drawing::Color::Red;
	}

	label_taskName->Text = gcnew String(robot.current_progname);
	label_lineNumber->Text = "" + robot.current_lineNumber;

	// Panel Indicator:

	if(robot.current_sdo_state[SDO_HAND_STATUS - 1] == ON)
		panel_hand->BackColor = System::Drawing::Color::Lime;
	else
		panel_hand->BackColor = System::Drawing::Color::Red;

	if (robot.current_sdo_state[SDO_GRND_STATUS - 1] == ON)
		panel_grnd->BackColor = System::Drawing::Color::Lime;
	else
		panel_grnd->BackColor = System::Drawing::Color::Red;

	if (robot.current_sdo_state[SDO_LEG_STATUS - 1] == ON)
		panel_leg->BackColor = System::Drawing::Color::Lime;
	else
		panel_leg->BackColor = System::Drawing::Color::Red;

	if (robot.current_sdo_state[SDO_SEAT_STATUS - 1] == ON)
		panel_seat->BackColor = System::Drawing::Color::Lime;
	else
		panel_seat->BackColor = System::Drawing::Color::Red;
}

void CustomFormDlg::handON()
{
	robot.set_sdo(SDO_HANDON, ON);
	hand_on_state = true;

	btn_hamdON->Enabled = false;
	btn_hamdON->BackColor = System::Drawing::Color::Gray;

	btn_grndOFF->Enabled = false;
	btn_grndOFF->BackColor = System::Drawing::Color::Gray;
	btn_grndON->Enabled = false;
	btn_grndON->BackColor = System::Drawing::Color::Gray;

	btn_handOFF->Enabled = true;
	btn_handOFF->BackColor = System::Drawing::Color::DarkTurquoise;
}



void CustomFormDlg::handOFF()
{
	robot.set_sdo(SDO_HANDOFF, ON);
	hand_on_state = false;
	
	btn_hamdON->Enabled = true;
	btn_hamdON->BackColor = System::Drawing::Color::DarkTurquoise;

	btn_grndOFF->Enabled = true;
	btn_grndOFF->BackColor = System::Drawing::Color::DarkTurquoise;
	btn_grndON->Enabled = true;
	btn_grndON->BackColor = System::Drawing::Color::DarkTurquoise;

	btn_handOFF->Enabled = false;
	btn_handOFF->BackColor = System::Drawing::Color::Gray;
}

void CustomFormDlg::grndON()
{
	robot.set_sdo(SDO_GRNDON, ON);
	panel_grnd->BackColor = System::Drawing::Color::LimeGreen;
	btn_grndON->Enabled = false;
	btn_grndON->BackColor = System::Drawing::Color::Gray;
	btn_grndOFF->Enabled = true;
	btn_grndOFF->BackColor = System::Drawing::Color::DarkTurquoise;
}

void CustomFormDlg::grndOFF()
{
	robot.set_sdo(SDO_GRNDOFF, ON);
	panel_grnd->BackColor = System::Drawing::Color::Red;
	btn_grndOFF->Enabled = false;
	btn_grndOFF->BackColor = System::Drawing::Color::Gray;
	btn_grndON->Enabled = true;
	btn_grndON->BackColor = System::Drawing::Color::DarkTurquoise;
}


void CustomFormDlg::home_position()
{
	robot.set_sdo(SDO_HOME, ON);
}

int chairLeg_state = 0;
void CustomFormDlg::chair_legAuto()
{
	if (chairLeg_state == 0) {
		robot.set_sdo(SDO_LEGAUTO, ON);

		btn_chairLeg->BackColor = System::Drawing::Color::Red;
		btn_chairLeg->Text = "CHAIR LEG STOP";
		
		btn_chairSeat->BackColor = System::Drawing::Color::Gray;
		btn_chairSeat->Enabled = false;

		chairLeg_state = 1;
	}
	else
	{
		robot.set_sdo(SDO_LEG_STOP, ON);

		btn_chairLeg->BackColor = System::Drawing::Color::Gold;
		btn_chairLeg->Text = "CHAIR LEG START";
		btn_chairSeat->BackColor = System::Drawing::Color::Gold;
		btn_chairSeat->Enabled = true;
		chairLeg_state = 0;
	}

}

int chairSeat_state = 0;
void CustomFormDlg::chair_seatAuto()
{
	if (chairSeat_state == 0) {
		robot.set_sdo(SDO_SEATAUTO, ON);

		btn_chairSeat->BackColor = System::Drawing::Color::Red;
		btn_chairSeat->Text = "CHAIR SEAT STOP";
		btn_chairLeg->BackColor = System::Drawing::Color::Gray;
		btn_chairLeg->Enabled = false;
		chairSeat_state = 1;
	}
	else
	{
		robot.set_sdo(SDO_SEAT_STOP, ON);

		btn_chairSeat->BackColor = System::Drawing::Color::Gold;
		btn_chairSeat->Text = "CHAIR SEAT START";
		btn_chairLeg->BackColor = System::Drawing::Color::Gold;
		btn_chairLeg->Enabled = true;
		chairSeat_state = 0;
	}
}

void CustomFormDlg::paper_change()
{
	robot.set_sdo(SDO_PAPER_CHANGE, ON);
}

void CustomFormDlg::sys_auto()
{
	robot.set_sdo(SDO_AUTO, ON);
}


void CustomFormDlg::update_settings()
{
	int total_laps = Convert::ToInt16(tb_laps->Text);
	robot.set_numreg(10, total_laps);
}
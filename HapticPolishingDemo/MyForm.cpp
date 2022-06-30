#include "main.h"
#include "stdafx.h"
#include "MyForm.h"
#include "Eigen\Dense"

using namespace Eigen;

using namespace System;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;

// Timer for display the value:
void MyForm::on_timer() {

	// Show the Fz:
	double Fe = 0;
	char str[100];
	//sprintf(str, "%.3f", calibrated_forces.Fz);
	sprintf(str, "%.3f", Fe);
	tb_force->Text = gcnew String(str);

	//double Fe = abs(calibrated_forces.Fz);
	double pos_ref = 80;
	double cur_pos = global_haptic_pos.Z;

	double force_error = pos_ref - cur_pos;

	Fe = force_error;

	if (Fe < -10) Fe = -10;
	sprintf(str, "%.3f", Fe);
	tb_force->Text = gcnew String(str);

	// Panel_color:
	if (Fe > 5.0 && Fe <= 15.0) {
		panel_contact->BackColor = System::Drawing::Color::Yellow;
		label_contact->Text = "Less Contact";
		label_contact->ForeColor = System::Drawing::Color::Black;
	}
	else if (Fe > 15 && Fe <= 30) {
		panel_contact->BackColor = System::Drawing::Color::Lime;
		label_contact->Text = "OK";
	}
	else if (Fe > 30) {
		panel_contact->BackColor = System::Drawing::Color::Red;
		label_contact->Text = "Over Contact";
	}
	else if (Fe <= 5.0) {
		panel_contact->BackColor = System::Drawing::Color::White;
		label_contact->Text = "No Contact";
		label_contact->ForeColor = System::Drawing::Color::Black;
	}

	Vector3d Xref(-129.352, -963.113, 674.953);
	Vector3d XCur(global_robot_pos.X, global_robot_pos.Y, global_robot_pos.Z);
	Vector3d Xerror = XCur - Xref;

	// Update Text 
	// Position :
	sprintf(str, "%.3f", global_robot_pos.X);
	tbPosX->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.Y);
	tbPosY->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.Z);
	tbPosZ->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.W);
	tbPosW->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.P);
	tbPosP->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.R);
	tbPosR->Text = gcnew String(str);

	// Ref Pos :
	sprintf(str, "%.3f", Xref[0]);
	rPos_X->Text = gcnew String(str);
	sprintf(str, "%.3f", Xref[1]);
	rPos_Y->Text = gcnew String(str);
	sprintf(str, "%.3f", Xref[2]);
	rPos_Z->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.W);
	rPos_W->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.P);
	rPos_p->Text = gcnew String(str);
	sprintf(str, "%.3f", global_robot_pos.R);
	rPos_r->Text = gcnew String(str);

	// Error Pos:
	sprintf(str, "%.3f", Xerror[0]);
	ePos_X->Text = gcnew String(str);
	sprintf(str, "%.3f", Xerror[1]);
	ePos_Y->Text = gcnew String(str);
	sprintf(str, "%.3f", Xerror[2]);
	ePos_Z->Text = gcnew String(str);
} 

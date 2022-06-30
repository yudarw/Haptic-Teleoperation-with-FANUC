#include "main.h"
#include "stdafx.h"
#include "TrajectoryForm.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;
using namespace msclr::interop;


float global_tp_points[9999][12];
int total_tp_point;
int current_tp_index;
bool _isRunning = false;

void TrajectoryForm::update_current_index()
{
	
	if (_isRunning) 
	{
		if(current_tp_index > 0)
			dataGridView1->Rows[current_tp_index - 1]->Selected = false;

		dataGridView1->Rows[current_tp_index]->Cells[0]->Selected = true;
	}
	else {
		current_tp_index = dataGridView1->CurrentRow->Index;
		textBox1->Text = "" + current_tp_index;
	}

}

void TrajectoryForm::init()
{
	dataGridView1->Rows->Add(1000);
}

void TrajectoryForm::read_csv(System::String ^ path)
{
}

void TrajectoryForm::load_file()
{
	string path;
	char str[200];
	float point[1000][12];
	int total_point;

	openFileDialog1->Filter = "Csv file (*.csv)|*.csv";
	openFileDialog1->Title = "Open trajectory file";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		String ^ filepath = openFileDialog1->FileName;
		path = marshal_as<std::string>(filepath);
	}

	total_tp_point = 0;
	load_trajectory(path, global_tp_points, &total_tp_point);

	dataGridView1->DataSource = nullptr;
	dataGridView1->Rows->Clear();
	dataGridView1->Rows->Add(total_tp_point);

	int row, col;
	for (row = 0; row < total_tp_point; row++) {
		for (col = 0; col < 12; col++) {
			if (col < 6)
				sprintf(str, "%.3f", global_tp_points[row][col]);
			else if (col >= 6)
				sprintf(str, "%d", (int)global_tp_points[row][col]);

			dataGridView1->Rows[row]->Cells[col+1]->Value = gcnew String (str);
		}

		dataGridView1->Rows[row]->Cells[0]->Value = row;
	}

	//dataGridView1->Rows[3]->Selected = true;
	//Controls->Add(dataGridView1);
}

void TrajectoryForm::save_file() {
	saveFileDialog1->Filter = "Text file (*.txt)|*.txt|Csv file (*.csv)|*.csv";
	saveFileDialog1->Title = "Save a trajectory file";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String ^ filepath = saveFileDialog1->FileName;
		std::string path = marshal_as<std::string>(filepath);
		save_trajectory(path, tp_points);
	}
}


// -- Record current point --
// /////////////////////////////////////////////
void TrajectoryForm::add_recorded_point()
{
	record_current_point();

	float teach_point[12];
	datapos_to_posarray(robot.current_pos, teach_point);

	current_tp_index = dataGridView1->CurrentRow->Index;
	for (int col = 0; col < 12; col++) {
		dataGridView1->Rows[index - 1]->Cells[col + 1]->Value = teach_point[col];
	}
	dataGridView1->Rows[index - 1]->Cells[0]->Value = index - 1;

	Controls->Add(dataGridView1);
}

void record_current_point()
{
	char str[200];
	datapos_to_posarray(robot.current_pos, tp_points[index]);
	sprintf(str, "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%d,%d,%d,%d,%d,%d",
		robot.current_pos.X,
		robot.current_pos.Y,
		robot.current_pos.Z,
		robot.current_pos.W,
		robot.current_pos.P,
		robot.current_pos.R,
		robot.current_pos.C1,
		robot.current_pos.C3,
		robot.current_pos.C4,
		robot.current_pos.C5,
		robot.current_pos.C6,
		robot.current_pos.C7
	);
	cout << currentDateTime <<  "___RECORD___: Point recorded [" << index << "] " << str << endl;
	index++;
}

void TrajectoryForm::move_to_point()
{
	float _tmp_points[12];
	for (int i = 0; i < 12; i++) {
		if (i < 6)
			_tmp_points[i] = Convert::ToDouble(dataGridView1->Rows[current_tp_index]->Cells[i + 1]->Value);
		else
			_tmp_points[i] = Convert::ToInt16(dataGridView1->Rows[current_tp_index]->Cells[i + 1]->Value);
	}

	if (prog_state == 2) {
		move_L(posarray_to_datapos(_tmp_points), 100, CNT, 100);
	}
	else {
		cout << currentDateTime << " Move point error!!! Fanuc cycle program is not running" << endl;
	}
}

void TrajectoryForm::get_current_point(float pos[12])
{
	
	for (int i = 0; i < 12; i++) {
		if (i < 6)
			pos[i] = Convert::ToDouble(dataGridView1->Rows[current_tp_index]->Cells[i + 1]->Value);
		else
			pos[i] = Convert::ToInt16(dataGridView1->Rows[current_tp_index]->Cells[i + 1]->Value);
	}
	
}



void home_to_polish(void *) 
{
	if (!robot.connected || prog_state != 2) {
		cout << currentDateTime << "Error: Robot is not connected or cycle program is not running!" << endl;
		return;
	}

	float home_pos[12] = { 764, 0, 252, -176, -1.604, -109, _N_, _U_, _T_, 0, 0 ,0 };;
	float cp_1[12] = { 812, 130, 696, -154, -33, -91, 0, 1, 1, 0, 0, 0 };
	float cp_2[12] = { -361, 739, 696, -154, -33, 15, 0, 1, 1, 0, 0, 0 };
	float cp_3[12] = { -1122, 892, 168, -164, 14, 21, 0, 1, 1, 0, 0, 0 };

	setOverride(40);
	move_L(convert_to_datapos(home_pos), 50, FINE, 20); Sleep(1000);
	move_L(convert_to_datapos(cp_1), 50, FINE, 20); Sleep(1000);
	move_J(convert_to_datapos(cp_2), 70, CNT, 20);
	move_J(convert_to_datapos(cp_3), 70, CNT, 20);
}


void polish_upper_side(void*) {

	if (!robot.connected || prog_state != 2) {
		cout << currentDateTime << "Error: Robot is not connected or cycle program is not running!" << endl;
		return;
	}

	_isRunning = true;

	float chek_point_up_side[12] = { -1152.459, 807.996, 307.040, -126.605, 18.935, 130.090, 0, 1, 1, 0 , 0, 0};

	// Load the trajectory file
	load_trajectory("D:/new_up_v3.csv", global_tp_points, &total_tp_point);

	float tmp[12];
	float delta[6] = { 0, 0, 0, 0, 0, 0 };
	int rotation_degree = 45;
	int total_step = 360 / rotation_degree;
	int step = 0;

	// Rotate Left 180 :
	setOverride(30);
	Sleep(1000);
	delta[5] = -175;
	move_J2(chek_point_up_side, 100, FINE);
	
	setOverride(60);
	for (int i = 0; i < total_step; i++) {
		current_tp_index = 0;
		if (delta[5] > 175) delta[5] = 175;
		if (delta[5] < -175) delta[5] = -175;

		while (current_tp_index < total_tp_point) {
			robot.Homogenious(global_tp_points[current_tp_index], tmp, delta);
			if (current_tp_index < 2) {
				move_J2(tmp, 50, CNT, 80);
				Sleep(200);
			}
			else
				move_J2(tmp, 10, CNT, 5);
			current_tp_index++;
		}
		delta[5] += rotation_degree;
	}
	delta[5] = 0;
	robot.Homogenious(global_tp_points[0], tmp, delta);
	move_J2(tmp, 100, CNT, 50);

	setOverride(30);
	move_J2(chek_point_up_side, 100, CNT, 80);

	_isRunning = false;


}

void polish_buttom_side(void*) {

	if (!robot.connected || prog_state != 2) {
		cout << currentDateTime << "Error: Robot is not connected or cycle program is not running!" << endl;
		return;
	}


	load_trajectory("D:/new_bottom_v33.csv", global_tp_points, &total_tp_point);

	_isRunning = true;
	float tmp[12];
	float delta[6] = { 0, 0, 0, 0, 0, 0 };
	int rotation_degree = 45;
	int total_step = 360 / rotation_degree;
	int step = 0;

	// Rotate Left 180 :
	delta[5] = -175;
	
	setOverride(55);

	for (int i = 0; i < total_step; i++) {
		current_tp_index = 0;
		if (delta[5] > 175) delta[5] = 179;
		if (delta[5] < -175) delta[5] = -179;
		
		while (current_tp_index < total_tp_point) {
			robot.Homogenious(global_tp_points[current_tp_index], tmp, delta);
			if (current_tp_index < 3) {
				move_J2(tmp, 50, CNT, 80);
				Sleep(200);
			}
			else
				move_J2(tmp, 10, CNT, 5);
			current_tp_index++;
		}
		delta[5] += rotation_degree;
	}
	delta[5] = 0;
	robot.Homogenious(global_tp_points[0], tmp, delta);
	move_J2(tmp, 100, CNT, 50);
	
	polish_upper_side(NULL);
	_isRunning = false;
}


void TrajectoryForm::main_program()
{
	_beginthread(polish_buttom_side, 0, NULL);
	//_beginthread(polish_upper_side, 0, NULL);
}

void TrajectoryForm::home_to_polish_pos()
{
	_beginthread(home_to_polish, 0, NULL);
}

void TrajectoryForm::delete_row() 
{
	current_tp_index = dataGridView1->CurrentRow->Index;
	dataGridView1->Rows->RemoveAt(current_tp_index);
}

void TrajectoryForm::insert_row()
{
	current_tp_index = dataGridView1->CurrentRow->Index;
	dataGridView1->Rows->Insert(current_tp_index);
}
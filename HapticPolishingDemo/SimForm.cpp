#include "stdafx.h"
#include "SimForm.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Haptic.h"

#define phi 3.141592
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;
using namespace std;
extern "C" {
#include "extApi.h"
}

ofstream txtFile;
PhantomOmniHaptic myhaptic;

int		clientID;
int		targetHandle;
int		robotHandle;
int		tipHandle;

float	position[3];
float	orientation[3];
float	initialPosition[3] = {0, 0, 0};

bool runningFlag = false;
bool recording = false;
float trajectory[100000][6];

void thread_readPosition(void * data);
void thread_record(void * data);
void thread_play(void * data);


// Haptic Data :
double hapticpos[6];
double robotpos[6] = {0, 0, 0, 0, 0, 0};

void SimForm::sim_connect()
{

	clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
	if (clientID == -1)
	{
		printf("Coppeliasim connection failed! \n");
		return;
	}
	printf("Coppeliasim connection success.\n");

	simxGetObjectHandle(clientID, "IRB140_manipulationSphere", &targetHandle, simx_opmode_oneshot_wait);
	simxGetObjectHandle(clientID, "UR5", &robotHandle, simx_opmode_oneshot_wait);
	simxGetObjectHandle(clientID, "tip", &tipHandle, simx_opmode_oneshot_wait);

	

	printf("Get 'targetpos' handle = %d \n", targetHandle);

	initialPosition[0] = 0.35;
	initialPosition[1] = 0.00;
	initialPosition[2] = 0.25;
	simxSetObjectPosition(clientID, targetHandle, robotHandle, initialPosition, simx_opmode_oneshot);
}


///////////////////////////////////////////////
//			SimForm On Timer 1:
//////////////////////////////////////////////

void SimForm::on_timer_1()
{
	char str[32];
	double pos[6];
	double transform[16];
	double force[3];
	double velocity[3];

	//haptic.readTransform(transform);
	myhaptic.readState(pos, force, transform, velocity);
	
	for (int i = 0; i < 6; i++)
		hapticpos[i] = pos[i];
	
	// Display Haptic position :
	sprintf(str, "%3.0f", hapticpos[0]);
	tbHx->Text = gcnew String(str);
	sprintf(str, "%3.0f", hapticpos[1]);
	tbHy->Text = gcnew String(str);
	sprintf(str, "%3.0f", hapticpos[2]);
	tbHz->Text = gcnew String(str);
	sprintf(str, "%3.2f", hapticpos[3]);
	tbHw->Text = gcnew String(str);
	sprintf(str, "%3.2f", hapticpos[4]);
	tbHp->Text = gcnew String(str);
	sprintf(str, "%3.2f", hapticpos[5]);
	tbHr->Text = gcnew String(str);

	// Display Robot position :
	sprintf(str, "%3.3f", robotpos[0]);
	tbX->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotpos[1]);
	tbY->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotpos[2]);
	tbZ->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotpos[3]);
	tbW->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotpos[4]);
	tbP->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotpos[5]);
	tbR->Text = gcnew String(str);
	
}

int btnHapticReadFlag = 0;
void SimForm::haptic_read()
{
	if (btnHapticReadFlag == 0) {
		btnHapticReadFlag = 1;
		button4->Text = "Stop";
		if (myhaptic.init() != -1) {
			//timer1->Interval = 100;
			timer1->Enabled = true;
			//_beginthread(thread_readPosition, 0, NULL);
		}
		else {
			btnHapticReadFlag = 1;
			button4->Text = "Read Haptic";
		}
	}
	else
	{
		btnHapticReadFlag = 0;
		timer1->Enabled = false;
		button4->Text = "Read Haptic";
		myhaptic.close();
	}
}

void SimForm::transform()
{
	char str[32];
	float scale = 2.0;
	float hapticPos[6];
	float robotPos[6];

	hapticPos[0] = Convert::ToDouble(tbHx->Text);
	hapticPos[1] = Convert::ToDouble(tbHy->Text);
	hapticPos[2] = Convert::ToDouble(tbHz->Text);
	hapticPos[3] = Convert::ToDouble(tbHw->Text);
	hapticPos[4] = Convert::ToDouble(tbHp->Text);
	hapticPos[5] = Convert::ToDouble(tbHr->Text);

	robotPos[0] = (hapticPos[0] * scale) / 1000;
	robotPos[1] = (hapticPos[1] * scale) / 1000;
	robotPos[2] = (hapticPos[2] * scale) / 1000;

	sprintf(str, "%3.3f", robotPos[0]); tbX->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotPos[1]); tbY->Text = gcnew String(str);
	sprintf(str, "%3.3f", robotPos[2]); tbZ->Text = gcnew String(str);
}


int buttonFlag = 0;
void SimForm::shift_left()
{
	if (buttonFlag == 0) {
		buttonFlag = 1;
		button2->Text = "Stop Recording";
		recording = true;
		_beginthread(thread_record, 0, NULL);
		//_beginthread(thread_readPosition, 0, NULL);
	}
	else if (buttonFlag == 1)
	{
		buttonFlag = 0;
		button2->Text = "Record";
		recording = false;
		runningFlag = false;
	}
}

void SimForm::shift_right() 
{
	_beginthread(thread_play, 0, NULL);
}

void thread_readPosition(void * data)
{
	runningFlag = true;
	
	while (runningFlag == true)
	{
		simxGetObjectPosition(clientID, targetHandle, robotHandle, position, simx_opmode_oneshot_wait);
		simxGetObjectOrientation(clientID, targetHandle, robotHandle, orientation, simx_opmode_oneshot_wait);

		//printf("Current position : %3.3f %3.3f %3.3f \n", position[0], position[1], position[2]);
		robotpos[0] = position[0];
		robotpos[1] = position[1];
		robotpos[2] = position[2];
		robotpos[3] = orientation[0] * (180 / phi);
		robotpos[4] = orientation[1] * (180 / phi);
		robotpos[5] = orientation[2] * (180 / phi);
		Sleep(50);
	}
}


void thread_record(void * data) {
	int step = 0;
	printf("Recording started... \n");
	long t_start = GetTickCount64();
	while (recording)
	{
		trajectory[step][0] = position[0];
		trajectory[step][1] = position[1];
		trajectory[step][2] = position[2];
		trajectory[step][3] = orientation[0];
		trajectory[step][4] = orientation[1];
		trajectory[step][5] = orientation[2];
		step++;
		Sleep(50);
	}
	long t_stop = GetTickCount64();
	long time = t_stop - t_start;
	printf("Recording time : %d \n", time);

	txtFile.open("robotsim_trajectory.txt");
	char str[200];

	for (int i = 0; i < step; i++)
	{
		sprintf(str, "%3.3f %3.3f %3.3f %3.3f %3.3f %3.3f",
			trajectory[i][0],
			trajectory[i][1],
			trajectory[i][2],
			trajectory[i][3],
			trajectory[i][4],
			trajectory[i][5] );

		txtFile << str << endl;
	}
	printf("Recording finish... \n");
	txtFile.close();
}

void thread_play(void * data)
{
	ifstream file("robotsim_trajectory.txt");
	string line = "";
	string pos_str;
	int step;
	const char* delim = " ";
	if (file.is_open())
	{	
		while (getline(file, line))
		{
			int i = 0;
			char *token = strtok(const_cast<char*>(line.c_str()), delim);
			while (token != nullptr)
			{
				trajectory[step][i] = stof(token);
				token = strtok(nullptr, delim);
				i++;
			}
			step++;
		}
	}
	file.close();

	long t_start = GetTickCount64();
	for (int i = 0; i < step; i++)
	{
		float orient[3] = { 0, 0, 0 };
		float pos[3];
		pos[0] = trajectory[i][0];
		pos[1] = trajectory[i][1];
		pos[2] = trajectory[i][2];
		simxSetObjectPosition(clientID, targetHandle, robotHandle, pos, simx_opmode_oneshot);
		simxSetObjectOrientation(clientID, targetHandle, robotHandle, orient, simx_opmode_oneshot);
		Sleep(50);
	}
	long t_stop = GetTickCount64();
	long time = t_stop - t_start;
	printf("Playing time : %d \n", time);
}


bool controlFlag = false;
void thread_setPosition(void * data)
{
	float orient[3];
	while (controlFlag == true) {

		position[0] = initialPosition[0] + (hapticpos[0] * -2.5 / 1000);
		position[1] = initialPosition[1] + (hapticpos[1] * -2.5 / 1000);
		position[2] = initialPosition[2] + (hapticpos[2] * 2.5 / 1000);

		orientation[0] = hapticpos[3] * (phi / 180);
		orientation[1] = hapticpos[4] * (phi / 180);
		orientation[2] = hapticpos[5] * (phi / 180);

		orientation[0] = 0;
		orientation[1] = 0;
		orientation[2] = 0;

		//printf("orientation : %.2f %.2f %.2f \n", orient[0], orient[1], orient[2]);
		simxSetObjectOrientation(clientID, targetHandle, sim_handle_parent , orientation, simx_opmode_oneshot);
		simxSetObjectPosition(clientID, targetHandle, robotHandle, position, simx_opmode_oneshot);
		Sleep(10);
	}
}

int controlState = 0;
void SimForm::robot_control()
{
	if (controlState == 0)
	{
		controlState = 1;
		controlFlag = true;
		btnControl->Text = "Stop";
		_beginthread(thread_setPosition, 0, NULL);
	}
	else
	{
		controlState = 0;
		controlFlag = false;
		btnControl->Text = "Robot Control";
	}
}
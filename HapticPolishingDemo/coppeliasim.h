#pragma once
#include <stdlib.h>
#include <iostream>

extern "C" {
#include "extApi.h"
}

using namespace std;

#define RAD_TO_DEG (180/3.141592)
#define DEG_TO_RAD (3.141592/180)

// Retrieve global handle;
class CoppeliaSim {
public:
	bool connected;
	int clientID;

public:
	bool connect(int port);
	void disconnect(int clientID);
};

// Class Robot
class CoppeliaRobot: public CoppeliaSim{
public:
	CoppeliaRobot(simxChar * robot_name);
	void init();
	void setPosition(float pos[6], bool wait);
	void setPosition(float x, float y, float z, float w, float p, float r, bool wait);
	void setPosition(float x, float y, float z, float w, float p, float r);
	void setJointPosition(float joint[6]);
	void setJointPosition(float J1, float J2, float J3, float J4, float J5, float J6);
	void setJointPosition(int num, float tetha);	// Set single joint position	

	void setPosition2(float pos[6]);				// Direct set object position (no speed control)
	void readCurrentJointPos(float joint_pos[6]);
	void readCurrentPosition(float current_pos[6]);
	void readObjectPosition(string object_name, float current_pos[6]);
	void enableIk(bool enable);
	bool isMoving();
	void setSpeed(int velocity);
	void gripperCatch();
	void gripperRelease();

	void getObjectMatrix(float M[4][4]);

public:
	int joint_handle[6];
	int forceSensor_handle;
	simxChar * script_name;

	//Ik Handle
	int ikTargetHandle;
	int ikTipHandle;
	int robotHandle;
	int moving;
};

// Class Force Sensor
class CoppeliaForce{
public:
	void init(int clientID, simxChar * obj_name);
	void read(float force[6]);
private:
	int forceHandle;
	int clientID;
};
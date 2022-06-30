#include "coppeliasim.h"
#include <windows.h>

// Connect to coppelia sim, defaulf port: 19999
/////////////////////////////////////////////////////////////////////
bool CoppeliaSim::connect(int port)
{
	if (!connected) {
		this->clientID = simxStart((simxChar*)"127.0.0.1", port, true, true, 2000, 5);
		if (this->clientID != -1) {
			this->connected = true;
			printf("__INFO___: CoppeliaSIM connection success! Client ID : %d \n", clientID);
			return true;
		}
		else {
			printf("__ERROR___: Connection failed. Please run the CoppeliaSim first! \n");
		}
	}
	else {
		printf("__INFO___: CoppeliaSim already connected. Please disconnect first. \n");
	}
	return false;
}

// Diconnect from CoppeliaSim
////////////////////////////////////////////////////////////////////
void CoppeliaSim::disconnect(int clientID)
{
	this->connected = false;
	simxFinish(clientID);
}


// Force Sensor
void CoppeliaForce::init(int clientID, simxChar * obj_name)
{
	this->clientID = clientID;
	simxGetObjectHandle(this->clientID, obj_name, &forceHandle, simx_opmode_oneshot_wait);
	printf("__INFO___: Coppeliasim force sensor handle ID : %d \n", forceHandle);
}

void CoppeliaForce::read(float force[6]) 
{
	simxUChar state;
	float _torque[3] = {0 ,0 ,0 };
	float _force[3] = {0, 0, 0,};
	simxReadForceSensor(this->clientID, forceHandle, &state, _force, _torque, simx_opmode_continuous);

	for (int i = 0; i < 3; i++) {
		force[i] = _force[i];
	}
	for (int i = 0; i < 3; i++) {
		force[i + 3] = _torque[i];
	}
//	printf("Force Data: %.3f  %.3f  %.3f \n", force[0], force[1], force[2]);
}





//	Robot Class
///////////////////////////////////////////////////////////////////
CoppeliaRobot::CoppeliaRobot(simxChar * robot_name) {
	script_name = robot_name;
}
void CoppeliaRobot::enableIk(bool enable) 
{
	int dataSend;
	if (enable) dataSend = 1;
	else dataSend = 0;

	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"enableIk",							// Function name
		1, &dataSend,							// inIntCnt, inInt
		0, NULL,						// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot);
}

// Robot initialization: retreive some handles:
//////////////////////////////////////////////////////////////////////	 
void CoppeliaRobot::init() 
{
	simxGetObjectHandle(clientID, script_name, &robotHandle, simx_opmode_oneshot_wait);
	simxGetObjectHandle(clientID, "FanucM20_ikTarget", &ikTargetHandle, simx_opmode_oneshot_wait);
	simxGetObjectHandle(clientID, "FanucM20_ikTip", &ikTipHandle, simx_opmode_oneshot_wait);

	// Get robot moving status flag:
	simxGetIntegerSignal(clientID, "moving_state", &moving, simx_opmode_streaming);
}


// Set robot arm position:
// ////////////////////////////////////////////////////////////////////
void CoppeliaRobot::setPosition(float pos[6], bool wait)
{
	setPosition(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5]);

	if (wait){
		while (isMoving());
	}
}
void CoppeliaRobot::setPosition(float x, float y, float z, float w, float p, float r, bool wait)
{
	setPosition(x, y, z, w, p, r);
	if (wait) {
		while (isMoving());
	}
}
void CoppeliaRobot::setPosition(float x, float y, float z, float w, float p, float r)
{
	enableIk(true);				// Enable IK mode

	float pos[6];
	pos[0] = x / 1000;			// meter
	pos[1] = y / 1000;			// meter
	pos[2] = z / 1000;			// meter
	pos[3] = w * DEG_TO_RAD;	// rad
	pos[4] = p * DEG_TO_RAD;	// rad
	pos[5] = r * DEG_TO_RAD;	// rad

	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"movePosition",						// Function name
		0, NULL,							// inIntCnt, inInt
		6, pos,								// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot_wait);
}


// Set Robot Joint Position:
///////////////////////////////////////////////////////////////////////////
void CoppeliaRobot::setJointPosition(float joint[6]) {
	setJointPosition(joint[0], joint[1], joint[2], joint[3], joint[4], joint[5]);
}
void CoppeliaRobot::setJointPosition(float J1, float J2, float J3, float J4, float J5, float J6) 
{
	enableIk(false);						// Enable Joint MODE

	float joint[6];
	joint[0] = J1 * (DEG_TO_RAD);
	joint[1] = J2 * (DEG_TO_RAD);
	joint[2] = J3 * (DEG_TO_RAD);
	joint[3] = J4 * (DEG_TO_RAD);
	joint[4] = J5 * (DEG_TO_RAD);
	joint[5] = J6 * (DEG_TO_RAD);

	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"moveJointPosition",				// Function name
		0, NULL,							// inIntCnt, inInt
		6, joint,							// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot);
	while (isMoving());						// Wait moving 
}

void CoppeliaRobot::setJointPosition(int num, float tetha)
{
	enableIk(false);						// Enable Joint Mode
	float jointAngle = tetha * DEG_TO_RAD;
	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"moveSingleJointPosition",			// Function name
		1, &num,							// inIntCnt, inInt
		1, &jointAngle,						// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot);

	while (isMoving());
}

// Read Current Robot Joint Position:
void CoppeliaRobot::readCurrentJointPos(float joint_pos[6]) 
{
	int cnt;
	float *jointData;
	int * inData;
	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"getJointPosition",					// Function name
		0, NULL,							// inIntCnt, inInt
		0, NULL,							// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		&cnt, &inData,						// outIntCnt, outInt
		&cnt, &jointData,					// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_blocking);

	for (int i = 0; i < 6; i++){
		joint_pos[i] = jointData[i] * RAD_TO_DEG;
	}
}


// Get robot moving status. Return TRUE if the robot is moving and
// return FALSE is robot is stop.
bool CoppeliaRobot::isMoving() {
	Sleep(50);
	simxGetIntegerSignal(clientID, "moving_state", &moving, simx_opmode_buffer);
	if (moving) return true;
	else return false;
}


// Arm Robot Gripper Catch
void CoppeliaRobot::gripperCatch()
{
	int state = 0;
	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"setGripper",						// Function name
		1, &state,							// inIntCnt, inInt
		0, NULL,							// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot);
}

// Arm Robot Gripper Gripper Release
void CoppeliaRobot::gripperRelease()
{
	int state = 1;
	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"setGripper",						// Function name
		1, &state,							// inIntCnt, inInt
		0, NULL,							// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot);
}

// Get Robot Tip Homogeneous Matrix:
/////////////////////////////////////////////////////////////////////////////////
void CoppeliaRobot::getObjectMatrix(float M[4][4])
{
	int cnt;
	float *pData;
	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"getObjectMatrix",						// Function name
		0, NULL,							// inIntCnt, inInt
		0, NULL,							// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		&cnt, &pData,						// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot_wait);

	M[0][0] = pData[0];
	M[0][1] = pData[1];
	M[0][2] = pData[2];
	M[0][3] = pData[3];

	M[1][0] = pData[4];
	M[1][1] = pData[5];
	M[1][2] = pData[6];
	M[1][3] = pData[7];

	M[2][0] = pData[8];
	M[2][1] = pData[9];
	M[2][2] = pData[10];
	M[2][3] = pData[11];

	M[3][0] = 0;
	M[3][1] = 0;
	M[3][2] = 0;
	M[3][3] = 1;
}


// Read Current Robot Tip Position
/////////////////////////////////////////////////////////////////////////////////
void CoppeliaRobot::readCurrentPosition(float currentPos[6])
{
	float position[3], orientation[3];
	simxGetObjectPosition(clientID, ikTipHandle, robotHandle, position, simx_opmode_oneshot);
	simxGetObjectOrientation(clientID, ikTipHandle, robotHandle, orientation, simx_opmode_oneshot);
	currentPos[0] = position[0] * 1000;	//mm
	currentPos[1] = position[1] * 1000; //mm
	currentPos[2] = position[2] * 1000; //mm
	currentPos[3] = orientation[0] * RAD_TO_DEG;
	currentPos[4] = orientation[1] * RAD_TO_DEG;
	currentPos[5] = orientation[2] * RAD_TO_DEG;
}

void CoppeliaRobot::readObjectPosition(string object_name, float currentPos[6]) {
	int object_handle;
	float position[3], orientation[3];
	simxGetObjectHandle(clientID, object_name.c_str(), &object_handle, simx_opmode_oneshot_wait);
	simxGetObjectPosition(clientID, object_handle, robotHandle, position, simx_opmode_oneshot_wait);
	simxGetObjectOrientation(clientID, object_handle, robotHandle, orientation, simx_opmode_oneshot_wait);
	currentPos[0] = position[0] * 1000;	//mm
	currentPos[1] = position[1] * 1000; //mm
	currentPos[2] = position[2] * 1000; //mm
	currentPos[3] = orientation[0] * RAD_TO_DEG;
	currentPos[4] = orientation[1] * RAD_TO_DEG;
	currentPos[5] = orientation[2] * RAD_TO_DEG;
}

// Directly set the robot position and orientation (no speed control)
void CoppeliaRobot::setPosition2(float pos[6])
{
	float position[3], orientation[3];
	for (int i = 0; i < 3; i++) {
		position[i] = pos[i] / 1000;	// mm
		orientation[i] = pos[i + 3] * DEG_TO_RAD;
	}
	simxSetObjectPosition(clientID, ikTargetHandle, robotHandle, position, simx_opmode_oneshot_wait);
	simxSetObjectOrientation(clientID, ikTargetHandle, robotHandle, orientation, simx_opmode_oneshot_wait);
}

// Set Robot Speed : 0 - 100
///////////////////////////////////////////////////////////////////////
void CoppeliaRobot::setSpeed(int velocity)
{
	int result = simxCallScriptFunction(
		clientID,
		script_name,						// the name of the associated obejct script
		sim_scripttype_childscript,			// the handle of the script
		"setSpeed",							// Function name
		1, &velocity ,							// inIntCnt, inInt
		0, NULL,							// inFloatCnt, inFloat
		0, NULL,							// inStringCnt, inString
		0, NULL,							// inBufferSize, inBuffer
		NULL, NULL,							// outIntCnt, outInt
		NULL, NULL,							// outFloatCnt, outFloat
		NULL, NULL,							// outStringCnt, outString
		NULL, NULL,							// outBufferSize, outBuffer
		simx_opmode_oneshot_wait);
}
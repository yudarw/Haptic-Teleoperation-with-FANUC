#include "Fanuc.h"

// Fanuc robot connect
int Fanuc::connect(CString ipAddress)
{
	pCore = new _Core;
	if (!pCore->CreateDispatch(_T("FRRJIF.Core")))
	{
		printf("___ERROR___: Unable to create FFRJIF.Core. \n");
		pCore = NULL;
		return 0;
	}
	pLibCore = new ILibCore(pCore->GetLib());
	pDataTable = new _DataTable(pCore->GetDataTable());

	pAlarm = new _DataAlarm(pDataTable->AddAlarm(ALARM_LIST, 5, 0));
	pAlarmCurrent = new _DataAlarm(pDataTable->AddAlarm(ALARM_CURRENT, 1, 0));
	pCurPos = new _DataCurPos(pDataTable->AddCurPos(CURPOS, 1));
	pCurPosUF = new _DataCurPos(pDataTable->AddCurPosUF(CURPOS, 1, 15));
	pNumReg = new _DataNumReg(pDataTable->AddNumReg(NUMREG_INT, 1, 100)); //
	pNumReg2 = new _DataNumReg(pDataTable->AddNumReg(NUMREG_REAL, 6, 10));
	pPosReg = new _DataPosReg(pDataTable->AddPosReg(POSREG, 1, 1, 10));
	pPosReg2 = new _DataPosReg(pDataTable->AddPosReg(POSREG, 2, 1, 5));
	pPosRegXyzwpr = new _DataPosRegXyzwpr(pDataTable->AddPosRegXyzwpr(POSREG_XYZWPR, 1, 1, 5));
	pPosRegMG = new _DataPosRegMG(pDataTable->AddPosRegMG(POSREGMG, _T("C,J6"), 1, 5));
	pSysVarInt = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_INT, _T("$FAST_CLOCK")));
	pSysVarInt2 = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_INT, _T("$TIMER[10].$TIMER_VAL")));
	pSysVarReal = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$MOR_GRP[1].$CURRENT_ANG[1]")));
	pSysVarReal2 = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$DUTY_TEMP")));
	pSysVarString = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_STRING, _T("$TIMER[10].$COMMENT")));
	pSysVarPos = new _DataSysVarPos(pDataTable->AddSysVarPos(SYSVAR_POS, _T("$MNUTOOL[1,1]")));
	pVarString = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_STRING, _T("$[HTTPKCL]CMDS[1]")));
	pTask = new _DataTask(pDataTable->AddTask(TASK, 1));
	pStrReg = new _DataString(pDataTable->AddString(STRREG, 1, 5));
	pSysVarForce[0] = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$CCC_GRP[1].$FS_FORCE[1]")));
	pSysVarForce[1] = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$CCC_GRP[1].$FS_FORCE[2]")));
	pSysVarForce[2] = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$CCC_GRP[1].$FS_FORCE[3]")));
	pSysVarForce[3] = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$CCC_GRP[1].$FS_FORCE[4]")));
	pSysVarForce[4] = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$CCC_GRP[1].$FS_FORCE[5]")));
	pSysVarForce[5] = new _DataSysVar(pDataTable->AddSysVar(SYSVAR_REAL, _T("$CCC_GRP[1].$FS_FORCE[6]")));

	pCore->SetTimeOutValue(1000);

	// Connect to the robot
	h_result = pCore->Connect(ipAddress);
	this->ip_address = ipAddress;

	if (h_result) {
		this->connected = true;
		printf("___INFO___: FANUC robot connection success. \n");
	}
	else
	{
		this->connected = false;
		printf("___ERROR___: FANUC robot connection failed! \n");
	}
	return h_result;
}

// Disconnect robot
void Fanuc::disconnect()
{
	if (this->connected) {
		this->connected = false;
		pCore->Disconnect();
		clearVars();
		printf("___INFO___: FANUC robot disconnected. \n");
	}
}

void Fanuc::__reset_connection() {
	disconnect();
	connect(this->ip_address);
}

// Clear variables
void Fanuc::clearVars()
{
	if (pCore) delete pCore;
	pCore = NULL;
	if (pLibCore) delete pLibCore;
	pLibCore = NULL;
	if (pDataTable) delete pDataTable;
	pDataTable = NULL;
	if (pDataTable2) delete pDataTable2;
	pDataTable2 = NULL;
	if (pAlarm) delete pAlarm;
	pAlarm = NULL;
	if (pAlarmCurrent) delete pAlarmCurrent;
	pAlarmCurrent = NULL;
	if (pCurPos) delete pCurPos;
	pCurPos = NULL;
	if (pCurPosUF) delete pCurPosUF;
	pCurPosUF = NULL;
	if (pNumReg) delete pNumReg;
	pNumReg = NULL;
	if (pNumReg2) delete pNumReg2;
	pNumReg2 = NULL;
	if (pNumReg3) delete pNumReg3;
	pNumReg3 = NULL;
	if (pPosReg) delete pPosReg;
	pPosReg = NULL;
	if (pPosReg2) delete pPosReg2;
	pPosReg2 = NULL;
	if (pPosRegXyzwpr) delete pPosRegXyzwpr;
	pPosRegXyzwpr = NULL;
	if (pPosRegMG) delete pPosRegMG;
	pPosRegMG = NULL;
	if (pSysVarInt) delete pSysVarInt;
	pSysVarInt = NULL;
	if (pSysVarInt2) delete pSysVarInt2;
	pSysVarInt2 = NULL;
	if (pSysVarReal) delete pSysVarReal;
	pSysVarReal = NULL;
	if (pSysVarReal2) delete pSysVarReal2;
	pSysVarReal2 = NULL;
	if (pSysVarString) delete pSysVarString;
	pSysVarString = NULL;
	if (pVarString) delete pVarString;
	pVarString = NULL;
	if (pSysVarPos) delete pSysVarPos;
	pSysVarPos = NULL;
	if (pTask) delete pTask;
	pTask = NULL;
	if (pStrReg) delete pStrReg;
	pStrReg = NULL;
	for (int ii = 0; ii <= 9; ii++)
	{
		if (pSysVarIntArray[ii]) delete pSysVarIntArray[ii];
		pSysVarIntArray[ii] = NULL;
	}
}

void Fanuc::refresh()
{
	if (!this->connected) return;
	pDataTable->Refresh();
}

// Set digital out:
void Fanuc::set_sdo(int num, int state)
{
	if (!this->connected) return;
	pLibCore->ReadSDO(1, current_sdo_state, 20);
	current_sdo_state[num - 1] = state;
	pLibCore->WriteSDO(1, current_sdo_state, 20);
}

// Read digital out value:
int Fanuc::read_sdo(int num)
{
	if (!this->connected) return 0;
	pLibCore->ReadSDO(1, current_sdo_state, 20);
	return current_sdo_state[num - 1];
}

// Set digital out:
void Fanuc::set_sdo2(int num, int state)
{
	if (!this->connected) return;
	pLibCore->ReadSDO(2, current_sdo2_state, 30);
	current_sdo2_state[num - 1] = state;
	pLibCore->WriteSDO(2, current_sdo2_state, 30);
}

// Read digital out value:
int Fanuc::read_sdo2(int num)
{
	if (!this->connected) return 0;
	pLibCore->ReadSDO(2, current_sdo2_state, 20);
	return current_sdo2_state[num - 1];
}

// Set robot ouput:
void Fanuc::set_rdo(int num, int state)
{
	short current_rdo_state[8];
	if (!this->connected) return;
	pLibCore->ReadRDO(1, current_rdo_state, 8);
	current_rdo_state[num - 1] = state;
	pLibCore->WriteRDO(1, current_rdo_state, 8);
}

// Set robot ouput state:
int Fanuc::read_rdo(int num)
{
	short current_rdo_state[8];
	if (!this->connected) return 0;
	pLibCore->ReadRDO(1, current_rdo_state, 8);
	return current_rdo_state[num - 1];
}

// Set Numeric Register:
void Fanuc::set_numreg(int num, int val)
{
	long new_val = val;
	if (!this->connected) return;
	pNumReg->SetValuesInt(num, &new_val, 1);
}

// Read Numeric Register:
int Fanuc::read_numreg(int num)
{
	long data_reg[100];
	COleVariant *pVal;
	pVal = new COleVariant();

	for (int i = 0; i < 100; i++)
	{
		pNumReg->GetValue(i + 1, pVal);
		data_reg[i] = pVal->intVal;
	}
	return 0;
}

// Read Position Register:
DataPos Fanuc::read_posreg(int num)
{	
	DataPos pos;
	float E1, E2, E3;
	short ValidC;

	if (!this->connected) return pos;
	// Read register position :
	h_result = pPosReg->GetValueXyzwpr(num,
		&pos.X, &pos.Y, &pos.Z, &pos.W, &pos.P, &pos.R, &E1, &E2, &E3,
		&pos.C1, &pos.C2, &pos.C3, &pos.C4, &pos.C5, &pos.C6, &pos.C7, &pos.UF, &pos.UT,&ValidC
	);

	if (!h_result) {
		printf("___ERROR___: Read position register  PR[%d] error. \n", num);
	}
	return pos;
}

// Set Position Register:
void Fanuc::set_posreg(int num, DataPos pos)
{
	if (!this->connected) return;
	h_result = pPosReg->SetValueXyzwpr2(num, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R, 0, 0, 0,
		pos.C1, pos.C2, pos.C3, pos.C4, pos.C5, pos.C6, pos.C7, 2, 1);
	if (!h_result)
		printf("___ERROR___: Set position register PR[%d] error.\n", num);
}

// Set Joint Position Register:
void Fanuc::set_jointreg(int num, float J[6])
{
	if (!this->connected) return;
	h_result = pPosReg->SetValueJoint2(num, J[0], J[1], J[2], J[3], J[4], J[5], 0, 0, 0, -1, -1);
	if (!h_result)
		printf("___ERROR___: Set joint position register PR[%d] error.\n", num);
}

// Read Joint Position Register:
void Fanuc::read_joint_posreg(int num, float J[6]) 
{
	float J6, J7, J8;
	short UF, UT, ValidJ;
	if (!this->connected) return;
	h_result = pPosReg->GetValueJoint(num, &J[0], &J[1], &J[2], &J[3], &J[4], &J[5], &J6, &J7, &J8, &UT, &ValidJ);
	if (!h_result)
		printf("___ERROR___: Read joint position register PR[%d] error.\n", num);
}

// Read Current WORLD FRAME pos:
DataPos Fanuc::read_currentPos()
{
	float E1, E2, E3;
	short ValidC;
	DataPos pos;

	if (!this->connected) return pos;
	// Current world coordinates frame:
	h_result = pCurPos->GetValueXyzwpr(
		&pos.X, &pos.Y, &pos.Z, &pos.W, &pos.P, &pos.R, &E1, &E2, &E3,
		&pos.C1, &pos.C2, &pos.C3, &pos.C4, &pos.C5, &pos.C6, &pos.C7, &pos.UF, &pos.UT, &ValidC
	);
	if (!h_result) {
		printf("___ERROR___: Read current position error.\n");
		__reset_connection();
	}
	current_pos = pos;
	return pos;
}

// Read Current USER FRAME pos:
DataPos Fanuc::read_currentPosUF()
{
	float E1, E2, E3;
	short ValidC;
	DataPos pos;

	if (!this->connected) return pos;
	// Current world coordinates frame:
	h_result = pCurPosUF->GetValueXyzwpr(
		&pos.X, &pos.Y, &pos.Z, &pos.W, &pos.P, &pos.R, &E1, &E2, &E3,
		&pos.C1, &pos.C2, &pos.C3, &pos.C4, &pos.C5, &pos.C6, &pos.C7, &pos.UF, &pos.UT, &ValidC
	);
	if (!h_result) {
		printf("___ERROR___: Read current position error.\n");
		__reset_connection();
	}
		current_pos = pos;
	return pos;
}

// Read WORLD FRAME Joint Position Register:
void Fanuc::read_currentJoint(float J[6])
{
	float J6, J7, J8;
	short UF, UT, ValidJ;
	if (!this->connected) return;
	h_result = pCurPos->GetValueJoint(&J[0], &J[1], &J[2], &J[3], &J[4], &J[5], &J6, &J7, &J8, &UT, &ValidJ);
	if (!h_result) {
		printf("___ERROR___: Read current joint position error.\n");
		__reset_connection();
	}
}

// Read USER FRAME Joint Position Register:
void Fanuc::read_currentJointUF(float J[6])
{
	float J6, J7, J8;
	short UF, UT, ValidJ;
	if (!this->connected) return;
	h_result = pCurPosUF->GetValueJoint(&J[0], &J[1], &J[2], &J[3], &J[4], &J[5], &J6, &J7, &J8, &UT, &ValidJ);
	if (!h_result)
		printf("___ERROR___: Read current joint position error.\n");
}

// Read Forces Sensor:
DataForce Fanuc::read_forces()
{
	DataForce force;
	if (!this->connected) return force;
	COleVariant *pVal;
	pVal = new COleVariant();
	pSysVarForce[0]->GetValue(pVal); force.Fx = pVal->fltVal;
	pSysVarForce[1]->GetValue(pVal); force.Fy = pVal->fltVal;
	pSysVarForce[2]->GetValue(pVal); force.Fz = pVal->fltVal;
	pSysVarForce[3]->GetValue(pVal); force.Mx = pVal->fltVal;
	pSysVarForce[4]->GetValue(pVal); force.My = pVal->fltVal;
	pSysVarForce[5]->GetValue(pVal); force.Mz = pVal->fltVal;
	return force;
}

// Read program status:
int Fanuc::read_programState()
{
	if (!this->connected) return 0;
	short LineNumber, State;
	BSTR progname, parentprogname;
	CString strTmp = _T("                                                ");
	progname = strTmp.AllocSysString();
	parentprogname = strTmp.AllocSysString();
	pTask->GetValue(&progname, &LineNumber, &State, &parentprogname);

	this->current_status = State;
	this->current_lineNumber = LineNumber;
	this->current_progname = progname;

	return State;
}

// Set Override:
void Fanuc::set_override(int val)
{
	if (!this->connected) return;
	set_numreg(ROBOT_REG_OVERRIDE, val);
	set_sdo(ROBOT_SDO_OVERRIDE, ON);
}

// Check the moving status:
bool Fanuc::check_moving_status()
{
	if (!connected) return false;
	// Moving status register is mapped from SDO 1 - 4
	short states[5];
	h_result = pLibCore->ReadSDO(1, states, 5);

	// If all of the moving pin is OFF, moving state = FALSE
	this->isMoving = false;
	for (int i = 0; i < 4; i++)
	{
		if (states[i] == 1)
			this->isMoving = true;
	}
	return isMoving;
}

// Set data pos:
DataPos	convert_to_datapos(float src[12])
{
	DataPos pos;
	pos.X = src[0];
	pos.Y = src[1];
	pos.Z = src[2];
	pos.W = src[3];
	pos.P = src[4];
	pos.R = src[5];
	pos.C1 = src[6];
	pos.C2 = 0;
	pos.C3 = src[7];
	pos.C4 = src[8];
	pos.C5 = src[9];
	pos.C6 = src[10];
	pos.C7 = src[11];
	pos.UF = -1;
	pos.UT = -1;

	return pos;
}

// 
DataPos	posarray_to_datapos(float src[12])
{
	DataPos pos;
	pos.X = src[0];
	pos.Y = src[1];
	pos.Z = src[2];
	pos.W = src[3];
	pos.P = src[4];
	pos.R = src[5];
	pos.C1 = src[6];
	pos.C2 = 0;
	pos.C3 = src[7];
	pos.C4 = src[8];
	pos.C5 = src[9];
	pos.C6 = src[10];
	pos.C7 = src[11];
	pos.UF = -1;
	pos.UT = -1;

	return pos;
}

void datapos_to_posarray(DataPos pos, float new_pos[12]) 
{
	new_pos[0] = pos.X;
	new_pos[1] = pos.Y;
	new_pos[2] = pos.Z;
	new_pos[3] = pos.W;
	new_pos[4] = pos.P;
	new_pos[5] = pos.R;
	new_pos[6] = pos.C1;
	new_pos[7] = pos.C3;
	new_pos[8] = pos.C4;
	new_pos[9] = pos.C5;
	new_pos[10] = pos.C6;
	new_pos[11] = pos.C7;
}

// -- Robot movement function --
// //////////////////////////////////////////////////////
// Move Linear FINE
void Fanuc::moveL(DataPos pos, int acc, int motion)
{
	set_numreg(ROBOT_REG_CNT, 100);
	set_numreg(ROBOT_REG_ACC, acc);
	set_posreg(ROBOT_POSREG_XYZWPR, pos);
	if (motion == CNT)
		set_sdo(ROBOT_SDO_MOVEL_CNT, ON);
	else if (motion == FINE)
		set_sdo(ROBOT_SDO_MOVEL_FINE, ON);
}

// Move Linear CNT
void Fanuc::moveL(DataPos pos, int acc, int motion, int cnt_val)
{
	set_numreg(ROBOT_REG_CNT, cnt_val);
	set_numreg(ROBOT_REG_ACC, acc);
	set_posreg(ROBOT_POSREG_XYZWPR, pos);
	if (motion == CNT)
		set_sdo(ROBOT_SDO_MOVEL_CNT, ON);
	else if (motion == FINE)
		set_sdo(ROBOT_SDO_MOVEL_FINE, ON);
}

// Move Joint FINE
void Fanuc::moveJ(DataPos pos, int acc, int motion)
{
	set_numreg(ROBOT_REG_CNT, 100);
	set_numreg(ROBOT_REG_ACC, acc);
	set_posreg(ROBOT_POSREG_XYZWPR, pos);
	if (motion == CNT)
		set_sdo(ROBOT_SDO_MOVEJ_CNT, ON);
	else if (motion == FINE)
		set_sdo(ROBOT_SDO_MOVEJ_FINE, ON);
}

// Move Joint CNT
void Fanuc::moveJ(DataPos pos, int acc, int motion, int cnt_val)
{
	set_numreg(ROBOT_REG_CNT, cnt_val);
	set_numreg(ROBOT_REG_ACC, acc);
	set_posreg(ROBOT_POSREG_XYZWPR, pos);
	if (motion == CNT)
		set_sdo(ROBOT_SDO_MOVEJ_CNT, ON);
	else if (motion == FINE)
		set_sdo(ROBOT_SDO_MOVEJ_FINE, ON);
}

// Move joint mode:
void Fanuc::move_joint(float joint[6], int acc)
{
	set_numreg(ROBOT_REG_ACC, acc);
	set_jointreg(ROBOT_POSREG_JOINT, joint);
	set_sdo(ROBOT_SDO_MOVE_JOINT, ON);
}


// -- Robot TOOL functions --
// //////////////////////////////////////////////////////////
void Fanuc::ATC_lock(){
	set_rdo(ROBOT_RO_ATC, OFF);
}

void Fanuc::ATC_unlock(){
	set_rdo(ROBOT_RO_ATC, ON);
}

// Gripper Catch and Release:
void Fanuc::gripper_ON() {
	set_rdo(ROBOT_RO_GRIPPER_CLOSE, OFF);
	Sleep(30);
	set_rdo(ROBOT_RO_GRIPPER_OPEN, ON);
}
void Fanuc::gripper_OFF() {
	set_rdo(ROBOT_RO_GRIPPER_OPEN, OFF);
	Sleep(30);
	set_rdo(ROBOT_RO_GRIPPER_CLOSE, ON);
}

// --- Homogenious Transformation ---
void Fanuc::Homogenious(float input_pose[12], float out_pose[12], float delta[6])
{
	for (int i = 0; i < 12; i++)
		out_pose[i] = input_pose[i];

	float rx = input_pose[3] * PI / 180;
	float ry = input_pose[4] * PI / 180;
	float rz = input_pose[5] * PI / 180;

	float m[4][4];
	m[0][0] = cos(ry)*cos(rz);
	m[0][1] = -sin(rz)*cos(rx) + cos(rz)*sin(ry)*sin(rx);
	m[0][2] = sin(rz)*sin(rx) + cos(rz)*sin(ry)*cos(rx);
	m[0][3] = input_pose[0];

	m[1][0] = sin(rz)*cos(ry);
	m[1][1] = cos(rz)*cos(rx) + sin(rz)*sin(ry)*sin(rx);
	m[1][2] = -cos(rz)*sin(rx) + sin(rz)*sin(ry)*cos(rx);
	m[1][3] = input_pose[1];

	m[2][0] = -sin(ry);
	m[2][1] = cos(ry)*sin(rx);
	m[2][2] = cos(ry)*cos(rx);
	m[2][3] = input_pose[2];

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;

	rx = delta[3] * PI / 180;
	ry = delta[4] * PI / 180;
	rz = delta[5] * PI / 180;

	float p[4][4];
	p[0][0] = cos(ry)*cos(rz);
	p[0][1] = -sin(rz)*cos(rx) + cos(rz)*sin(ry)*sin(rx);
	p[0][2] = sin(rz)*sin(rx) + cos(rz)*sin(ry)*cos(rx);
	p[0][3] = delta[0];

	p[1][0] = sin(rz)*cos(ry);
	p[1][1] = cos(rz)*cos(rx) + sin(rz)*sin(ry)*sin(rx);
	p[1][2] = -cos(rz)*sin(rx) + sin(rz)*sin(ry)*cos(rx);
	p[1][3] = delta[1];

	p[2][0] = -sin(ry);
	p[2][1] = cos(ry)*sin(rx);
	p[2][2] = cos(ry)*cos(rx);
	p[2][3] = delta[2];

	p[3][0] = 0;
	p[3][1] = 0;
	p[3][2] = 0;
	p[3][3] = 1;

	float r[4][4];
	// x
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			r[i][j] = 0;
			for (int k = 0; k<4; k++)
			{
				r[i][j] += m[i][k] * p[k][j];
			}
		}
	}
	if (r[2][0] < 1)
	{
		if (r[2][0] > -1)
		{
			ry = asin(-r[2][0]);
			rz = atan2(r[1][0], r[0][0]);
			rx = atan2(r[2][1], r[2][2]);
		}
		else//=-1
		{
			ry = PI / 2;
			rz = -atan2(-r[1][2], r[1][1]);
			rx = 0;//rz/20170305
		}
	}
	else//=1
	{
		ry = -PI / 2;
		rz = atan2(-r[1][2], r[1][1]);
		rx = 0;
	}
	out_pose[0] = r[0][3];
	out_pose[1] = r[1][3];
	out_pose[2] = r[2][3];
	out_pose[3] = rx * 180 / PI;
	out_pose[4] = ry * 180 / PI;
	out_pose[5] = rz * 180 / PI;
	//	if (h[3] <= -180)
	//		h[3] += 360;
	//	if (h[4] <= -180)e
	//		h[4] += 360;
	//	if (h[5] <= -180)
	//		h[6] += 360;

}
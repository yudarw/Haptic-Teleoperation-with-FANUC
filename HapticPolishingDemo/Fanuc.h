#pragma once
#ifndef  __FANUC_H__
#define __FANUC_H__

#include "frrjif.h"
#include "frrobotiflib.h"

// Digital Output Trigger: 		[DO]
#define ROBOT_SDO_MOVEL_CNT		1
#define ROBOT_SDO_MOVEL_FINE	2
#define ROBOT_SDO_MOVEJ_CNT		3
#define ROBOT_SDO_MOVEJ_FINE	4
#define ROBOT_SDO_MOVE_JOINT	5
#define ROBOT_SDO_OVERRIDE		6
// Robot Output:				[RO]
#define ROBOT_RO_ATC			1
#define ROBOT_RO_GRIPPER_OPEN	2
#define ROBOT_RO_GRIPPER_CLOSE	3
#define ROBOT_RO_TOOL_ON		4
// Position Register:			[PR]
#define ROBOT_POSREG_XYZWPR		1
#define ROBOT_POSREG_JOINT		2
// Num Register				   [R]
#define ROBOT_REG_CNT			20
#define ROBOT_REG_ACC			21
#define ROBOT_REG_OVERRIDE		22
// State:
#define ON						1
#define OFF						0
#define CNT						0
#define FINE					1
#define MOVE_L					2
#define MOVE_J					3
#define MOVE_JOINT				4
// Robot Config:
#define _F_						1	 
#define _L_						1
#define _U_						1
#define _T_						1
#define _N_						0
#define _R_						0
#define _D_						0	
#define _B_						0

#define PI 3.141592

typedef struct {
	float X, Y, Z, W, P, R;
	short C1, C2, C3, C4, C5, C6, C7, UF, UT;
}DataPos;

typedef struct {
	float Fx, Fy, Fz, Mx, My, Mz;
}DataForce;

extern DataPos	convert_to_datapos(float src[12]);
extern DataPos  posarray_to_datapos(float stc[12]);
extern void datapos_to_posarray(DataPos pos, float new_pos[12]);

class Fanuc
{
public:
	ILibCore		*pLibCore;
	_Core			*pCore;
	_DataTable		*pDataTable;
	_DataTable		*pDataTable2;
	_DataAlarm		*pAlarm;
	_DataAlarm		*pAlarmCurrent;
	_DataCurPos		*pCurPos;
	_DataCurPos		*pCurPosUF;
	_DataNumReg		*pNumReg;
	_DataNumReg		*pNumReg2;
	_DataNumReg		*pNumReg3;
	_DataPosReg		*pPosReg;
	_DataPosReg		*pPosReg2;
	_DataPosRegXyzwpr *pPosRegXyzwpr;
	_DataPosRegMG	*pPosRegMG;
	_DataTask		*pTask;
	_DataSysVar		*pSysVarInt;
	_DataSysVar		*pSysVarInt2;
	_DataSysVar		*pSysVarReal;
	_DataSysVar		*pSysVarReal2;
	_DataSysVar		*pSysVarString;
	_DataSysVarPos	*pSysVarPos;
	_DataSysVar		*pSysVarIntArray[10];
	_DataSysVar		*pVarString;
	_DataString		*pStrReg;
	_DataSysVar		*pSysVarForce[6];

public:
	BOOL h_result;
	BOOL connected;
	DataPos current_pos;
	BOOL isMoving;
	BOOL dataIsValid;
	DataPos goal_position;
	float current_joint[6];
	float dst_joint[6];
	short current_sdo_state[20];
	short current_sdo2_state[30];

	// Trigger Flag:
	BOOL doMoving;
	BOOL doAttachTool;
	BOOL doDetacthTool;
	BOOL doGripperON;
	BOOL doGripperOFF;
	BOOL doToolTurnON;
	BOOL doToolTurnOFF;
	BOOL doSetOvrr;

	int _moving_mode;
	int _motion_type;
	int _cnt_val;
	int _acc_val;
	int _override_val;

	BSTR current_progname;
	short current_lineNumber;
	int current_status;

	CString ip_address;

public:
	int		connect(CString ipAddress);
	void	disconnect();
	void	refresh();

	// Read:
	int		read_sdo(int num);
	int		read_sdo2(int num);
	int		read_rdo(int num);
	int		read_numreg(int num);
	DataPos	read_posreg(int num);
	DataPos	read_currentPos();
	DataPos	read_currentPosUF();
	void	read_currentJoint(float joint[6]);
	void	read_currentJointUF(float joint[6]);
	void	read_joint_posreg(int num, float joint[6]);
	DataForce	read_forces();
	int		read_programState();

	// Write:
	void	set_sdo(int num, int state);
	void	set_sdo2(int num, int state);
	void	set_rdo(int num, int state);
	void	set_numreg(int num, int val);
	void	set_posreg(int num, DataPos pos);
	void	set_jointreg(int num, float joint[6]);
	void	set_override(int val);
	

	// Movement function:
	bool	check_moving_status();
	void	moveL(DataPos pos, int acc, int motion_type );
	void	moveL(DataPos pos, int acc, int motion_cnt, int cnt_val);
	void	moveJ(DataPos pos, int acc, int motion_type);
	void	moveJ(DataPos pos, int acc, int motion_cnt, int cnt_val);
	void	move_joint(float joint[6], int acc);

	// Tools:
	void	ATC_lock();
	void	ATC_unlock();
	void	gripper_ON();
	void	gripper_OFF();

	void    Homogenious(float input_pose[12], float out_pose[12], float delta[6]);


private:
	void clearVars();
	void __reset_connection();
};
#endif // ! __FANUC_H__

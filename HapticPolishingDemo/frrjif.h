// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _Core wrapper class
#include "StdAfx.h"

#define	NUMREG_INT		0
#define	NUMREG_REAL		1
#define	POSREG			2
#define	CURPOS			3
#define	TASK			4
#define	SYSVAR_INT		5
#define	SYSVAR_REAL		6
#define	SYSVAR_POS		7
#define	SYSVAR_STRING	8
#define	ALARM_LIST		9
#define	ALARM_CURRENT	10
#define	ALARM_PASSWORD	11
#define	POSREG_XYZWPR	12
#define	STRREG			13
#define	STRREG_COMMENT	14
#define	NUMREG_COMMENT	15
#define	POSREG_COMMENT	16
#define	SDI_COMMENT		17
#define	SDO_COMMENT		18
#define	RDI_COMMENT		19
#define	RDO_COMMENT		20
#define	UI_COMMENT		21
#define	UO_COMMENT		22
#define	SI_COMMENT		23
#define	SO_COMMENT		24
#define	WI_COMMENT		25
#define	WO_COMMENT		26
#define	WSI_COMMENT		27
#define	WSO_COMMENT		28
#define	GI_COMMENT		29
#define	GO_COMMENT		30
#define	AI_COMMENT		31
#define	AO_COMMENT		32
#define	TASK_IGNORE_MACRO			33
#define	TASK_IGNORE_KAREL			34
#define	TASK_IGNORE_MACRO_KAREL		35
#define	POSREGMG		36

class _Core : public COleDispatchDriver
{
public:
	_Core() {}		// Calls COleDispatchDriver default constructor
	_Core(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Core(const _Core& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetObjectID();
	BOOL Connect(LPCTSTR HostName);
	BOOL Disconnect();
	BOOL ClearAlarm(long vlngType);
	LPDISPATCH GetDataTable();
	LPDISPATCH GetDataTable2();
	BOOL GetProtectAvailable();
	long GetProtectTrialRemainDays();
	CString GetProtectStatus();
	long GetProtectErrorNumber();
	CString GetProtectPCID();
	BOOL ProtectSetPassword(LPCTSTR strPassword);
	long GetTimeOutValue();
	void SetTimeOutValue(long nNewValue);
	long GetMlngDataTableCount();
	long GetPortNumber();
	void SetPortNumber(long nNewValue);
	short GetClientID();
	void SetClientID(short nNewValue);
	BOOL GetIsConnected();
	CString GetDebugMessage();
	CString GetDebugMessages();
	long GetConnectState();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
	void SetDebugLog(BOOL bNewValue);
	LPDISPATCH GetLib();
};
/////////////////////////////////////////////////////////////////////////////
// _DataTable wrapper class

class _DataTable : public COleDispatchDriver
{
public:
	_DataTable() {}		// Calls COleDispatchDriver default constructor
	_DataTable(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataTable(const _DataTable& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	BOOL Clear();
	BOOL Refresh();
	long Count();
	LPDISPATCH Item(const VARIANT& Index);
	LPDISPATCH AddNumReg(long DataType, long StartIndex, long EndIndex);
	LPDISPATCH AddPosReg(long DataType, long Group, long StartIndex, long EndIndex);
	LPDISPATCH AddPosRegXyzwpr(long DataType, long Group, long StartIndex, long EndIndex);
	LPDISPATCH AddPosRegMG(long DataType, LPCTSTR Group, long StartIndex, long EndIndex);
	LPDISPATCH AddCurPos(long DataType, long Group);
	LPDISPATCH AddCurPosUF(long DataType, long Group, long UF);
	LPDISPATCH AddTask(long DataType, long Index);
	LPDISPATCH AddSysVarPos(long DataType, LPCTSTR SysVarName);
	LPDISPATCH AddSysVar(long DataType, LPCTSTR SysVarName);
	LPDISPATCH AddAlarm(long DataType, long AlarmCount, long AlarmMessageMode);
	BOOL GetLastDataFloat(long lngAddress, float* sngValue);
	BOOL GetFixed();
	long GetObjectID();
	BOOL GetValid();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
	LPDISPATCH AddString(long DataType, long StartIndex, long EndIndex);
	LPDISPATCH AddStringEx(long DataType, LPCTSTR DataSymbol, long StartIndex, long EndIndex);
};
/////////////////////////////////////////////////////////////////////////////
// _DataPosReg wrapper class

class _DataPosReg : public COleDispatchDriver
{
public:
	_DataPosReg() {}		// Calls COleDispatchDriver default constructor
	_DataPosReg(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataPosReg(const _DataPosReg& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetGroup();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValueXyzwpr(long Index, float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7, short* UF, short* UT, short* validc);
	BOOL GetValueJoint(long Index, float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9, short* UT, short* ValidJ);
	BOOL SetValueJoint2(long Index, float J1, float J2, float J3, float J4, float J5, float J6, float J7, float J8, float J9, short UF, short UT);
	BOOL SetValueXyzwpr2(long Index, float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7, short UF, short UT);
	long GetStartIndex();
	long GetEndIndex();
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataAlarm wrapper class

class _DataAlarm : public COleDispatchDriver
{
public:
	_DataAlarm() {}		// Calls COleDispatchDriver default constructor
	_DataAlarm(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataAlarm(const _DataAlarm& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValue(long Count, short* AlarmID, short* AlarmNumber, short* CauseAlarmID, short* CauseAlarmNumber, short* Severity, short* Year, short* Month, short* Day, short* Hour, short* Minute, short* Second, BSTR* AlarmMessage, 
		BSTR* CauseAlarmMessage, BSTR* SeverityMessage);
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataSysVarPos wrapper class

class _DataSysVarPos : public COleDispatchDriver
{
public:
	_DataSysVarPos() {}		// Calls COleDispatchDriver default constructor
	_DataSysVarPos(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataSysVarPos(const _DataSysVarPos& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValueXyzwpr(float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7, short* UF, short* UT, short* ValidC);
	BOOL GetValueJoint(float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9, short* UT, short* ValidJ);
	CString GetSysVarName();
	BOOL SetValueJoint2(float J1, float J2, float J3, float J4, float J5, float J6, float J7, float J8, float J9, short UF, short UT);
	BOOL SetValueXyzwpr2(float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7, short UF, short UT);
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataNumReg wrapper class

class _DataNumReg : public COleDispatchDriver
{
public:
	_DataNumReg() {}		// Calls COleDispatchDriver default constructor
	_DataNumReg(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataNumReg(const _DataNumReg& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetStartIndex();
	long GetEndIndex();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValue(long Index, VARIANT* Value);
	BOOL SetValue(long Index, const VARIANT& Value);
	BOOL SetValuesInt(long Index, long* Value, long Count);
	BOOL SetValuesReal(long Index, float* Value, long Count);
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataTask wrapper class

class _DataTask : public COleDispatchDriver
{
public:
	_DataTask() {}		// Calls COleDispatchDriver default constructor
	_DataTask(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataTask(const _DataTask& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetIndex();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValue(BSTR* ProgName, short* LineNumber, short* State, BSTR* ParentProgName);
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataCurPos wrapper class

class _DataCurPos : public COleDispatchDriver
{
public:
	_DataCurPos() {}		// Calls COleDispatchDriver default constructor
	_DataCurPos(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataCurPos(const _DataCurPos& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetGroup();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValueXyzwpr(float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7, short* UF, short* UT, short* validc);
	BOOL GetValueJoint(float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9, short* UT, short* ValidJ);
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataSysVar wrapper class

class _DataSysVar : public COleDispatchDriver
{
public:
	_DataSysVar() {}		// Calls COleDispatchDriver default constructor
	_DataSysVar(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataSysVar(const _DataSysVar& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValue(VARIANT* Value);
	CString GetSysVarName();
	BOOL SetValue(const VARIANT& Value);
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataPosRegXyzwpr wrapper class

class _DataPosRegXyzwpr : public COleDispatchDriver
{
public:
	_DataPosRegXyzwpr() {}		// Calls COleDispatchDriver default constructor
	_DataPosRegXyzwpr(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataPosRegXyzwpr(const _DataPosRegXyzwpr& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetGroup();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL SetValueXyzwpr2(long Index, float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7);
	BOOL Update();
	long GetStartIndex();
	long GetEndIndex();
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
	void Reset();
};
/////////////////////////////////////////////////////////////////////////////
// _DataString wrapper class

class _DataString : public COleDispatchDriver
{
public:
	_DataString() {}		// Calls COleDispatchDriver default constructor
	_DataString(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataString(const _DataString& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetStartIndex();
	long GetEndIndex();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	BOOL GetValue(long Index, BSTR* Value);
	BOOL SetValue(long Index, LPCTSTR Value);
	BOOL Update();
	void Reset();
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
};
/////////////////////////////////////////////////////////////////////////////
// _DataPosRegMG wrapper class

class _DataPosRegMG : public COleDispatchDriver
{
public:
	_DataPosRegMG() {}		// Calls COleDispatchDriver default constructor
	_DataPosRegMG(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_DataPosRegMG(const _DataPosRegMG& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDataType();
	long GetGroupCount();
	LPDISPATCH GetDataTable();
	BOOL GetValid();
	// method 'SetValueJoint' not emitted because of invalid return type or parameter type
	BOOL SetValueJoint2(long Index, long Group, float J1, float J2, float J3, float J4, float J5, float J6, float J7, float J8, float J9);
	// method 'SetValueXyzwpr' not emitted because of invalid return type or parameter type
	BOOL SetValueXyzwpr2(long Index, long Group, float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7);
	BOOL Update();
	long GetStartIndex();
	long GetEndIndex();
	long GetObjectID();
	void Kill();
	CString GetTypeName();
	void AddUserMessage(LPCTSTR vstrMessage);
	BOOL GetDebugLog();
	void Reset();
	BOOL GetValueJoint(long Index, long Group, float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9);
	BOOL GetValueXyzwpr(long Index, long Group, float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7);
};

// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "frrjif.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// _Core properties

/////////////////////////////////////////////////////////////////////////////
// _Core operations

long _Core::GetObjectID()
{
	long result;
	InvokeHelper(0x6803002b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _Core::Connect(LPCTSTR HostName)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030006, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		HostName);
	return result;
}

BOOL _Core::Disconnect()
{
	BOOL result;
	InvokeHelper(0x60030007, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Core::ClearAlarm(long vlngType)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60030028, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		vlngType);
	return result;
}

LPDISPATCH _Core::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Core::GetDataTable2()
{
	LPDISPATCH result;
	InvokeHelper(0x68030023, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Core::GetProtectAvailable()
{
	BOOL result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _Core::GetProtectTrialRemainDays()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _Core::GetProtectStatus()
{
	CString result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long _Core::GetProtectErrorNumber()
{
	long result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _Core::GetProtectPCID()
{
	CString result;
	InvokeHelper(0x6803001e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Core::ProtectSetPassword(LPCTSTR strPassword)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030021, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		strPassword);
	return result;
}

long _Core::GetTimeOutValue()
{
	long result;
	InvokeHelper(0x6803001d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Core::SetTimeOutValue(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6803001d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Core::GetMlngDataTableCount()
{
	long result;
	InvokeHelper(0x68030022, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Core::GetPortNumber()
{
	long result;
	InvokeHelper(0x68030024, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Core::SetPortNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030024, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _Core::GetClientID()
{
	short result;
	InvokeHelper(0x68030025, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _Core::SetClientID(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x68030025, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Core::GetIsConnected()
{
	BOOL result;
	InvokeHelper(0x68030026, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _Core::GetDebugMessage()
{
	CString result;
	InvokeHelper(0x68030029, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _Core::GetDebugMessages()
{
	CString result;
	InvokeHelper(0x60030030, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

long _Core::GetConnectState()
{
	long result;
	InvokeHelper(0x68030031, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _Core::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030036, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Core::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030037, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _Core::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030038, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Core::SetDebugLog(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x68030038, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Core::GetLib()
{
	LPDISPATCH result;
	InvokeHelper(0x6003003d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataTable properties

/////////////////////////////////////////////////////////////////////////////
// _DataTable operations

BOOL _DataTable::Clear()
{
	BOOL result;
	InvokeHelper(0x60030003, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataTable::Refresh()
{
	BOOL result;
	InvokeHelper(0x60030004, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _DataTable::Count()
{
	long result;
	InvokeHelper(0x60030005, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataTable::Item(const VARIANT& Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x60030006, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		&Index);
	return result;
}

LPDISPATCH _DataTable::AddNumReg(long DataType, long StartIndex, long EndIndex)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60030007, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, StartIndex, EndIndex);
	return result;
}

LPDISPATCH _DataTable::AddPosReg(long DataType, long Group, long StartIndex, long EndIndex)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60030008, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, Group, StartIndex, EndIndex);
	return result;
}

LPDISPATCH _DataTable::AddPosRegXyzwpr(long DataType, long Group, long StartIndex, long EndIndex)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60030035, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, Group, StartIndex, EndIndex);
	return result;
}

LPDISPATCH _DataTable::AddPosRegMG(long DataType, LPCTSTR Group, long StartIndex, long EndIndex)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_I4 VTS_I4;
	InvokeHelper(0x60030048, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, Group, StartIndex, EndIndex);
	return result;
}

LPDISPATCH _DataTable::AddCurPos(long DataType, long Group)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x60030009, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, Group);
	return result;
}

LPDISPATCH _DataTable::AddCurPosUF(long DataType, long Group, long UF)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60030036, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, Group, UF);
	return result;
}

LPDISPATCH _DataTable::AddTask(long DataType, long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, Index);
	return result;
}

LPDISPATCH _DataTable::AddSysVarPos(long DataType, LPCTSTR SysVarName)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, SysVarName);
	return result;
}

LPDISPATCH _DataTable::AddSysVar(long DataType, LPCTSTR SysVarName)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, SysVarName);
	return result;
}

LPDISPATCH _DataTable::AddAlarm(long DataType, long AlarmCount, long AlarmMessageMode)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, AlarmCount, AlarmMessageMode);
	return result;
}

BOOL _DataTable::GetLastDataFloat(long lngAddress, float* sngValue)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PR4;
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		lngAddress, sngValue);
	return result;
}

BOOL _DataTable::GetFixed()
{
	BOOL result;
	InvokeHelper(0x68030013, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _DataTable::GetObjectID()
{
	long result;
	InvokeHelper(0x68030014, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _DataTable::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030015, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _DataTable::Kill()
{
	InvokeHelper(0x60030022, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataTable::GetTypeName()
{
	CString result;
	InvokeHelper(0x6003002f, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataTable::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030030, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataTable::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030031, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataTable::AddString(long DataType, long StartIndex, long EndIndex)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60030043, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, StartIndex, EndIndex);
	return result;
}

LPDISPATCH _DataTable::AddStringEx(long DataType, LPCTSTR DataSymbol, long StartIndex, long EndIndex)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_I4 VTS_I4;
	InvokeHelper(0x60030044, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DataType, DataSymbol, StartIndex, EndIndex);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataPosReg properties

/////////////////////////////////////////////////////////////////////////////
// _DataPosReg operations

long _DataPosReg::GetDataType()
{
	long result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosReg::GetGroup()
{
	long result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataPosReg::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataPosReg::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataPosReg::GetValueXyzwpr(long Index, float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7, short* UF, short* UT, short* ValidC)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x6003001e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7, UF, UT, ValidC);
	return result;
}

BOOL _DataPosReg::GetValueJoint(long Index, float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9, short* UT, short* ValidJ)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2;
	InvokeHelper(0x6003001f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, J1, J2, J3, J4, J5, J6, J7, J8, J9, UT, ValidJ);
	return result;
}

BOOL _DataPosReg::SetValueJoint2(long Index, float J1, float J2, float J3, float J4, float J5, float J6, float J7, float J8, float J9, short UF, short UT)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I2 VTS_I2;
	InvokeHelper(0x60030020, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, J1, J2, J3, J4, J5, J6, J7, J8, J9, UF, UT);
	return result;
}

BOOL _DataPosReg::SetValueXyzwpr2(long Index, float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7, short UF, short UT)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x60030021, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7, UF, UT);
	return result;
}

long _DataPosReg::GetStartIndex()
{
	long result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosReg::GetEndIndex()
{
	long result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosReg::GetObjectID()
{
	long result;
	InvokeHelper(0x6803000c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataPosReg::Kill()
{
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataPosReg::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030018, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataPosReg::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030019, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataPosReg::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x6803001a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataAlarm properties

/////////////////////////////////////////////////////////////////////////////
// _DataAlarm operations

long _DataAlarm::GetDataType()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataAlarm::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataAlarm::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataAlarm::GetValue(long Count, short* AlarmID, short* AlarmNumber, short* CauseAlarmID, short* CauseAlarmNumber, short* Severity, short* Year, short* Month, short* Day, short* Hour, short* Minute, short* Second, BSTR* AlarmMessage, 
		BSTR* CauseAlarmMessage, BSTR* SeverityMessage)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PBSTR VTS_PBSTR VTS_PBSTR;
	InvokeHelper(0x60030006, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Count, AlarmID, AlarmNumber, CauseAlarmID, CauseAlarmNumber, Severity, Year, Month, Day, Hour, Minute, Second, AlarmMessage, CauseAlarmMessage, SeverityMessage);
	return result;
}

long _DataAlarm::GetObjectID()
{
	long result;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataAlarm::Kill()
{
	InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataAlarm::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030013, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataAlarm::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030014, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataAlarm::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030015, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataSysVarPos properties

/////////////////////////////////////////////////////////////////////////////
// _DataSysVarPos operations

long _DataSysVarPos::GetDataType()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataSysVarPos::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataSysVarPos::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataSysVarPos::GetValueXyzwpr(float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7, short* UF, short* UT, short* ValidC)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x6003001d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7, UF, UT, ValidC);
	return result;
}

BOOL _DataSysVarPos::GetValueJoint(float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9, short* UT, short* ValidJ)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2;
	InvokeHelper(0x6003001e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		J1, J2, J3, J4, J5, J6, J7, J8, J9, UT, ValidJ);
	return result;
}

CString _DataSysVarPos::GetSysVarName()
{
	CString result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _DataSysVarPos::SetValueJoint2(float J1, float J2, float J3, float J4, float J5, float J6, float J7, float J8, float J9, short UF, short UT)
{
	BOOL result;
	static BYTE parms[] =
		VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I2 VTS_I2;
	InvokeHelper(0x6003001f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		J1, J2, J3, J4, J5, J6, J7, J8, J9, UF, UT);
	return result;
}

BOOL _DataSysVarPos::SetValueXyzwpr2(float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7, short UF, short UT)
{
	BOOL result;
	static BYTE parms[] =
		VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x60030020, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7, UF, UT);
	return result;
}

long _DataSysVarPos::GetObjectID()
{
	long result;
	InvokeHelper(0x6803000d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataSysVarPos::Kill()
{
	InvokeHelper(0x60030011, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataSysVarPos::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030017, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataSysVarPos::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030018, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataSysVarPos::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030019, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataNumReg properties

/////////////////////////////////////////////////////////////////////////////
// _DataNumReg operations

long _DataNumReg::GetDataType()
{
	long result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataNumReg::GetStartIndex()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataNumReg::GetEndIndex()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataNumReg::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataNumReg::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataNumReg::GetValue(long Index, VARIANT* Value)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT;
	InvokeHelper(0x60030008, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Value);
	return result;
}

BOOL _DataNumReg::SetValue(long Index, const VARIANT& Value)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT;
	InvokeHelper(0x60030009, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, &Value);
	return result;
}

BOOL _DataNumReg::SetValuesInt(long Index, long* Value, long Count)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_I4;
	InvokeHelper(0x6003001b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Value, Count);
	return result;
}

BOOL _DataNumReg::SetValuesReal(long Index, float* Value, long Count)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PR4 VTS_I4;
	InvokeHelper(0x6003001c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Value, Count);
	return result;
}

long _DataNumReg::GetObjectID()
{
	long result;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataNumReg::Kill()
{
	InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataNumReg::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030014, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataNumReg::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030015, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataNumReg::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030016, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataTask properties

/////////////////////////////////////////////////////////////////////////////
// _DataTask operations

long _DataTask::GetDataType()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataTask::GetIndex()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataTask::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataTask::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataTask::GetValue(BSTR* ProgName, short* LineNumber, short* State, BSTR* ParentProgName)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PBSTR VTS_PI2 VTS_PI2 VTS_PBSTR;
	InvokeHelper(0x60030007, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		ProgName, LineNumber, State, ParentProgName);
	return result;
}

long _DataTask::GetObjectID()
{
	long result;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataTask::Kill()
{
	InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataTask::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataTask::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030013, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataTask::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030014, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataCurPos properties

/////////////////////////////////////////////////////////////////////////////
// _DataCurPos operations

long _DataCurPos::GetDataType()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataCurPos::GetGroup()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataCurPos::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataCurPos::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataCurPos::GetValueXyzwpr(float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7, short* UF, short* UT, short* ValidC)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x6003001b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7, UF, UT, ValidC);
	return result;
}

BOOL _DataCurPos::GetValueJoint(float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9, short* UT, short* ValidJ)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2;
	InvokeHelper(0x6003001c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		J1, J2, J3, J4, J5, J6, J7, J8, J9, UT, ValidJ);
	return result;
}

long _DataCurPos::GetObjectID()
{
	long result;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataCurPos::Kill()
{
	InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataCurPos::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030014, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataCurPos::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030015, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataCurPos::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030016, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataSysVar properties

/////////////////////////////////////////////////////////////////////////////
// _DataSysVar operations

long _DataSysVar::GetDataType()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataSysVar::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataSysVar::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataSysVar::GetValue(VARIANT* Value)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x60030007, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Value);
	return result;
}

CString _DataSysVar::GetSysVarName()
{
	CString result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _DataSysVar::SetValue(const VARIANT& Value)
{
	BOOL result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		&Value);
	return result;
}

long _DataSysVar::GetObjectID()
{
	long result;
	InvokeHelper(0x6803000c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataSysVar::Kill()
{
	InvokeHelper(0x60030010, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataSysVar::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030016, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataSysVar::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030017, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataSysVar::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030018, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _DataPosRegXyzwpr properties

/////////////////////////////////////////////////////////////////////////////
// _DataPosRegXyzwpr operations

long _DataPosRegXyzwpr::GetDataType()
{
	long result;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosRegXyzwpr::GetGroup()
{
	long result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataPosRegXyzwpr::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataPosRegXyzwpr::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataPosRegXyzwpr::SetValueXyzwpr2(long Index, float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x60030016, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7);
	return result;
}

BOOL _DataPosRegXyzwpr::Update()
{
	BOOL result;
	InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _DataPosRegXyzwpr::GetStartIndex()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosRegXyzwpr::GetEndIndex()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosRegXyzwpr::GetObjectID()
{
	long result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataPosRegXyzwpr::Kill()
{
	InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataPosRegXyzwpr::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030010, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataPosRegXyzwpr::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030011, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataPosRegXyzwpr::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _DataPosRegXyzwpr::Reset()
{
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// _DataString properties

/////////////////////////////////////////////////////////////////////////////
// _DataString operations

long _DataString::GetDataType()
{
	long result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataString::GetStartIndex()
{
	long result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataString::GetEndIndex()
{
	long result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataString::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataString::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataString::GetValue(long Index, BSTR* Value)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Value);
	return result;
}

BOOL _DataString::SetValue(long Index, LPCTSTR Value)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Value);
	return result;
}

BOOL _DataString::Update()
{
	BOOL result;
	InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _DataString::Reset()
{
	InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _DataString::GetObjectID()
{
	long result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataString::Kill()
{
	InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataString::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030011, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataString::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataString::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

/////////////////////////////////////////////////////////////////////////////
// _DataPosRegMG properties

/////////////////////////////////////////////////////////////////////////////
// _DataPosRegMG operations

long _DataPosRegMG::GetDataType()
{
	long result;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosRegMG::GetGroupCount()
{
	long result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _DataPosRegMG::GetDataTable()
{
	LPDISPATCH result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _DataPosRegMG::GetValid()
{
	BOOL result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _DataPosRegMG::SetValueJoint2(long Index, long Group, float J1, float J2, float J3, float J4, float J5, float J6, float J7, float J8, float J9)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
	InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Group, J1, J2, J3, J4, J5, J6, J7, J8, J9);
	return result;
}

BOOL _DataPosRegMG::SetValueXyzwpr2(long Index, long Group, float X, float Y, float Z, float W, float P, float R, float E1, float E2, float E3, short C1, short C2, short C3, short C4, short C5, short C6, short C7)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Group, X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7);
	return result;
}

BOOL _DataPosRegMG::Update()
{
	BOOL result;
	InvokeHelper(0x60030010, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _DataPosRegMG::GetStartIndex()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosRegMG::GetEndIndex()
{
	long result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _DataPosRegMG::GetObjectID()
{
	long result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _DataPosRegMG::Kill()
{
	InvokeHelper(0x60030013, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _DataPosRegMG::GetTypeName()
{
	CString result;
	InvokeHelper(0x60030014, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _DataPosRegMG::AddUserMessage(LPCTSTR vstrMessage)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030015, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 vstrMessage);
}

BOOL _DataPosRegMG::GetDebugLog()
{
	BOOL result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _DataPosRegMG::Reset()
{
	InvokeHelper(0x60030016, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL _DataPosRegMG::GetValueJoint(long Index, long Group, float* J1, float* J2, float* J3, float* J4, float* J5, float* J6, float* J7, float* J8, float* J9)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4;
	InvokeHelper(0x60030018, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Group, J1, J2, J3, J4, J5, J6, J7, J8, J9);
	return result;
}

BOOL _DataPosRegMG::GetValueXyzwpr(long Index, long Group, float* X, float* Y, float* Z, float* W, float* P, float* R, float* E1, float* E2, float* E3, short* C1, short* C2, short* C3, short* C4, short* C5, short* C6, short* C7)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PR4 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x60030019, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index, Group, X, Y, Z, W, P, R, E1, E2, E3, C1, C2, C3, C4, C5, C6, C7);
	return result;
}


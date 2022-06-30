// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// ILibCore wrapper class
#include "StdAfx.h"

class ILibCore : public COleDispatchDriver
{
public:
	ILibCore() {}		// Calls COleDispatchDriver default constructor
	ILibCore(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ILibCore(const ILibCore& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	CString GetHostName();
	void SetHostName(LPCTSTR);
	long GetTimeOutValue();
	void SetTimeOutValue(long);
	long GetPortNumber();
	void SetPortNumber(long);
	long GetMajor();
	void SetMajor(long);
	long GetMinor();
	void SetMinor(long);
	long GetRevision();
	void SetRevision(long);

// Operations
public:
	long SendCommand(LPCTSTR strcmd);
	long WriteVar(LPCTSTR varname, LPCTSTR value);
	long Close();
	long TestConnection();
	long Connect();
	long ClearRAssignment();
	long SetRAssignment(LPCTSTR data);
	long ReadR(short Address, BSTR* Buf);
	long ReadRLong(short Address, long* LongBuf, short CntLong);
	long WriteR(short Address, BSTR* Buf);
	long WriteRLong(short Address, long* LongBuf, short CntLong);
	long ReadShort(short Address, short* ShortBuf, short CntShort);
	long WriteRShort(short Address, short* ShortBuf, short CntShort);
	long ReadRFloat(short Address, float* FloatBuf, short CntFloat);
	long WriteRFloat(short Address, float* FloatBuf, short CntFloat);
	long ReadRJoint(short Address, float* data, short CntAxes, short* UserFrame, short* UserTool, short* Valid);
	long WriteRJoint(short Address, float* data, short CntAxes, short UserFrame, short UserTool);
	long ReadRXyzwpr(short Address, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig, short* UserFrame, short* UserTool, short* Valid);
	long WriteRXyzwpr(short Address, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig, short UserFrame, short UserTool);
	long ReadRPos(short Address, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig, float* Joint, short CntJoint, short* UserFrame, short* UserTool, short* ValidC, short* ValidJ);
	long ReadSDO(short Index, short* Buf, short Cnt);
	long WriteSDO(short Index, short* Buf, short Cnt);
	long ReadSDI(short Index, short* Buf, short Cnt);
	long WriteSDI(short Index, short* Buf, short Cnt);
	long ReadRDI(short Index, short* Buf, short Cnt);
	long WriteRDI(short Index, short* Buf, short Cnt);
	long ReadUI(short Index, short* Buf, short Cnt);
	long ReadUO(short Index, short* Buf, short Cnt);
	long WriteUO(short Index, short* Buf, short Cnt);
	long ReadSI(short Index, short* Buf, short Cnt);
	long ReadSO(short Index, short* Buf, short Cnt);
	long WriteSO(short Index, short* Buf, short Cnt);
	long ReadAI(short Index, long* Buf, short Cnt);
	long WriteAI(short Index, long* Buf, short Cnt);
	long ReadAO(short Index, long* Buf, short Cnt);
	long WriteAO(short Index, long* Buf, short Cnt);
	long ReadGI(short Index, long* Buf, short Cnt);
	long WriteGI(short Index, long* Buf, short Cnt);
	long ReadGO(short Index, long* Buf, short Cnt);
	long WriteGO(short Index, long* Buf, short Cnt);
	long ReadPMCK(short IndexA, short IndexB, short* Buf, short Cnt);
	long WritePMCK(short IndexA, short IndexB, short* Buf, short Cnt);
	long ReadPMCR(short IndexA, short IndexB, short* Buf, short Cnt);
	long WritePMCR(short IndexA, short IndexB, short* Buf, short Cnt);
	long ReadPMCD(short Index, short* Buf, short Cnt);
	long WritePMCD(short Index, short* Buf, short Cnt);
	long ReadRDO(short Index, short* Buf, short Cnt);
	long WriteRDO(short Index, short* Buf, short Cnt);
	long ReadSDO2(short Index, short* Buf, short Cnt);
	long ReadRShort(short Address, short* ShortBuf, short Count);
	long ConvToLong(short* ShortBuf);
	float ConvToFloat(short* ShortBuf);
	long ReadPMCR2(short Index, short* Buf, short Cnt);
	long WritePMCR2(short Index, short* Buf, short Cnt);
	short GetClientID();
	void SetClientID(short ClientID);
	long WriteRXyzwprMulti(short Address, short Count, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig);
};

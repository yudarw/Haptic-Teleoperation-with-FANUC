// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "frrobotiflib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// ILibCore properties

CString ILibCore::GetHostName()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void ILibCore::SetHostName(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

long ILibCore::GetTimeOutValue()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}

void ILibCore::SetTimeOutValue(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}

long ILibCore::GetPortNumber()
{
	long result;
	GetProperty(0x3, VT_I4, (void*)&result);
	return result;
}

void ILibCore::SetPortNumber(long propVal)
{
	SetProperty(0x3, VT_I4, propVal);
}

long ILibCore::GetMajor()
{
	long result;
	GetProperty(0x4, VT_I4, (void*)&result);
	return result;
}

void ILibCore::SetMajor(long propVal)
{
	SetProperty(0x4, VT_I4, propVal);
}

long ILibCore::GetMinor()
{
	long result;
	GetProperty(0x5, VT_I4, (void*)&result);
	return result;
}

void ILibCore::SetMinor(long propVal)
{
	SetProperty(0x5, VT_I4, propVal);
}

long ILibCore::GetRevision()
{
	long result;
	GetProperty(0x6, VT_I4, (void*)&result);
	return result;
}

void ILibCore::SetRevision(long propVal)
{
	SetProperty(0x6, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// ILibCore operations

long ILibCore::SendCommand(LPCTSTR strcmd)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		strcmd);
	return result;
}

long ILibCore::WriteVar(LPCTSTR varname, LPCTSTR value)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		varname, value);
	return result;
}

long ILibCore::Close()
{
	long result;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long ILibCore::TestConnection()
{
	long result;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long ILibCore::Connect()
{
	long result;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long ILibCore::ClearRAssignment()
{
	long result;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long ILibCore::SetRAssignment(LPCTSTR data)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		data);
	return result;
}

long ILibCore::ReadR(short Address, BSTR* Buf)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PBSTR;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, Buf);
	return result;
}

long ILibCore::ReadRLong(short Address, long* LongBuf, short CntLong)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, LongBuf, CntLong);
	return result;
}

long ILibCore::WriteR(short Address, BSTR* Buf)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PBSTR;
	InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, Buf);
	return result;
}

long ILibCore::WriteRLong(short Address, long* LongBuf, short CntLong)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, LongBuf, CntLong);
	return result;
}

long ILibCore::ReadShort(short Address, short* ShortBuf, short CntShort)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, ShortBuf, CntShort);
	return result;
}

long ILibCore::WriteRShort(short Address, short* ShortBuf, short CntShort)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, ShortBuf, CntShort);
	return result;
}

long ILibCore::ReadRFloat(short Address, float* FloatBuf, short CntFloat)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2;
	InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, FloatBuf, CntFloat);
	return result;
}

long ILibCore::WriteRFloat(short Address, float* FloatBuf, short CntFloat)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2;
	InvokeHelper(0x15, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, FloatBuf, CntFloat);
	return result;
}

long ILibCore::ReadRJoint(short Address, float* data, short CntAxes, short* UserFrame, short* UserTool, short* Valid)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, data, CntAxes, UserFrame, UserTool, Valid);
	return result;
}

long ILibCore::WriteRJoint(short Address, float* data, short CntAxes, short UserFrame, short UserTool)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, data, CntAxes, UserFrame, UserTool);
	return result;
}

long ILibCore::ReadRXyzwpr(short Address, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig, short* UserFrame, short* UserTool, short* Valid)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2 VTS_PI2 VTS_I2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, Xyzwpr, CntXyzwpr, Config, CntConfig, UserFrame, UserTool, Valid);
	return result;
}

long ILibCore::WriteRXyzwpr(short Address, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig, short UserFrame, short UserTool)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2 VTS_PI2 VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, Xyzwpr, CntXyzwpr, Config, CntConfig, UserFrame, UserTool);
	return result;
}

long ILibCore::ReadRPos(short Address, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig, float* Joint, short CntJoint, short* UserFrame, short* UserTool, short* ValidC, short* ValidJ)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_I2 VTS_PI2 VTS_I2 VTS_PR4 VTS_I2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, Xyzwpr, CntXyzwpr, Config, CntConfig, Joint, CntJoint, UserFrame, UserTool, ValidC, ValidJ);
	return result;
}

long ILibCore::ReadSDO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteSDO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadSDI(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteSDI(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadRDI(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteRDI(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadUI(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadUO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteUO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadSI(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadSO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteSO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadAI(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteAI(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadAO(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteAO(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x2a, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadGI(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteGI(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x2c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadGO(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x2d, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteGO(short Index, long* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI4 VTS_I2;
	InvokeHelper(0x2e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadPMCK(short IndexA, short IndexB, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x2f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		IndexA, IndexB, Buf, Cnt);
	return result;
}

long ILibCore::WritePMCK(short IndexA, short IndexB, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x30, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		IndexA, IndexB, Buf, Cnt);
	return result;
}

long ILibCore::ReadPMCR(short IndexA, short IndexB, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x31, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		IndexA, IndexB, Buf, Cnt);
	return result;
}

long ILibCore::WritePMCR(short IndexA, short IndexB, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x32, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		IndexA, IndexB, Buf, Cnt);
	return result;
}

long ILibCore::ReadPMCD(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WritePMCD(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x34, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadRDO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x35, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WriteRDO(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadSDO2(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x37, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::ReadRShort(short Address, short* ShortBuf, short Count)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, ShortBuf, Count);
	return result;
}

long ILibCore::ConvToLong(short* ShortBuf)
{
	long result;
	static BYTE parms[] =
		VTS_PI2;
	InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		ShortBuf);
	return result;
}

float ILibCore::ConvToFloat(short* ShortBuf)
{
	float result;
	static BYTE parms[] =
		VTS_PI2;
	InvokeHelper(0x3a, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		ShortBuf);
	return result;
}

long ILibCore::ReadPMCR2(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x3b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

long ILibCore::WritePMCR2(short Index, short* Buf, short Cnt)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x3c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index, Buf, Cnt);
	return result;
}

short ILibCore::GetClientID()
{
	short result;
	InvokeHelper(0x3d, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
	return result;
}

void ILibCore::SetClientID(short ClientID)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x3e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ClientID);
}

long ILibCore::WriteRXyzwprMulti(short Address, short Count, float* Xyzwpr, short CntXyzwpr, short* Config, short CntConfig)
{
	long result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_PR4 VTS_I2 VTS_PI2 VTS_I2;
	InvokeHelper(0x3f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Address, Count, Xyzwpr, CntXyzwpr, Config, CntConfig);
	return result;
}

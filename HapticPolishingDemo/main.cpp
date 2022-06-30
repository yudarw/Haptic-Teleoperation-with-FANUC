//#include "MainForm.h"
//#include "HapticForm.h"
//#include "SimForm.h"
#include "main.h"
#include "MainFormDlg.h"
#include <msclr\marshal_cppstd.h>


float	trajectory[MAX_TRAJECRORY_NUM][15];
float	tp_points[MAX_TRAJECRORY_NUM][12];

bool trajectory_form_isOpen;
bool robotControl_form_isOpen;
bool custom_form_isOpen;
bool force_calibration_form_isOpen;
bool coppelia_form_isOpen;
bool myform_isOpen;

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace HapticPolishingDemo;
using namespace msclr::interop;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainFormDlg());
	return 0;
}

void console_print(string text)
{
	DateTime now = DateTime::Now;
	String^ text_time = now.ToString("yyyy/MM/dd HH:mm");
	std::string time = marshal_as<std::string>(text_time);
	cout << time << " ___INFO___ : " << text << endl;
}

void console_print_error(string text)
{
	DateTime now = DateTime::Now;
	String^ text_time = now.ToString("yyyy/MM/dd HH:mm");
	std::string time = marshal_as<std::string>(text_time);
	cout << time << " ___ERROR___ : " << text << endl;
}

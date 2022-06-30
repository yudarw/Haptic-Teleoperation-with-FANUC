#pragma once
#include "Fanuc.h"
#include "Haptic.h"

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void system_init();
		void OnTimer1();
		void on_timer_2();
		//void OnTimer2();
		//void program_initialization();

		// =============== Coppelia Sim ================== //
		void coppeliasim_connect();
		
		// =============== Haptic Function ================ //
		void haptic_connect();
		//void haptic_read();
	//	void haptic_record();
	//	void haptic_record_stop();

		// =============== Fanuc Function ================= //
		void robot_connect();
		void robot_test_move();
		void robot_readpos();
		void robot_record();
		void robot_play_motion();
		void robot_move_to_home();
		void robot_set_joint();
		void robot_read_joint();
		//void robot_disconnect();
		//void robot_setPosition();
		//void robot_readCurrentPosition();

		void display_position(DataPos pos);
		void display_force_data(float force[6]);
		void display_haptic(DeviceStateStruct pState);

		void button_scale_up();
		void button_scale_down();

		void start_teaching_mode();
		void record_force();
		void record_force_stop();


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  calibrationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  tbHapticR;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbHapticP;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbHapticW;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbHapticZ;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbHapticY;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbHapticX;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  tbPosRz;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbPosRy;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbPosRx;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbPosZ;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tbPosY;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  tbPosX;

	private: System::Windows::Forms::Label^  label12;

	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Button^  hapticStopRecord;

	private: System::Windows::Forms::Button^  btnHapticRecord;






	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnSimConnect;
	private: System::Windows::Forms::ToolStripMenuItem^  hapticOpenMenu;

	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::Button^  button3;


private: System::Windows::Forms::GroupBox^  groupBox3;





















private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Timer^  timer1;

private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::StatusStrip^  statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel^  label_status;



private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::Label^  label_ut;

private: System::Windows::Forms::Label^  label_uf;

private: System::Windows::Forms::Label^  label_config;

private: System::Windows::Forms::Label^  label_coor_system;

private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Label^  label_haptic_conenction;

private: System::Windows::Forms::Button^  btnHapticConnect;


private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::Button^  btnTeaching;
private: System::Windows::Forms::Button^  button2;


private: System::Windows::Forms::TextBox^  tb_joint1;
private: System::Windows::Forms::TextBox^  tb_joint2;
private: System::Windows::Forms::TextBox^  tb_joint5;
private: System::Windows::Forms::TextBox^  tb_joint6;
private: System::Windows::Forms::TextBox^  tb_joint4;
private: System::Windows::Forms::TextBox^  tb_joint3;
private: System::Windows::Forms::Button^  btn_set_joint;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::GroupBox^  groupBox13;
private: System::Windows::Forms::Button^  button12;

private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::GroupBox^  groupBox12;
private: System::Windows::Forms::Button^  btnScaleUp;


private: System::Windows::Forms::Button^  btnScaleDown;


private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::RadioButton^  rb_wpr;


private: System::Windows::Forms::RadioButton^  rb_xyz;

private: System::Windows::Forms::RadioButton^  rb_xyzwpr;
private: System::Windows::Forms::GroupBox^  groupBox14;
private: System::Windows::Forms::RadioButton^  rb_real_robot;

private: System::Windows::Forms::RadioButton^  rb_simulator;

private: System::Windows::Forms::TextBox^  tb_speed;
private: System::Windows::Forms::TextBox^  label_scale_factor;
private: System::Windows::Forms::CheckBox^  check_inverse;

private: System::Windows::Forms::Timer^  timer2;
private: System::Windows::Forms::ProgressBar^  force_x_bar;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::ProgressBar^  force_y_bar;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::ProgressBar^  force_z_bar;
private: System::Windows::Forms::Label^  label_fx;
private: System::Windows::Forms::Label^  label_fy;
private: System::Windows::Forms::Label^  label_fz;
private: System::Windows::Forms::GroupBox^  groupBox15;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::TextBox^  tb_ipaddress;
private: System::Windows::Forms::Label^  labelRobotConnState;
private: System::Windows::Forms::Button^  btnConnect;
private: System::Windows::Forms::Label^  Connect;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::Label^  label_mz;
private: System::Windows::Forms::ProgressBar^  force_mx_bar;
private: System::Windows::Forms::Label^  label_my;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label_mx;
private: System::Windows::Forms::ProgressBar^  force_my_bar;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::ProgressBar^  force_mz_bar;
private: System::Windows::Forms::Label^  label_haptic_control_state;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Button^  button17;









private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hapticOpenMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbHapticR = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbHapticP = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbHapticW = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbHapticZ = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbHapticY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbHapticX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tbPosRz = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbPosRy = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbPosRx = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbPosZ = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tbPosY = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tbPosX = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->btnSimConnect = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->hapticStopRecord = (gcnew System::Windows::Forms::Button());
			this->btnHapticRecord = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label_mz = (gcnew System::Windows::Forms::Label());
			this->force_mx_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label_my = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label_mx = (gcnew System::Windows::Forms::Label());
			this->force_my_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->force_mz_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label_fz = (gcnew System::Windows::Forms::Label());
			this->force_x_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label_fy = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label_fx = (gcnew System::Windows::Forms::Label());
			this->force_y_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->force_z_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->label_status = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label_ut = (gcnew System::Windows::Forms::Label());
			this->label_uf = (gcnew System::Windows::Forms::Label());
			this->label_config = (gcnew System::Windows::Forms::Label());
			this->label_coor_system = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->label_haptic_conenction = (gcnew System::Windows::Forms::Label());
			this->btnHapticConnect = (gcnew System::Windows::Forms::Button());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->label_haptic_control_state = (gcnew System::Windows::Forms::Label());
			this->Connect = (gcnew System::Windows::Forms::Label());
			this->check_inverse = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->rb_real_robot = (gcnew System::Windows::Forms::RadioButton());
			this->rb_simulator = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_speed = (gcnew System::Windows::Forms::TextBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->label_scale_factor = (gcnew System::Windows::Forms::TextBox());
			this->btnScaleUp = (gcnew System::Windows::Forms::Button());
			this->btnScaleDown = (gcnew System::Windows::Forms::Button());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->rb_wpr = (gcnew System::Windows::Forms::RadioButton());
			this->rb_xyz = (gcnew System::Windows::Forms::RadioButton());
			this->rb_xyzwpr = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnTeaching = (gcnew System::Windows::Forms::Button());
			this->tb_joint1 = (gcnew System::Windows::Forms::TextBox());
			this->tb_joint2 = (gcnew System::Windows::Forms::TextBox());
			this->tb_joint5 = (gcnew System::Windows::Forms::TextBox());
			this->tb_joint6 = (gcnew System::Windows::Forms::TextBox());
			this->tb_joint4 = (gcnew System::Windows::Forms::TextBox());
			this->tb_joint3 = (gcnew System::Windows::Forms::TextBox());
			this->btn_set_joint = (gcnew System::Windows::Forms::Button());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->tb_ipaddress = (gcnew System::Windows::Forms::TextBox());
			this->labelRobotConnState = (gcnew System::Windows::Forms::Label());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox14->SuspendLayout();
			this->groupBox13->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->groupBox15->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->fileToolStripMenuItem,
					this->settingToolStripMenuItem, this->helpToolStripMenuItem, this->calibrationToolStripMenuItem, this->helpToolStripMenuItem1,
					this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(922, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// settingToolStripMenuItem
			// 
			this->settingToolStripMenuItem->Name = L"settingToolStripMenuItem";
			this->settingToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->settingToolStripMenuItem->Text = L"Setting";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->hapticOpenMenu });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->helpToolStripMenuItem->Text = L"Haptic";
			// 
			// hapticOpenMenu
			// 
			this->hapticOpenMenu->Name = L"hapticOpenMenu";
			this->hapticOpenMenu->Size = System::Drawing::Size(106, 22);
			this->hapticOpenMenu->Text = L"Demo";
			this->hapticOpenMenu->Click += gcnew System::EventHandler(this, &MainForm::hapticOpenMenu_Click);
			// 
			// calibrationToolStripMenuItem
			// 
			this->calibrationToolStripMenuItem->Name = L"calibrationToolStripMenuItem";
			this->calibrationToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->calibrationToolStripMenuItem->Text = L"Calibration";
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem1->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// groupBox1
			// 
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->groupBox1->Controls->Add(this->tbHapticR);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbHapticP);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbHapticW);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbHapticZ);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbHapticY);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->tbHapticX);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(249, 146);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(217, 111);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"HAPTIC POSITION";
			// 
			// tbHapticR
			// 
			this->tbHapticR->Location = System::Drawing::Point(145, 77);
			this->tbHapticR->Name = L"tbHapticR";
			this->tbHapticR->Size = System::Drawing::Size(57, 20);
			this->tbHapticR->TabIndex = 11;
			this->tbHapticR->Text = L"00.00";
			this->tbHapticR->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(119, 80);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Rz:";
			// 
			// tbHapticP
			// 
			this->tbHapticP->Location = System::Drawing::Point(145, 51);
			this->tbHapticP->Name = L"tbHapticP";
			this->tbHapticP->Size = System::Drawing::Size(57, 20);
			this->tbHapticP->TabIndex = 9;
			this->tbHapticP->Text = L"00.00";
			this->tbHapticP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(119, 54);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Ry:";
			// 
			// tbHapticW
			// 
			this->tbHapticW->Location = System::Drawing::Point(145, 25);
			this->tbHapticW->Name = L"tbHapticW";
			this->tbHapticW->Size = System::Drawing::Size(57, 20);
			this->tbHapticW->TabIndex = 7;
			this->tbHapticW->Text = L"00.00";
			this->tbHapticW->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(119, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Rx:";
			// 
			// tbHapticZ
			// 
			this->tbHapticZ->Location = System::Drawing::Point(43, 76);
			this->tbHapticZ->Name = L"tbHapticZ";
			this->tbHapticZ->Size = System::Drawing::Size(57, 20);
			this->tbHapticZ->TabIndex = 5;
			this->tbHapticZ->Text = L"00.00";
			this->tbHapticZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Z :";
			// 
			// tbHapticY
			// 
			this->tbHapticY->Location = System::Drawing::Point(43, 50);
			this->tbHapticY->Name = L"tbHapticY";
			this->tbHapticY->Size = System::Drawing::Size(57, 20);
			this->tbHapticY->TabIndex = 3;
			this->tbHapticY->Text = L"00.00";
			this->tbHapticY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y:";
			// 
			// tbHapticX
			// 
			this->tbHapticX->Location = System::Drawing::Point(43, 24);
			this->tbHapticX->Name = L"tbHapticX";
			this->tbHapticX->Size = System::Drawing::Size(57, 20);
			this->tbHapticX->TabIndex = 1;
			this->tbHapticX->Text = L"00.00";
			this->tbHapticX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X :";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tbPosRz);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->tbPosRy);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->tbPosRx);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->tbPosZ);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->tbPosY);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->tbPosX);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Location = System::Drawing::Point(249, 26);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(217, 114);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"ROBOT POSITION";
			// 
			// tbPosRz
			// 
			this->tbPosRz->Location = System::Drawing::Point(145, 81);
			this->tbPosRz->Name = L"tbPosRz";
			this->tbPosRz->Size = System::Drawing::Size(57, 20);
			this->tbPosRz->TabIndex = 11;
			this->tbPosRz->Text = L"00.000";
			this->tbPosRz->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(119, 84);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"r :";
			// 
			// tbPosRy
			// 
			this->tbPosRy->Location = System::Drawing::Point(145, 55);
			this->tbPosRy->Name = L"tbPosRy";
			this->tbPosRy->Size = System::Drawing::Size(57, 20);
			this->tbPosRy->TabIndex = 9;
			this->tbPosRy->Text = L"00.000";
			this->tbPosRy->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(119, 58);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(19, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"p :";
			// 
			// tbPosRx
			// 
			this->tbPosRx->Location = System::Drawing::Point(145, 29);
			this->tbPosRx->Name = L"tbPosRx";
			this->tbPosRx->Size = System::Drawing::Size(57, 20);
			this->tbPosRx->TabIndex = 7;
			this->tbPosRx->Text = L"00.000";
			this->tbPosRx->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(119, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 6;
			this->label9->Text = L"w :";
			// 
			// tbPosZ
			// 
			this->tbPosZ->Location = System::Drawing::Point(43, 78);
			this->tbPosZ->Name = L"tbPosZ";
			this->tbPosZ->Size = System::Drawing::Size(57, 20);
			this->tbPosZ->TabIndex = 5;
			this->tbPosZ->Text = L"00.000";
			this->tbPosZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(17, 81);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(18, 13);
			this->label10->TabIndex = 4;
			this->label10->Text = L"z :";
			// 
			// tbPosY
			// 
			this->tbPosY->Location = System::Drawing::Point(43, 52);
			this->tbPosY->Name = L"tbPosY";
			this->tbPosY->Size = System::Drawing::Size(57, 20);
			this->tbPosY->TabIndex = 3;
			this->tbPosY->Text = L"00.000";
			this->tbPosY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(17, 55);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(18, 13);
			this->label11->TabIndex = 2;
			this->label11->Text = L"y :";
			// 
			// tbPosX
			// 
			this->tbPosX->Location = System::Drawing::Point(43, 26);
			this->tbPosX->Name = L"tbPosX";
			this->tbPosX->Size = System::Drawing::Size(57, 20);
			this->tbPosX->TabIndex = 1;
			this->tbPosX->Text = L"00.000";
			this->tbPosX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(17, 29);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(18, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"x :";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(765, 48);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(106, 23);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Test Move";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// btnSimConnect
			// 
			this->btnSimConnect->Location = System::Drawing::Point(765, 189);
			this->btnSimConnect->Name = L"btnSimConnect";
			this->btnSimConnect->Size = System::Drawing::Size(105, 23);
			this->btnSimConnect->TabIndex = 20;
			this->btnSimConnect->Text = L"Sim Connect";
			this->btnSimConnect->UseVisualStyleBackColor = true;
			this->btnSimConnect->Click += gcnew System::EventHandler(this, &MainForm::btnSimConnect_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(765, 161);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(105, 23);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Upload";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->hapticStopRecord);
			this->groupBox5->Controls->Add(this->btnHapticRecord);
			this->groupBox5->Location = System::Drawing::Point(765, 227);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(122, 86);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Trajectory Recording";
			// 
			// hapticStopRecord
			// 
			this->hapticStopRecord->Location = System::Drawing::Point(10, 51);
			this->hapticStopRecord->Name = L"hapticStopRecord";
			this->hapticStopRecord->Size = System::Drawing::Size(99, 24);
			this->hapticStopRecord->TabIndex = 1;
			this->hapticStopRecord->Text = L"StopRecording";
			this->hapticStopRecord->UseVisualStyleBackColor = true;
			this->hapticStopRecord->Click += gcnew System::EventHandler(this, &MainForm::hapticStopRecord_Click);
			// 
			// btnHapticRecord
			// 
			this->btnHapticRecord->Location = System::Drawing::Point(10, 19);
			this->btnHapticRecord->Name = L"btnHapticRecord";
			this->btnHapticRecord->Size = System::Drawing::Size(99, 24);
			this->btnHapticRecord->TabIndex = 0;
			this->btnHapticRecord->Text = L"Start Recording";
			this->btnHapticRecord->UseVisualStyleBackColor = true;
			this->btnHapticRecord->Click += gcnew System::EventHandler(this, &MainForm::btnHapticRecord_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(765, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Generate CSV File";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(765, 77);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 23);
			this->button3->TabIndex = 22;
			this->button3->Text = L"Read Pos Reg";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label_mz);
			this->groupBox3->Controls->Add(this->force_mx_bar);
			this->groupBox3->Controls->Add(this->label_my);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->label_mx);
			this->groupBox3->Controls->Add(this->force_my_bar);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->force_mz_bar);
			this->groupBox3->Controls->Add(this->label_fz);
			this->groupBox3->Controls->Add(this->force_x_bar);
			this->groupBox3->Controls->Add(this->label_fy);
			this->groupBox3->Controls->Add(this->label33);
			this->groupBox3->Controls->Add(this->label_fx);
			this->groupBox3->Controls->Add(this->force_y_bar);
			this->groupBox3->Controls->Add(this->label36);
			this->groupBox3->Controls->Add(this->label35);
			this->groupBox3->Controls->Add(this->force_z_bar);
			this->groupBox3->Location = System::Drawing::Point(17, 146);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(226, 163);
			this->groupBox3->TabIndex = 13;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"FANUC FORCE SENSOR";
			// 
			// label_mz
			// 
			this->label_mz->AutoSize = true;
			this->label_mz->Location = System::Drawing::Point(139, 150);
			this->label_mz->Name = L"label_mz";
			this->label_mz->Size = System::Drawing::Size(13, 13);
			this->label_mz->TabIndex = 55;
			this->label_mz->Text = L"0";
			// 
			// force_mx_bar
			// 
			this->force_mx_bar->Location = System::Drawing::Point(33, 97);
			this->force_mx_bar->Name = L"force_mx_bar";
			this->force_mx_bar->Size = System::Drawing::Size(100, 18);
			this->force_mx_bar->TabIndex = 48;
			// 
			// label_my
			// 
			this->label_my->AutoSize = true;
			this->label_my->Location = System::Drawing::Point(139, 123);
			this->label_my->Name = L"label_my";
			this->label_my->Size = System::Drawing::Size(13, 13);
			this->label_my->TabIndex = 54;
			this->label_my->Text = L"0";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 98);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(21, 13);
			this->label17->TabIndex = 47;
			this->label17->Text = L"Mx";
			// 
			// label_mx
			// 
			this->label_mx->AutoSize = true;
			this->label_mx->Location = System::Drawing::Point(139, 101);
			this->label_mx->Name = L"label_mx";
			this->label_mx->Size = System::Drawing::Size(13, 13);
			this->label_mx->TabIndex = 53;
			this->label_mx->Text = L"0";
			// 
			// force_my_bar
			// 
			this->force_my_bar->Location = System::Drawing::Point(33, 121);
			this->force_my_bar->Name = L"force_my_bar";
			this->force_my_bar->Size = System::Drawing::Size(100, 18);
			this->force_my_bar->TabIndex = 50;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(12, 146);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(21, 13);
			this->label19->TabIndex = 51;
			this->label19->Text = L"Mz";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(12, 122);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(21, 13);
			this->label20->TabIndex = 49;
			this->label20->Text = L"My";
			// 
			// force_mz_bar
			// 
			this->force_mz_bar->Location = System::Drawing::Point(33, 145);
			this->force_mz_bar->Name = L"force_mz_bar";
			this->force_mz_bar->Size = System::Drawing::Size(100, 18);
			this->force_mz_bar->TabIndex = 52;
			// 
			// label_fz
			// 
			this->label_fz->AutoSize = true;
			this->label_fz->Location = System::Drawing::Point(139, 76);
			this->label_fz->Name = L"label_fz";
			this->label_fz->Size = System::Drawing::Size(13, 13);
			this->label_fz->TabIndex = 46;
			this->label_fz->Text = L"0";
			// 
			// force_x_bar
			// 
			this->force_x_bar->Location = System::Drawing::Point(33, 25);
			this->force_x_bar->Name = L"force_x_bar";
			this->force_x_bar->Size = System::Drawing::Size(100, 18);
			this->force_x_bar->TabIndex = 39;
			// 
			// label_fy
			// 
			this->label_fy->AutoSize = true;
			this->label_fy->Location = System::Drawing::Point(139, 51);
			this->label_fy->Name = L"label_fy";
			this->label_fy->Size = System::Drawing::Size(13, 13);
			this->label_fy->TabIndex = 45;
			this->label_fy->Text = L"0";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(12, 26);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(18, 13);
			this->label33->TabIndex = 12;
			this->label33->Text = L"Fx";
			// 
			// label_fx
			// 
			this->label_fx->AutoSize = true;
			this->label_fx->Location = System::Drawing::Point(139, 27);
			this->label_fx->Name = L"label_fx";
			this->label_fx->Size = System::Drawing::Size(13, 13);
			this->label_fx->TabIndex = 44;
			this->label_fx->Text = L"0";
			// 
			// force_y_bar
			// 
			this->force_y_bar->Location = System::Drawing::Point(33, 49);
			this->force_y_bar->Name = L"force_y_bar";
			this->force_y_bar->Size = System::Drawing::Size(100, 18);
			this->force_y_bar->TabIndex = 41;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(12, 74);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(18, 13);
			this->label36->TabIndex = 42;
			this->label36->Text = L"Fz";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(12, 50);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(18, 13);
			this->label35->TabIndex = 40;
			this->label35->Text = L"Fy";
			// 
			// force_z_bar
			// 
			this->force_z_bar->Location = System::Drawing::Point(33, 73);
			this->force_z_bar->Name = L"force_z_bar";
			this->force_z_bar->Size = System::Drawing::Size(100, 18);
			this->force_z_bar->TabIndex = 43;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(765, 106);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(106, 23);
			this->button4->TabIndex = 25;
			this->button4->Text = L"Read Force";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(141, 49);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(63, 28);
			this->button8->TabIndex = 27;
			this->button8->Text = L"Play ";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MainForm::button8_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->label_status });
			this->statusStrip1->Location = System::Drawing::Point(0, 483);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(922, 22);
			this->statusStrip1->TabIndex = 28;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// label_status
			// 
			this->label_status->Name = L"label_status";
			this->label_status->Size = System::Drawing::Size(109, 17);
			this->label_status->Text = L"Program initialized!";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->groupBox3);
			this->groupBox6->Controls->Add(this->groupBox7);
			this->groupBox6->Controls->Add(this->groupBox1);
			this->groupBox6->Controls->Add(this->groupBox2);
			this->groupBox6->Location = System::Drawing::Point(268, 27);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(491, 315);
			this->groupBox6->TabIndex = 29;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"System";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label_ut);
			this->groupBox7->Controls->Add(this->label_uf);
			this->groupBox7->Controls->Add(this->label_config);
			this->groupBox7->Controls->Add(this->label_coor_system);
			this->groupBox7->Controls->Add(this->label29);
			this->groupBox7->Controls->Add(this->label28);
			this->groupBox7->Controls->Add(this->label27);
			this->groupBox7->Controls->Add(this->label26);
			this->groupBox7->Controls->Add(this->label25);
			this->groupBox7->Controls->Add(this->label24);
			this->groupBox7->Controls->Add(this->label23);
			this->groupBox7->Controls->Add(this->label14);
			this->groupBox7->Location = System::Drawing::Point(17, 27);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(226, 113);
			this->groupBox7->TabIndex = 30;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"ROBOT CONFIG";
			// 
			// label_ut
			// 
			this->label_ut->AutoSize = true;
			this->label_ut->Location = System::Drawing::Point(139, 87);
			this->label_ut->Name = L"label_ut";
			this->label_ut->Size = System::Drawing::Size(13, 13);
			this->label_ut->TabIndex = 11;
			this->label_ut->Text = L"3";
			// 
			// label_uf
			// 
			this->label_uf->AutoSize = true;
			this->label_uf->Location = System::Drawing::Point(139, 68);
			this->label_uf->Name = L"label_uf";
			this->label_uf->Size = System::Drawing::Size(13, 13);
			this->label_uf->TabIndex = 10;
			this->label_uf->Text = L"2";
			// 
			// label_config
			// 
			this->label_config->AutoSize = true;
			this->label_config->Location = System::Drawing::Point(139, 49);
			this->label_config->Name = L"label_config";
			this->label_config->Size = System::Drawing::Size(60, 13);
			this->label_config->TabIndex = 9;
			this->label_config->Text = L"NUT 0 0 0 ";
			// 
			// label_coor_system
			// 
			this->label_coor_system->AutoSize = true;
			this->label_coor_system->Location = System::Drawing::Point(139, 30);
			this->label_coor_system->Name = L"label_coor_system";
			this->label_coor_system->Size = System::Drawing::Size(48, 13);
			this->label_coor_system->TabIndex = 8;
			this->label_coor_system->Text = L"WORLD";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(123, 87);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(10, 13);
			this->label29->TabIndex = 7;
			this->label29->Text = L":";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(123, 68);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(10, 13);
			this->label28->TabIndex = 6;
			this->label28->Text = L":";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(123, 49);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(10, 13);
			this->label27->TabIndex = 5;
			this->label27->Text = L":";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(123, 30);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(10, 13);
			this->label26->TabIndex = 4;
			this->label26->Text = L":";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(22, 87);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(77, 13);
			this->label25->TabIndex = 3;
			this->label25->Text = L"User Tool (UT)";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(22, 68);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(84, 13);
			this->label24->TabIndex = 2;
			this->label24->Text = L"User Frame (UF)";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(22, 49);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(69, 13);
			this->label23->TabIndex = 1;
			this->label23->Text = L"Configuration";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(22, 30);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(95, 13);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Coordinate System";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->textBox7);
			this->groupBox8->Controls->Add(this->label34);
			this->groupBox8->Controls->Add(this->button8);
			this->groupBox8->Controls->Add(this->button7);
			this->groupBox8->Location = System::Drawing::Point(671, 335);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(216, 86);
			this->groupBox8->TabIndex = 30;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"TRAJECTORY";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(75, 23);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(129, 20);
			this->textBox7->TabIndex = 12;
			this->textBox7->Text = L"fanuc_trajectory.txt";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(14, 26);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(55, 13);
			this->label34->TabIndex = 1;
			this->label34->Text = L"Filename :";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->label_haptic_conenction);
			this->groupBox9->Controls->Add(this->btnHapticConnect);
			this->groupBox9->Location = System::Drawing::Point(12, 116);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(164, 81);
			this->groupBox9->TabIndex = 20;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"HAPTIC";
			// 
			// label_haptic_conenction
			// 
			this->label_haptic_conenction->AutoSize = true;
			this->label_haptic_conenction->BackColor = System::Drawing::Color::Red;
			this->label_haptic_conenction->ForeColor = System::Drawing::Color::White;
			this->label_haptic_conenction->Location = System::Drawing::Point(10, 38);
			this->label_haptic_conenction->Name = L"label_haptic_conenction";
			this->label_haptic_conenction->Size = System::Drawing::Size(73, 13);
			this->label_haptic_conenction->TabIndex = 19;
			this->label_haptic_conenction->Text = L"Disconnected";
			// 
			// btnHapticConnect
			// 
			this->btnHapticConnect->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnHapticConnect.BackgroundImage")));
			this->btnHapticConnect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnHapticConnect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnHapticConnect->Location = System::Drawing::Point(95, 10);
			this->btnHapticConnect->Name = L"btnHapticConnect";
			this->btnHapticConnect->Size = System::Drawing::Size(63, 60);
			this->btnHapticConnect->TabIndex = 16;
			this->btnHapticConnect->UseVisualStyleBackColor = true;
			this->btnHapticConnect->Click += gcnew System::EventHandler(this, &MainForm::btnHapticConnect_Click);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->label_haptic_control_state);
			this->groupBox10->Controls->Add(this->Connect);
			this->groupBox10->Controls->Add(this->check_inverse);
			this->groupBox10->Controls->Add(this->groupBox14);
			this->groupBox10->Controls->Add(this->groupBox13);
			this->groupBox10->Controls->Add(this->groupBox12);
			this->groupBox10->Controls->Add(this->groupBox11);
			this->groupBox10->Controls->Add(this->button2);
			this->groupBox10->Controls->Add(this->btnTeaching);
			this->groupBox10->Location = System::Drawing::Point(12, 203);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(250, 269);
			this->groupBox10->TabIndex = 22;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Teaching Mode";
			// 
			// label_haptic_control_state
			// 
			this->label_haptic_control_state->AutoSize = true;
			this->label_haptic_control_state->BackColor = System::Drawing::Color::Red;
			this->label_haptic_control_state->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_haptic_control_state->ForeColor = System::Drawing::Color::White;
			this->label_haptic_control_state->Location = System::Drawing::Point(40, 239);
			this->label_haptic_control_state->Name = L"label_haptic_control_state";
			this->label_haptic_control_state->Size = System::Drawing::Size(103, 16);
			this->label_haptic_control_state->TabIndex = 20;
			this->label_haptic_control_state->Text = L"Disconnected";
			// 
			// Connect
			// 
			this->Connect->AutoSize = true;
			this->Connect->Location = System::Drawing::Point(183, 187);
			this->Connect->Name = L"Connect";
			this->Connect->Size = System::Drawing::Size(25, 13);
			this->Connect->TabIndex = 12;
			this->Connect->Text = L"Pair";
			// 
			// check_inverse
			// 
			this->check_inverse->AutoSize = true;
			this->check_inverse->Location = System::Drawing::Point(147, 161);
			this->check_inverse->Name = L"check_inverse";
			this->check_inverse->Size = System::Drawing::Size(61, 17);
			this->check_inverse->TabIndex = 39;
			this->check_inverse->Text = L"Inverse";
			this->check_inverse->UseVisualStyleBackColor = true;
			// 
			// groupBox14
			// 
			this->groupBox14->Controls->Add(this->rb_real_robot);
			this->groupBox14->Controls->Add(this->rb_simulator);
			this->groupBox14->Location = System::Drawing::Point(12, 129);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(113, 70);
			this->groupBox14->TabIndex = 24;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"Program Select";
			// 
			// rb_real_robot
			// 
			this->rb_real_robot->AutoSize = true;
			this->rb_real_robot->Location = System::Drawing::Point(17, 45);
			this->rb_real_robot->Name = L"rb_real_robot";
			this->rb_real_robot->Size = System::Drawing::Size(87, 17);
			this->rb_real_robot->TabIndex = 21;
			this->rb_real_robot->TabStop = true;
			this->rb_real_robot->Text = L"Fanuc Robot";
			this->rb_real_robot->UseVisualStyleBackColor = true;
			// 
			// rb_simulator
			// 
			this->rb_simulator->AutoSize = true;
			this->rb_simulator->Location = System::Drawing::Point(17, 22);
			this->rb_simulator->Name = L"rb_simulator";
			this->rb_simulator->Size = System::Drawing::Size(68, 17);
			this->rb_simulator->TabIndex = 20;
			this->rb_simulator->TabStop = true;
			this->rb_simulator->Text = L"Simulator";
			this->rb_simulator->UseVisualStyleBackColor = true;
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->tb_speed);
			this->groupBox13->Controls->Add(this->button12);
			this->groupBox13->Controls->Add(this->button13);
			this->groupBox13->Location = System::Drawing::Point(131, 23);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(113, 63);
			this->groupBox13->TabIndex = 24;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"Speed";
			// 
			// tb_speed
			// 
			this->tb_speed->Location = System::Drawing::Point(42, 27);
			this->tb_speed->Name = L"tb_speed";
			this->tb_speed->Size = System::Drawing::Size(35, 20);
			this->tb_speed->TabIndex = 40;
			this->tb_speed->Text = L"0";
			this->tb_speed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(78, 24);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(25, 25);
			this->button12->TabIndex = 23;
			this->button12->Text = L">";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(16, 24);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(25, 25);
			this->button13->TabIndex = 22;
			this->button13->Text = L"<";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->label_scale_factor);
			this->groupBox12->Controls->Add(this->btnScaleUp);
			this->groupBox12->Controls->Add(this->btnScaleDown);
			this->groupBox12->Location = System::Drawing::Point(131, 92);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(113, 63);
			this->groupBox12->TabIndex = 21;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Scaling Factor";
			// 
			// label_scale_factor
			// 
			this->label_scale_factor->Location = System::Drawing::Point(42, 27);
			this->label_scale_factor->Name = L"label_scale_factor";
			this->label_scale_factor->Size = System::Drawing::Size(35, 20);
			this->label_scale_factor->TabIndex = 39;
			this->label_scale_factor->Text = L"1.0";
			this->label_scale_factor->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnScaleUp
			// 
			this->btnScaleUp->Location = System::Drawing::Point(78, 24);
			this->btnScaleUp->Name = L"btnScaleUp";
			this->btnScaleUp->Size = System::Drawing::Size(25, 25);
			this->btnScaleUp->TabIndex = 23;
			this->btnScaleUp->Text = L">";
			this->btnScaleUp->UseVisualStyleBackColor = true;
			this->btnScaleUp->Click += gcnew System::EventHandler(this, &MainForm::btnScaleUp_Click);
			// 
			// btnScaleDown
			// 
			this->btnScaleDown->Location = System::Drawing::Point(16, 24);
			this->btnScaleDown->Name = L"btnScaleDown";
			this->btnScaleDown->Size = System::Drawing::Size(25, 25);
			this->btnScaleDown->TabIndex = 22;
			this->btnScaleDown->Text = L"<";
			this->btnScaleDown->UseVisualStyleBackColor = true;
			this->btnScaleDown->Click += gcnew System::EventHandler(this, &MainForm::btnScaleDown_Click);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->rb_wpr);
			this->groupBox11->Controls->Add(this->rb_xyz);
			this->groupBox11->Controls->Add(this->rb_xyzwpr);
			this->groupBox11->Location = System::Drawing::Point(12, 23);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(113, 100);
			this->groupBox11->TabIndex = 20;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Mode";
			// 
			// rb_wpr
			// 
			this->rb_wpr->AutoSize = true;
			this->rb_wpr->Location = System::Drawing::Point(17, 70);
			this->rb_wpr->Name = L"rb_wpr";
			this->rb_wpr->Size = System::Drawing::Size(57, 17);
			this->rb_wpr->TabIndex = 21;
			this->rb_wpr->TabStop = true;
			this->rb_wpr->Text = L"W-P-R";
			this->rb_wpr->UseVisualStyleBackColor = true;
			// 
			// rb_xyz
			// 
			this->rb_xyz->AutoSize = true;
			this->rb_xyz->Location = System::Drawing::Point(17, 47);
			this->rb_xyz->Name = L"rb_xyz";
			this->rb_xyz->Size = System::Drawing::Size(52, 17);
			this->rb_xyz->TabIndex = 20;
			this->rb_xyz->TabStop = true;
			this->rb_xyz->Text = L"X-Y-Z";
			this->rb_xyz->UseVisualStyleBackColor = true;
			// 
			// rb_xyzwpr
			// 
			this->rb_xyzwpr->AutoSize = true;
			this->rb_xyzwpr->Location = System::Drawing::Point(17, 24);
			this->rb_xyzwpr->Name = L"rb_xyzwpr";
			this->rb_xyzwpr->Size = System::Drawing::Size(72, 17);
			this->rb_xyzwpr->TabIndex = 19;
			this->rb_xyzwpr->TabStop = true;
			this->rb_xyzwpr->Text = L"XYZWPR";
			this->rb_xyzwpr->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 205);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(78, 24);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Home";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click_1);
			// 
			// btnTeaching
			// 
			this->btnTeaching->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTeaching.BackgroundImage")));
			this->btnTeaching->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnTeaching->Location = System::Drawing::Point(184, 213);
			this->btnTeaching->Name = L"btnTeaching";
			this->btnTeaching->Size = System::Drawing::Size(50, 50);
			this->btnTeaching->TabIndex = 17;
			this->btnTeaching->UseVisualStyleBackColor = true;
			this->btnTeaching->Click += gcnew System::EventHandler(this, &MainForm::btnTeaching_Click);
			// 
			// tb_joint1
			// 
			this->tb_joint1->Location = System::Drawing::Point(288, 406);
			this->tb_joint1->Name = L"tb_joint1";
			this->tb_joint1->Size = System::Drawing::Size(35, 20);
			this->tb_joint1->TabIndex = 31;
			this->tb_joint1->Text = L"0";
			this->tb_joint1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_joint2
			// 
			this->tb_joint2->Location = System::Drawing::Point(329, 406);
			this->tb_joint2->Name = L"tb_joint2";
			this->tb_joint2->Size = System::Drawing::Size(35, 20);
			this->tb_joint2->TabIndex = 32;
			this->tb_joint2->Text = L"0";
			this->tb_joint2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_joint5
			// 
			this->tb_joint5->Location = System::Drawing::Point(452, 406);
			this->tb_joint5->Name = L"tb_joint5";
			this->tb_joint5->Size = System::Drawing::Size(35, 20);
			this->tb_joint5->TabIndex = 33;
			this->tb_joint5->Text = L"0";
			this->tb_joint5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_joint6
			// 
			this->tb_joint6->Location = System::Drawing::Point(493, 406);
			this->tb_joint6->Name = L"tb_joint6";
			this->tb_joint6->Size = System::Drawing::Size(35, 20);
			this->tb_joint6->TabIndex = 36;
			this->tb_joint6->Text = L"0";
			this->tb_joint6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_joint4
			// 
			this->tb_joint4->Location = System::Drawing::Point(411, 406);
			this->tb_joint4->Name = L"tb_joint4";
			this->tb_joint4->Size = System::Drawing::Size(35, 20);
			this->tb_joint4->TabIndex = 35;
			this->tb_joint4->Text = L"0";
			this->tb_joint4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_joint3
			// 
			this->tb_joint3->Location = System::Drawing::Point(370, 406);
			this->tb_joint3->Name = L"tb_joint3";
			this->tb_joint3->Size = System::Drawing::Size(35, 20);
			this->tb_joint3->TabIndex = 34;
			this->tb_joint3->Text = L"0";
			this->tb_joint3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_set_joint
			// 
			this->btn_set_joint->Location = System::Drawing::Point(452, 435);
			this->btn_set_joint->Name = L"btn_set_joint";
			this->btn_set_joint->Size = System::Drawing::Size(79, 23);
			this->btn_set_joint->TabIndex = 37;
			this->btn_set_joint->Text = L"Set Joint";
			this->btn_set_joint->UseVisualStyleBackColor = true;
			this->btn_set_joint->Click += gcnew System::EventHandler(this, &MainForm::btn_set_joint_Click);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(285, 384);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(75, 13);
			this->label32->TabIndex = 21;
			this->label32->Text = L"Joint Position :";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(367, 435);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(79, 23);
			this->button9->TabIndex = 38;
			this->button9->Text = L"Read Joint";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MainForm::button9_Click);
			// 
			// timer2
			// 
			this->timer2->Interval = 50;
			this->timer2->Tick += gcnew System::EventHandler(this, &MainForm::timer2_Tick);
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->label16);
			this->groupBox15->Controls->Add(this->tb_ipaddress);
			this->groupBox15->Controls->Add(this->labelRobotConnState);
			this->groupBox15->Controls->Add(this->btnConnect);
			this->groupBox15->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox15->Location = System::Drawing::Point(12, 27);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox15->Size = System::Drawing::Size(164, 85);
			this->groupBox15->TabIndex = 44;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"Robot";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 17);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(64, 13);
			this->label16->TabIndex = 20;
			this->label16->Text = L"IP Address :";
			// 
			// tb_ipaddress
			// 
			this->tb_ipaddress->Location = System::Drawing::Point(8, 36);
			this->tb_ipaddress->Name = L"tb_ipaddress";
			this->tb_ipaddress->Size = System::Drawing::Size(78, 20);
			this->tb_ipaddress->TabIndex = 12;
			this->tb_ipaddress->Text = L"192.168.0.100";
			this->tb_ipaddress->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelRobotConnState
			// 
			this->labelRobotConnState->AutoSize = true;
			this->labelRobotConnState->BackColor = System::Drawing::Color::Red;
			this->labelRobotConnState->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelRobotConnState->ForeColor = System::Drawing::Color::White;
			this->labelRobotConnState->Location = System::Drawing::Point(10, 62);
			this->labelRobotConnState->Name = L"labelRobotConnState";
			this->labelRobotConnState->Size = System::Drawing::Size(73, 13);
			this->labelRobotConnState->TabIndex = 20;
			this->labelRobotConnState->Text = L"Disconnected";
			// 
			// btnConnect
			// 
			this->btnConnect->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConnect.BackgroundImage")));
			this->btnConnect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnConnect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnConnect->Location = System::Drawing::Point(98, 15);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(60, 60);
			this->btnConnect->TabIndex = 16;
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button7
			// 
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Location = System::Drawing::Point(94, 44);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(35, 35);
			this->button7->TabIndex = 26;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// button11
			// 
			this->button11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.BackgroundImage")));
			this->button11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button11->Location = System::Drawing::Point(771, 435);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(35, 35);
			this->button11->TabIndex = 45;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MainForm::button11_Click);
			// 
			// button14
			// 
			this->button14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.BackgroundImage")));
			this->button14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button14->Location = System::Drawing::Point(812, 435);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(35, 35);
			this->button14->TabIndex = 46;
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.BackgroundImage")));
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button15->Location = System::Drawing::Point(643, 435);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(35, 35);
			this->button15->TabIndex = 48;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button16.BackgroundImage")));
			this->button16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button16->Location = System::Drawing::Point(684, 436);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(35, 35);
			this->button16->TabIndex = 47;
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(420, 353);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(91, 28);
			this->button10->TabIndex = 28;
			this->button10->Text = L"Record Force";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MainForm::button10_Click);
			// 
			// button17
			// 
			this->button17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.BackgroundImage")));
			this->button17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button17->Location = System::Drawing::Point(519, 353);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(32, 28);
			this->button17->TabIndex = 49;
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MainForm::button17_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(922, 505);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->groupBox15);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->btn_set_joint);
			this->Controls->Add(this->tb_joint6);
			this->Controls->Add(this->tb_joint4);
			this->Controls->Add(this->tb_joint3);
			this->Controls->Add(this->tb_joint5);
			this->Controls->Add(this->tb_joint2);
			this->Controls->Add(this->tb_joint1);
			this->Controls->Add(this->groupBox10);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->btnSimConnect);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Robot Polishing Demo";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->groupBox14->ResumeLayout(false);
			this->groupBox14->PerformLayout();
			this->groupBox13->ResumeLayout(false);
			this->groupBox13->PerformLayout();
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->groupBox15->ResumeLayout(false);
			this->groupBox15->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSimConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		coppeliasim_connect();
	}
private: System::Void hapticOpenMenu_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_connect();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_test_move();
}
private: System::Void btnHapticRecord_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_record();
}
private: System::Void hapticStopRecord_Click(System::Object^  sender, System::EventArgs^  e) {
	//haptic_record_stop();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_readpos();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = true;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	OnTimer1();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_record();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_play_motion();
}
private: System::Void btnHapticConnect_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_connect();
}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	system_init();
}

private: System::Void btnTeaching_Click(System::Object^  sender, System::EventArgs^  e) {
	start_teaching_mode();
}
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	robot_move_to_home();
}
private: System::Void btn_set_joint_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_set_joint();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_read_joint();
}
private: System::Void btnScaleUp_Click(System::Object^  sender, System::EventArgs^  e) {
	button_scale_up();
}
private: System::Void btnScaleDown_Click(System::Object^  sender, System::EventArgs^  e) {
	button_scale_down();
}

private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer_2();
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	record_force();
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	record_force_stop();
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

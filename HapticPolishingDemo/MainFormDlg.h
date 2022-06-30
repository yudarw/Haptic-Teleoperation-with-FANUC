#pragma once
#include "Fanuc.h"
#include "OpenHaptic.h"
#include "TrajectoryForm.h"
#include "CustomFormDlg.h"
#include "ForceCalibrationForm.h"

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewForm
	/// </summary>
	public ref class MainFormDlg : public System::Windows::Forms::Form
	{
	public:
		MainFormDlg(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void on_init();
		void on_timer();

		void haptic_connect();
		void haptic_update();
		void haptic_initpos();
		void haptic_reset_center_pos();
		void haptic_display_pos(DataPos state);
		void scale_up();
		void scale_down();

		void trajectory_form_setting();
		void show_robot_control_form();

		void robot_connect();
		void robot_move_toInitPos();
		void override_up();
		void override_down();
		void haptic_jog_mode();
		void set_override(int _override);

		void display_position(DataPos position);
		void display_force(DataForce force);
		void display_progState(int state);
		void robot_move_handle();

		void show_menu();
		void close_form();
		void start_program();

		void record_point();
		void stop_record_point();
		void record_force();
		void stop_record_force();
		void save_system_trajectory();
		void show_video_preview();

		void force_sensor_calibration();
		void show_force_calibration_menu();

		void get_current_position();

		void show_coppelia_form();
		void show_new_custom_form();

	public:
		TrajectoryForm ^ myform;
		CustomFormDlg ^ customForm;
		ForceCalibrationForm ^ force_calibration_form;
		







	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
















	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trajectoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveSystemTrajectoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;




























private: System::Windows::Forms::ToolStripMenuItem^  forceRecordToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  forceCalibrationToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  getCurrentPositionToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  coppeliaSimToolStripMenuItem;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  btnRecord;
private: System::Windows::Forms::Button^  btn_haptic_jog;
private: System::Windows::Forms::Button^  btn_start;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
private: System::Windows::Forms::GroupBox^  groupbox;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  btn_browse;
private: System::Windows::Forms::Button^  btn_trajectory_save;
private: System::Windows::Forms::GroupBox^  groupBox12;
private: System::Windows::Forms::TextBox^  textBox22;
private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Panel^  panel8;
private: System::Windows::Forms::Label^  label_config;
private: System::Windows::Forms::Panel^  panel_haptic;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Panel^  panel_jog;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Panel^  panel_robot;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Panel^  panel_move;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Panel^  panel_prog;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TextBox^  tb_hapticR;
private: System::Windows::Forms::TextBox^  tb_hapticP;
private: System::Windows::Forms::TextBox^  tb_hapticW;
private: System::Windows::Forms::TextBox^  tb_hapticZ;
private: System::Windows::Forms::TextBox^  tb_hapticY;
private: System::Windows::Forms::TextBox^  tb_hapticX;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TextBox^  tbPosR;
private: System::Windows::Forms::TextBox^  tbPosP;
private: System::Windows::Forms::TextBox^  tbPosW;
private: System::Windows::Forms::TextBox^  tbPosZ;
private: System::Windows::Forms::TextBox^  tbPosY;
private: System::Windows::Forms::TextBox^  tbPosX;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::TextBox^  label_mz;
private: System::Windows::Forms::TextBox^  label_my;
private: System::Windows::Forms::TextBox^  label_mx;
private: System::Windows::Forms::TextBox^  label_fz;
private: System::Windows::Forms::TextBox^  label_fy;
private: System::Windows::Forms::TextBox^  label_fx;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::ProgressBar^  fx_bar;
private: System::Windows::Forms::ProgressBar^  fy_bar;
private: System::Windows::Forms::ProgressBar^  fz_bar;
private: System::Windows::Forms::ProgressBar^  mx_bar;
private: System::Windows::Forms::ProgressBar^  my_bar;
private: System::Windows::Forms::ProgressBar^  mz_bar;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Button^  btn_robot_initpos;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::ComboBox^  ip_address_box;
private: System::Windows::Forms::Panel^  robot_connect_indicator;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::Label^  label_override;
private: System::Windows::Forms::Button^  btn_override_up;
private: System::Windows::Forms::Button^  btn_overide_down;
private: System::Windows::Forms::Button^  btn_robot_connect;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::RadioButton^  rb_xyzwpr_mode;
private: System::Windows::Forms::RadioButton^  rb_xyz_mode;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  tb_robot_initW;
private: System::Windows::Forms::TextBox^  tb_robot_initR;
private: System::Windows::Forms::TextBox^  tb_robot_initX;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TextBox^  tb_robot_initP;
private: System::Windows::Forms::TextBox^  tb_robot_initY;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::TextBox^  tb_robot_initZ;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Button^  btn_haptic_update;
private: System::Windows::Forms::Panel^  haptic_connect_indicator;
private: System::Windows::Forms::Button^  btn_haptic_moveinitpos;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Label^  label_scale_factor;
private: System::Windows::Forms::Button^  btn_scale_up;
private: System::Windows::Forms::Button^  btn_scale_down;
private: System::Windows::Forms::Button^  btn_haptic_connect;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::TextBox^  tb_haptic_initZ;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  tb_haptic_initY;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::TextBox^  tb_haptic_initX;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::RadioButton^  rb_noeffect;
private: System::Windows::Forms::NumericUpDown^  magnitude_box;
private: System::Windows::Forms::NumericUpDown^  gain_box;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::RadioButton^  rb_spring;
private: System::Windows::Forms::RadioButton^  rb_friction;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
private: System::Windows::Forms::ToolStripMenuItem^  extraToolStripMenuItem;








	private: System::Windows::Forms::Timer^  timer2;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainFormDlg()
		{
			if (components)
			{
				delete components;
			}
		}



	protected:

	protected:


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label_datetime;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;














































































































































































private: System::Windows::Forms::Timer^  timer1;
private: System::ComponentModel::IContainer^  components;




	protected:






























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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainFormDlg::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label_datetime = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trajectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveSystemTrajectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->forceRecordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->forceCalibrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getCurrentPositionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->coppeliaSimToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->extraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->btnRecord = (gcnew System::Windows::Forms::Button());
			this->btn_haptic_jog = (gcnew System::Windows::Forms::Button());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_browse = (gcnew System::Windows::Forms::Button());
			this->btn_trajectory_save = (gcnew System::Windows::Forms::Button());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label_config = (gcnew System::Windows::Forms::Label());
			this->panel_haptic = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel_jog = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel_robot = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel_move = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel_prog = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->tb_hapticR = (gcnew System::Windows::Forms::TextBox());
			this->tb_hapticP = (gcnew System::Windows::Forms::TextBox());
			this->tb_hapticW = (gcnew System::Windows::Forms::TextBox());
			this->tb_hapticZ = (gcnew System::Windows::Forms::TextBox());
			this->tb_hapticY = (gcnew System::Windows::Forms::TextBox());
			this->tb_hapticX = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tbPosR = (gcnew System::Windows::Forms::TextBox());
			this->tbPosP = (gcnew System::Windows::Forms::TextBox());
			this->tbPosW = (gcnew System::Windows::Forms::TextBox());
			this->tbPosZ = (gcnew System::Windows::Forms::TextBox());
			this->tbPosY = (gcnew System::Windows::Forms::TextBox());
			this->tbPosX = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label_mz = (gcnew System::Windows::Forms::TextBox());
			this->label_my = (gcnew System::Windows::Forms::TextBox());
			this->label_mx = (gcnew System::Windows::Forms::TextBox());
			this->label_fz = (gcnew System::Windows::Forms::TextBox());
			this->label_fy = (gcnew System::Windows::Forms::TextBox());
			this->label_fx = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->fx_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->fy_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->fz_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->mx_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->my_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->mz_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_robot_initpos = (gcnew System::Windows::Forms::Button());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->ip_address_box = (gcnew System::Windows::Forms::ComboBox());
			this->robot_connect_indicator = (gcnew System::Windows::Forms::Panel());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label_override = (gcnew System::Windows::Forms::Label());
			this->btn_override_up = (gcnew System::Windows::Forms::Button());
			this->btn_overide_down = (gcnew System::Windows::Forms::Button());
			this->btn_robot_connect = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->rb_xyzwpr_mode = (gcnew System::Windows::Forms::RadioButton());
			this->rb_xyz_mode = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->tb_robot_initW = (gcnew System::Windows::Forms::TextBox());
			this->tb_robot_initR = (gcnew System::Windows::Forms::TextBox());
			this->tb_robot_initX = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->tb_robot_initP = (gcnew System::Windows::Forms::TextBox());
			this->tb_robot_initY = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->tb_robot_initZ = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_haptic_update = (gcnew System::Windows::Forms::Button());
			this->haptic_connect_indicator = (gcnew System::Windows::Forms::Panel());
			this->btn_haptic_moveinitpos = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label_scale_factor = (gcnew System::Windows::Forms::Label());
			this->btn_scale_up = (gcnew System::Windows::Forms::Button());
			this->btn_scale_down = (gcnew System::Windows::Forms::Button());
			this->btn_haptic_connect = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->tb_haptic_initZ = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->tb_haptic_initY = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->tb_haptic_initX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->rb_noeffect = (gcnew System::Windows::Forms::RadioButton());
			this->magnitude_box = (gcnew System::Windows::Forms::NumericUpDown());
			this->gain_box = (gcnew System::Windows::Forms::NumericUpDown());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->rb_spring = (gcnew System::Windows::Forms::RadioButton());
			this->rb_friction = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupbox->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel_haptic->SuspendLayout();
			this->panel_jog->SuspendLayout();
			this->panel_robot->SuspendLayout();
			this->panel_move->SuspendLayout();
			this->panel_prog->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magnitude_box))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gain_box))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label_datetime);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 28);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1078, 49);
			this->panel1->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(4, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(49, 46);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// label_datetime
			// 
			this->label_datetime->AutoSize = true;
			this->label_datetime->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_datetime->ForeColor = System::Drawing::Color::White;
			this->label_datetime->Location = System::Drawing::Point(907, 11);
			this->label_datetime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_datetime->Name = L"label_datetime";
			this->label_datetime->Size = System::Drawing::Size(94, 23);
			this->label_datetime->TabIndex = 2;
			this->label_datetime->Text = L"8/11/2020";
			this->label_datetime->Click += gcnew System::EventHandler(this, &MainFormDlg::label3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(281, 11);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(323, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"AUTOMATIC POLISHING SYSTEM";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainFormDlg::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 10;
			this->timer2->Tick += gcnew System::EventHandler(this, &MainFormDlg::timer2_Tick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainFormDlg::backgroundWorker1_DoWork);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->fileToolStripMenuItem,
					this->trajectoryToolStripMenuItem, this->forceRecordToolStripMenuItem, this->settingToolStripMenuItem, this->aboutToolStripMenuItem,
					this->getCurrentPositionToolStripMenuItem, this->coppeliaSimToolStripMenuItem, this->extraToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1078, 28);
			this->menuStrip1->TabIndex = 43;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MainFormDlg::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// trajectoryToolStripMenuItem
			// 
			this->trajectoryToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->saveSystemTrajectoryToolStripMenuItem });
			this->trajectoryToolStripMenuItem->Name = L"trajectoryToolStripMenuItem";
			this->trajectoryToolStripMenuItem->Size = System::Drawing::Size(86, 24);
			this->trajectoryToolStripMenuItem->Text = L"Trajectory";
			// 
			// saveSystemTrajectoryToolStripMenuItem
			// 
			this->saveSystemTrajectoryToolStripMenuItem->Name = L"saveSystemTrajectoryToolStripMenuItem";
			this->saveSystemTrajectoryToolStripMenuItem->Size = System::Drawing::Size(235, 26);
			this->saveSystemTrajectoryToolStripMenuItem->Text = L"Save System Trajectory";
			this->saveSystemTrajectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFormDlg::saveSystemTrajectoryToolStripMenuItem_Click);
			// 
			// forceRecordToolStripMenuItem
			// 
			this->forceRecordToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->forceCalibrationToolStripMenuItem });
			this->forceRecordToolStripMenuItem->Name = L"forceRecordToolStripMenuItem";
			this->forceRecordToolStripMenuItem->Size = System::Drawing::Size(108, 24);
			this->forceRecordToolStripMenuItem->Text = L"Force Record";
			// 
			// forceCalibrationToolStripMenuItem
			// 
			this->forceCalibrationToolStripMenuItem->Name = L"forceCalibrationToolStripMenuItem";
			this->forceCalibrationToolStripMenuItem->Size = System::Drawing::Size(195, 26);
			this->forceCalibrationToolStripMenuItem->Text = L"Force calibration";
			this->forceCalibrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFormDlg::forceCalibrationToolStripMenuItem_Click);
			// 
			// settingToolStripMenuItem
			// 
			this->settingToolStripMenuItem->Name = L"settingToolStripMenuItem";
			this->settingToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->settingToolStripMenuItem->Text = L"Setting";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(62, 24);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// getCurrentPositionToolStripMenuItem
			// 
			this->getCurrentPositionToolStripMenuItem->Name = L"getCurrentPositionToolStripMenuItem";
			this->getCurrentPositionToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->getCurrentPositionToolStripMenuItem->Text = L"Get Current Position";
			this->getCurrentPositionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFormDlg::getCurrentPositionToolStripMenuItem_Click);
			// 
			// coppeliaSimToolStripMenuItem
			// 
			this->coppeliaSimToolStripMenuItem->Name = L"coppeliaSimToolStripMenuItem";
			this->coppeliaSimToolStripMenuItem->Size = System::Drawing::Size(106, 24);
			this->coppeliaSimToolStripMenuItem->Text = L"CoppeliaSim";
			this->coppeliaSimToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFormDlg::coppeliaSimToolStripMenuItem_Click);
			// 
			// extraToolStripMenuItem
			// 
			this->extraToolStripMenuItem->Name = L"extraToolStripMenuItem";
			this->extraToolStripMenuItem->Size = System::Drawing::Size(54, 24);
			this->extraToolStripMenuItem->Text = L"Extra";
			this->extraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFormDlg::extraToolStripMenuItem_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 283)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 265)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 86)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1071, 641);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 6;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				103)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->Controls->Add(this->button2, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->button4, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->button5, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->btnRecord, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn_haptic_jog, 4, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn_start, 5, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(4, 552);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 79)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 79)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(1063, 78);
			this->tableLayoutPanel5->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Location = System::Drawing::Point(4, 4);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 71);
			this->button2->TabIndex = 42;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainFormDlg::button2_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(299, 4);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(184, 71);
			this->button4->TabIndex = 40;
			this->button4->Text = L"Force Calibration";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainFormDlg::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(107, 4);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(184, 71);
			this->button5->TabIndex = 41;
			this->button5->Text = L"Robot Control";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainFormDlg::button5_Click);
			// 
			// btnRecord
			// 
			this->btnRecord->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnRecord->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRecord->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRecord->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRecord->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRecord->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRecord->Location = System::Drawing::Point(491, 4);
			this->btnRecord->Margin = System::Windows::Forms::Padding(4);
			this->btnRecord->Name = L"btnRecord";
			this->btnRecord->Size = System::Drawing::Size(184, 71);
			this->btnRecord->TabIndex = 2;
			this->btnRecord->Text = L"Record";
			this->btnRecord->UseVisualStyleBackColor = false;
			this->btnRecord->Click += gcnew System::EventHandler(this, &MainFormDlg::btnRecord_Click);
			// 
			// btn_haptic_jog
			// 
			this->btn_haptic_jog->BackColor = System::Drawing::Color::Gold;
			this->btn_haptic_jog->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_haptic_jog->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_haptic_jog->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_haptic_jog->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_haptic_jog->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_haptic_jog->Location = System::Drawing::Point(683, 4);
			this->btn_haptic_jog->Margin = System::Windows::Forms::Padding(4);
			this->btn_haptic_jog->Name = L"btn_haptic_jog";
			this->btn_haptic_jog->Size = System::Drawing::Size(184, 71);
			this->btn_haptic_jog->TabIndex = 1;
			this->btn_haptic_jog->Text = L"Haptic Jog";
			this->btn_haptic_jog->UseVisualStyleBackColor = false;
			this->btn_haptic_jog->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_haptic_jog_Click);
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::Color::LimeGreen;
			this->btn_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_start->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_start->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_start->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_start->Location = System::Drawing::Point(875, 4);
			this->btn_start->Margin = System::Windows::Forms::Padding(4);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(184, 71);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Start";
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_start_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				505)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				323)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				530)));
			this->tableLayoutPanel3->Controls->Add(this->groupbox, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->panel2, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->panel3, 1, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1063, 275);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// groupbox
			// 
			this->groupbox->Controls->Add(this->button1);
			this->groupbox->Controls->Add(this->btn_browse);
			this->groupbox->Controls->Add(this->btn_trajectory_save);
			this->groupbox->Controls->Add(this->groupBox12);
			this->groupbox->Controls->Add(this->groupBox11);
			this->groupbox->ForeColor = System::Drawing::Color::Lime;
			this->groupbox->Location = System::Drawing::Point(832, 4);
			this->groupbox->Margin = System::Windows::Forms::Padding(4);
			this->groupbox->Name = L"groupbox";
			this->groupbox->Padding = System::Windows::Forms::Padding(4);
			this->groupbox->Size = System::Drawing::Size(223, 267);
			this->groupbox->TabIndex = 39;
			this->groupbox->TabStop = false;
			this->groupbox->Text = L"Trajectory Planning";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(12, 209);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 47);
			this->button1->TabIndex = 42;
			this->button1->Text = L"Trajectory Setting";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainFormDlg::button1_Click);
			// 
			// btn_browse
			// 
			this->btn_browse->ForeColor = System::Drawing::Color::Black;
			this->btn_browse->Location = System::Drawing::Point(12, 177);
			this->btn_browse->Margin = System::Windows::Forms::Padding(4);
			this->btn_browse->Name = L"btn_browse";
			this->btn_browse->Size = System::Drawing::Size(92, 28);
			this->btn_browse->TabIndex = 37;
			this->btn_browse->Text = L"Browse";
			this->btn_browse->UseVisualStyleBackColor = true;
			this->btn_browse->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_browse_Click);
			// 
			// btn_trajectory_save
			// 
			this->btn_trajectory_save->ForeColor = System::Drawing::Color::Black;
			this->btn_trajectory_save->Location = System::Drawing::Point(115, 177);
			this->btn_trajectory_save->Margin = System::Windows::Forms::Padding(4);
			this->btn_trajectory_save->Name = L"btn_trajectory_save";
			this->btn_trajectory_save->Size = System::Drawing::Size(84, 28);
			this->btn_trajectory_save->TabIndex = 1;
			this->btn_trajectory_save->Text = L"Save";
			this->btn_trajectory_save->UseVisualStyleBackColor = true;
			this->btn_trajectory_save->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_trajectory_save_Click);
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->textBox22);
			this->groupBox12->ForeColor = System::Drawing::Color::White;
			this->groupBox12->Location = System::Drawing::Point(8, 114);
			this->groupBox12->Margin = System::Windows::Forms::Padding(4);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Padding = System::Windows::Forms::Padding(4);
			this->groupBox12->Size = System::Drawing::Size(196, 55);
			this->groupBox12->TabIndex = 36;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Filename";
			// 
			// textBox22
			// 
			this->textBox22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox22->ForeColor = System::Drawing::Color::Yellow;
			this->textBox22->Location = System::Drawing::Point(12, 23);
			this->textBox22->Margin = System::Windows::Forms::Padding(4);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(173, 15);
			this->textBox22->TabIndex = 6;
			this->textBox22->Text = L"polishing_trajectory.txt";
			this->textBox22->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->button13);
			this->groupBox11->Controls->Add(this->button15);
			this->groupBox11->Controls->Add(this->button14);
			this->groupBox11->ForeColor = System::Drawing::Color::White;
			this->groupBox11->Location = System::Drawing::Point(8, 23);
			this->groupBox11->Margin = System::Windows::Forms::Padding(4);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Padding = System::Windows::Forms::Padding(4);
			this->groupBox11->Size = System::Drawing::Size(196, 84);
			this->groupBox11->TabIndex = 35;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Record";
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.BackgroundImage")));
			this->button13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::Black;
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(12, 22);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(51, 47);
			this->button13->TabIndex = 32;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MainFormDlg::button13_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.BackgroundImage")));
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button15->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::Black;
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(135, 22);
			this->button15->Margin = System::Windows::Forms::Padding(4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(51, 47);
			this->button15->TabIndex = 34;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MainFormDlg::button15_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.BackgroundImage")));
			this->button14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button14->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(73, 22);
			this->button14->Margin = System::Windows::Forms::Padding(4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(51, 47);
			this->button14->TabIndex = 33;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MainFormDlg::button14_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->panel8);
			this->panel2->Controls->Add(this->panel_haptic);
			this->panel2->Controls->Add(this->panel_jog);
			this->panel2->Controls->Add(this->panel_robot);
			this->panel2->Controls->Add(this->panel_move);
			this->panel2->Controls->Add(this->panel_prog);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->tb_hapticR);
			this->panel2->Controls->Add(this->tb_hapticP);
			this->panel2->Controls->Add(this->tb_hapticW);
			this->panel2->Controls->Add(this->tb_hapticZ);
			this->panel2->Controls->Add(this->tb_hapticY);
			this->panel2->Controls->Add(this->tb_hapticX);
			this->panel2->Controls->Add(this->label21);
			this->panel2->Controls->Add(this->label23);
			this->panel2->Controls->Add(this->label25);
			this->panel2->Controls->Add(this->label27);
			this->panel2->Controls->Add(this->label29);
			this->panel2->Controls->Add(this->label30);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->tbPosR);
			this->panel2->Controls->Add(this->tbPosP);
			this->panel2->Controls->Add(this->tbPosW);
			this->panel2->Controls->Add(this->tbPosZ);
			this->panel2->Controls->Add(this->tbPosY);
			this->panel2->Controls->Add(this->tbPosX);
			this->panel2->Controls->Add(this->label24);
			this->panel2->Controls->Add(this->label26);
			this->panel2->Controls->Add(this->label28);
			this->panel2->Controls->Add(this->label22);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->label17);
			this->panel2->Location = System::Drawing::Point(4, 4);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(492, 267);
			this->panel2->TabIndex = 28;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel8->Controls->Add(this->label_config);
			this->panel8->ForeColor = System::Drawing::Color::Black;
			this->panel8->Location = System::Drawing::Point(11, 229);
			this->panel8->Margin = System::Windows::Forms::Padding(4);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(101, 23);
			this->panel8->TabIndex = 58;
			// 
			// label_config
			// 
			this->label_config->AutoSize = true;
			this->label_config->ForeColor = System::Drawing::Color::Black;
			this->label_config->Location = System::Drawing::Point(4, 4);
			this->label_config->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_config->Name = L"label_config";
			this->label_config->Size = System::Drawing::Size(88, 17);
			this->label_config->TabIndex = 56;
			this->label_config->Text = L"NRUT 0 0 -1";
			// 
			// panel_haptic
			// 
			this->panel_haptic->BackColor = System::Drawing::Color::Red;
			this->panel_haptic->Controls->Add(this->label12);
			this->panel_haptic->ForeColor = System::Drawing::Color::Black;
			this->panel_haptic->Location = System::Drawing::Point(192, 229);
			this->panel_haptic->Margin = System::Windows::Forms::Padding(4);
			this->panel_haptic->Name = L"panel_haptic";
			this->panel_haptic->Size = System::Drawing::Size(65, 23);
			this->panel_haptic->TabIndex = 58;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(4, 4);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(57, 17);
			this->label12->TabIndex = 56;
			this->label12->Text = L"HAPTIC";
			// 
			// panel_jog
			// 
			this->panel_jog->BackColor = System::Drawing::Color::Yellow;
			this->panel_jog->Controls->Add(this->label10);
			this->panel_jog->ForeColor = System::Drawing::Color::Black;
			this->panel_jog->Location = System::Drawing::Point(395, 229);
			this->panel_jog->Margin = System::Windows::Forms::Padding(4);
			this->panel_jog->Name = L"panel_jog";
			this->panel_jog->Size = System::Drawing::Size(57, 23);
			this->panel_jog->TabIndex = 58;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(8, 4);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 17);
			this->label10->TabIndex = 56;
			this->label10->Text = L"JOG";
			// 
			// panel_robot
			// 
			this->panel_robot->BackColor = System::Drawing::Color::Red;
			this->panel_robot->Controls->Add(this->label11);
			this->panel_robot->ForeColor = System::Drawing::Color::Black;
			this->panel_robot->Location = System::Drawing::Point(120, 229);
			this->panel_robot->Margin = System::Windows::Forms::Padding(4);
			this->panel_robot->Name = L"panel_robot";
			this->panel_robot->Size = System::Drawing::Size(65, 23);
			this->panel_robot->TabIndex = 57;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(4, 4);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(58, 17);
			this->label11->TabIndex = 56;
			this->label11->Text = L"ROBOT";
			// 
			// panel_move
			// 
			this->panel_move->BackColor = System::Drawing::Color::Red;
			this->panel_move->Controls->Add(this->label3);
			this->panel_move->ForeColor = System::Drawing::Color::Black;
			this->panel_move->Location = System::Drawing::Point(329, 229);
			this->panel_move->Margin = System::Windows::Forms::Padding(4);
			this->panel_move->Name = L"panel_move";
			this->panel_move->Size = System::Drawing::Size(57, 23);
			this->panel_move->TabIndex = 57;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(4, 4);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 17);
			this->label3->TabIndex = 56;
			this->label3->Text = L"MOVE";
			// 
			// panel_prog
			// 
			this->panel_prog->BackColor = System::Drawing::Color::Red;
			this->panel_prog->Controls->Add(this->label2);
			this->panel_prog->ForeColor = System::Drawing::Color::Black;
			this->panel_prog->Location = System::Drawing::Point(264, 229);
			this->panel_prog->Margin = System::Windows::Forms::Padding(4);
			this->panel_prog->Name = L"panel_prog";
			this->panel_prog->Size = System::Drawing::Size(57, 23);
			this->panel_prog->TabIndex = 55;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(4, 4);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 17);
			this->label2->TabIndex = 56;
			this->label2->Text = L"CYCLE";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Lime;
			this->label19->Location = System::Drawing::Point(268, 9);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(161, 24);
			this->label19->TabIndex = 48;
			this->label19->Text = L"Haptic Position :";
			// 
			// tb_hapticR
			// 
			this->tb_hapticR->BackColor = System::Drawing::Color::Black;
			this->tb_hapticR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_hapticR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_hapticR->ForeColor = System::Drawing::Color::White;
			this->tb_hapticR->Location = System::Drawing::Point(327, 201);
			this->tb_hapticR->Margin = System::Windows::Forms::Padding(4);
			this->tb_hapticR->Name = L"tb_hapticR";
			this->tb_hapticR->Size = System::Drawing::Size(104, 23);
			this->tb_hapticR->TabIndex = 47;
			this->tb_hapticR->Text = L"0.00";
			this->tb_hapticR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_hapticP
			// 
			this->tb_hapticP->BackColor = System::Drawing::Color::Black;
			this->tb_hapticP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_hapticP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_hapticP->ForeColor = System::Drawing::Color::White;
			this->tb_hapticP->Location = System::Drawing::Point(327, 170);
			this->tb_hapticP->Margin = System::Windows::Forms::Padding(4);
			this->tb_hapticP->Name = L"tb_hapticP";
			this->tb_hapticP->Size = System::Drawing::Size(104, 23);
			this->tb_hapticP->TabIndex = 46;
			this->tb_hapticP->Text = L"0.00";
			this->tb_hapticP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_hapticW
			// 
			this->tb_hapticW->BackColor = System::Drawing::Color::Black;
			this->tb_hapticW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_hapticW->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_hapticW->ForeColor = System::Drawing::Color::White;
			this->tb_hapticW->Location = System::Drawing::Point(327, 139);
			this->tb_hapticW->Margin = System::Windows::Forms::Padding(4);
			this->tb_hapticW->Name = L"tb_hapticW";
			this->tb_hapticW->Size = System::Drawing::Size(104, 23);
			this->tb_hapticW->TabIndex = 45;
			this->tb_hapticW->Text = L"0.00";
			this->tb_hapticW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_hapticZ
			// 
			this->tb_hapticZ->BackColor = System::Drawing::Color::Black;
			this->tb_hapticZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_hapticZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_hapticZ->ForeColor = System::Drawing::Color::White;
			this->tb_hapticZ->Location = System::Drawing::Point(327, 108);
			this->tb_hapticZ->Margin = System::Windows::Forms::Padding(4);
			this->tb_hapticZ->Name = L"tb_hapticZ";
			this->tb_hapticZ->Size = System::Drawing::Size(104, 23);
			this->tb_hapticZ->TabIndex = 44;
			this->tb_hapticZ->Text = L"0.00";
			this->tb_hapticZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_hapticY
			// 
			this->tb_hapticY->BackColor = System::Drawing::Color::Black;
			this->tb_hapticY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_hapticY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_hapticY->ForeColor = System::Drawing::Color::White;
			this->tb_hapticY->Location = System::Drawing::Point(327, 78);
			this->tb_hapticY->Margin = System::Windows::Forms::Padding(4);
			this->tb_hapticY->Name = L"tb_hapticY";
			this->tb_hapticY->Size = System::Drawing::Size(104, 23);
			this->tb_hapticY->TabIndex = 43;
			this->tb_hapticY->Text = L"0.00";
			this->tb_hapticY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_hapticX
			// 
			this->tb_hapticX->BackColor = System::Drawing::Color::Black;
			this->tb_hapticX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_hapticX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_hapticX->ForeColor = System::Drawing::Color::White;
			this->tb_hapticX->Location = System::Drawing::Point(327, 47);
			this->tb_hapticX->Margin = System::Windows::Forms::Padding(4);
			this->tb_hapticX->Name = L"tb_hapticX";
			this->tb_hapticX->Size = System::Drawing::Size(104, 23);
			this->tb_hapticX->TabIndex = 42;
			this->tb_hapticX->Text = L"0.00";
			this->tb_hapticX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Lime;
			this->label21->Location = System::Drawing::Point(268, 202);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(24, 24);
			this->label21->TabIndex = 41;
			this->label21->Text = L"R";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Lime;
			this->label23->Location = System::Drawing::Point(268, 171);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(23, 24);
			this->label23->TabIndex = 40;
			this->label23->Text = L"P";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Lime;
			this->label25->Location = System::Drawing::Point(268, 140);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(29, 24);
			this->label25->TabIndex = 39;
			this->label25->Text = L"W";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::Lime;
			this->label27->Location = System::Drawing::Point(269, 106);
			this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(23, 24);
			this->label27->TabIndex = 38;
			this->label27->Text = L"Z";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::Color::Lime;
			this->label29->Location = System::Drawing::Point(269, 76);
			this->label29->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(23, 24);
			this->label29->TabIndex = 37;
			this->label29->Text = L"Y";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::Color::Lime;
			this->label30->Location = System::Drawing::Point(269, 47);
			this->label30->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(25, 24);
			this->label30->TabIndex = 36;
			this->label30->Text = L"X";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Lime;
			this->label18->Location = System::Drawing::Point(24, 9);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(157, 24);
			this->label18->TabIndex = 35;
			this->label18->Text = L"Robot Position :";
			// 
			// tbPosR
			// 
			this->tbPosR->BackColor = System::Drawing::Color::Black;
			this->tbPosR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosR->ForeColor = System::Drawing::Color::White;
			this->tbPosR->Location = System::Drawing::Point(83, 201);
			this->tbPosR->Margin = System::Windows::Forms::Padding(4);
			this->tbPosR->Name = L"tbPosR";
			this->tbPosR->Size = System::Drawing::Size(104, 23);
			this->tbPosR->TabIndex = 34;
			this->tbPosR->Text = L"0.00";
			this->tbPosR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tbPosP
			// 
			this->tbPosP->BackColor = System::Drawing::Color::Black;
			this->tbPosP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosP->ForeColor = System::Drawing::Color::White;
			this->tbPosP->Location = System::Drawing::Point(83, 170);
			this->tbPosP->Margin = System::Windows::Forms::Padding(4);
			this->tbPosP->Name = L"tbPosP";
			this->tbPosP->Size = System::Drawing::Size(104, 23);
			this->tbPosP->TabIndex = 33;
			this->tbPosP->Text = L"0.00";
			this->tbPosP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tbPosW
			// 
			this->tbPosW->BackColor = System::Drawing::Color::Black;
			this->tbPosW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosW->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosW->ForeColor = System::Drawing::Color::White;
			this->tbPosW->Location = System::Drawing::Point(83, 139);
			this->tbPosW->Margin = System::Windows::Forms::Padding(4);
			this->tbPosW->Name = L"tbPosW";
			this->tbPosW->Size = System::Drawing::Size(104, 23);
			this->tbPosW->TabIndex = 32;
			this->tbPosW->Text = L"0.00";
			this->tbPosW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tbPosZ
			// 
			this->tbPosZ->BackColor = System::Drawing::Color::Black;
			this->tbPosZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosZ->ForeColor = System::Drawing::Color::White;
			this->tbPosZ->Location = System::Drawing::Point(83, 108);
			this->tbPosZ->Margin = System::Windows::Forms::Padding(4);
			this->tbPosZ->Name = L"tbPosZ";
			this->tbPosZ->Size = System::Drawing::Size(104, 23);
			this->tbPosZ->TabIndex = 31;
			this->tbPosZ->Text = L"0.00";
			this->tbPosZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tbPosY
			// 
			this->tbPosY->BackColor = System::Drawing::Color::Black;
			this->tbPosY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosY->ForeColor = System::Drawing::Color::White;
			this->tbPosY->Location = System::Drawing::Point(83, 78);
			this->tbPosY->Margin = System::Windows::Forms::Padding(4);
			this->tbPosY->Name = L"tbPosY";
			this->tbPosY->Size = System::Drawing::Size(104, 23);
			this->tbPosY->TabIndex = 30;
			this->tbPosY->Text = L"0.00";
			this->tbPosY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tbPosX
			// 
			this->tbPosX->BackColor = System::Drawing::Color::Black;
			this->tbPosX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosX->ForeColor = System::Drawing::Color::White;
			this->tbPosX->Location = System::Drawing::Point(83, 47);
			this->tbPosX->Margin = System::Windows::Forms::Padding(4);
			this->tbPosX->Name = L"tbPosX";
			this->tbPosX->Size = System::Drawing::Size(104, 23);
			this->tbPosX->TabIndex = 29;
			this->tbPosX->Text = L"0.00";
			this->tbPosX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Lime;
			this->label24->Location = System::Drawing::Point(24, 202);
			this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(24, 24);
			this->label24->TabIndex = 10;
			this->label24->Text = L"R";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::Lime;
			this->label26->Location = System::Drawing::Point(24, 171);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(23, 24);
			this->label26->TabIndex = 8;
			this->label26->Text = L"P";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::Lime;
			this->label28->Location = System::Drawing::Point(24, 140);
			this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(29, 24);
			this->label28->TabIndex = 6;
			this->label28->Text = L"W";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Lime;
			this->label22->Location = System::Drawing::Point(25, 106);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(23, 24);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Z";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Lime;
			this->label20->Location = System::Drawing::Point(25, 76);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(23, 24);
			this->label20->TabIndex = 2;
			this->label20->Text = L"Y";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Lime;
			this->label17->Location = System::Drawing::Point(25, 47);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(25, 24);
			this->label17->TabIndex = 0;
			this->label17->Text = L"X";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label_mz);
			this->panel3->Controls->Add(this->label_my);
			this->panel3->Controls->Add(this->label_mx);
			this->panel3->Controls->Add(this->label_fz);
			this->panel3->Controls->Add(this->label_fy);
			this->panel3->Controls->Add(this->label_fx);
			this->panel3->Controls->Add(this->label31);
			this->panel3->Controls->Add(this->fx_bar);
			this->panel3->Controls->Add(this->fy_bar);
			this->panel3->Controls->Add(this->fz_bar);
			this->panel3->Controls->Add(this->mx_bar);
			this->panel3->Controls->Add(this->my_bar);
			this->panel3->Controls->Add(this->mz_bar);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Location = System::Drawing::Point(509, 4);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(309, 267);
			this->panel3->TabIndex = 29;
			// 
			// label_mz
			// 
			this->label_mz->BackColor = System::Drawing::Color::Black;
			this->label_mz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_mz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_mz->ForeColor = System::Drawing::Color::White;
			this->label_mz->Location = System::Drawing::Point(189, 215);
			this->label_mz->Margin = System::Windows::Forms::Padding(4);
			this->label_mz->Name = L"label_mz";
			this->label_mz->Size = System::Drawing::Size(104, 19);
			this->label_mz->TabIndex = 64;
			this->label_mz->Text = L"0.00";
			this->label_mz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_my
			// 
			this->label_my->BackColor = System::Drawing::Color::Black;
			this->label_my->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_my->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_my->ForeColor = System::Drawing::Color::White;
			this->label_my->Location = System::Drawing::Point(189, 187);
			this->label_my->Margin = System::Windows::Forms::Padding(4);
			this->label_my->Name = L"label_my";
			this->label_my->Size = System::Drawing::Size(104, 19);
			this->label_my->TabIndex = 63;
			this->label_my->Text = L"0.00";
			this->label_my->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_mx
			// 
			this->label_mx->BackColor = System::Drawing::Color::Black;
			this->label_mx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_mx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_mx->ForeColor = System::Drawing::Color::White;
			this->label_mx->Location = System::Drawing::Point(189, 158);
			this->label_mx->Margin = System::Windows::Forms::Padding(4);
			this->label_mx->Name = L"label_mx";
			this->label_mx->Size = System::Drawing::Size(104, 19);
			this->label_mx->TabIndex = 62;
			this->label_mx->Text = L"0.00";
			this->label_mx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_fz
			// 
			this->label_fz->BackColor = System::Drawing::Color::Black;
			this->label_fz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_fz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fz->ForeColor = System::Drawing::Color::White;
			this->label_fz->Location = System::Drawing::Point(189, 128);
			this->label_fz->Margin = System::Windows::Forms::Padding(4);
			this->label_fz->Name = L"label_fz";
			this->label_fz->Size = System::Drawing::Size(104, 19);
			this->label_fz->TabIndex = 61;
			this->label_fz->Text = L"0.00";
			this->label_fz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_fy
			// 
			this->label_fy->BackColor = System::Drawing::Color::Black;
			this->label_fy->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_fy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fy->ForeColor = System::Drawing::Color::White;
			this->label_fy->Location = System::Drawing::Point(189, 98);
			this->label_fy->Margin = System::Windows::Forms::Padding(4);
			this->label_fy->Name = L"label_fy";
			this->label_fy->Size = System::Drawing::Size(104, 19);
			this->label_fy->TabIndex = 60;
			this->label_fy->Text = L"0.00";
			this->label_fy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_fx
			// 
			this->label_fx->BackColor = System::Drawing::Color::Black;
			this->label_fx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_fx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fx->ForeColor = System::Drawing::Color::White;
			this->label_fx->Location = System::Drawing::Point(189, 69);
			this->label_fx->Margin = System::Windows::Forms::Padding(4);
			this->label_fx->Name = L"label_fx";
			this->label_fx->Size = System::Drawing::Size(104, 19);
			this->label_fx->TabIndex = 59;
			this->label_fx->Text = L"0.00";
			this->label_fx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::Color::Lime;
			this->label31->Location = System::Drawing::Point(77, 12);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(137, 24);
			this->label31->TabIndex = 49;
			this->label31->Text = L"Force Sensor";
			// 
			// fx_bar
			// 
			this->fx_bar->Location = System::Drawing::Point(55, 65);
			this->fx_bar->Margin = System::Windows::Forms::Padding(4);
			this->fx_bar->Name = L"fx_bar";
			this->fx_bar->Size = System::Drawing::Size(133, 22);
			this->fx_bar->TabIndex = 4;
			// 
			// fy_bar
			// 
			this->fy_bar->Location = System::Drawing::Point(55, 95);
			this->fy_bar->Margin = System::Windows::Forms::Padding(4);
			this->fy_bar->Name = L"fy_bar";
			this->fy_bar->Size = System::Drawing::Size(133, 22);
			this->fy_bar->TabIndex = 5;
			// 
			// fz_bar
			// 
			this->fz_bar->Location = System::Drawing::Point(55, 124);
			this->fz_bar->Margin = System::Windows::Forms::Padding(4);
			this->fz_bar->Name = L"fz_bar";
			this->fz_bar->Size = System::Drawing::Size(133, 22);
			this->fz_bar->TabIndex = 6;
			// 
			// mx_bar
			// 
			this->mx_bar->Location = System::Drawing::Point(55, 154);
			this->mx_bar->Margin = System::Windows::Forms::Padding(4);
			this->mx_bar->Name = L"mx_bar";
			this->mx_bar->Size = System::Drawing::Size(133, 22);
			this->mx_bar->TabIndex = 7;
			// 
			// my_bar
			// 
			this->my_bar->Location = System::Drawing::Point(55, 183);
			this->my_bar->Margin = System::Windows::Forms::Padding(4);
			this->my_bar->Name = L"my_bar";
			this->my_bar->Size = System::Drawing::Size(133, 22);
			this->my_bar->TabIndex = 8;
			// 
			// mz_bar
			// 
			this->mz_bar->Location = System::Drawing::Point(55, 213);
			this->mz_bar->Margin = System::Windows::Forms::Padding(4);
			this->mz_bar->Name = L"mz_bar";
			this->mz_bar->Size = System::Drawing::Size(133, 22);
			this->mz_bar->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(17, 68);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Fx";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Lime;
			this->label5->Location = System::Drawing::Point(17, 97);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 20);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Fy";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Lime;
			this->label7->Location = System::Drawing::Point(17, 127);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(28, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Fz";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Lime;
			this->label6->Location = System::Drawing::Point(17, 156);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Mx";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Lime;
			this->label9->Location = System::Drawing::Point(17, 186);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 20);
			this->label9->TabIndex = 14;
			this->label9->Text = L"My";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Lime;
			this->label8->Location = System::Drawing::Point(17, 215);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Mz";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.41298F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.58702F)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox5, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(4, 287);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(1063, 257);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::Color::Transparent;
			this->groupBox5->Controls->Add(this->btn_robot_initpos);
			this->groupBox5->Controls->Add(this->groupBox10);
			this->groupBox5->Controls->Add(this->robot_connect_indicator);
			this->groupBox5->Controls->Add(this->groupBox8);
			this->groupBox5->Controls->Add(this->btn_robot_connect);
			this->groupBox5->Controls->Add(this->groupBox7);
			this->groupBox5->Controls->Add(this->groupBox6);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox5->ForeColor = System::Drawing::Color::Lime;
			this->groupBox5->Location = System::Drawing::Point(508, 4);
			this->groupBox5->Margin = System::Windows::Forms::Padding(4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(4);
			this->groupBox5->Size = System::Drawing::Size(551, 249);
			this->groupBox5->TabIndex = 38;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Robot Configuration";
			// 
			// btn_robot_initpos
			// 
			this->btn_robot_initpos->BackColor = System::Drawing::Color::Silver;
			this->btn_robot_initpos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_robot_initpos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_robot_initpos->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_robot_initpos->ForeColor = System::Drawing::Color::Black;
			this->btn_robot_initpos->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_robot_initpos->Location = System::Drawing::Point(337, 186);
			this->btn_robot_initpos->Margin = System::Windows::Forms::Padding(4);
			this->btn_robot_initpos->Name = L"btn_robot_initpos";
			this->btn_robot_initpos->Size = System::Drawing::Size(163, 42);
			this->btn_robot_initpos->TabIndex = 38;
			this->btn_robot_initpos->Text = L"Move Initial Pos";
			this->btn_robot_initpos->UseVisualStyleBackColor = false;
			this->btn_robot_initpos->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_robot_initpos_Click);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->ip_address_box);
			this->groupBox10->ForeColor = System::Drawing::Color::White;
			this->groupBox10->Location = System::Drawing::Point(19, 174);
			this->groupBox10->Margin = System::Windows::Forms::Padding(4);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Padding = System::Windows::Forms::Padding(4);
			this->groupBox10->Size = System::Drawing::Size(167, 60);
			this->groupBox10->TabIndex = 51;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"IP Address";
			// 
			// ip_address_box
			// 
			this->ip_address_box->FormattingEnabled = true;
			this->ip_address_box->Location = System::Drawing::Point(13, 23);
			this->ip_address_box->Margin = System::Windows::Forms::Padding(4);
			this->ip_address_box->Name = L"ip_address_box";
			this->ip_address_box->Size = System::Drawing::Size(136, 24);
			this->ip_address_box->TabIndex = 26;
			this->ip_address_box->Text = L"127.168.0.100";
			// 
			// robot_connect_indicator
			// 
			this->robot_connect_indicator->BackColor = System::Drawing::Color::Red;
			this->robot_connect_indicator->Location = System::Drawing::Point(315, 186);
			this->robot_connect_indicator->Margin = System::Windows::Forms::Padding(4);
			this->robot_connect_indicator->Name = L"robot_connect_indicator";
			this->robot_connect_indicator->Size = System::Drawing::Size(15, 42);
			this->robot_connect_indicator->TabIndex = 37;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label_override);
			this->groupBox8->Controls->Add(this->btn_override_up);
			this->groupBox8->Controls->Add(this->btn_overide_down);
			this->groupBox8->ForeColor = System::Drawing::Color::White;
			this->groupBox8->Location = System::Drawing::Point(19, 89);
			this->groupBox8->Margin = System::Windows::Forms::Padding(4);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(4);
			this->groupBox8->Size = System::Drawing::Size(204, 75);
			this->groupBox8->TabIndex = 36;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Override";
			// 
			// label_override
			// 
			this->label_override->AutoSize = true;
			this->label_override->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_override->ForeColor = System::Drawing::Color::Yellow;
			this->label_override->Location = System::Drawing::Point(75, 33);
			this->label_override->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_override->Name = L"label_override";
			this->label_override->Size = System::Drawing::Size(45, 20);
			this->label_override->TabIndex = 50;
			this->label_override->Text = L"10%";
			// 
			// btn_override_up
			// 
			this->btn_override_up->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btn_override_up->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_override_up->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_override_up->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_override_up->ForeColor = System::Drawing::Color::Black;
			this->btn_override_up->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_override_up->Location = System::Drawing::Point(136, 25);
			this->btn_override_up->Margin = System::Windows::Forms::Padding(4);
			this->btn_override_up->Name = L"btn_override_up";
			this->btn_override_up->Size = System::Drawing::Size(48, 39);
			this->btn_override_up->TabIndex = 32;
			this->btn_override_up->Text = L"+";
			this->btn_override_up->UseVisualStyleBackColor = false;
			this->btn_override_up->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_override_up_Click);
			// 
			// btn_overide_down
			// 
			this->btn_overide_down->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btn_overide_down->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_overide_down->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_overide_down->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_overide_down->ForeColor = System::Drawing::Color::Black;
			this->btn_overide_down->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_overide_down->Location = System::Drawing::Point(13, 25);
			this->btn_overide_down->Margin = System::Windows::Forms::Padding(4);
			this->btn_overide_down->Name = L"btn_overide_down";
			this->btn_overide_down->Size = System::Drawing::Size(48, 39);
			this->btn_overide_down->TabIndex = 31;
			this->btn_overide_down->Text = L"-";
			this->btn_overide_down->UseVisualStyleBackColor = false;
			this->btn_overide_down->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_overide_down_Click);
			// 
			// btn_robot_connect
			// 
			this->btn_robot_connect->BackColor = System::Drawing::Color::Silver;
			this->btn_robot_connect->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_robot_connect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_robot_connect->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_robot_connect->ForeColor = System::Drawing::Color::Black;
			this->btn_robot_connect->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_robot_connect->Location = System::Drawing::Point(193, 186);
			this->btn_robot_connect->Margin = System::Windows::Forms::Padding(4);
			this->btn_robot_connect->Name = L"btn_robot_connect";
			this->btn_robot_connect->Size = System::Drawing::Size(117, 42);
			this->btn_robot_connect->TabIndex = 38;
			this->btn_robot_connect->Text = L"Connect";
			this->btn_robot_connect->UseVisualStyleBackColor = false;
			this->btn_robot_connect->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_robot_connect_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->rb_xyzwpr_mode);
			this->groupBox7->Controls->Add(this->rb_xyz_mode);
			this->groupBox7->ForeColor = System::Drawing::Color::White;
			this->groupBox7->Location = System::Drawing::Point(19, 23);
			this->groupBox7->Margin = System::Windows::Forms::Padding(4);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(4);
			this->groupBox7->Size = System::Drawing::Size(204, 60);
			this->groupBox7->TabIndex = 34;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Movement Mode";
			// 
			// rb_xyzwpr_mode
			// 
			this->rb_xyzwpr_mode->AutoSize = true;
			this->rb_xyzwpr_mode->Checked = true;
			this->rb_xyzwpr_mode->ForeColor = System::Drawing::Color::White;
			this->rb_xyzwpr_mode->Location = System::Drawing::Point(13, 27);
			this->rb_xyzwpr_mode->Margin = System::Windows::Forms::Padding(4);
			this->rb_xyzwpr_mode->Name = L"rb_xyzwpr_mode";
			this->rb_xyzwpr_mode->Size = System::Drawing::Size(88, 21);
			this->rb_xyzwpr_mode->TabIndex = 2;
			this->rb_xyzwpr_mode->TabStop = true;
			this->rb_xyzwpr_mode->Text = L"XYZWPR";
			this->rb_xyzwpr_mode->UseVisualStyleBackColor = true;
			// 
			// rb_xyz_mode
			// 
			this->rb_xyz_mode->AutoSize = true;
			this->rb_xyz_mode->ForeColor = System::Drawing::Color::White;
			this->rb_xyz_mode->Location = System::Drawing::Point(135, 27);
			this->rb_xyz_mode->Margin = System::Windows::Forms::Padding(4);
			this->rb_xyz_mode->Name = L"rb_xyz_mode";
			this->rb_xyz_mode->Size = System::Drawing::Size(56, 21);
			this->rb_xyz_mode->TabIndex = 1;
			this->rb_xyz_mode->Text = L"XYZ";
			this->rb_xyz_mode->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label41);
			this->groupBox6->Controls->Add(this->tb_robot_initW);
			this->groupBox6->Controls->Add(this->tb_robot_initR);
			this->groupBox6->Controls->Add(this->tb_robot_initX);
			this->groupBox6->Controls->Add(this->label42);
			this->groupBox6->Controls->Add(this->label38);
			this->groupBox6->Controls->Add(this->tb_robot_initP);
			this->groupBox6->Controls->Add(this->tb_robot_initY);
			this->groupBox6->Controls->Add(this->label43);
			this->groupBox6->Controls->Add(this->label39);
			this->groupBox6->Controls->Add(this->tb_robot_initZ);
			this->groupBox6->Controls->Add(this->label40);
			this->groupBox6->ForeColor = System::Drawing::Color::White;
			this->groupBox6->Location = System::Drawing::Point(231, 23);
			this->groupBox6->Margin = System::Windows::Forms::Padding(4);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(4);
			this->groupBox6->Size = System::Drawing::Size(267, 140);
			this->groupBox6->TabIndex = 0;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Intial Position";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->ForeColor = System::Drawing::Color::White;
			this->label41->Location = System::Drawing::Point(136, 102);
			this->label41->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(18, 17);
			this->label41->TabIndex = 48;
			this->label41->Text = L"R";
			// 
			// tb_robot_initW
			// 
			this->tb_robot_initW->Location = System::Drawing::Point(163, 33);
			this->tb_robot_initW->Margin = System::Windows::Forms::Padding(4);
			this->tb_robot_initW->Name = L"tb_robot_initW";
			this->tb_robot_initW->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initW->TabIndex = 43;
			this->tb_robot_initW->Text = L"0";
			this->tb_robot_initW->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_robot_initR
			// 
			this->tb_robot_initR->Location = System::Drawing::Point(163, 98);
			this->tb_robot_initR->Margin = System::Windows::Forms::Padding(4);
			this->tb_robot_initR->Name = L"tb_robot_initR";
			this->tb_robot_initR->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initR->TabIndex = 47;
			this->tb_robot_initR->Text = L"0";
			this->tb_robot_initR->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_robot_initX
			// 
			this->tb_robot_initX->Location = System::Drawing::Point(41, 33);
			this->tb_robot_initX->Margin = System::Windows::Forms::Padding(4);
			this->tb_robot_initX->Name = L"tb_robot_initX";
			this->tb_robot_initX->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initX->TabIndex = 6;
			this->tb_robot_initX->Text = L"0";
			this->tb_robot_initX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->ForeColor = System::Drawing::Color::White;
			this->label42->Location = System::Drawing::Point(136, 70);
			this->label42->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(17, 17);
			this->label42->TabIndex = 46;
			this->label42->Text = L"P";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->ForeColor = System::Drawing::Color::White;
			this->label38->Location = System::Drawing::Point(15, 37);
			this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(17, 17);
			this->label38->TabIndex = 7;
			this->label38->Text = L"X";
			// 
			// tb_robot_initP
			// 
			this->tb_robot_initP->Location = System::Drawing::Point(163, 66);
			this->tb_robot_initP->Margin = System::Windows::Forms::Padding(4);
			this->tb_robot_initP->Name = L"tb_robot_initP";
			this->tb_robot_initP->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initP->TabIndex = 45;
			this->tb_robot_initP->Text = L"0";
			this->tb_robot_initP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_robot_initY
			// 
			this->tb_robot_initY->Location = System::Drawing::Point(41, 66);
			this->tb_robot_initY->Margin = System::Windows::Forms::Padding(4);
			this->tb_robot_initY->Name = L"tb_robot_initY";
			this->tb_robot_initY->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initY->TabIndex = 39;
			this->tb_robot_initY->Text = L"0";
			this->tb_robot_initY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->ForeColor = System::Drawing::Color::White;
			this->label43->Location = System::Drawing::Point(136, 37);
			this->label43->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(21, 17);
			this->label43->TabIndex = 44;
			this->label43->Text = L"W";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->ForeColor = System::Drawing::Color::White;
			this->label39->Location = System::Drawing::Point(15, 70);
			this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(17, 17);
			this->label39->TabIndex = 40;
			this->label39->Text = L"Y";
			// 
			// tb_robot_initZ
			// 
			this->tb_robot_initZ->Location = System::Drawing::Point(41, 98);
			this->tb_robot_initZ->Margin = System::Windows::Forms::Padding(4);
			this->tb_robot_initZ->Name = L"tb_robot_initZ";
			this->tb_robot_initZ->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initZ->TabIndex = 41;
			this->tb_robot_initZ->Text = L"0";
			this->tb_robot_initZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->ForeColor = System::Drawing::Color::White;
			this->label40->Location = System::Drawing::Point(15, 102);
			this->label40->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(17, 17);
			this->label40->TabIndex = 42;
			this->label40->Text = L"Z";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->btn_haptic_update);
			this->groupBox1->Controls->Add(this->haptic_connect_indicator);
			this->groupBox1->Controls->Add(this->btn_haptic_moveinitpos);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->btn_haptic_connect);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->ForeColor = System::Drawing::Color::Lime;
			this->groupBox1->Location = System::Drawing::Point(4, 4);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(496, 249);
			this->groupBox1->TabIndex = 30;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Haptic Configuration";
			// 
			// btn_haptic_update
			// 
			this->btn_haptic_update->BackColor = System::Drawing::Color::Silver;
			this->btn_haptic_update->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_haptic_update->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_haptic_update->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_haptic_update->ForeColor = System::Drawing::Color::Black;
			this->btn_haptic_update->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_haptic_update->Location = System::Drawing::Point(191, 186);
			this->btn_haptic_update->Margin = System::Windows::Forms::Padding(4);
			this->btn_haptic_update->Name = L"btn_haptic_update";
			this->btn_haptic_update->Size = System::Drawing::Size(117, 42);
			this->btn_haptic_update->TabIndex = 37;
			this->btn_haptic_update->Text = L"Update";
			this->btn_haptic_update->UseVisualStyleBackColor = false;
			this->btn_haptic_update->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_haptic_update_Click);
			// 
			// haptic_connect_indicator
			// 
			this->haptic_connect_indicator->BackColor = System::Drawing::Color::Red;
			this->haptic_connect_indicator->Location = System::Drawing::Point(439, 186);
			this->haptic_connect_indicator->Margin = System::Windows::Forms::Padding(4);
			this->haptic_connect_indicator->Name = L"haptic_connect_indicator";
			this->haptic_connect_indicator->Size = System::Drawing::Size(15, 42);
			this->haptic_connect_indicator->TabIndex = 31;
			// 
			// btn_haptic_moveinitpos
			// 
			this->btn_haptic_moveinitpos->BackColor = System::Drawing::Color::Silver;
			this->btn_haptic_moveinitpos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_haptic_moveinitpos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_haptic_moveinitpos->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_haptic_moveinitpos->ForeColor = System::Drawing::Color::Black;
			this->btn_haptic_moveinitpos->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_haptic_moveinitpos->Location = System::Drawing::Point(20, 186);
			this->btn_haptic_moveinitpos->Margin = System::Windows::Forms::Padding(4);
			this->btn_haptic_moveinitpos->Name = L"btn_haptic_moveinitpos";
			this->btn_haptic_moveinitpos->Size = System::Drawing::Size(163, 42);
			this->btn_haptic_moveinitpos->TabIndex = 36;
			this->btn_haptic_moveinitpos->Text = L"Move Initial Pos";
			this->btn_haptic_moveinitpos->UseVisualStyleBackColor = false;
			this->btn_haptic_moveinitpos->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_haptic_moveinitpos_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label_scale_factor);
			this->groupBox4->Controls->Add(this->btn_scale_up);
			this->groupBox4->Controls->Add(this->btn_scale_down);
			this->groupBox4->ForeColor = System::Drawing::Color::White;
			this->groupBox4->Location = System::Drawing::Point(205, 103);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4);
			this->groupBox4->Size = System::Drawing::Size(247, 75);
			this->groupBox4->TabIndex = 35;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Scaling Factor";
			// 
			// label_scale_factor
			// 
			this->label_scale_factor->AutoSize = true;
			this->label_scale_factor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_scale_factor->ForeColor = System::Drawing::Color::Yellow;
			this->label_scale_factor->Location = System::Drawing::Point(103, 32);
			this->label_scale_factor->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_scale_factor->Name = L"label_scale_factor";
			this->label_scale_factor->Size = System::Drawing::Size(44, 20);
			this->label_scale_factor->TabIndex = 50;
			this->label_scale_factor->Text = L"1.00";
			// 
			// btn_scale_up
			// 
			this->btn_scale_up->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btn_scale_up->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_scale_up->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_scale_up->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_scale_up->ForeColor = System::Drawing::Color::Black;
			this->btn_scale_up->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_scale_up->Location = System::Drawing::Point(167, 23);
			this->btn_scale_up->Margin = System::Windows::Forms::Padding(4);
			this->btn_scale_up->Name = L"btn_scale_up";
			this->btn_scale_up->Size = System::Drawing::Size(48, 39);
			this->btn_scale_up->TabIndex = 32;
			this->btn_scale_up->Text = L"+";
			this->btn_scale_up->UseVisualStyleBackColor = false;
			this->btn_scale_up->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_scale_up_Click);
			// 
			// btn_scale_down
			// 
			this->btn_scale_down->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btn_scale_down->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_scale_down->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_scale_down->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_scale_down->ForeColor = System::Drawing::Color::Black;
			this->btn_scale_down->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_scale_down->Location = System::Drawing::Point(36, 23);
			this->btn_scale_down->Margin = System::Windows::Forms::Padding(4);
			this->btn_scale_down->Name = L"btn_scale_down";
			this->btn_scale_down->Size = System::Drawing::Size(48, 39);
			this->btn_scale_down->TabIndex = 31;
			this->btn_scale_down->Text = L"-";
			this->btn_scale_down->UseVisualStyleBackColor = false;
			this->btn_scale_down->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_scale_down_Click);
			// 
			// btn_haptic_connect
			// 
			this->btn_haptic_connect->BackColor = System::Drawing::Color::Silver;
			this->btn_haptic_connect->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_haptic_connect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_haptic_connect->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_haptic_connect->ForeColor = System::Drawing::Color::Black;
			this->btn_haptic_connect->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_haptic_connect->Location = System::Drawing::Point(316, 186);
			this->btn_haptic_connect->Margin = System::Windows::Forms::Padding(4);
			this->btn_haptic_connect->Name = L"btn_haptic_connect";
			this->btn_haptic_connect->Size = System::Drawing::Size(117, 42);
			this->btn_haptic_connect->TabIndex = 31;
			this->btn_haptic_connect->Text = L"Connect";
			this->btn_haptic_connect->UseVisualStyleBackColor = false;
			this->btn_haptic_connect->Click += gcnew System::EventHandler(this, &MainFormDlg::btn_haptic_connect_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label36);
			this->groupBox3->Controls->Add(this->tb_haptic_initZ);
			this->groupBox3->Controls->Add(this->label35);
			this->groupBox3->Controls->Add(this->tb_haptic_initY);
			this->groupBox3->Controls->Add(this->label34);
			this->groupBox3->Controls->Add(this->tb_haptic_initX);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(205, 23);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(247, 73);
			this->groupBox3->TabIndex = 34;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Initial Position";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->ForeColor = System::Drawing::Color::White;
			this->label36->Location = System::Drawing::Point(165, 34);
			this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(17, 17);
			this->label36->TabIndex = 5;
			this->label36->Text = L"Z";
			// 
			// tb_haptic_initZ
			// 
			this->tb_haptic_initZ->Location = System::Drawing::Point(187, 31);
			this->tb_haptic_initZ->Margin = System::Windows::Forms::Padding(4);
			this->tb_haptic_initZ->Name = L"tb_haptic_initZ";
			this->tb_haptic_initZ->Size = System::Drawing::Size(47, 22);
			this->tb_haptic_initZ->TabIndex = 4;
			this->tb_haptic_initZ->Text = L"0";
			this->tb_haptic_initZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->ForeColor = System::Drawing::Color::White;
			this->label35->Location = System::Drawing::Point(87, 34);
			this->label35->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(17, 17);
			this->label35->TabIndex = 3;
			this->label35->Text = L"Y";
			// 
			// tb_haptic_initY
			// 
			this->tb_haptic_initY->Location = System::Drawing::Point(108, 31);
			this->tb_haptic_initY->Margin = System::Windows::Forms::Padding(4);
			this->tb_haptic_initY->Name = L"tb_haptic_initY";
			this->tb_haptic_initY->Size = System::Drawing::Size(47, 22);
			this->tb_haptic_initY->TabIndex = 2;
			this->tb_haptic_initY->Text = L"0";
			this->tb_haptic_initY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->ForeColor = System::Drawing::Color::White;
			this->label34->Location = System::Drawing::Point(8, 34);
			this->label34->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(17, 17);
			this->label34->TabIndex = 1;
			this->label34->Text = L"X";
			// 
			// tb_haptic_initX
			// 
			this->tb_haptic_initX->Location = System::Drawing::Point(29, 31);
			this->tb_haptic_initX->Margin = System::Windows::Forms::Padding(4);
			this->tb_haptic_initX->Name = L"tb_haptic_initX";
			this->tb_haptic_initX->Size = System::Drawing::Size(47, 22);
			this->tb_haptic_initX->TabIndex = 0;
			this->tb_haptic_initX->Text = L"0";
			this->tb_haptic_initX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->rb_noeffect);
			this->groupBox2->Controls->Add(this->magnitude_box);
			this->groupBox2->Controls->Add(this->gain_box);
			this->groupBox2->Controls->Add(this->label33);
			this->groupBox2->Controls->Add(this->label32);
			this->groupBox2->Controls->Add(this->rb_spring);
			this->groupBox2->Controls->Add(this->rb_friction);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(15, 23);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(183, 155);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Force Effect";
			// 
			// rb_noeffect
			// 
			this->rb_noeffect->AutoSize = true;
			this->rb_noeffect->ForeColor = System::Drawing::Color::White;
			this->rb_noeffect->Location = System::Drawing::Point(95, 23);
			this->rb_noeffect->Margin = System::Windows::Forms::Padding(4);
			this->rb_noeffect->Name = L"rb_noeffect";
			this->rb_noeffect->Size = System::Drawing::Size(63, 21);
			this->rb_noeffect->TabIndex = 33;
			this->rb_noeffect->Text = L"None";
			this->rb_noeffect->UseVisualStyleBackColor = true;
			// 
			// magnitude_box
			// 
			this->magnitude_box->DecimalPlaces = 2;
			this->magnitude_box->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
			this->magnitude_box->Location = System::Drawing::Point(97, 111);
			this->magnitude_box->Margin = System::Windows::Forms::Padding(4);
			this->magnitude_box->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->magnitude_box->Name = L"magnitude_box";
			this->magnitude_box->Size = System::Drawing::Size(71, 22);
			this->magnitude_box->TabIndex = 32;
			this->magnitude_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->magnitude_box->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 65536 });
			// 
			// gain_box
			// 
			this->gain_box->DecimalPlaces = 2;
			this->gain_box->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
			this->gain_box->Location = System::Drawing::Point(97, 82);
			this->gain_box->Margin = System::Windows::Forms::Padding(4);
			this->gain_box->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 65536 });
			this->gain_box->Name = L"gain_box";
			this->gain_box->Size = System::Drawing::Size(71, 22);
			this->gain_box->TabIndex = 31;
			this->gain_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->gain_box->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 65536 });
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->ForeColor = System::Drawing::Color::White;
			this->label33->Location = System::Drawing::Point(13, 113);
			this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(64, 17);
			this->label33->TabIndex = 5;
			this->label33->Text = L"Damping";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->ForeColor = System::Drawing::Color::White;
			this->label32->Location = System::Drawing::Point(13, 85);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(62, 17);
			this->label32->TabIndex = 4;
			this->label32->Text = L"Stiffness";
			// 
			// rb_spring
			// 
			this->rb_spring->AutoSize = true;
			this->rb_spring->Checked = true;
			this->rb_spring->ForeColor = System::Drawing::Color::White;
			this->rb_spring->Location = System::Drawing::Point(11, 52);
			this->rb_spring->Margin = System::Windows::Forms::Padding(4);
			this->rb_spring->Name = L"rb_spring";
			this->rb_spring->Size = System::Drawing::Size(70, 21);
			this->rb_spring->TabIndex = 1;
			this->rb_spring->TabStop = true;
			this->rb_spring->Text = L"Spring";
			this->rb_spring->UseVisualStyleBackColor = true;
			// 
			// rb_friction
			// 
			this->rb_friction->AutoSize = true;
			this->rb_friction->ForeColor = System::Drawing::Color::White;
			this->rb_friction->Location = System::Drawing::Point(11, 23);
			this->rb_friction->Margin = System::Windows::Forms::Padding(4);
			this->rb_friction->Name = L"rb_friction";
			this->rb_friction->Size = System::Drawing::Size(79, 21);
			this->rb_friction->TabIndex = 0;
			this->rb_friction->Text = L"Friction ";
			this->rb_friction->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				1374)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 77);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 649)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 649)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 649)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1078, 649);
			this->tableLayoutPanel1->TabIndex = 44;
			// 
			// MainFormDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1078, 726);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainFormDlg";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Polishing Software";
			this->Load += gcnew System::EventHandler(this, &MainFormDlg::NewForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupbox->ResumeLayout(false);
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel_haptic->ResumeLayout(false);
			this->panel_haptic->PerformLayout();
			this->panel_jog->ResumeLayout(false);
			this->panel_jog->PerformLayout();
			this->panel_robot->ResumeLayout(false);
			this->panel_robot->PerformLayout();
			this->panel_move->ResumeLayout(false);
			this->panel_move->PerformLayout();
			this->panel_prog->ResumeLayout(false);
			this->panel_prog->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox10->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magnitude_box))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gain_box))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void btn_haptic_connect_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_connect();
}
private: System::Void btn_haptic_update_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_update();
}
private: System::Void btn_haptic_moveinitpos_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_initpos();
	//haptic_reset_center_pos();
}
private: System::Void NewForm_Load(System::Object^  sender, System::EventArgs^  e) {
	DateTime now = DateTime::Now;
	String^ timestamp = now.ToString("yyyy-MM-dd   H:m");
	label_datetime->Text = timestamp;
	on_init();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	trajectory_form_setting();
}
private: System::Void btn_scale_up_Click(System::Object^  sender, System::EventArgs^  e) {
	scale_up();
}
private: System::Void btn_scale_down_Click(System::Object^  sender, System::EventArgs^  e) {
	scale_down();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	show_robot_control_form();
}
private: System::Void btn_robot_connect_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_connect();
}
private: System::Void btn_override_up_Click(System::Object^  sender, System::EventArgs^  e) {
	override_up();
}
private: System::Void btn_overide_down_Click(System::Object^  sender, System::EventArgs^  e) {
	override_down();
}
private: System::Void label2_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btn_robot_initpos_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_move_toInitPos();
}
private: System::Void btn_haptic_jog_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_jog_mode();
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	robot_move_handle();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	show_menu();
}
		 
private:  System::Void btn_start_Click(System::Object^  sender, System::EventArgs^  e) {
	start_program();
	//show_menu();
	
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
}
private: System::Void btnRecord_Click(System::Object^  sender, System::EventArgs^  e) {
	record_point();
	//record_force();
}
private: System::Void saveSystemTrajectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	save_system_trajectory();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	force_sensor_calibration();
}
private: System::Void btn_setForceThreshold_Click(System::Object^  sender, System::EventArgs^  e) {
	force_sensor_calibration();
}
private: System::Void btn_recordForce_Click(System::Object^  sender, System::EventArgs^  e) {
	record_force();
}
private: System::Void btn_stopRecordForce_Click(System::Object^  sender, System::EventArgs^  e) {
	stop_record_force();
}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void forceCalibrationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	show_force_calibration_menu();
}
private: System::Void getCurrentPositionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	get_current_position();
}
private: System::Void coppeliaSimToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	show_coppelia_form();
}
private: System::Void extraToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	show_new_custom_form();
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	record_point();

}
private: System::Void btn_browse_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btn_trajectory_save_Click(System::Object^  sender, System::EventArgs^  e) {
	save_system_trajectory();
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	stop_record_point();
}
};
}

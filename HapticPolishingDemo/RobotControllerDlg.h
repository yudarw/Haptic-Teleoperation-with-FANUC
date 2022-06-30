#pragma once
#include "Fanuc.h"
#include "main.h"

extern Fanuc robot;

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for RobotControllerDlg
	/// </summary>
	public ref class RobotControllerDlg : public System::Windows::Forms::Form
	{
	public:
		RobotControllerDlg(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void load_configuration(Fanuc _robot);
		void read_position(DataPos * _current_pos);
		void update_position();
		void set_sdo_on();
		void set_sdo_off();
		void set_sdo(int num, int val);
		void set_position(DataPos pos);
		void posX_up();


		void attach_gripper();
		void release_gripper();
		void gripper_open();
		void gripper_close();

		//void attach_grinder();
		//void release_grinder();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RobotControllerDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btn_x_up;
	protected:





	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  tb_robotR;

	private: System::Windows::Forms::TextBox^  tb_robotP;

	private: System::Windows::Forms::TextBox^  tb_robotW;

	private: System::Windows::Forms::TextBox^  tb_robotZ;

	private: System::Windows::Forms::TextBox^  tb_robotY;

	private: System::Windows::Forms::TextBox^  tb_robotX;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Panel^  do_indicator;

	private: System::Windows::Forms::Button^  btn_sdo_ON;
	private: System::Windows::Forms::NumericUpDown^  tb_DO;


	private: System::Windows::Forms::Button^  btn_sdo_OFF;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
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
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::GroupBox^  groupBox8;



private: System::Windows::Forms::Button^  btn_attach;
private: System::Windows::Forms::Button^  button21;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_x_up = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tb_robotR = (gcnew System::Windows::Forms::TextBox());
			this->tb_robotP = (gcnew System::Windows::Forms::TextBox());
			this->tb_robotW = (gcnew System::Windows::Forms::TextBox());
			this->tb_robotZ = (gcnew System::Windows::Forms::TextBox());
			this->tb_robotY = (gcnew System::Windows::Forms::TextBox());
			this->tb_robotX = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->do_indicator = (gcnew System::Windows::Forms::Panel());
			this->btn_sdo_ON = (gcnew System::Windows::Forms::Button());
			this->tb_DO = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_sdo_OFF = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
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
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btn_attach = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_DO))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(8, 23);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(67, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"X-";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// btn_x_up
			// 
			this->btn_x_up->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_x_up->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_x_up->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_x_up->ForeColor = System::Drawing::Color::Black;
			this->btn_x_up->Location = System::Drawing::Point(83, 23);
			this->btn_x_up->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_x_up->Name = L"btn_x_up";
			this->btn_x_up->Size = System::Drawing::Size(67, 55);
			this->btn_x_up->TabIndex = 1;
			this->btn_x_up->Text = L"X+";
			this->btn_x_up->UseVisualStyleBackColor = false;
			this->btn_x_up->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RobotControllerDlg::btn_x_up_KeyPress);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->tb_robotR);
			this->panel1->Controls->Add(this->tb_robotP);
			this->panel1->Controls->Add(this->tb_robotW);
			this->panel1->Controls->Add(this->tb_robotZ);
			this->panel1->Controls->Add(this->tb_robotY);
			this->panel1->Controls->Add(this->tb_robotX);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(16, 23);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(241, 267);
			this->panel1->TabIndex = 12;
			// 
			// tb_robotR
			// 
			this->tb_robotR->BackColor = System::Drawing::Color::Black;
			this->tb_robotR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_robotR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_robotR->ForeColor = System::Drawing::Color::White;
			this->tb_robotR->Location = System::Drawing::Point(95, 219);
			this->tb_robotR->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robotR->Name = L"tb_robotR";
			this->tb_robotR->Size = System::Drawing::Size(108, 23);
			this->tb_robotR->TabIndex = 12;
			this->tb_robotR->Text = L"0.00";
			this->tb_robotR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_robotP
			// 
			this->tb_robotP->BackColor = System::Drawing::Color::Black;
			this->tb_robotP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_robotP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_robotP->ForeColor = System::Drawing::Color::White;
			this->tb_robotP->Location = System::Drawing::Point(95, 190);
			this->tb_robotP->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robotP->Name = L"tb_robotP";
			this->tb_robotP->Size = System::Drawing::Size(108, 23);
			this->tb_robotP->TabIndex = 11;
			this->tb_robotP->Text = L"0.00";
			this->tb_robotP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_robotW
			// 
			this->tb_robotW->BackColor = System::Drawing::Color::Black;
			this->tb_robotW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_robotW->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_robotW->ForeColor = System::Drawing::Color::White;
			this->tb_robotW->Location = System::Drawing::Point(95, 158);
			this->tb_robotW->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robotW->Name = L"tb_robotW";
			this->tb_robotW->Size = System::Drawing::Size(108, 23);
			this->tb_robotW->TabIndex = 10;
			this->tb_robotW->Text = L"0.00";
			this->tb_robotW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_robotZ
			// 
			this->tb_robotZ->BackColor = System::Drawing::Color::Black;
			this->tb_robotZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_robotZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_robotZ->ForeColor = System::Drawing::Color::White;
			this->tb_robotZ->Location = System::Drawing::Point(95, 126);
			this->tb_robotZ->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robotZ->Name = L"tb_robotZ";
			this->tb_robotZ->Size = System::Drawing::Size(108, 23);
			this->tb_robotZ->TabIndex = 9;
			this->tb_robotZ->Text = L"0.00";
			this->tb_robotZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_robotY
			// 
			this->tb_robotY->BackColor = System::Drawing::Color::Black;
			this->tb_robotY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_robotY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_robotY->ForeColor = System::Drawing::Color::White;
			this->tb_robotY->Location = System::Drawing::Point(95, 95);
			this->tb_robotY->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robotY->Name = L"tb_robotY";
			this->tb_robotY->Size = System::Drawing::Size(108, 23);
			this->tb_robotY->TabIndex = 8;
			this->tb_robotY->Text = L"0.00";
			this->tb_robotY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_robotX
			// 
			this->tb_robotX->BackColor = System::Drawing::Color::Black;
			this->tb_robotX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_robotX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_robotX->ForeColor = System::Drawing::Color::White;
			this->tb_robotX->Location = System::Drawing::Point(95, 63);
			this->tb_robotX->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robotX->Name = L"tb_robotX";
			this->tb_robotX->Size = System::Drawing::Size(108, 23);
			this->tb_robotX->TabIndex = 7;
			this->tb_robotX->Text = L"0.00";
			this->tb_robotX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Lime;
			this->label6->Location = System::Drawing::Point(17, 219);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 25);
			this->label6->TabIndex = 6;
			this->label6->Text = L"R";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Lime;
			this->label7->Location = System::Drawing::Point(17, 188);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 25);
			this->label7->TabIndex = 5;
			this->label7->Text = L"P";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(17, 156);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"W";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Lime;
			this->label5->Location = System::Drawing::Point(17, 126);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(25, 25);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Z";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(17, 94);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(17, 63);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"X";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(33, 21);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Robot Position";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button13);
			this->groupBox1->Controls->Add(this->button14);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->btn_x_up);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(277, 78);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(159, 213);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Position";
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::Black;
			this->button13->Location = System::Drawing::Point(8, 149);
			this->button13->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(67, 55);
			this->button13->TabIndex = 4;
			this->button13->Text = L"Z-";
			this->button13->UseVisualStyleBackColor = false;
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button14->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->Location = System::Drawing::Point(83, 149);
			this->button14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(67, 55);
			this->button14->TabIndex = 5;
			this->button14->Text = L"Z+";
			this->button14->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(8, 86);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(67, 55);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Y-";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(83, 86);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(67, 55);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Y+";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button7);
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->button10);
			this->groupBox2->Controls->Add(this->button11);
			this->groupBox2->Controls->Add(this->button12);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(444, 78);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(159, 213);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Orientation";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::Black;
			this->button7->Location = System::Drawing::Point(83, 149);
			this->button7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(67, 55);
			this->button7->TabIndex = 17;
			this->button7->Text = L"R+";
			this->button7->UseVisualStyleBackColor = false;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::Black;
			this->button8->Location = System::Drawing::Point(8, 149);
			this->button8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(67, 55);
			this->button8->TabIndex = 16;
			this->button8->Text = L"R-";
			this->button8->UseVisualStyleBackColor = false;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Black;
			this->button9->Location = System::Drawing::Point(83, 86);
			this->button9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(67, 55);
			this->button9->TabIndex = 15;
			this->button9->Text = L"P+";
			this->button9->UseVisualStyleBackColor = false;
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::Black;
			this->button10->Location = System::Drawing::Point(8, 86);
			this->button10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(67, 55);
			this->button10->TabIndex = 14;
			this->button10->Text = L"P-";
			this->button10->UseVisualStyleBackColor = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::Black;
			this->button11->Location = System::Drawing::Point(83, 23);
			this->button11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(67, 55);
			this->button11->TabIndex = 13;
			this->button11->Text = L"W+";
			this->button11->UseVisualStyleBackColor = false;
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button12->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::Black;
			this->button12->Location = System::Drawing::Point(8, 23);
			this->button12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(67, 55);
			this->button12->TabIndex = 12;
			this->button12->Text = L"W-";
			this->button12->UseVisualStyleBackColor = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->do_indicator);
			this->groupBox3->Controls->Add(this->btn_sdo_ON);
			this->groupBox3->Controls->Add(this->tb_DO);
			this->groupBox3->Controls->Add(this->btn_sdo_OFF);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(16, 299);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(241, 101);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Digital Output";
			// 
			// do_indicator
			// 
			this->do_indicator->BackColor = System::Drawing::Color::Lime;
			this->do_indicator->Location = System::Drawing::Point(9, 28);
			this->do_indicator->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->do_indicator->Name = L"do_indicator";
			this->do_indicator->Size = System::Drawing::Size(67, 18);
			this->do_indicator->TabIndex = 11;
			// 
			// btn_sdo_ON
			// 
			this->btn_sdo_ON->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_sdo_ON->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_sdo_ON->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_sdo_ON->ForeColor = System::Drawing::Color::Black;
			this->btn_sdo_ON->Location = System::Drawing::Point(89, 28);
			this->btn_sdo_ON->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_sdo_ON->Name = L"btn_sdo_ON";
			this->btn_sdo_ON->Size = System::Drawing::Size(67, 55);
			this->btn_sdo_ON->TabIndex = 8;
			this->btn_sdo_ON->Text = L"On";
			this->btn_sdo_ON->UseVisualStyleBackColor = false;
			this->btn_sdo_ON->Click += gcnew System::EventHandler(this, &RobotControllerDlg::btn_sdo_ON_Click);
			// 
			// tb_DO
			// 
			this->tb_DO->BackColor = System::Drawing::SystemColors::MenuText;
			this->tb_DO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_DO->ForeColor = System::Drawing::Color::White;
			this->tb_DO->Location = System::Drawing::Point(9, 52);
			this->tb_DO->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_DO->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->tb_DO->Name = L"tb_DO";
			this->tb_DO->Size = System::Drawing::Size(67, 30);
			this->tb_DO->TabIndex = 10;
			this->tb_DO->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_DO->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// btn_sdo_OFF
			// 
			this->btn_sdo_OFF->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_sdo_OFF->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_sdo_OFF->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_sdo_OFF->ForeColor = System::Drawing::Color::Black;
			this->btn_sdo_OFF->Location = System::Drawing::Point(164, 28);
			this->btn_sdo_OFF->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_sdo_OFF->Name = L"btn_sdo_OFF";
			this->btn_sdo_OFF->Size = System::Drawing::Size(67, 55);
			this->btn_sdo_OFF->TabIndex = 9;
			this->btn_sdo_OFF->Text = L"Off";
			this->btn_sdo_OFF->UseVisualStyleBackColor = false;
			this->btn_sdo_OFF->Click += gcnew System::EventHandler(this, &RobotControllerDlg::btn_sdo_OFF_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->panel2);
			this->groupBox4->Controls->Add(this->button15);
			this->groupBox4->Controls->Add(this->numericUpDown2);
			this->groupBox4->Controls->Add(this->button16);
			this->groupBox4->ForeColor = System::Drawing::Color::White;
			this->groupBox4->Location = System::Drawing::Point(16, 407);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Size = System::Drawing::Size(241, 96);
			this->groupBox4->TabIndex = 17;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Robot Output";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Red;
			this->panel2->Location = System::Drawing::Point(9, 23);
			this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(67, 18);
			this->panel2->TabIndex = 7;
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button15->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::Black;
			this->button15->Location = System::Drawing::Point(89, 23);
			this->button15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(67, 55);
			this->button15->TabIndex = 4;
			this->button15->Text = L"On";
			this->button15->UseVisualStyleBackColor = false;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->BackColor = System::Drawing::SystemColors::MenuText;
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown2->ForeColor = System::Drawing::Color::White;
			this->numericUpDown2->Location = System::Drawing::Point(9, 47);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(67, 30);
			this->numericUpDown2->TabIndex = 6;
			this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button16->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::Color::Black;
			this->button16->Location = System::Drawing::Point(164, 23);
			this->button16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(67, 55);
			this->button16->TabIndex = 5;
			this->button16->Text = L"Off";
			this->button16->UseVisualStyleBackColor = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(20, 23);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(81, 21);
			this->radioButton1->TabIndex = 18;
			this->radioButton1->Text = L"WORLD";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->radioButton3);
			this->groupBox5->Controls->Add(this->radioButton2);
			this->groupBox5->Controls->Add(this->radioButton1);
			this->groupBox5->ForeColor = System::Drawing::Color::White;
			this->groupBox5->Location = System::Drawing::Point(277, 16);
			this->groupBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox5->Size = System::Drawing::Size(325, 54);
			this->groupBox5->TabIndex = 19;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"COORD";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(224, 23);
			this->radioButton3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(69, 21);
			this->radioButton3->TabIndex = 20;
			this->radioButton3->Text = L"JOINT";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(128, 23);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(67, 21);
			this->radioButton2->TabIndex = 19;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"USER";
			this->radioButton2->UseVisualStyleBackColor = true;
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
			this->groupBox6->Location = System::Drawing::Point(277, 299);
			this->groupBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox6->Size = System::Drawing::Size(325, 127);
			this->groupBox6->TabIndex = 21;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Move To";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->ForeColor = System::Drawing::Color::White;
			this->label41->Location = System::Drawing::Point(180, 92);
			this->label41->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(19, 17);
			this->label41->TabIndex = 48;
			this->label41->Text = L"R";
			// 
			// tb_robot_initW
			// 
			this->tb_robot_initW->Location = System::Drawing::Point(207, 23);
			this->tb_robot_initW->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robot_initW->Name = L"tb_robot_initW";
			this->tb_robot_initW->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initW->TabIndex = 43;
			this->tb_robot_initW->Text = L"0.00";
			this->tb_robot_initW->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_robot_initR
			// 
			this->tb_robot_initR->Location = System::Drawing::Point(207, 89);
			this->tb_robot_initR->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robot_initR->Name = L"tb_robot_initR";
			this->tb_robot_initR->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initR->TabIndex = 47;
			this->tb_robot_initR->Text = L"0.00";
			this->tb_robot_initR->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_robot_initX
			// 
			this->tb_robot_initX->Location = System::Drawing::Point(56, 23);
			this->tb_robot_initX->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robot_initX->Name = L"tb_robot_initX";
			this->tb_robot_initX->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initX->TabIndex = 6;
			this->tb_robot_initX->Text = L"0.00";
			this->tb_robot_initX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->ForeColor = System::Drawing::Color::White;
			this->label42->Location = System::Drawing::Point(180, 60);
			this->label42->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(18, 17);
			this->label42->TabIndex = 46;
			this->label42->Text = L"P";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->ForeColor = System::Drawing::Color::White;
			this->label38->Location = System::Drawing::Point(29, 27);
			this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(18, 17);
			this->label38->TabIndex = 7;
			this->label38->Text = L"X";
			// 
			// tb_robot_initP
			// 
			this->tb_robot_initP->Location = System::Drawing::Point(207, 57);
			this->tb_robot_initP->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robot_initP->Name = L"tb_robot_initP";
			this->tb_robot_initP->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initP->TabIndex = 45;
			this->tb_robot_initP->Text = L"0.00";
			this->tb_robot_initP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_robot_initY
			// 
			this->tb_robot_initY->Location = System::Drawing::Point(56, 57);
			this->tb_robot_initY->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robot_initY->Name = L"tb_robot_initY";
			this->tb_robot_initY->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initY->TabIndex = 39;
			this->tb_robot_initY->Text = L"0.00";
			this->tb_robot_initY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->ForeColor = System::Drawing::Color::White;
			this->label43->Location = System::Drawing::Point(180, 27);
			this->label43->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(22, 17);
			this->label43->TabIndex = 44;
			this->label43->Text = L"W";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->ForeColor = System::Drawing::Color::White;
			this->label39->Location = System::Drawing::Point(29, 60);
			this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(18, 17);
			this->label39->TabIndex = 40;
			this->label39->Text = L"Y";
			// 
			// tb_robot_initZ
			// 
			this->tb_robot_initZ->Location = System::Drawing::Point(56, 89);
			this->tb_robot_initZ->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_robot_initZ->Name = L"tb_robot_initZ";
			this->tb_robot_initZ->Size = System::Drawing::Size(83, 22);
			this->tb_robot_initZ->TabIndex = 41;
			this->tb_robot_initZ->Text = L"0.00";
			this->tb_robot_initZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->ForeColor = System::Drawing::Color::White;
			this->label40->Location = System::Drawing::Point(29, 92);
			this->label40->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(18, 17);
			this->label40->TabIndex = 42;
			this->label40->Text = L"Z";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->button19);
			this->groupBox7->Controls->Add(this->button18);
			this->groupBox7->Controls->Add(this->numericUpDown3);
			this->groupBox7->ForeColor = System::Drawing::Color::White;
			this->groupBox7->Location = System::Drawing::Point(277, 433);
			this->groupBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox7->Size = System::Drawing::Size(325, 70);
			this->groupBox7->TabIndex = 21;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Position Register";
			// 
			// button19
			// 
			this->button19->ForeColor = System::Drawing::Color::Black;
			this->button19->Location = System::Drawing::Point(216, 26);
			this->button19->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(100, 28);
			this->button19->TabIndex = 10;
			this->button19->Text = L"Write";
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->ForeColor = System::Drawing::Color::Black;
			this->button18->Location = System::Drawing::Point(100, 26);
			this->button18->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(100, 28);
			this->button18->TabIndex = 9;
			this->button18->Text = L"Read";
			this->button18->UseVisualStyleBackColor = true;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->BackColor = System::Drawing::SystemColors::MenuText;
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown3->ForeColor = System::Drawing::Color::White;
			this->numericUpDown3->Location = System::Drawing::Point(20, 23);
			this->numericUpDown3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(67, 30);
			this->numericUpDown3->TabIndex = 8;
			this->numericUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &RobotControllerDlg::timer1_Tick);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->button21);
			this->groupBox8->Controls->Add(this->button17);
			this->groupBox8->Controls->Add(this->button20);
			this->groupBox8->Controls->Add(this->button6);
			this->groupBox8->Controls->Add(this->button5);
			this->groupBox8->Controls->Add(this->button2);
			this->groupBox8->Controls->Add(this->btn_attach);
			this->groupBox8->ForeColor = System::Drawing::Color::White;
			this->groupBox8->Location = System::Drawing::Point(611, 16);
			this->groupBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox8->Size = System::Drawing::Size(227, 487);
			this->groupBox8->TabIndex = 22;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"TOOL";
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->ForeColor = System::Drawing::Color::Black;
			this->button21->Location = System::Drawing::Point(8, 425);
			this->button21->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(208, 55);
			this->button21->TabIndex = 12;
			this->button21->Text = L"Grinder ON";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &RobotControllerDlg::button21_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::Color::Black;
			this->button17->Location = System::Drawing::Point(8, 363);
			this->button17->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(208, 55);
			this->button17->TabIndex = 11;
			this->button17->Text = L"Gripper CLOSE";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &RobotControllerDlg::button17_Click_1);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->ForeColor = System::Drawing::Color::Black;
			this->button20->Location = System::Drawing::Point(8, 300);
			this->button20->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(208, 55);
			this->button20->TabIndex = 10;
			this->button20->Text = L"Gripper OPEN";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &RobotControllerDlg::button20_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(8, 224);
			this->button6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(208, 55);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Release Grinder";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(8, 161);
			this->button5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(208, 55);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Attach Grinder";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(8, 98);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(208, 55);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Release Gripper";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &RobotControllerDlg::button2_Click);
			// 
			// btn_attach
			// 
			this->btn_attach->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_attach->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_attach->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_attach->ForeColor = System::Drawing::Color::Black;
			this->btn_attach->Location = System::Drawing::Point(8, 36);
			this->btn_attach->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_attach->Name = L"btn_attach";
			this->btn_attach->Size = System::Drawing::Size(208, 55);
			this->btn_attach->TabIndex = 6;
			this->btn_attach->Text = L"Attach Gripper";
			this->btn_attach->UseVisualStyleBackColor = false;
			this->btn_attach->Click += gcnew System::EventHandler(this, &RobotControllerDlg::btn_attach_Click);
			// 
			// RobotControllerDlg
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(853, 518);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"RobotControllerDlg";
			this->Text = L"RobotControllerDlg";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RobotControllerDlg::RobotControllerDlg_FormClosed);
			this->Load += gcnew System::EventHandler(this, &RobotControllerDlg::RobotControllerDlg_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_DO))->EndInit();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->groupBox8->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RobotControllerDlg_Load(System::Object^  sender, System::EventArgs^  e) {
		robotControl_form_isOpen = true;
		//timer1->Enabled = true;
	}
private: System::Void RobotControllerDlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	robotControl_form_isOpen = false;
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	update_position();
}
private: System::Void btn_sdo_ON_Click(System::Object^  sender, System::EventArgs^  e) {
	set_sdo_on();
}

private: System::Void btn_x_up_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	posX_up();
}

private: System::Void btn_attach_Click(System::Object^  sender, System::EventArgs^  e) {
	attach_gripper();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	release_gripper();
}
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
	gripper_open();
}
private: System::Void button17_Click_1(System::Object^  sender, System::EventArgs^  e) {
	gripper_close();
}
private: System::Void btn_sdo_OFF_Click(System::Object^  sender, System::EventArgs^  e) {
	set_sdo_off();
}
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

#pragma once

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void on_timer();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;













	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::ProgressBar^  progressBar4;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::ProgressBar^  progressBar5;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::ProgressBar^  progressBar6;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ProgressBar^  progressBar3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Panel^  panel_contact;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label_contact;
	private: System::Windows::Forms::TextBox^  tb_force;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::GroupBox^  groupBox5;
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
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::TextBox^  ePos_X;
	private: System::Windows::Forms::TextBox^  ePos_R;


	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  ePos_P;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  ePos_W;


	private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::TextBox^  ePos_Z;

	private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::TextBox^  ePos_Y;

	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::TextBox^  rPos_X;
	private: System::Windows::Forms::TextBox^  rPos_r;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  rPos_p;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  rPos_W;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  rPos_Z;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  rPos_Y;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->progressBar4 = (gcnew System::Windows::Forms::ProgressBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->progressBar5 = (gcnew System::Windows::Forms::ProgressBar());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->progressBar6 = (gcnew System::Windows::Forms::ProgressBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel_contact = (gcnew System::Windows::Forms::Panel());
			this->label_contact = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_force = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->rPos_X = (gcnew System::Windows::Forms::TextBox());
			this->rPos_r = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->rPos_p = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->rPos_W = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->rPos_Z = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->rPos_Y = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->ePos_X = (gcnew System::Windows::Forms::TextBox());
			this->ePos_R = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->ePos_P = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->ePos_W = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->ePos_Z = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->ePos_Y = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->panel_contact->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox8);
			this->groupBox1->Controls->Add(this->groupBox7);
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(251, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(716, 470);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Trajectory";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(224, 286);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Action Command";
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(19, 209);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(173, 51);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Add Online Points";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(19, 38);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 51);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Load Trajectory";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(19, 152);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(173, 51);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Add New Points";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(19, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(173, 51);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Select Points";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(12, 304);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(224, 178);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Haptic Teleoperation";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(106, 133);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"3.4";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 136);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Damping:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(106, 105);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"2.0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Stiffness :";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button7->ForeColor = System::Drawing::Color::Black;
			this->button7->Location = System::Drawing::Point(19, 38);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(173, 51);
			this->button7->TabIndex = 3;
			this->button7->Text = L"Connect to Device";
			this->button7->UseVisualStyleBackColor = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Controls->Add(this->radioButton3);
			this->groupBox4->Controls->Add(this->radioButton2);
			this->groupBox4->Controls->Add(this->radioButton1);
			this->groupBox4->ForeColor = System::Drawing::Color::White;
			this->groupBox4->Location = System::Drawing::Point(12, 495);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(224, 164);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Teleoperatoin Mode";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(58, 116);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 39);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(39, 89);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(142, 21);
			this->radioButton3->TabIndex = 14;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Free Manipulation";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(39, 62);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(106, 21);
			this->radioButton2->TabIndex = 13;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Follow Lines";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(39, 35);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(68, 21);
			this->radioButton1->TabIndex = 12;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Points";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label12);
			this->groupBox6->Controls->Add(this->progressBar4);
			this->groupBox6->Controls->Add(this->label13);
			this->groupBox6->Controls->Add(this->progressBar5);
			this->groupBox6->Controls->Add(this->label14);
			this->groupBox6->Controls->Add(this->progressBar6);
			this->groupBox6->Controls->Add(this->label11);
			this->groupBox6->Controls->Add(this->progressBar3);
			this->groupBox6->Controls->Add(this->label10);
			this->groupBox6->Controls->Add(this->progressBar2);
			this->groupBox6->Controls->Add(this->label9);
			this->groupBox6->Controls->Add(this->progressBar1);
			this->groupBox6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox6->Location = System::Drawing::Point(254, 495);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(360, 164);
			this->groupBox6->TabIndex = 13;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Force";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(200, 107);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(30, 17);
			this->label12->TabIndex = 32;
			this->label12->Text = L"Mz:";
			// 
			// progressBar4
			// 
			this->progressBar4->Location = System::Drawing::Point(231, 103);
			this->progressBar4->Name = L"progressBar4";
			this->progressBar4->Size = System::Drawing::Size(100, 23);
			this->progressBar4->TabIndex = 31;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(200, 77);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(30, 17);
			this->label13->TabIndex = 30;
			this->label13->Text = L"My:";
			// 
			// progressBar5
			// 
			this->progressBar5->Location = System::Drawing::Point(231, 73);
			this->progressBar5->Name = L"progressBar5";
			this->progressBar5->Size = System::Drawing::Size(100, 23);
			this->progressBar5->TabIndex = 29;
			this->progressBar5->Value = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(200, 48);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(29, 17);
			this->label14->TabIndex = 28;
			this->label14->Text = L"Mx:";
			// 
			// progressBar6
			// 
			this->progressBar6->Location = System::Drawing::Point(231, 44);
			this->progressBar6->Name = L"progressBar6";
			this->progressBar6->Size = System::Drawing::Size(100, 23);
			this->progressBar6->TabIndex = 27;
			this->progressBar6->Value = 2;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(30, 109);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 17);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Fz :";
			// 
			// progressBar3
			// 
			this->progressBar3->Location = System::Drawing::Point(61, 105);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(100, 23);
			this->progressBar3->TabIndex = 25;
			this->progressBar3->Value = 30;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(30, 79);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 17);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Fy :";
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(61, 75);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(100, 23);
			this->progressBar2->TabIndex = 23;
			this->progressBar2->Value = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(30, 50);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 17);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Fx :";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(61, 46);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 0;
			this->progressBar1->Value = 2;
			// 
			// panel_contact
			// 
			this->panel_contact->BackColor = System::Drawing::Color::Red;
			this->panel_contact->Controls->Add(this->label_contact);
			this->panel_contact->Location = System::Drawing::Point(644, 584);
			this->panel_contact->Name = L"panel_contact";
			this->panel_contact->Size = System::Drawing::Size(322, 74);
			this->panel_contact->TabIndex = 14;
			// 
			// label_contact
			// 
			this->label_contact->AutoSize = true;
			this->label_contact->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_contact->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label_contact->Location = System::Drawing::Point(78, 20);
			this->label_contact->Name = L"label_contact";
			this->label_contact->Size = System::Drawing::Size(166, 32);
			this->label_contact->TabIndex = 16;
			this->label_contact->Text = L"No Contact";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(641, 557);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 17);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Contact Status:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// tb_force
			// 
			this->tb_force->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->tb_force->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_force->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_force->ForeColor = System::Drawing::Color::White;
			this->tb_force->Location = System::Drawing::Point(799, 513);
			this->tb_force->Name = L"tb_force";
			this->tb_force->Size = System::Drawing::Size(156, 38);
			this->tb_force->TabIndex = 16;
			this->tb_force->Text = L"-120.452";
			this->tb_force->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tb_force->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(765, 513);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 17);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Fe:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// tbPosR
			// 
			this->tbPosR->BackColor = System::Drawing::Color::Black;
			this->tbPosR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosR->ForeColor = System::Drawing::Color::White;
			this->tbPosR->Location = System::Drawing::Point(76, 178);
			this->tbPosR->Margin = System::Windows::Forms::Padding(4);
			this->tbPosR->Name = L"tbPosR";
			this->tbPosR->Size = System::Drawing::Size(104, 23);
			this->tbPosR->TabIndex = 46;
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
			this->tbPosP->Location = System::Drawing::Point(76, 147);
			this->tbPosP->Margin = System::Windows::Forms::Padding(4);
			this->tbPosP->Name = L"tbPosP";
			this->tbPosP->Size = System::Drawing::Size(104, 23);
			this->tbPosP->TabIndex = 45;
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
			this->tbPosW->Location = System::Drawing::Point(76, 116);
			this->tbPosW->Margin = System::Windows::Forms::Padding(4);
			this->tbPosW->Name = L"tbPosW";
			this->tbPosW->Size = System::Drawing::Size(104, 23);
			this->tbPosW->TabIndex = 44;
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
			this->tbPosZ->Location = System::Drawing::Point(76, 85);
			this->tbPosZ->Margin = System::Windows::Forms::Padding(4);
			this->tbPosZ->Name = L"tbPosZ";
			this->tbPosZ->Size = System::Drawing::Size(104, 23);
			this->tbPosZ->TabIndex = 43;
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
			this->tbPosY->Location = System::Drawing::Point(76, 55);
			this->tbPosY->Margin = System::Windows::Forms::Padding(4);
			this->tbPosY->Name = L"tbPosY";
			this->tbPosY->Size = System::Drawing::Size(104, 23);
			this->tbPosY->TabIndex = 42;
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
			this->tbPosX->Location = System::Drawing::Point(76, 24);
			this->tbPosX->Margin = System::Windows::Forms::Padding(4);
			this->tbPosX->Name = L"tbPosX";
			this->tbPosX->Size = System::Drawing::Size(104, 23);
			this->tbPosX->TabIndex = 41;
			this->tbPosX->Text = L"0.00";
			this->tbPosX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Lime;
			this->label24->Location = System::Drawing::Point(17, 179);
			this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(24, 24);
			this->label24->TabIndex = 40;
			this->label24->Text = L"R";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::Lime;
			this->label26->Location = System::Drawing::Point(17, 148);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(23, 24);
			this->label26->TabIndex = 39;
			this->label26->Text = L"P";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::Lime;
			this->label28->Location = System::Drawing::Point(17, 117);
			this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(29, 24);
			this->label28->TabIndex = 38;
			this->label28->Text = L"W";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Lime;
			this->label22->Location = System::Drawing::Point(18, 83);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(23, 24);
			this->label22->TabIndex = 37;
			this->label22->Text = L"Z";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Lime;
			this->label20->Location = System::Drawing::Point(18, 53);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(23, 24);
			this->label20->TabIndex = 36;
			this->label20->Text = L"Y";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Lime;
			this->label17->Location = System::Drawing::Point(18, 24);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(25, 24);
			this->label17->TabIndex = 35;
			this->label17->Text = L"X";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tbPosX);
			this->groupBox5->Controls->Add(this->tbPosR);
			this->groupBox5->Controls->Add(this->label17);
			this->groupBox5->Controls->Add(this->tbPosP);
			this->groupBox5->Controls->Add(this->label20);
			this->groupBox5->Controls->Add(this->tbPosW);
			this->groupBox5->Controls->Add(this->label22);
			this->groupBox5->Controls->Add(this->tbPosZ);
			this->groupBox5->Controls->Add(this->label28);
			this->groupBox5->Controls->Add(this->tbPosY);
			this->groupBox5->Controls->Add(this->label26);
			this->groupBox5->Controls->Add(this->label24);
			this->groupBox5->ForeColor = System::Drawing::Color::White;
			this->groupBox5->Location = System::Drawing::Point(36, 38);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(204, 220);
			this->groupBox5->TabIndex = 47;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"ROBOT POS";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->rPos_X);
			this->groupBox7->Controls->Add(this->rPos_r);
			this->groupBox7->Controls->Add(this->label4);
			this->groupBox7->Controls->Add(this->rPos_p);
			this->groupBox7->Controls->Add(this->label6);
			this->groupBox7->Controls->Add(this->rPos_W);
			this->groupBox7->Controls->Add(this->label7);
			this->groupBox7->Controls->Add(this->rPos_Z);
			this->groupBox7->Controls->Add(this->label8);
			this->groupBox7->Controls->Add(this->rPos_Y);
			this->groupBox7->Controls->Add(this->label15);
			this->groupBox7->Controls->Add(this->label16);
			this->groupBox7->ForeColor = System::Drawing::Color::White;
			this->groupBox7->Location = System::Drawing::Point(255, 40);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(204, 220);
			this->groupBox7->TabIndex = 48;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"REFERENCE POS";
			// 
			// rPos_X
			// 
			this->rPos_X->BackColor = System::Drawing::Color::Black;
			this->rPos_X->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rPos_X->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rPos_X->ForeColor = System::Drawing::Color::White;
			this->rPos_X->Location = System::Drawing::Point(76, 24);
			this->rPos_X->Margin = System::Windows::Forms::Padding(4);
			this->rPos_X->Name = L"rPos_X";
			this->rPos_X->Size = System::Drawing::Size(104, 23);
			this->rPos_X->TabIndex = 41;
			this->rPos_X->Text = L"0.00";
			this->rPos_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// rPos_r
			// 
			this->rPos_r->BackColor = System::Drawing::Color::Black;
			this->rPos_r->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rPos_r->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rPos_r->ForeColor = System::Drawing::Color::White;
			this->rPos_r->Location = System::Drawing::Point(76, 178);
			this->rPos_r->Margin = System::Windows::Forms::Padding(4);
			this->rPos_r->Name = L"rPos_r";
			this->rPos_r->Size = System::Drawing::Size(104, 23);
			this->rPos_r->TabIndex = 46;
			this->rPos_r->Text = L"0.00";
			this->rPos_r->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(18, 24);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 24);
			this->label4->TabIndex = 35;
			this->label4->Text = L"X";
			// 
			// rPos_p
			// 
			this->rPos_p->BackColor = System::Drawing::Color::Black;
			this->rPos_p->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rPos_p->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rPos_p->ForeColor = System::Drawing::Color::White;
			this->rPos_p->Location = System::Drawing::Point(76, 147);
			this->rPos_p->Margin = System::Windows::Forms::Padding(4);
			this->rPos_p->Name = L"rPos_p";
			this->rPos_p->Size = System::Drawing::Size(104, 23);
			this->rPos_p->TabIndex = 45;
			this->rPos_p->Text = L"0.00";
			this->rPos_p->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Lime;
			this->label6->Location = System::Drawing::Point(18, 53);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 24);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Y";
			// 
			// rPos_W
			// 
			this->rPos_W->BackColor = System::Drawing::Color::Black;
			this->rPos_W->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rPos_W->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rPos_W->ForeColor = System::Drawing::Color::White;
			this->rPos_W->Location = System::Drawing::Point(76, 116);
			this->rPos_W->Margin = System::Windows::Forms::Padding(4);
			this->rPos_W->Name = L"rPos_W";
			this->rPos_W->Size = System::Drawing::Size(104, 23);
			this->rPos_W->TabIndex = 44;
			this->rPos_W->Text = L"0.00";
			this->rPos_W->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Lime;
			this->label7->Location = System::Drawing::Point(18, 83);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(23, 24);
			this->label7->TabIndex = 37;
			this->label7->Text = L"Z";
			// 
			// rPos_Z
			// 
			this->rPos_Z->BackColor = System::Drawing::Color::Black;
			this->rPos_Z->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rPos_Z->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rPos_Z->ForeColor = System::Drawing::Color::White;
			this->rPos_Z->Location = System::Drawing::Point(76, 85);
			this->rPos_Z->Margin = System::Windows::Forms::Padding(4);
			this->rPos_Z->Name = L"rPos_Z";
			this->rPos_Z->Size = System::Drawing::Size(104, 23);
			this->rPos_Z->TabIndex = 43;
			this->rPos_Z->Text = L"0.00";
			this->rPos_Z->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Lime;
			this->label8->Location = System::Drawing::Point(17, 117);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 24);
			this->label8->TabIndex = 38;
			this->label8->Text = L"W";
			// 
			// rPos_Y
			// 
			this->rPos_Y->BackColor = System::Drawing::Color::Black;
			this->rPos_Y->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rPos_Y->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rPos_Y->ForeColor = System::Drawing::Color::White;
			this->rPos_Y->Location = System::Drawing::Point(76, 55);
			this->rPos_Y->Margin = System::Windows::Forms::Padding(4);
			this->rPos_Y->Name = L"rPos_Y";
			this->rPos_Y->Size = System::Drawing::Size(104, 23);
			this->rPos_Y->TabIndex = 42;
			this->rPos_Y->Text = L"0.00";
			this->rPos_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Lime;
			this->label15->Location = System::Drawing::Point(17, 148);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(23, 24);
			this->label15->TabIndex = 39;
			this->label15->Text = L"P";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Lime;
			this->label16->Location = System::Drawing::Point(17, 179);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(24, 24);
			this->label16->TabIndex = 40;
			this->label16->Text = L"R";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->ePos_X);
			this->groupBox8->Controls->Add(this->ePos_R);
			this->groupBox8->Controls->Add(this->label18);
			this->groupBox8->Controls->Add(this->ePos_P);
			this->groupBox8->Controls->Add(this->label19);
			this->groupBox8->Controls->Add(this->ePos_W);
			this->groupBox8->Controls->Add(this->label21);
			this->groupBox8->Controls->Add(this->ePos_Z);
			this->groupBox8->Controls->Add(this->label23);
			this->groupBox8->Controls->Add(this->ePos_Y);
			this->groupBox8->Controls->Add(this->label25);
			this->groupBox8->Controls->Add(this->label27);
			this->groupBox8->ForeColor = System::Drawing::Color::White;
			this->groupBox8->Location = System::Drawing::Point(465, 40);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(204, 220);
			this->groupBox8->TabIndex = 49;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"POS DEVIATION";
			// 
			// ePos_X
			// 
			this->ePos_X->BackColor = System::Drawing::Color::Black;
			this->ePos_X->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ePos_X->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ePos_X->ForeColor = System::Drawing::Color::White;
			this->ePos_X->Location = System::Drawing::Point(76, 24);
			this->ePos_X->Margin = System::Windows::Forms::Padding(4);
			this->ePos_X->Name = L"ePos_X";
			this->ePos_X->Size = System::Drawing::Size(104, 23);
			this->ePos_X->TabIndex = 41;
			this->ePos_X->Text = L"0.00";
			this->ePos_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ePos_R
			// 
			this->ePos_R->BackColor = System::Drawing::Color::Black;
			this->ePos_R->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ePos_R->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ePos_R->ForeColor = System::Drawing::Color::White;
			this->ePos_R->Location = System::Drawing::Point(76, 178);
			this->ePos_R->Margin = System::Windows::Forms::Padding(4);
			this->ePos_R->Name = L"ePos_R";
			this->ePos_R->Size = System::Drawing::Size(104, 23);
			this->ePos_R->TabIndex = 46;
			this->ePos_R->Text = L"0.00";
			this->ePos_R->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Lime;
			this->label18->Location = System::Drawing::Point(18, 24);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(25, 24);
			this->label18->TabIndex = 35;
			this->label18->Text = L"X";
			// 
			// ePos_P
			// 
			this->ePos_P->BackColor = System::Drawing::Color::Black;
			this->ePos_P->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ePos_P->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ePos_P->ForeColor = System::Drawing::Color::White;
			this->ePos_P->Location = System::Drawing::Point(76, 147);
			this->ePos_P->Margin = System::Windows::Forms::Padding(4);
			this->ePos_P->Name = L"ePos_P";
			this->ePos_P->Size = System::Drawing::Size(104, 23);
			this->ePos_P->TabIndex = 45;
			this->ePos_P->Text = L"0.00";
			this->ePos_P->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Lime;
			this->label19->Location = System::Drawing::Point(18, 53);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(23, 24);
			this->label19->TabIndex = 36;
			this->label19->Text = L"Y";
			// 
			// ePos_W
			// 
			this->ePos_W->BackColor = System::Drawing::Color::Black;
			this->ePos_W->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ePos_W->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ePos_W->ForeColor = System::Drawing::Color::White;
			this->ePos_W->Location = System::Drawing::Point(76, 116);
			this->ePos_W->Margin = System::Windows::Forms::Padding(4);
			this->ePos_W->Name = L"ePos_W";
			this->ePos_W->Size = System::Drawing::Size(104, 23);
			this->ePos_W->TabIndex = 44;
			this->ePos_W->Text = L"0.00";
			this->ePos_W->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Lime;
			this->label21->Location = System::Drawing::Point(18, 83);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(23, 24);
			this->label21->TabIndex = 37;
			this->label21->Text = L"Z";
			// 
			// ePos_Z
			// 
			this->ePos_Z->BackColor = System::Drawing::Color::Black;
			this->ePos_Z->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ePos_Z->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ePos_Z->ForeColor = System::Drawing::Color::White;
			this->ePos_Z->Location = System::Drawing::Point(76, 85);
			this->ePos_Z->Margin = System::Windows::Forms::Padding(4);
			this->ePos_Z->Name = L"ePos_Z";
			this->ePos_Z->Size = System::Drawing::Size(104, 23);
			this->ePos_Z->TabIndex = 43;
			this->ePos_Z->Text = L"0.00";
			this->ePos_Z->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Lime;
			this->label23->Location = System::Drawing::Point(17, 117);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(29, 24);
			this->label23->TabIndex = 38;
			this->label23->Text = L"W";
			// 
			// ePos_Y
			// 
			this->ePos_Y->BackColor = System::Drawing::Color::Black;
			this->ePos_Y->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ePos_Y->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ePos_Y->ForeColor = System::Drawing::Color::White;
			this->ePos_Y->Location = System::Drawing::Point(76, 55);
			this->ePos_Y->Margin = System::Windows::Forms::Padding(4);
			this->ePos_Y->Name = L"ePos_Y";
			this->ePos_Y->Size = System::Drawing::Size(104, 23);
			this->ePos_Y->TabIndex = 42;
			this->ePos_Y->Text = L"0.00";
			this->ePos_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Lime;
			this->label25->Location = System::Drawing::Point(17, 148);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(23, 24);
			this->label25->TabIndex = 39;
			this->label25->Text = L"P";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::Lime;
			this->label27->Location = System::Drawing::Point(17, 179);
			this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(24, 24);
			this->label27->TabIndex = 40;
			this->label27->Text = L"R";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(984, 671);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tb_force);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel_contact);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->panel_contact->ResumeLayout(false);
			this->panel_contact->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}

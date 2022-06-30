#pragma once

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HapticForm
	/// </summary>
	public ref class HapticForm : public System::Windows::Forms::Form
	{
	public:
		HapticForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void haptic_begin();
		void HapticOnTimer1();
		void read_haptic_position();
		void read_haptic_force();
		void haptic_start_record();
		void haptic_stop_record();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HapticForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  Position;
	protected:
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textbox_posZ;
	private: System::Windows::Forms::TextBox^  textbox_posRz;


	private: System::Windows::Forms::TextBox^  textbox_posX;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textbox_posRy;

	private: System::Windows::Forms::TextBox^  textbox_posY;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textbox_posRx;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textbox_forceZ;

	private: System::Windows::Forms::TextBox^  textbox_forceX;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textbox_forceY;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::Label^  labelDevice;

	private: System::Windows::Forms::Button^  btnReadPos;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  t44;
	private: System::Windows::Forms::TextBox^  t34;
	private: System::Windows::Forms::TextBox^  t14;
	private: System::Windows::Forms::TextBox^  t24;
	private: System::Windows::Forms::TextBox^  t43;
	private: System::Windows::Forms::TextBox^  t33;
	private: System::Windows::Forms::TextBox^  t13;
	private: System::Windows::Forms::TextBox^  t23;
	private: System::Windows::Forms::TextBox^  t42;
	private: System::Windows::Forms::TextBox^  t32;
	private: System::Windows::Forms::TextBox^  t12;
	private: System::Windows::Forms::TextBox^  t22;
	private: System::Windows::Forms::TextBox^  t41;
	private: System::Windows::Forms::TextBox^  t31;
	private: System::Windows::Forms::TextBox^  t11;
	private: System::Windows::Forms::TextBox^  t21;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  labelConnection;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  startRecord;
	private: System::Windows::Forms::Button^  stopRecord;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TextBox^  tbV3;

	private: System::Windows::Forms::TextBox^  tbV1;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tbV2;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
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
			this->Position = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textbox_posZ = (gcnew System::Windows::Forms::TextBox());
			this->textbox_posRz = (gcnew System::Windows::Forms::TextBox());
			this->textbox_posX = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textbox_posRy = (gcnew System::Windows::Forms::TextBox());
			this->textbox_posY = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textbox_posRx = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textbox_forceZ = (gcnew System::Windows::Forms::TextBox());
			this->textbox_forceX = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textbox_forceY = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->labelDevice = (gcnew System::Windows::Forms::Label());
			this->btnReadPos = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->t44 = (gcnew System::Windows::Forms::TextBox());
			this->t34 = (gcnew System::Windows::Forms::TextBox());
			this->t14 = (gcnew System::Windows::Forms::TextBox());
			this->t24 = (gcnew System::Windows::Forms::TextBox());
			this->t43 = (gcnew System::Windows::Forms::TextBox());
			this->t33 = (gcnew System::Windows::Forms::TextBox());
			this->t13 = (gcnew System::Windows::Forms::TextBox());
			this->t23 = (gcnew System::Windows::Forms::TextBox());
			this->t42 = (gcnew System::Windows::Forms::TextBox());
			this->t32 = (gcnew System::Windows::Forms::TextBox());
			this->t12 = (gcnew System::Windows::Forms::TextBox());
			this->t22 = (gcnew System::Windows::Forms::TextBox());
			this->t41 = (gcnew System::Windows::Forms::TextBox());
			this->t31 = (gcnew System::Windows::Forms::TextBox());
			this->t11 = (gcnew System::Windows::Forms::TextBox());
			this->t21 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->labelConnection = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->startRecord = (gcnew System::Windows::Forms::Button());
			this->stopRecord = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tbV3 = (gcnew System::Windows::Forms::TextBox());
			this->tbV1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tbV2 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->Position->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// Position
			// 
			this->Position->Controls->Add(this->label4);
			this->Position->Controls->Add(this->textbox_posZ);
			this->Position->Controls->Add(this->textbox_posRz);
			this->Position->Controls->Add(this->textbox_posX);
			this->Position->Controls->Add(this->label5);
			this->Position->Controls->Add(this->label1);
			this->Position->Controls->Add(this->textbox_posRy);
			this->Position->Controls->Add(this->textbox_posY);
			this->Position->Controls->Add(this->label6);
			this->Position->Controls->Add(this->label2);
			this->Position->Controls->Add(this->textbox_posRx);
			this->Position->Controls->Add(this->label3);
			this->Position->Location = System::Drawing::Point(12, 12);
			this->Position->Name = L"Position";
			this->Position->Size = System::Drawing::Size(115, 191);
			this->Position->TabIndex = 0;
			this->Position->TabStop = false;
			this->Position->Text = L"Position";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 157);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Rz :";
			// 
			// textbox_posZ
			// 
			this->textbox_posZ->Location = System::Drawing::Point(45, 76);
			this->textbox_posZ->Name = L"textbox_posZ";
			this->textbox_posZ->Size = System::Drawing::Size(50, 20);
			this->textbox_posZ->TabIndex = 5;
			this->textbox_posZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textbox_posRz
			// 
			this->textbox_posRz->Location = System::Drawing::Point(45, 154);
			this->textbox_posRz->Name = L"textbox_posRz";
			this->textbox_posRz->Size = System::Drawing::Size(50, 20);
			this->textbox_posRz->TabIndex = 11;
			this->textbox_posRz->Text = L"0.23";
			this->textbox_posRz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textbox_posX
			// 
			this->textbox_posX->Location = System::Drawing::Point(45, 24);
			this->textbox_posX->Name = L"textbox_posX";
			this->textbox_posX->Size = System::Drawing::Size(50, 20);
			this->textbox_posX->TabIndex = 1;
			this->textbox_posX->Text = L"-280";
			this->textbox_posX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 131);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Ry :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"X :";
			// 
			// textbox_posRy
			// 
			this->textbox_posRy->Location = System::Drawing::Point(45, 128);
			this->textbox_posRy->Name = L"textbox_posRy";
			this->textbox_posRy->Size = System::Drawing::Size(50, 20);
			this->textbox_posRy->TabIndex = 9;
			this->textbox_posRy->Text = L"90.00";
			this->textbox_posRy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textbox_posY
			// 
			this->textbox_posY->Location = System::Drawing::Point(45, 50);
			this->textbox_posY->Name = L"textbox_posY";
			this->textbox_posY->Size = System::Drawing::Size(50, 20);
			this->textbox_posY->TabIndex = 3;
			this->textbox_posY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 105);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Rx :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y :";
			// 
			// textbox_posRx
			// 
			this->textbox_posRx->Location = System::Drawing::Point(45, 102);
			this->textbox_posRx->Name = L"textbox_posRx";
			this->textbox_posRx->Size = System::Drawing::Size(50, 20);
			this->textbox_posRx->TabIndex = 7;
			this->textbox_posRx->Text = L"-180.78";
			this->textbox_posRx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Z :";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textbox_forceZ);
			this->groupBox1->Controls->Add(this->textbox_forceX);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->textbox_forceY);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Location = System::Drawing::Point(12, 206);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(115, 118);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Force";
			// 
			// textbox_forceZ
			// 
			this->textbox_forceZ->Location = System::Drawing::Point(46, 79);
			this->textbox_forceZ->Name = L"textbox_forceZ";
			this->textbox_forceZ->Size = System::Drawing::Size(49, 20);
			this->textbox_forceZ->TabIndex = 5;
			// 
			// textbox_forceX
			// 
			this->textbox_forceX->Location = System::Drawing::Point(46, 27);
			this->textbox_forceX->Name = L"textbox_forceX";
			this->textbox_forceX->Size = System::Drawing::Size(49, 20);
			this->textbox_forceX->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(20, 30);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Fx :";
			// 
			// textbox_forceY
			// 
			this->textbox_forceY->Location = System::Drawing::Point(46, 53);
			this->textbox_forceY->Name = L"textbox_forceY";
			this->textbox_forceY->Size = System::Drawing::Size(49, 20);
			this->textbox_forceY->TabIndex = 3;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(20, 56);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(24, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Fy :";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(20, 82);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(24, 13);
			this->label12->TabIndex = 6;
			this->label12->Text = L"Fz :";
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(50, 95);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(85, 23);
			this->btnConnect->TabIndex = 14;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &HapticForm::btnConnect_Click);
			// 
			// labelDevice
			// 
			this->labelDevice->AutoSize = true;
			this->labelDevice->Location = System::Drawing::Point(97, 29);
			this->labelDevice->Name = L"labelDevice";
			this->labelDevice->Size = System::Drawing::Size(38, 13);
			this->labelDevice->TabIndex = 15;
			this->labelDevice->Text = L"Touch";
			// 
			// btnReadPos
			// 
			this->btnReadPos->Location = System::Drawing::Point(388, 301);
			this->btnReadPos->Name = L"btnReadPos";
			this->btnReadPos->Size = System::Drawing::Size(102, 23);
			this->btnReadPos->TabIndex = 16;
			this->btnReadPos->Text = L"Read Position";
			this->btnReadPos->UseVisualStyleBackColor = true;
			this->btnReadPos->Click += gcnew System::EventHandler(this, &HapticForm::btnReadPos_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->t44);
			this->groupBox2->Controls->Add(this->t34);
			this->groupBox2->Controls->Add(this->t14);
			this->groupBox2->Controls->Add(this->t24);
			this->groupBox2->Controls->Add(this->t43);
			this->groupBox2->Controls->Add(this->t33);
			this->groupBox2->Controls->Add(this->t13);
			this->groupBox2->Controls->Add(this->t23);
			this->groupBox2->Controls->Add(this->t42);
			this->groupBox2->Controls->Add(this->t32);
			this->groupBox2->Controls->Add(this->t12);
			this->groupBox2->Controls->Add(this->t22);
			this->groupBox2->Controls->Add(this->t41);
			this->groupBox2->Controls->Add(this->t31);
			this->groupBox2->Controls->Add(this->t11);
			this->groupBox2->Controls->Add(this->t21);
			this->groupBox2->Location = System::Drawing::Point(133, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(280, 136);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Transform";
			// 
			// t44
			// 
			this->t44->Location = System::Drawing::Point(206, 104);
			this->t44->Name = L"t44";
			this->t44->Size = System::Drawing::Size(55, 20);
			this->t44->TabIndex = 18;
			this->t44->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t34
			// 
			this->t34->Location = System::Drawing::Point(206, 78);
			this->t34->Name = L"t34";
			this->t34->Size = System::Drawing::Size(55, 20);
			this->t34->TabIndex = 17;
			this->t34->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t14
			// 
			this->t14->Location = System::Drawing::Point(206, 26);
			this->t14->Name = L"t14";
			this->t14->Size = System::Drawing::Size(55, 20);
			this->t14->TabIndex = 15;
			this->t14->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t24
			// 
			this->t24->Location = System::Drawing::Point(206, 52);
			this->t24->Name = L"t24";
			this->t24->Size = System::Drawing::Size(55, 20);
			this->t24->TabIndex = 16;
			this->t24->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t43
			// 
			this->t43->Location = System::Drawing::Point(145, 104);
			this->t43->Name = L"t43";
			this->t43->Size = System::Drawing::Size(55, 20);
			this->t43->TabIndex = 14;
			this->t43->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t33
			// 
			this->t33->Location = System::Drawing::Point(145, 78);
			this->t33->Name = L"t33";
			this->t33->Size = System::Drawing::Size(55, 20);
			this->t33->TabIndex = 13;
			this->t33->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t13
			// 
			this->t13->Location = System::Drawing::Point(145, 26);
			this->t13->Name = L"t13";
			this->t13->Size = System::Drawing::Size(55, 20);
			this->t13->TabIndex = 11;
			this->t13->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t23
			// 
			this->t23->Location = System::Drawing::Point(145, 52);
			this->t23->Name = L"t23";
			this->t23->Size = System::Drawing::Size(55, 20);
			this->t23->TabIndex = 12;
			this->t23->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t42
			// 
			this->t42->Location = System::Drawing::Point(84, 104);
			this->t42->Name = L"t42";
			this->t42->Size = System::Drawing::Size(55, 20);
			this->t42->TabIndex = 10;
			this->t42->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t32
			// 
			this->t32->Location = System::Drawing::Point(84, 78);
			this->t32->Name = L"t32";
			this->t32->Size = System::Drawing::Size(55, 20);
			this->t32->TabIndex = 9;
			this->t32->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t12
			// 
			this->t12->Location = System::Drawing::Point(84, 26);
			this->t12->Name = L"t12";
			this->t12->Size = System::Drawing::Size(55, 20);
			this->t12->TabIndex = 7;
			this->t12->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t22
			// 
			this->t22->Location = System::Drawing::Point(84, 52);
			this->t22->Name = L"t22";
			this->t22->Size = System::Drawing::Size(55, 20);
			this->t22->TabIndex = 8;
			this->t22->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t41
			// 
			this->t41->Location = System::Drawing::Point(23, 104);
			this->t41->Name = L"t41";
			this->t41->Size = System::Drawing::Size(55, 20);
			this->t41->TabIndex = 6;
			this->t41->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t31
			// 
			this->t31->Location = System::Drawing::Point(23, 78);
			this->t31->Name = L"t31";
			this->t31->Size = System::Drawing::Size(55, 20);
			this->t31->TabIndex = 5;
			this->t31->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t11
			// 
			this->t11->Location = System::Drawing::Point(23, 26);
			this->t11->Name = L"t11";
			this->t11->Size = System::Drawing::Size(55, 20);
			this->t11->TabIndex = 1;
			this->t11->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// t21
			// 
			this->t21->Location = System::Drawing::Point(23, 52);
			this->t21->Name = L"t21";
			this->t21->Size = System::Drawing::Size(55, 20);
			this->t21->TabIndex = 3;
			this->t21->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->labelConnection);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->btnConnect);
			this->groupBox3->Controls->Add(this->labelDevice);
			this->groupBox3->Location = System::Drawing::Point(419, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(186, 136);
			this->groupBox3->TabIndex = 17;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Haptic Device";
			// 
			// labelConnection
			// 
			this->labelConnection->AutoSize = true;
			this->labelConnection->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelConnection->Location = System::Drawing::Point(97, 47);
			this->labelConnection->Name = L"labelConnection";
			this->labelConnection->Size = System::Drawing::Size(73, 13);
			this->labelConnection->TabIndex = 18;
			this->labelConnection->Text = L"Disconnected";
			this->labelConnection->Click += gcnew System::EventHandler(this, &HapticForm::label10_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(47, 47);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Status :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(78, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Device Name :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(267, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Read Transform";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HapticForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(496, 301);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 23);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Scan";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HapticForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &HapticForm::timer1_Tick);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(267, 272);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 23);
			this->button3->TabIndex = 20;
			this->button3->Text = L"Read Force";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &HapticForm::button3_Click);
			// 
			// startRecord
			// 
			this->startRecord->Location = System::Drawing::Point(507, 197);
			this->startRecord->Name = L"startRecord";
			this->startRecord->Size = System::Drawing::Size(98, 23);
			this->startRecord->TabIndex = 21;
			this->startRecord->Text = L"Record";
			this->startRecord->UseVisualStyleBackColor = true;
			this->startRecord->Click += gcnew System::EventHandler(this, &HapticForm::startRecord_Click);
			// 
			// stopRecord
			// 
			this->stopRecord->Location = System::Drawing::Point(506, 226);
			this->stopRecord->Name = L"stopRecord";
			this->stopRecord->Size = System::Drawing::Size(98, 23);
			this->stopRecord->TabIndex = 22;
			this->stopRecord->Text = L"Stop Record";
			this->stopRecord->UseVisualStyleBackColor = true;
			this->stopRecord->Click += gcnew System::EventHandler(this, &HapticForm::stopRecord_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tbV3);
			this->groupBox4->Controls->Add(this->tbV1);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->tbV2);
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->label14);
			this->groupBox4->Location = System::Drawing::Point(133, 206);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(115, 118);
			this->groupBox4->TabIndex = 23;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Velocity";
			// 
			// tbV3
			// 
			this->tbV3->Location = System::Drawing::Point(46, 79);
			this->tbV3->Name = L"tbV3";
			this->tbV3->Size = System::Drawing::Size(49, 20);
			this->tbV3->TabIndex = 5;
			// 
			// tbV1
			// 
			this->tbV1->Location = System::Drawing::Point(46, 27);
			this->tbV1->Name = L"tbV1";
			this->tbV1->Size = System::Drawing::Size(49, 20);
			this->tbV1->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(20, 30);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(26, 13);
			this->label10->TabIndex = 2;
			this->label10->Text = L"V1 :";
			// 
			// tbV2
			// 
			this->tbV2->Location = System::Drawing::Point(46, 53);
			this->tbV2->Name = L"tbV2";
			this->tbV2->Size = System::Drawing::Size(49, 20);
			this->tbV2->TabIndex = 3;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(20, 56);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 13);
			this->label13->TabIndex = 4;
			this->label13->Text = L"V2:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(20, 82);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(20, 13);
			this->label14->TabIndex = 6;
			this->label14->Text = L"V3";
			// 
			// HapticForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 342);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->stopRecord);
			this->Controls->Add(this->startRecord);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->btnReadPos);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Position);
			this->Name = L"HapticForm";
			this->Text = L"HapticForm";
			this->Load += gcnew System::EventHandler(this, &HapticForm::HapticForm_Load);
			this->Position->ResumeLayout(false);
			this->Position->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		haptic_begin();
	}
	private: System::Void btnReadPos_Click(System::Object^  sender, System::EventArgs^  e) {
		read_haptic_position();
	}
private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = true;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	HapticOnTimer1();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	read_haptic_force();
}
private: System::Void startRecord_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_start_record();
}
private: System::Void stopRecord_Click(System::Object^  sender, System::EventArgs^  e) {
	haptic_stop_record();
}
private: System::Void HapticForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}

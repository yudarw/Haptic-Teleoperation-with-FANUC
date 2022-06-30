#pragma once

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ForceCalibrationForm
	/// </summary>
	public ref class ForceCalibrationForm : public System::Windows::Forms::Form
	{
	public:
		ForceCalibrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void display_force_data();
		void robot_set_position();
		void robot_set_force();
		void move_step_up();
		void move_step_down();
		void load_file();
		void main_program();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ForceCalibrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel3;
	protected:
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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  calibrated_mz_tb;

	private: System::Windows::Forms::TextBox^  calibrated_my_tb;

	private: System::Windows::Forms::TextBox^  calibrated_mx_tb;

	private: System::Windows::Forms::TextBox^  calibrated_fz_tb;

	private: System::Windows::Forms::TextBox^  calibrated_fy_tb;

	private: System::Windows::Forms::TextBox^  calibrated_fx_tb;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  calibrated_fx_bar;
	private: System::Windows::Forms::ProgressBar^  calibrated_fy_bar;
	private: System::Windows::Forms::ProgressBar^  calibrated_fz_bar;
	private: System::Windows::Forms::ProgressBar^  calibrated_mx_bar;
	private: System::Windows::Forms::ProgressBar^  calibrated_my_bar;
	private: System::Windows::Forms::ProgressBar^  calibrated_mz_bar;







	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  btnRecord;
	private: System::Windows::Forms::Button^  btnCalibrate;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  tb_pos_x;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  tb_pos_y;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  tb_pos_w;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  tb_pos_z;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  tb_pos_r;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  tb_pos_p;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  tb_force_x;
	private: System::Windows::Forms::TextBox^  tb_force_y;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  tb_force_z;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Button^  btnSetForce;
	private: System::Windows::Forms::Button^  btnSetPosition;
private: System::Windows::Forms::Button^  btnStepDown;

private: System::Windows::Forms::Button^  btnLoad;
private: System::Windows::Forms::Button^  btnStepUp;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label21;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->calibrated_mz_tb = (gcnew System::Windows::Forms::TextBox());
			this->calibrated_my_tb = (gcnew System::Windows::Forms::TextBox());
			this->calibrated_mx_tb = (gcnew System::Windows::Forms::TextBox());
			this->calibrated_fz_tb = (gcnew System::Windows::Forms::TextBox());
			this->calibrated_fy_tb = (gcnew System::Windows::Forms::TextBox());
			this->calibrated_fx_tb = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->calibrated_fx_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->calibrated_fy_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->calibrated_fz_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->calibrated_mx_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->calibrated_my_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->calibrated_mz_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->btnRecord = (gcnew System::Windows::Forms::Button());
			this->btnCalibrate = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tb_pos_x = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_y = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_w = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_z = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_r = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_p = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tb_force_x = (gcnew System::Windows::Forms::TextBox());
			this->tb_force_y = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tb_force_z = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->btnSetForce = (gcnew System::Windows::Forms::Button());
			this->btnSetPosition = (gcnew System::Windows::Forms::Button());
			this->btnStepDown = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->btnStepUp = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
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
			this->panel3->Location = System::Drawing::Point(13, 13);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(309, 267);
			this->panel3->TabIndex = 30;
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
			this->label31->Location = System::Drawing::Point(61, 12);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(185, 24);
			this->label31->TabIndex = 49;
			this->label31->Text = L"Real Force Sensor";
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
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->calibrated_mz_tb);
			this->panel1->Controls->Add(this->calibrated_my_tb);
			this->panel1->Controls->Add(this->calibrated_mx_tb);
			this->panel1->Controls->Add(this->calibrated_fz_tb);
			this->panel1->Controls->Add(this->calibrated_fy_tb);
			this->panel1->Controls->Add(this->calibrated_fx_tb);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->calibrated_fx_bar);
			this->panel1->Controls->Add(this->calibrated_fy_bar);
			this->panel1->Controls->Add(this->calibrated_fz_bar);
			this->panel1->Controls->Add(this->calibrated_mx_bar);
			this->panel1->Controls->Add(this->calibrated_my_bar);
			this->panel1->Controls->Add(this->calibrated_mz_bar);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Location = System::Drawing::Point(342, 13);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(309, 267);
			this->panel1->TabIndex = 65;
			// 
			// calibrated_mz_tb
			// 
			this->calibrated_mz_tb->BackColor = System::Drawing::Color::Black;
			this->calibrated_mz_tb->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->calibrated_mz_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calibrated_mz_tb->ForeColor = System::Drawing::Color::White;
			this->calibrated_mz_tb->Location = System::Drawing::Point(189, 215);
			this->calibrated_mz_tb->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_mz_tb->Name = L"calibrated_mz_tb";
			this->calibrated_mz_tb->Size = System::Drawing::Size(104, 19);
			this->calibrated_mz_tb->TabIndex = 64;
			this->calibrated_mz_tb->Text = L"0.00";
			this->calibrated_mz_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// calibrated_my_tb
			// 
			this->calibrated_my_tb->BackColor = System::Drawing::Color::Black;
			this->calibrated_my_tb->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->calibrated_my_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calibrated_my_tb->ForeColor = System::Drawing::Color::White;
			this->calibrated_my_tb->Location = System::Drawing::Point(189, 187);
			this->calibrated_my_tb->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_my_tb->Name = L"calibrated_my_tb";
			this->calibrated_my_tb->Size = System::Drawing::Size(104, 19);
			this->calibrated_my_tb->TabIndex = 63;
			this->calibrated_my_tb->Text = L"0.00";
			this->calibrated_my_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// calibrated_mx_tb
			// 
			this->calibrated_mx_tb->BackColor = System::Drawing::Color::Black;
			this->calibrated_mx_tb->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->calibrated_mx_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calibrated_mx_tb->ForeColor = System::Drawing::Color::White;
			this->calibrated_mx_tb->Location = System::Drawing::Point(189, 158);
			this->calibrated_mx_tb->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_mx_tb->Name = L"calibrated_mx_tb";
			this->calibrated_mx_tb->Size = System::Drawing::Size(104, 19);
			this->calibrated_mx_tb->TabIndex = 62;
			this->calibrated_mx_tb->Text = L"0.00";
			this->calibrated_mx_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// calibrated_fz_tb
			// 
			this->calibrated_fz_tb->BackColor = System::Drawing::Color::Black;
			this->calibrated_fz_tb->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->calibrated_fz_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calibrated_fz_tb->ForeColor = System::Drawing::Color::White;
			this->calibrated_fz_tb->Location = System::Drawing::Point(189, 128);
			this->calibrated_fz_tb->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_fz_tb->Name = L"calibrated_fz_tb";
			this->calibrated_fz_tb->Size = System::Drawing::Size(104, 19);
			this->calibrated_fz_tb->TabIndex = 61;
			this->calibrated_fz_tb->Text = L"0.00";
			this->calibrated_fz_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// calibrated_fy_tb
			// 
			this->calibrated_fy_tb->BackColor = System::Drawing::Color::Black;
			this->calibrated_fy_tb->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->calibrated_fy_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calibrated_fy_tb->ForeColor = System::Drawing::Color::White;
			this->calibrated_fy_tb->Location = System::Drawing::Point(189, 98);
			this->calibrated_fy_tb->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_fy_tb->Name = L"calibrated_fy_tb";
			this->calibrated_fy_tb->Size = System::Drawing::Size(104, 19);
			this->calibrated_fy_tb->TabIndex = 60;
			this->calibrated_fy_tb->Text = L"0.00";
			this->calibrated_fy_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// calibrated_fx_tb
			// 
			this->calibrated_fx_tb->BackColor = System::Drawing::Color::Black;
			this->calibrated_fx_tb->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->calibrated_fx_tb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calibrated_fx_tb->ForeColor = System::Drawing::Color::White;
			this->calibrated_fx_tb->Location = System::Drawing::Point(189, 69);
			this->calibrated_fx_tb->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_fx_tb->Name = L"calibrated_fx_tb";
			this->calibrated_fx_tb->Size = System::Drawing::Size(104, 19);
			this->calibrated_fx_tb->TabIndex = 59;
			this->calibrated_fx_tb->Text = L"0.00";
			this->calibrated_fx_tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(35, 12);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 24);
			this->label1->TabIndex = 49;
			this->label1->Text = L"Calibrated Force Sensor";
			// 
			// calibrated_fx_bar
			// 
			this->calibrated_fx_bar->Location = System::Drawing::Point(55, 65);
			this->calibrated_fx_bar->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_fx_bar->Name = L"calibrated_fx_bar";
			this->calibrated_fx_bar->Size = System::Drawing::Size(133, 22);
			this->calibrated_fx_bar->TabIndex = 4;
			// 
			// calibrated_fy_bar
			// 
			this->calibrated_fy_bar->Location = System::Drawing::Point(55, 95);
			this->calibrated_fy_bar->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_fy_bar->Name = L"calibrated_fy_bar";
			this->calibrated_fy_bar->Size = System::Drawing::Size(133, 22);
			this->calibrated_fy_bar->TabIndex = 5;
			// 
			// calibrated_fz_bar
			// 
			this->calibrated_fz_bar->Location = System::Drawing::Point(55, 124);
			this->calibrated_fz_bar->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_fz_bar->Name = L"calibrated_fz_bar";
			this->calibrated_fz_bar->Size = System::Drawing::Size(133, 22);
			this->calibrated_fz_bar->TabIndex = 6;
			// 
			// calibrated_mx_bar
			// 
			this->calibrated_mx_bar->Location = System::Drawing::Point(55, 154);
			this->calibrated_mx_bar->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_mx_bar->Name = L"calibrated_mx_bar";
			this->calibrated_mx_bar->Size = System::Drawing::Size(133, 22);
			this->calibrated_mx_bar->TabIndex = 7;
			// 
			// calibrated_my_bar
			// 
			this->calibrated_my_bar->Location = System::Drawing::Point(55, 183);
			this->calibrated_my_bar->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_my_bar->Name = L"calibrated_my_bar";
			this->calibrated_my_bar->Size = System::Drawing::Size(133, 22);
			this->calibrated_my_bar->TabIndex = 8;
			// 
			// calibrated_mz_bar
			// 
			this->calibrated_mz_bar->Location = System::Drawing::Point(55, 213);
			this->calibrated_mz_bar->Margin = System::Windows::Forms::Padding(4);
			this->calibrated_mz_bar->Name = L"calibrated_mz_bar";
			this->calibrated_mz_bar->Size = System::Drawing::Size(133, 22);
			this->calibrated_mz_bar->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(17, 68);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Fx";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(17, 97);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Fy";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Lime;
			this->label10->Location = System::Drawing::Point(17, 127);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(28, 20);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Fz";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Lime;
			this->label11->Location = System::Drawing::Point(17, 156);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 20);
			this->label11->TabIndex = 13;
			this->label11->Text = L"Mx";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Lime;
			this->label12->Location = System::Drawing::Point(17, 186);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 20);
			this->label12->TabIndex = 14;
			this->label12->Text = L"My";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Lime;
			this->label13->Location = System::Drawing::Point(17, 215);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(32, 20);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Mz";
			// 
			// btnRecord
			// 
			this->btnRecord->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnRecord->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRecord->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRecord->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRecord->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRecord->Location = System::Drawing::Point(136, 98);
			this->btnRecord->Margin = System::Windows::Forms::Padding(4);
			this->btnRecord->Name = L"btnRecord";
			this->btnRecord->Size = System::Drawing::Size(118, 53);
			this->btnRecord->TabIndex = 66;
			this->btnRecord->Text = L"Set Offset";
			this->btnRecord->UseVisualStyleBackColor = false;
			// 
			// btnCalibrate
			// 
			this->btnCalibrate->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnCalibrate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCalibrate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnCalibrate->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCalibrate->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCalibrate->Location = System::Drawing::Point(136, 161);
			this->btnCalibrate->Margin = System::Windows::Forms::Padding(4);
			this->btnCalibrate->Name = L"btnCalibrate";
			this->btnCalibrate->Size = System::Drawing::Size(118, 53);
			this->btnCalibrate->TabIndex = 67;
			this->btnCalibrate->Text = L"Calibrate";
			this->btnCalibrate->UseVisualStyleBackColor = false;
			this->btnCalibrate->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::btnCalibrate_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &ForceCalibrationForm::timer1_Tick);
			// 
			// tb_pos_x
			// 
			this->tb_pos_x->Location = System::Drawing::Point(57, 29);
			this->tb_pos_x->Name = L"tb_pos_x";
			this->tb_pos_x->Size = System::Drawing::Size(73, 22);
			this->tb_pos_x->TabIndex = 68;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(34, 32);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(17, 17);
			this->label14->TabIndex = 69;
			this->label14->Text = L"X";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(34, 60);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(17, 17);
			this->label15->TabIndex = 71;
			this->label15->Text = L"Y";
			// 
			// tb_pos_y
			// 
			this->tb_pos_y->Location = System::Drawing::Point(57, 57);
			this->tb_pos_y->Name = L"tb_pos_y";
			this->tb_pos_y->Size = System::Drawing::Size(73, 22);
			this->tb_pos_y->TabIndex = 70;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(34, 116);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(21, 17);
			this->label16->TabIndex = 75;
			this->label16->Text = L"W";
			// 
			// tb_pos_w
			// 
			this->tb_pos_w->Location = System::Drawing::Point(57, 113);
			this->tb_pos_w->Name = L"tb_pos_w";
			this->tb_pos_w->Size = System::Drawing::Size(73, 22);
			this->tb_pos_w->TabIndex = 74;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(34, 88);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(17, 17);
			this->label17->TabIndex = 73;
			this->label17->Text = L"Z";
			// 
			// tb_pos_z
			// 
			this->tb_pos_z->Location = System::Drawing::Point(57, 85);
			this->tb_pos_z->Name = L"tb_pos_z";
			this->tb_pos_z->Size = System::Drawing::Size(73, 22);
			this->tb_pos_z->TabIndex = 72;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(34, 172);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(18, 17);
			this->label18->TabIndex = 79;
			this->label18->Text = L"R";
			// 
			// tb_pos_r
			// 
			this->tb_pos_r->Location = System::Drawing::Point(57, 169);
			this->tb_pos_r->Name = L"tb_pos_r";
			this->tb_pos_r->Size = System::Drawing::Size(73, 22);
			this->tb_pos_r->TabIndex = 78;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(34, 144);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(17, 17);
			this->label19->TabIndex = 77;
			this->label19->Text = L"P";
			// 
			// tb_pos_p
			// 
			this->tb_pos_p->Location = System::Drawing::Point(57, 141);
			this->tb_pos_p->Name = L"tb_pos_p";
			this->tb_pos_p->Size = System::Drawing::Size(73, 22);
			this->tb_pos_p->TabIndex = 76;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->tb_pos_x);
			this->groupBox1->Controls->Add(this->tb_pos_r);
			this->groupBox1->Controls->Add(this->tb_pos_y);
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->tb_pos_p);
			this->groupBox1->Controls->Add(this->tb_pos_z);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->tb_pos_w);
			this->groupBox1->Location = System::Drawing::Point(13, 297);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(160, 227);
			this->groupBox1->TabIndex = 80;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Position";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->tb_force_x);
			this->groupBox2->Controls->Add(this->tb_force_y);
			this->groupBox2->Controls->Add(this->label23);
			this->groupBox2->Controls->Add(this->tb_force_z);
			this->groupBox2->Controls->Add(this->label25);
			this->groupBox2->Location = System::Drawing::Point(189, 297);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(160, 116);
			this->groupBox2->TabIndex = 81;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Force";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(34, 32);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(22, 17);
			this->label20->TabIndex = 69;
			this->label20->Text = L"Fx";
			// 
			// tb_force_x
			// 
			this->tb_force_x->Location = System::Drawing::Point(57, 29);
			this->tb_force_x->Name = L"tb_force_x";
			this->tb_force_x->Size = System::Drawing::Size(73, 22);
			this->tb_force_x->TabIndex = 68;
			// 
			// tb_force_y
			// 
			this->tb_force_y->Location = System::Drawing::Point(57, 57);
			this->tb_force_y->Name = L"tb_force_y";
			this->tb_force_y->Size = System::Drawing::Size(73, 22);
			this->tb_force_y->TabIndex = 70;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(34, 60);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(23, 17);
			this->label23->TabIndex = 71;
			this->label23->Text = L"Fy";
			// 
			// tb_force_z
			// 
			this->tb_force_z->Location = System::Drawing::Point(57, 85);
			this->tb_force_z->Name = L"tb_force_z";
			this->tb_force_z->Size = System::Drawing::Size(73, 22);
			this->tb_force_z->TabIndex = 72;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(34, 88);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(23, 17);
			this->label25->TabIndex = 73;
			this->label25->Text = L"Fz";
			// 
			// btnSetForce
			// 
			this->btnSetForce->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnSetForce->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSetForce->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSetForce->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSetForce->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSetForce->Location = System::Drawing::Point(16, 98);
			this->btnSetForce->Margin = System::Windows::Forms::Padding(4);
			this->btnSetForce->Name = L"btnSetForce";
			this->btnSetForce->Size = System::Drawing::Size(112, 53);
			this->btnSetForce->TabIndex = 82;
			this->btnSetForce->Text = L"Set Force";
			this->btnSetForce->UseVisualStyleBackColor = false;
			this->btnSetForce->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::btnSetForce_Click);
			// 
			// btnSetPosition
			// 
			this->btnSetPosition->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnSetPosition->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSetPosition->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSetPosition->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSetPosition->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSetPosition->Location = System::Drawing::Point(136, 32);
			this->btnSetPosition->Margin = System::Windows::Forms::Padding(4);
			this->btnSetPosition->Name = L"btnSetPosition";
			this->btnSetPosition->Size = System::Drawing::Size(118, 54);
			this->btnSetPosition->TabIndex = 83;
			this->btnSetPosition->Text = L"Set Position";
			this->btnSetPosition->UseVisualStyleBackColor = false;
			this->btnSetPosition->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::btnSetPosition_Click);
			// 
			// btnStepDown
			// 
			this->btnStepDown->BackColor = System::Drawing::Color::Yellow;
			this->btnStepDown->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStepDown->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStepDown->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStepDown->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStepDown->Location = System::Drawing::Point(188, 466);
			this->btnStepDown->Margin = System::Windows::Forms::Padding(4);
			this->btnStepDown->Name = L"btnStepDown";
			this->btnStepDown->Size = System::Drawing::Size(69, 54);
			this->btnStepDown->TabIndex = 84;
			this->btnStepDown->Text = L"<<";
			this->btnStepDown->UseVisualStyleBackColor = false;
			this->btnStepDown->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::btnStep_Click);
			// 
			// btnLoad
			// 
			this->btnLoad->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnLoad->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLoad->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLoad->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnLoad->Location = System::Drawing::Point(16, 161);
			this->btnLoad->Margin = System::Windows::Forms::Padding(4);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(112, 53);
			this->btnLoad->TabIndex = 85;
			this->btnLoad->Text = L"Load Data";
			this->btnLoad->UseVisualStyleBackColor = false;
			this->btnLoad->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::btnLoad_Click);
			// 
			// btnStepUp
			// 
			this->btnStepUp->BackColor = System::Drawing::Color::Yellow;
			this->btnStepUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStepUp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStepUp->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStepUp->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStepUp->Location = System::Drawing::Point(280, 466);
			this->btnStepUp->Margin = System::Windows::Forms::Padding(4);
			this->btnStepUp->Name = L"btnStepUp";
			this->btnStepUp->Size = System::Drawing::Size(69, 54);
			this->btnStepUp->TabIndex = 86;
			this->btnStepUp->Text = L">>";
			this->btnStepUp->UseVisualStyleBackColor = false;
			this->btnStepUp->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::btnStepUp_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Controls->Add(this->btnSetForce);
			this->groupBox3->Controls->Add(this->btnRecord);
			this->groupBox3->Controls->Add(this->btnLoad);
			this->groupBox3->Controls->Add(this->btnCalibrate);
			this->groupBox3->Controls->Add(this->btnSetPosition);
			this->groupBox3->Location = System::Drawing::Point(365, 297);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(286, 232);
			this->groupBox3->TabIndex = 87;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"groupBox3";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(18, 33);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 53);
			this->button1->TabIndex = 86;
			this->button1->Text = L"Main Program";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ForceCalibrationForm::button1_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->ForeColor = System::Drawing::Color::Black;
			this->label21->Location = System::Drawing::Point(186, 441);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(92, 17);
			this->label21->TabIndex = 88;
			this->label21->Text = L"MOVE STEP:";
			// 
			// ForceCalibrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(667, 536);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->btnStepUp);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->btnStepDown);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"ForceCalibrationForm";
			this->Text = L"ForceCalibrationForm";
			this->Load += gcnew System::EventHandler(this, &ForceCalibrationForm::ForceCalibrationForm_Load);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ForceCalibrationForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	display_force_data();
}
private: System::Void btnCalibrate_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void btnSetPosition_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_set_position();
}
private: System::Void btnSetForce_Click(System::Object^  sender, System::EventArgs^  e) {
	robot_set_force();
}
private: System::Void btnStep_Click(System::Object^  sender, System::EventArgs^  e) {
	move_step_down();
}
private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	load_file();
}
private: System::Void btnStepUp_Click(System::Object^  sender, System::EventArgs^  e) {
	move_step_up();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	main_program();
}
};
}

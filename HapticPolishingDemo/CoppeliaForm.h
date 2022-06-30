#pragma once

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CoppeliaForm
	/// </summary>
	public ref class CoppeliaForm : public System::Windows::Forms::Form
	{
	public:
		CoppeliaForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void on_timer();
		void sim_connect();
		void sim_haptic_jog();
		void sim_set_position();
		void get_current_position();
		void test();
		void main_program();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CoppeliaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnSimConnect;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  tb_pos_x;
	private: System::Windows::Forms::TextBox^  tb_pos_r;
	private: System::Windows::Forms::TextBox^  tb_pos_y;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  tb_pos_p;
	private: System::Windows::Forms::TextBox^  tb_pos_z;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  tb_pos_w;
	private: System::Windows::Forms::Button^  btnHapticJog;
	private: System::Windows::Forms::Timer^  timer1;
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
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  tb_out_posr;
	private: System::Windows::Forms::TextBox^  tb_out_posp;
	private: System::Windows::Forms::TextBox^  tb_out_posw;
	private: System::Windows::Forms::TextBox^  tb_out_posz;
	private: System::Windows::Forms::TextBox^  tb_out_posy;
	private: System::Windows::Forms::TextBox^  tb_out_posx;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  label_fz1;
	private: System::Windows::Forms::TextBox^  label_fy1;
	private: System::Windows::Forms::TextBox^  label_fx1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  fx_bar1;
	private: System::Windows::Forms::ProgressBar^  fy_bar1;
	private: System::Windows::Forms::ProgressBar^  fz_bar1;
	private: System::Windows::Forms::ProgressBar^  progressBar4;
	private: System::Windows::Forms::ProgressBar^  progressBar5;
	private: System::Windows::Forms::ProgressBar^  progressBar6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button3;
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
			this->btnSimConnect = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_x = (gcnew System::Windows::Forms::TextBox());
			this->tb_pos_r = (gcnew System::Windows::Forms::TextBox());
			this->tb_pos_y = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_p = (gcnew System::Windows::Forms::TextBox());
			this->tb_pos_z = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->tb_pos_w = (gcnew System::Windows::Forms::TextBox());
			this->btnHapticJog = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tb_out_posr = (gcnew System::Windows::Forms::TextBox());
			this->tb_out_posp = (gcnew System::Windows::Forms::TextBox());
			this->tb_out_posw = (gcnew System::Windows::Forms::TextBox());
			this->tb_out_posz = (gcnew System::Windows::Forms::TextBox());
			this->tb_out_posy = (gcnew System::Windows::Forms::TextBox());
			this->tb_out_posx = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label_fz1 = (gcnew System::Windows::Forms::TextBox());
			this->label_fy1 = (gcnew System::Windows::Forms::TextBox());
			this->label_fx1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fx_bar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->fy_bar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->fz_bar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar4 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar5 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar6 = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSimConnect
			// 
			this->btnSimConnect->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnSimConnect->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSimConnect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSimConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSimConnect->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSimConnect->Location = System::Drawing::Point(724, 349);
			this->btnSimConnect->Margin = System::Windows::Forms::Padding(4);
			this->btnSimConnect->Name = L"btnSimConnect";
			this->btnSimConnect->Size = System::Drawing::Size(161, 53);
			this->btnSimConnect->TabIndex = 67;
			this->btnSimConnect->Text = L"Sim Connect";
			this->btnSimConnect->UseVisualStyleBackColor = false;
			this->btnSimConnect->Click += gcnew System::EventHandler(this, &CoppeliaForm::btnSimConnect_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(388, 349);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 53);
			this->button1->TabIndex = 68;
			this->button1->Text = L"Set Position";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &CoppeliaForm::button1_Click);
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
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(13, 273);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(256, 127);
			this->groupBox1->TabIndex = 81;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Position";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(21, 35);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(17, 17);
			this->label14->TabIndex = 69;
			this->label14->Text = L"X";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(131, 91);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(18, 17);
			this->label18->TabIndex = 79;
			this->label18->Text = L"R";
			// 
			// tb_pos_x
			// 
			this->tb_pos_x->Location = System::Drawing::Point(44, 32);
			this->tb_pos_x->Name = L"tb_pos_x";
			this->tb_pos_x->Size = System::Drawing::Size(73, 22);
			this->tb_pos_x->TabIndex = 68;
			// 
			// tb_pos_r
			// 
			this->tb_pos_r->Location = System::Drawing::Point(154, 88);
			this->tb_pos_r->Name = L"tb_pos_r";
			this->tb_pos_r->Size = System::Drawing::Size(73, 22);
			this->tb_pos_r->TabIndex = 78;
			// 
			// tb_pos_y
			// 
			this->tb_pos_y->Location = System::Drawing::Point(44, 60);
			this->tb_pos_y->Name = L"tb_pos_y";
			this->tb_pos_y->Size = System::Drawing::Size(73, 22);
			this->tb_pos_y->TabIndex = 70;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(131, 63);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(17, 17);
			this->label19->TabIndex = 77;
			this->label19->Text = L"P";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(21, 63);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(17, 17);
			this->label15->TabIndex = 71;
			this->label15->Text = L"Y";
			// 
			// tb_pos_p
			// 
			this->tb_pos_p->Location = System::Drawing::Point(154, 60);
			this->tb_pos_p->Name = L"tb_pos_p";
			this->tb_pos_p->Size = System::Drawing::Size(73, 22);
			this->tb_pos_p->TabIndex = 76;
			// 
			// tb_pos_z
			// 
			this->tb_pos_z->Location = System::Drawing::Point(44, 88);
			this->tb_pos_z->Name = L"tb_pos_z";
			this->tb_pos_z->Size = System::Drawing::Size(73, 22);
			this->tb_pos_z->TabIndex = 72;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(131, 35);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(21, 17);
			this->label16->TabIndex = 75;
			this->label16->Text = L"W";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(21, 91);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(17, 17);
			this->label17->TabIndex = 73;
			this->label17->Text = L"Z";
			// 
			// tb_pos_w
			// 
			this->tb_pos_w->Location = System::Drawing::Point(154, 32);
			this->tb_pos_w->Name = L"tb_pos_w";
			this->tb_pos_w->Size = System::Drawing::Size(73, 22);
			this->tb_pos_w->TabIndex = 74;
			// 
			// btnHapticJog
			// 
			this->btnHapticJog->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnHapticJog->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHapticJog->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnHapticJog->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHapticJog->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnHapticJog->Location = System::Drawing::Point(557, 349);
			this->btnHapticJog->Margin = System::Windows::Forms::Padding(4);
			this->btnHapticJog->Name = L"btnHapticJog";
			this->btnHapticJog->Size = System::Drawing::Size(161, 53);
			this->btnHapticJog->TabIndex = 82;
			this->btnHapticJog->Text = L"Haptic Jog";
			this->btnHapticJog->UseVisualStyleBackColor = false;
			this->btnHapticJog->Click += gcnew System::EventHandler(this, &CoppeliaForm::btnHapticJog_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &CoppeliaForm::timer1_Tick);
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
			this->panel3->Location = System::Drawing::Point(259, 9);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(309, 257);
			this->panel3->TabIndex = 83;
			// 
			// label_mz
			// 
			this->label_mz->BackColor = System::Drawing::Color::Black;
			this->label_mz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_mz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_mz->ForeColor = System::Drawing::Color::White;
			this->label_mz->Location = System::Drawing::Point(185, 199);
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
			this->label_my->Location = System::Drawing::Point(185, 171);
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
			this->label_mx->Location = System::Drawing::Point(185, 142);
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
			this->label_fz->Location = System::Drawing::Point(185, 112);
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
			this->label_fy->Location = System::Drawing::Point(185, 82);
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
			this->label_fx->Location = System::Drawing::Point(185, 53);
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
			this->label31->Location = System::Drawing::Point(19, 9);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(230, 24);
			this->label31->TabIndex = 49;
			this->label31->Text = L"Raw Force Sensor Data";
			// 
			// fx_bar
			// 
			this->fx_bar->Location = System::Drawing::Point(51, 49);
			this->fx_bar->Margin = System::Windows::Forms::Padding(4);
			this->fx_bar->Name = L"fx_bar";
			this->fx_bar->Size = System::Drawing::Size(133, 22);
			this->fx_bar->TabIndex = 4;
			// 
			// fy_bar
			// 
			this->fy_bar->Location = System::Drawing::Point(51, 79);
			this->fy_bar->Margin = System::Windows::Forms::Padding(4);
			this->fy_bar->Name = L"fy_bar";
			this->fy_bar->Size = System::Drawing::Size(133, 22);
			this->fy_bar->TabIndex = 5;
			// 
			// fz_bar
			// 
			this->fz_bar->Location = System::Drawing::Point(51, 108);
			this->fz_bar->Margin = System::Windows::Forms::Padding(4);
			this->fz_bar->Name = L"fz_bar";
			this->fz_bar->Size = System::Drawing::Size(133, 22);
			this->fz_bar->TabIndex = 6;
			// 
			// mx_bar
			// 
			this->mx_bar->Location = System::Drawing::Point(51, 138);
			this->mx_bar->Margin = System::Windows::Forms::Padding(4);
			this->mx_bar->Name = L"mx_bar";
			this->mx_bar->Size = System::Drawing::Size(133, 22);
			this->mx_bar->TabIndex = 7;
			// 
			// my_bar
			// 
			this->my_bar->Location = System::Drawing::Point(51, 167);
			this->my_bar->Margin = System::Windows::Forms::Padding(4);
			this->my_bar->Name = L"my_bar";
			this->my_bar->Size = System::Drawing::Size(133, 22);
			this->my_bar->TabIndex = 8;
			// 
			// mz_bar
			// 
			this->mz_bar->Location = System::Drawing::Point(51, 197);
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
			this->label4->Location = System::Drawing::Point(13, 52);
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
			this->label5->Location = System::Drawing::Point(13, 81);
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
			this->label7->Location = System::Drawing::Point(13, 111);
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
			this->label6->Location = System::Drawing::Point(13, 140);
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
			this->label9->Location = System::Drawing::Point(13, 170);
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
			this->label8->Location = System::Drawing::Point(13, 199);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Mz";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->tb_out_posr);
			this->panel2->Controls->Add(this->tb_out_posp);
			this->panel2->Controls->Add(this->tb_out_posw);
			this->panel2->Controls->Add(this->tb_out_posz);
			this->panel2->Controls->Add(this->tb_out_posy);
			this->panel2->Controls->Add(this->tb_out_posx);
			this->panel2->Controls->Add(this->label24);
			this->panel2->Controls->Add(this->label26);
			this->panel2->Controls->Add(this->label28);
			this->panel2->Controls->Add(this->label22);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->label32);
			this->panel2->Location = System::Drawing::Point(13, 9);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(238, 257);
			this->panel2->TabIndex = 84;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Lime;
			this->label13->Location = System::Drawing::Point(18, 9);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(157, 24);
			this->label13->TabIndex = 35;
			this->label13->Text = L"Robot Position :";
			// 
			// tb_out_posr
			// 
			this->tb_out_posr->BackColor = System::Drawing::Color::Black;
			this->tb_out_posr->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_out_posr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_out_posr->ForeColor = System::Drawing::Color::White;
			this->tb_out_posr->Location = System::Drawing::Point(83, 201);
			this->tb_out_posr->Margin = System::Windows::Forms::Padding(4);
			this->tb_out_posr->Name = L"tb_out_posr";
			this->tb_out_posr->Size = System::Drawing::Size(104, 23);
			this->tb_out_posr->TabIndex = 34;
			this->tb_out_posr->Text = L"0.00";
			this->tb_out_posr->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_out_posp
			// 
			this->tb_out_posp->BackColor = System::Drawing::Color::Black;
			this->tb_out_posp->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_out_posp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_out_posp->ForeColor = System::Drawing::Color::White;
			this->tb_out_posp->Location = System::Drawing::Point(83, 170);
			this->tb_out_posp->Margin = System::Windows::Forms::Padding(4);
			this->tb_out_posp->Name = L"tb_out_posp";
			this->tb_out_posp->Size = System::Drawing::Size(104, 23);
			this->tb_out_posp->TabIndex = 33;
			this->tb_out_posp->Text = L"0.00";
			this->tb_out_posp->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_out_posw
			// 
			this->tb_out_posw->BackColor = System::Drawing::Color::Black;
			this->tb_out_posw->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_out_posw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_out_posw->ForeColor = System::Drawing::Color::White;
			this->tb_out_posw->Location = System::Drawing::Point(83, 139);
			this->tb_out_posw->Margin = System::Windows::Forms::Padding(4);
			this->tb_out_posw->Name = L"tb_out_posw";
			this->tb_out_posw->Size = System::Drawing::Size(104, 23);
			this->tb_out_posw->TabIndex = 32;
			this->tb_out_posw->Text = L"0.00";
			this->tb_out_posw->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_out_posz
			// 
			this->tb_out_posz->BackColor = System::Drawing::Color::Black;
			this->tb_out_posz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_out_posz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_out_posz->ForeColor = System::Drawing::Color::White;
			this->tb_out_posz->Location = System::Drawing::Point(83, 108);
			this->tb_out_posz->Margin = System::Windows::Forms::Padding(4);
			this->tb_out_posz->Name = L"tb_out_posz";
			this->tb_out_posz->Size = System::Drawing::Size(104, 23);
			this->tb_out_posz->TabIndex = 31;
			this->tb_out_posz->Text = L"0.00";
			this->tb_out_posz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_out_posy
			// 
			this->tb_out_posy->BackColor = System::Drawing::Color::Black;
			this->tb_out_posy->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_out_posy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_out_posy->ForeColor = System::Drawing::Color::White;
			this->tb_out_posy->Location = System::Drawing::Point(83, 78);
			this->tb_out_posy->Margin = System::Windows::Forms::Padding(4);
			this->tb_out_posy->Name = L"tb_out_posy";
			this->tb_out_posy->Size = System::Drawing::Size(104, 23);
			this->tb_out_posy->TabIndex = 30;
			this->tb_out_posy->Text = L"0.00";
			this->tb_out_posy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tb_out_posx
			// 
			this->tb_out_posx->BackColor = System::Drawing::Color::Black;
			this->tb_out_posx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_out_posx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_out_posx->ForeColor = System::Drawing::Color::White;
			this->tb_out_posx->Location = System::Drawing::Point(83, 47);
			this->tb_out_posx->Margin = System::Windows::Forms::Padding(4);
			this->tb_out_posx->Name = L"tb_out_posx";
			this->tb_out_posx->Size = System::Drawing::Size(104, 23);
			this->tb_out_posx->TabIndex = 29;
			this->tb_out_posx->Text = L"0.00";
			this->tb_out_posx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
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
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Lime;
			this->label32->Location = System::Drawing::Point(25, 47);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(25, 24);
			this->label32->TabIndex = 0;
			this->label32->Text = L"X";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label_fz1);
			this->panel1->Controls->Add(this->label_fy1);
			this->panel1->Controls->Add(this->label_fx1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->fx_bar1);
			this->panel1->Controls->Add(this->fy_bar1);
			this->panel1->Controls->Add(this->fz_bar1);
			this->panel1->Controls->Add(this->progressBar4);
			this->panel1->Controls->Add(this->progressBar5);
			this->panel1->Controls->Add(this->progressBar6);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label21);
			this->panel1->Location = System::Drawing::Point(576, 9);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(309, 257);
			this->panel1->TabIndex = 84;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(185, 199);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(104, 19);
			this->textBox1->TabIndex = 64;
			this->textBox1->Text = L"0.00";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Black;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(185, 171);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(104, 19);
			this->textBox2->TabIndex = 63;
			this->textBox2->Text = L"0.00";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Black;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(185, 142);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(104, 19);
			this->textBox3->TabIndex = 62;
			this->textBox3->Text = L"0.00";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_fz1
			// 
			this->label_fz1->BackColor = System::Drawing::Color::Black;
			this->label_fz1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_fz1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fz1->ForeColor = System::Drawing::Color::White;
			this->label_fz1->Location = System::Drawing::Point(185, 112);
			this->label_fz1->Margin = System::Windows::Forms::Padding(4);
			this->label_fz1->Name = L"label_fz1";
			this->label_fz1->Size = System::Drawing::Size(104, 19);
			this->label_fz1->TabIndex = 61;
			this->label_fz1->Text = L"0.00";
			this->label_fz1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_fy1
			// 
			this->label_fy1->BackColor = System::Drawing::Color::Black;
			this->label_fy1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_fy1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fy1->ForeColor = System::Drawing::Color::White;
			this->label_fy1->Location = System::Drawing::Point(185, 82);
			this->label_fy1->Margin = System::Windows::Forms::Padding(4);
			this->label_fy1->Name = L"label_fy1";
			this->label_fy1->Size = System::Drawing::Size(104, 19);
			this->label_fy1->TabIndex = 60;
			this->label_fy1->Text = L"0.00";
			this->label_fy1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label_fx1
			// 
			this->label_fx1->BackColor = System::Drawing::Color::Black;
			this->label_fx1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->label_fx1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_fx1->ForeColor = System::Drawing::Color::White;
			this->label_fx1->Location = System::Drawing::Point(185, 53);
			this->label_fx1->Margin = System::Windows::Forms::Padding(4);
			this->label_fx1->Name = L"label_fx1";
			this->label_fx1->Size = System::Drawing::Size(104, 19);
			this->label_fx1->TabIndex = 59;
			this->label_fx1->Text = L"0.00";
			this->label_fx1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(19, 9);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(249, 24);
			this->label1->TabIndex = 49;
			this->label1->Text = L"Normalized Force Sensor";
			// 
			// fx_bar1
			// 
			this->fx_bar1->Location = System::Drawing::Point(51, 49);
			this->fx_bar1->Margin = System::Windows::Forms::Padding(4);
			this->fx_bar1->Name = L"fx_bar1";
			this->fx_bar1->Size = System::Drawing::Size(133, 22);
			this->fx_bar1->TabIndex = 4;
			// 
			// fy_bar1
			// 
			this->fy_bar1->Location = System::Drawing::Point(51, 79);
			this->fy_bar1->Margin = System::Windows::Forms::Padding(4);
			this->fy_bar1->Name = L"fy_bar1";
			this->fy_bar1->Size = System::Drawing::Size(133, 22);
			this->fy_bar1->TabIndex = 5;
			// 
			// fz_bar1
			// 
			this->fz_bar1->Location = System::Drawing::Point(51, 108);
			this->fz_bar1->Margin = System::Windows::Forms::Padding(4);
			this->fz_bar1->Name = L"fz_bar1";
			this->fz_bar1->Size = System::Drawing::Size(133, 22);
			this->fz_bar1->TabIndex = 6;
			// 
			// progressBar4
			// 
			this->progressBar4->Location = System::Drawing::Point(51, 138);
			this->progressBar4->Margin = System::Windows::Forms::Padding(4);
			this->progressBar4->Name = L"progressBar4";
			this->progressBar4->Size = System::Drawing::Size(133, 22);
			this->progressBar4->TabIndex = 7;
			// 
			// progressBar5
			// 
			this->progressBar5->Location = System::Drawing::Point(51, 167);
			this->progressBar5->Margin = System::Windows::Forms::Padding(4);
			this->progressBar5->Name = L"progressBar5";
			this->progressBar5->Size = System::Drawing::Size(133, 22);
			this->progressBar5->TabIndex = 8;
			// 
			// progressBar6
			// 
			this->progressBar6->Location = System::Drawing::Point(51, 197);
			this->progressBar6->Margin = System::Windows::Forms::Padding(4);
			this->progressBar6->Name = L"progressBar6";
			this->progressBar6->Size = System::Drawing::Size(133, 22);
			this->progressBar6->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(13, 52);
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
			this->label3->Location = System::Drawing::Point(13, 81);
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
			this->label10->Location = System::Drawing::Point(13, 111);
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
			this->label11->Location = System::Drawing::Point(13, 140);
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
			this->label12->Location = System::Drawing::Point(13, 170);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 20);
			this->label12->TabIndex = 14;
			this->label12->Text = L"My";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Lime;
			this->label21->Location = System::Drawing::Point(13, 199);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(32, 20);
			this->label21->TabIndex = 15;
			this->label21->Text = L"Mz";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(388, 288);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(161, 53);
			this->button2->TabIndex = 85;
			this->button2->Text = L"Get Current Pos";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &CoppeliaForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(724, 288);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(161, 53);
			this->button3->TabIndex = 86;
			this->button3->Text = L"Main Program";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &CoppeliaForm::button3_Click);
			// 
			// CoppeliaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(895, 415);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->btnHapticJog);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnSimConnect);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"CoppeliaForm";
			this->Text = L"CoppeliaForm";
			this->Load += gcnew System::EventHandler(this, &CoppeliaForm::CoppeliaForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnSimConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		sim_connect();
	}
private: System::Void btnHapticJog_Click(System::Object^  sender, System::EventArgs^  e) {
	sim_haptic_jog();
	//test();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	sim_set_position();
}
private: System::Void CoppeliaForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	get_current_position();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	main_program();
}
};
}

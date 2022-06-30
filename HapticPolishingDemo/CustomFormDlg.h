#pragma once
#include "fanuc.h"
#include "main.h"

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CustomFormDlg
	/// </summary>
	public ref class CustomFormDlg : public System::Windows::Forms::Form
	{
	public:
		CustomFormDlg(void)
		{
			InitializeComponent();
			custom_form_isOpen = true;
			//
			//TODO: Add the constructor code here
			//
		}
		void handON();
		void handOFF();
		void grndON();
		void grndOFF();
		void home_position();
		void chair_legAuto();
		void chair_seatAuto();
		void paper_change();
		void on_timer1();
		void sys_auto();

		void update_settings();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomFormDlg()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  btn_start;




	private: System::Windows::Forms::Button^  btn_chairSeat;

	private: System::Windows::Forms::Button^  btn_hamdON;
	private: System::Windows::Forms::Button^  btn_chairLeg;


	private: System::Windows::Forms::Button^  btn_grndON;

	private: System::Windows::Forms::Button^  btn_handOFF;
	private: System::Windows::Forms::Button^  btn_grndOFF;
	private: System::Windows::Forms::Button^  btn_home;
	private: System::Windows::Forms::Button^  btn_paperChange;
	private: System::Windows::Forms::Label^  label_lineNumber;





	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label_taskName;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label_cycle;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel_seat;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Panel^  panel_error;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  panel_leg;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Panel^  panel_stanby;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel_grnd;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel_hand;


	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::NumericUpDown^  tb_laps;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btn_apply;

	private: System::ComponentModel::IContainer^  components;





















	protected:








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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel_seat = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel_error = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel_leg = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel_stanby = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel_grnd = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel_hand = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label_lineNumber = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label_taskName = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_cycle = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn_chairLeg = (gcnew System::Windows::Forms::Button());
			this->btn_chairSeat = (gcnew System::Windows::Forms::Button());
			this->btn_hamdON = (gcnew System::Windows::Forms::Button());
			this->btn_grndON = (gcnew System::Windows::Forms::Button());
			this->btn_handOFF = (gcnew System::Windows::Forms::Button());
			this->btn_grndOFF = (gcnew System::Windows::Forms::Button());
			this->btn_home = (gcnew System::Windows::Forms::Button());
			this->btn_paperChange = (gcnew System::Windows::Forms::Button());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_laps = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_apply = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel_seat->SuspendLayout();
			this->panel_error->SuspendLayout();
			this->panel_leg->SuspendLayout();
			this->panel_stanby->SuspendLayout();
			this->panel_grnd->SuspendLayout();
			this->panel_hand->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_laps))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel_seat);
			this->panel1->Controls->Add(this->panel_error);
			this->panel1->Controls->Add(this->panel_leg);
			this->panel1->Controls->Add(this->panel_stanby);
			this->panel1->Controls->Add(this->panel_grnd);
			this->panel1->Controls->Add(this->panel_hand);
			this->panel1->Controls->Add(this->label_lineNumber);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label_taskName);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label_cycle);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(320, 137);
			this->panel1->TabIndex = 0;
			// 
			// panel_seat
			// 
			this->panel_seat->BackColor = System::Drawing::Color::Lime;
			this->panel_seat->Controls->Add(this->label10);
			this->panel_seat->ForeColor = System::Drawing::Color::Black;
			this->panel_seat->Location = System::Drawing::Point(120, 106);
			this->panel_seat->Name = L"panel_seat";
			this->panel_seat->Size = System::Drawing::Size(49, 19);
			this->panel_seat->TabIndex = 60;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(8, 3);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 13);
			this->label10->TabIndex = 56;
			this->label10->Text = L"SEAT";
			// 
			// panel_error
			// 
			this->panel_error->BackColor = System::Drawing::Color::Gray;
			this->panel_error->Controls->Add(this->label9);
			this->panel_error->ForeColor = System::Drawing::Color::Black;
			this->panel_error->Location = System::Drawing::Point(65, 106);
			this->panel_error->Name = L"panel_error";
			this->panel_error->Size = System::Drawing::Size(49, 19);
			this->panel_error->TabIndex = 59;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Enabled = false;
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(3, 3);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 13);
			this->label9->TabIndex = 56;
			this->label9->Text = L"ERROR";
			// 
			// panel_leg
			// 
			this->panel_leg->BackColor = System::Drawing::Color::Lime;
			this->panel_leg->Controls->Add(this->label12);
			this->panel_leg->ForeColor = System::Drawing::Color::Black;
			this->panel_leg->Location = System::Drawing::Point(175, 106);
			this->panel_leg->Name = L"panel_leg";
			this->panel_leg->Size = System::Drawing::Size(49, 19);
			this->panel_leg->TabIndex = 61;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(11, 3);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(28, 13);
			this->label12->TabIndex = 56;
			this->label12->Text = L"LEG";
			// 
			// panel_stanby
			// 
			this->panel_stanby->BackColor = System::Drawing::Color::Gray;
			this->panel_stanby->Controls->Add(this->label8);
			this->panel_stanby->ForeColor = System::Drawing::Color::Black;
			this->panel_stanby->Location = System::Drawing::Point(230, 106);
			this->panel_stanby->Name = L"panel_stanby";
			this->panel_stanby->Size = System::Drawing::Size(49, 19);
			this->panel_stanby->TabIndex = 59;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(0, 3);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(50, 13);
			this->label8->TabIndex = 56;
			this->label8->Text = L"STANBY";
			// 
			// panel_grnd
			// 
			this->panel_grnd->BackColor = System::Drawing::Color::Red;
			this->panel_grnd->Controls->Add(this->label7);
			this->panel_grnd->ForeColor = System::Drawing::Color::Black;
			this->panel_grnd->Location = System::Drawing::Point(10, 106);
			this->panel_grnd->Name = L"panel_grnd";
			this->panel_grnd->Size = System::Drawing::Size(49, 19);
			this->panel_grnd->TabIndex = 59;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(3, 3);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(39, 13);
			this->label7->TabIndex = 56;
			this->label7->Text = L"GRND";
			// 
			// panel_hand
			// 
			this->panel_hand->BackColor = System::Drawing::Color::Red;
			this->panel_hand->Controls->Add(this->label11);
			this->panel_hand->ForeColor = System::Drawing::Color::Black;
			this->panel_hand->Location = System::Drawing::Point(10, 81);
			this->panel_hand->Name = L"panel_hand";
			this->panel_hand->Size = System::Drawing::Size(49, 19);
			this->panel_hand->TabIndex = 58;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(3, 3);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(38, 13);
			this->label11->TabIndex = 56;
			this->label11->Text = L"HAND";
			// 
			// label_lineNumber
			// 
			this->label_lineNumber->AutoSize = true;
			this->label_lineNumber->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_lineNumber->ForeColor = System::Drawing::Color::White;
			this->label_lineNumber->Location = System::Drawing::Point(93, 51);
			this->label_lineNumber->Name = L"label_lineNumber";
			this->label_lineNumber->Size = System::Drawing::Size(13, 13);
			this->label_lineNumber->TabIndex = 5;
			this->label_lineNumber->Text = L"5";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(7, 51);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Line Number:";
			// 
			// label_taskName
			// 
			this->label_taskName->AutoSize = true;
			this->label_taskName->BackColor = System::Drawing::Color::White;
			this->label_taskName->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_taskName->ForeColor = System::Drawing::Color::Black;
			this->label_taskName->Location = System::Drawing::Point(93, 30);
			this->label_taskName->Name = L"label_taskName";
			this->label_taskName->Size = System::Drawing::Size(61, 13);
			this->label_taskName->TabIndex = 3;
			this->label_taskName->Text = L"ROBOT API";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(7, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Task Name:";
			// 
			// label_cycle
			// 
			this->label_cycle->AutoSize = true;
			this->label_cycle->BackColor = System::Drawing::Color::Lime;
			this->label_cycle->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_cycle->ForeColor = System::Drawing::Color::Black;
			this->label_cycle->Location = System::Drawing::Point(93, 11);
			this->label_cycle->Name = L"label_cycle";
			this->label_cycle->Size = System::Drawing::Size(49, 13);
			this->label_cycle->TabIndex = 1;
			this->label_cycle->Text = L"Running";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(7, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Cycle Status:";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn_start, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(153, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.28706F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.71293F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(164, 309);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->btn_chairLeg, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->btn_chairSeat, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->btn_hamdON, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn_grndON, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->btn_handOFF, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn_grndOFF, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->btn_home, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->btn_paperChange, 1, 2);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 4;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(158, 232);
			this->tableLayoutPanel3->TabIndex = 0;
			this->tableLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CustomFormDlg::tableLayoutPanel3_Paint);
			// 
			// btn_chairLeg
			// 
			this->btn_chairLeg->BackColor = System::Drawing::Color::Yellow;
			this->btn_chairLeg->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_chairLeg->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_chairLeg->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_chairLeg->Location = System::Drawing::Point(3, 177);
			this->btn_chairLeg->Name = L"btn_chairLeg";
			this->btn_chairLeg->Size = System::Drawing::Size(73, 52);
			this->btn_chairLeg->TabIndex = 4;
			this->btn_chairLeg->Text = L"CHAIR LEG START";
			this->btn_chairLeg->UseVisualStyleBackColor = false;
			this->btn_chairLeg->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_chairLeg_Click);
			// 
			// btn_chairSeat
			// 
			this->btn_chairSeat->BackColor = System::Drawing::Color::Yellow;
			this->btn_chairSeat->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_chairSeat->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_chairSeat->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_chairSeat->Location = System::Drawing::Point(82, 177);
			this->btn_chairSeat->Name = L"btn_chairSeat";
			this->btn_chairSeat->Size = System::Drawing::Size(73, 52);
			this->btn_chairSeat->TabIndex = 3;
			this->btn_chairSeat->Text = L"CHAIR SEAT START";
			this->btn_chairSeat->UseVisualStyleBackColor = false;
			this->btn_chairSeat->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_chairSeat_Click);
			// 
			// btn_hamdON
			// 
			this->btn_hamdON->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_hamdON->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_hamdON->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_hamdON->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_hamdON->Location = System::Drawing::Point(3, 3);
			this->btn_hamdON->Name = L"btn_hamdON";
			this->btn_hamdON->Size = System::Drawing::Size(73, 52);
			this->btn_hamdON->TabIndex = 2;
			this->btn_hamdON->Text = L"HAND ON";
			this->btn_hamdON->UseVisualStyleBackColor = false;
			this->btn_hamdON->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_hamdON_Click);
			// 
			// btn_grndON
			// 
			this->btn_grndON->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_grndON->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_grndON->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_grndON->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_grndON->Location = System::Drawing::Point(3, 61);
			this->btn_grndON->Name = L"btn_grndON";
			this->btn_grndON->Size = System::Drawing::Size(73, 52);
			this->btn_grndON->TabIndex = 5;
			this->btn_grndON->Text = L"GRND ON";
			this->btn_grndON->UseVisualStyleBackColor = false;
			this->btn_grndON->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_grndON_Click);
			// 
			// btn_handOFF
			// 
			this->btn_handOFF->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_handOFF->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_handOFF->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_handOFF->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_handOFF->Location = System::Drawing::Point(82, 3);
			this->btn_handOFF->Name = L"btn_handOFF";
			this->btn_handOFF->Size = System::Drawing::Size(73, 52);
			this->btn_handOFF->TabIndex = 6;
			this->btn_handOFF->Text = L"HAND OFF";
			this->btn_handOFF->UseVisualStyleBackColor = false;
			this->btn_handOFF->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_handOFF_Click);
			// 
			// btn_grndOFF
			// 
			this->btn_grndOFF->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_grndOFF->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_grndOFF->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_grndOFF->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_grndOFF->Location = System::Drawing::Point(82, 61);
			this->btn_grndOFF->Name = L"btn_grndOFF";
			this->btn_grndOFF->Size = System::Drawing::Size(73, 52);
			this->btn_grndOFF->TabIndex = 7;
			this->btn_grndOFF->Text = L"GRND OFF";
			this->btn_grndOFF->UseVisualStyleBackColor = false;
			this->btn_grndOFF->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_grndOFF_Click);
			// 
			// btn_home
			// 
			this->btn_home->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_home->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_home->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_home->Location = System::Drawing::Point(3, 119);
			this->btn_home->Name = L"btn_home";
			this->btn_home->Size = System::Drawing::Size(73, 52);
			this->btn_home->TabIndex = 8;
			this->btn_home->Text = L"HOME";
			this->btn_home->UseVisualStyleBackColor = false;
			this->btn_home->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_home_Click);
			// 
			// btn_paperChange
			// 
			this->btn_paperChange->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_paperChange->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_paperChange->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_paperChange->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_paperChange->Location = System::Drawing::Point(82, 119);
			this->btn_paperChange->Name = L"btn_paperChange";
			this->btn_paperChange->Size = System::Drawing::Size(73, 52);
			this->btn_paperChange->TabIndex = 9;
			this->btn_paperChange->Text = L"GRND PAPER CHANGE";
			this->btn_paperChange->UseVisualStyleBackColor = false;
			this->btn_paperChange->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_paperChange_Click);
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_start->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_start->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_start->Location = System::Drawing::Point(3, 241);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(158, 65);
			this->btn_start->TabIndex = 1;
			this->btn_start->Text = L"START AUTO";
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_start_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &CustomFormDlg::timer1_Tick);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30.81897F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 69.18104F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(326, 464);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.875F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.125F)));
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 146);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(320, 315);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tb_laps);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->btn_apply);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(144, 97);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// tb_laps
			// 
			this->tb_laps->Location = System::Drawing::Point(85, 38);
			this->tb_laps->Name = L"tb_laps";
			this->tb_laps->Size = System::Drawing::Size(43, 20);
			this->tb_laps->TabIndex = 2;
			this->tb_laps->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_laps->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Cushion Lap :";
			// 
			// btn_apply
			// 
			this->btn_apply->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btn_apply->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_apply->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_apply->ForeColor = System::Drawing::Color::Black;
			this->btn_apply->Location = System::Drawing::Point(53, 64);
			this->btn_apply->Name = L"btn_apply";
			this->btn_apply->Size = System::Drawing::Size(75, 23);
			this->btn_apply->TabIndex = 0;
			this->btn_apply->Text = L"Apply";
			this->btn_apply->UseVisualStyleBackColor = false;
			this->btn_apply->Click += gcnew System::EventHandler(this, &CustomFormDlg::btn_apply_Click);
			// 
			// CustomFormDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(326, 464);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"CustomFormDlg";
			this->Text = L"Automatic Polishing Software";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &CustomFormDlg::CustomFormDlg_FormClosed);
			this->Load += gcnew System::EventHandler(this, &CustomFormDlg::CustomFormDlg_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel_seat->ResumeLayout(false);
			this->panel_seat->PerformLayout();
			this->panel_error->ResumeLayout(false);
			this->panel_error->PerformLayout();
			this->panel_leg->ResumeLayout(false);
			this->panel_leg->PerformLayout();
			this->panel_stanby->ResumeLayout(false);
			this->panel_stanby->PerformLayout();
			this->panel_grnd->ResumeLayout(false);
			this->panel_grnd->PerformLayout();
			this->panel_hand->ResumeLayout(false);
			this->panel_hand->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_laps))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CustomFormDlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		custom_form_isOpen = false;
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

}

private: System::Void tableLayoutPanel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void CustomFormDlg_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btn_hamdON_Click(System::Object^  sender, System::EventArgs^  e) {
	handON();
}
private: System::Void btn_handOFF_Click(System::Object^  sender, System::EventArgs^  e) {
	handOFF();
}
private: System::Void btn_grndON_Click(System::Object^  sender, System::EventArgs^  e) {
	grndON();
}
private: System::Void btn_grndOFF_Click(System::Object^  sender, System::EventArgs^  e) {
	grndOFF();
}
private: System::Void btn_home_Click(System::Object^  sender, System::EventArgs^  e) {
	home_position();
}
private: System::Void btn_paperChange_Click(System::Object^  sender, System::EventArgs^  e) {
	paper_change();
}
private: System::Void btn_chairLeg_Click(System::Object^  sender, System::EventArgs^  e) {
	chair_legAuto();
}
private: System::Void btn_chairSeat_Click(System::Object^  sender, System::EventArgs^  e) {
	chair_seatAuto();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer1();
}
private: System::Void btn_start_Click(System::Object^  sender, System::EventArgs^  e) {
	sys_auto();
}
private: System::Void btn_apply_Click(System::Object^  sender, System::EventArgs^  e) {
	update_settings();
}
};
}

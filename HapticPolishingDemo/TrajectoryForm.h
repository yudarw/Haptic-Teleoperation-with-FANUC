#pragma once
#include "main.h"

namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TrajectoryForm
	/// </summary>
	public ref class TrajectoryForm : public System::Windows::Forms::Form
	{
	public:
		TrajectoryForm(void)
		{
			InitializeComponent();
			trajectory_form_isOpen = true;
			//
			//TODO: Add the constructor code here
			//
		}

		void load_file();
		void read_csv(System::String ^ path);
		void add_recorded_point();
		void save_file();
		void move_to_point();
		void update_current_index();
		void get_current_point(float pos[12]);
		void main_program();
		void home_to_polish_pos();
		void delete_row();
		void insert_row();
		void init();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TrajectoryForm()
		{
			if (components)
			{
				delete components;
				trajectory_form_isOpen = false;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_x;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_y;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_z;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_w;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_p;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_r;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_c1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_c3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_c4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_c5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_c6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  column_c7;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->column_num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_z = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_w = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_p = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_r = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_c1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_c3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_c4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_c5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_c6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->column_c7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SunkenHorizontal;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(13) {
				this->column_num,
					this->column_x, this->column_y, this->column_z, this->column_w, this->column_p, this->column_r, this->column_c1, this->column_c3,
					this->column_c4, this->column_c5, this->column_c6, this->column_c7
			});
			this->dataGridView1->Location = System::Drawing::Point(171, 13);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dataGridView1->Size = System::Drawing::Size(698, 339);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TrajectoryForm::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TrajectoryForm::dataGridView1_CellContentClick);
			// 
			// column_num
			// 
			this->column_num->HeaderText = L"No";
			this->column_num->Name = L"column_num";
			this->column_num->Width = 50;
			// 
			// column_x
			// 
			this->column_x->HeaderText = L"X";
			this->column_x->Name = L"column_x";
			// 
			// column_y
			// 
			this->column_y->HeaderText = L"Y";
			this->column_y->Name = L"column_y";
			// 
			// column_z
			// 
			this->column_z->HeaderText = L"Z";
			this->column_z->Name = L"column_z";
			// 
			// column_w
			// 
			this->column_w->HeaderText = L"W";
			this->column_w->Name = L"column_w";
			// 
			// column_p
			// 
			this->column_p->HeaderText = L"P";
			this->column_p->Name = L"column_p";
			// 
			// column_r
			// 
			this->column_r->HeaderText = L"R";
			this->column_r->Name = L"column_r";
			// 
			// column_c1
			// 
			this->column_c1->HeaderText = L"C1";
			this->column_c1->Name = L"column_c1";
			// 
			// column_c3
			// 
			this->column_c3->HeaderText = L"C3";
			this->column_c3->Name = L"column_c3";
			// 
			// column_c4
			// 
			this->column_c4->HeaderText = L"C4";
			this->column_c4->Name = L"column_c4";
			// 
			// column_c5
			// 
			this->column_c5->HeaderText = L"C5";
			this->column_c5->Name = L"column_c5";
			// 
			// column_c6
			// 
			this->column_c6->HeaderText = L"C6";
			this->column_c6->Name = L"column_c6";
			// 
			// column_c7
			// 
			this->column_c7->HeaderText = L"C7";
			this->column_c7->Name = L"column_c7";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 235);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Load File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TrajectoryForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(23, 271);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 49);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Add Current Point";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TrajectoryForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(23, 199);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 28);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Save File";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &TrajectoryForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(69, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(42, 22);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Step:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(23, 91);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 28);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Move to";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &TrajectoryForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(23, 127);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 28);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Record";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(23, 163);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(104, 28);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Delete";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &TrajectoryForm::button6_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Location = System::Drawing::Point(12, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(152, 339);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Points";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &TrajectoryForm::timer1_Tick);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(35, 544);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(104, 49);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Chair Leg Polishing";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &TrajectoryForm::button7_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(86, 501);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(68, 22);
			this->textBox2->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 506);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Accel:";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(171, 544);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(104, 49);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Home to Polish Pos";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &TrajectoryForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(69, 377);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(104, 28);
			this->button9->TabIndex = 9;
			this->button9->Text = L"Insert";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &TrajectoryForm::button9_Click);
			// 
			// TrajectoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(884, 606);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"TrajectoryForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"TrajectoryForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TrajectoryForm::TrajectoryForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TrajectoryForm::TrajectoryForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TrajectoryForm_Load(System::Object^  sender, System::EventArgs^  e) {
		init();
	}
private: System::Void TrajectoryForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	trajectory_form_isOpen = false;
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		load_file();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		add_recorded_point();
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	save_file();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	move_to_point();
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	update_current_index();
}
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	update_current_index();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	update_current_index();
}

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	main_program();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	home_to_polish_pos();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	delete_row();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	insert_row();
}
};
}

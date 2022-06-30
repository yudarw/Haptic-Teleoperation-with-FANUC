#pragma once
#include <stdio.h>
#include <stdlib.h>


namespace HapticPolishingDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SimForm
	/// </summary>
	public ref class SimForm : public System::Windows::Forms::Form
	{
	public:
		SimForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void sim_connect();
		void shift_left();
		void shift_right();
		void transform();
		void on_timer_1();
		void haptic_read();
		void robot_control();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SimForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  tbHx;
	private: System::Windows::Forms::TextBox^  tbHy;
	private: System::Windows::Forms::TextBox^  tbHw;
	private: System::Windows::Forms::TextBox^  tbHz;
	private: System::Windows::Forms::TextBox^  tbHr;

	private: System::Windows::Forms::TextBox^  tbHp;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  tbZ;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbX;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbY;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbW;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tbP;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  tbR;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  btnControl;
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
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tbHx = (gcnew System::Windows::Forms::TextBox());
			this->tbHy = (gcnew System::Windows::Forms::TextBox());
			this->tbHw = (gcnew System::Windows::Forms::TextBox());
			this->tbHz = (gcnew System::Windows::Forms::TextBox());
			this->tbHr = (gcnew System::Windows::Forms::TextBox());
			this->tbHp = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tbZ = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbX = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbY = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbW = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tbP = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tbR = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->btnControl = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(292, 99);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(106, 23);
			this->btnConnect->TabIndex = 0;
			this->btnConnect->Text = L"Test Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &SimForm::btnConnect_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(292, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SimForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(292, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Record";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SimForm::button2_Click);
			// 
			// tbHx
			// 
			this->tbHx->Location = System::Drawing::Point(40, 23);
			this->tbHx->Name = L"tbHx";
			this->tbHx->Size = System::Drawing::Size(49, 20);
			this->tbHx->TabIndex = 3;
			this->tbHx->Text = L"43";
			this->tbHx->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbHy
			// 
			this->tbHy->Location = System::Drawing::Point(40, 49);
			this->tbHy->Name = L"tbHy";
			this->tbHy->Size = System::Drawing::Size(49, 20);
			this->tbHy->TabIndex = 4;
			this->tbHy->Text = L"7";
			this->tbHy->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbHw
			// 
			this->tbHw->Location = System::Drawing::Point(40, 101);
			this->tbHw->Name = L"tbHw";
			this->tbHw->Size = System::Drawing::Size(49, 20);
			this->tbHw->TabIndex = 6;
			this->tbHw->Text = L"0";
			this->tbHw->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbHz
			// 
			this->tbHz->Location = System::Drawing::Point(40, 75);
			this->tbHz->Name = L"tbHz";
			this->tbHz->Size = System::Drawing::Size(49, 20);
			this->tbHz->TabIndex = 5;
			this->tbHz->Text = L"112";
			this->tbHz->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbHr
			// 
			this->tbHr->Location = System::Drawing::Point(40, 153);
			this->tbHr->Name = L"tbHr";
			this->tbHr->Size = System::Drawing::Size(49, 20);
			this->tbHr->TabIndex = 8;
			this->tbHr->Text = L"0";
			this->tbHr->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbHp
			// 
			this->tbHp->Location = System::Drawing::Point(40, 127);
			this->tbHp->Name = L"tbHp";
			this->tbHp->Size = System::Drawing::Size(49, 20);
			this->tbHp->TabIndex = 7;
			this->tbHp->Text = L"0";
			this->tbHp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"x :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"y :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"z :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 153);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"r :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 127);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"p :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(14, 101);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"w :";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbHz);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbHx);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbHy);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbHw);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbHp);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->tbHr);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(125, 194);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Haptic Position";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tbZ);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->tbX);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->tbY);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->tbW);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->tbP);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->tbR);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Location = System::Drawing::Point(152, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(125, 194);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Robot Position";
			// 
			// tbZ
			// 
			this->tbZ->Location = System::Drawing::Point(40, 75);
			this->tbZ->Name = L"tbZ";
			this->tbZ->Size = System::Drawing::Size(49, 20);
			this->tbZ->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(14, 153);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"r :";
			// 
			// tbX
			// 
			this->tbX->Location = System::Drawing::Point(40, 23);
			this->tbX->Name = L"tbX";
			this->tbX->Size = System::Drawing::Size(49, 20);
			this->tbX->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(14, 127);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(19, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"p :";
			// 
			// tbY
			// 
			this->tbY->Location = System::Drawing::Point(40, 49);
			this->tbY->Name = L"tbY";
			this->tbY->Size = System::Drawing::Size(49, 20);
			this->tbY->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(14, 101);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"w :";
			// 
			// tbW
			// 
			this->tbW->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tbW->Location = System::Drawing::Point(40, 101);
			this->tbW->Name = L"tbW";
			this->tbW->Size = System::Drawing::Size(49, 20);
			this->tbW->TabIndex = 6;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(14, 78);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(18, 13);
			this->label10->TabIndex = 11;
			this->label10->Text = L"z :";
			// 
			// tbP
			// 
			this->tbP->Location = System::Drawing::Point(40, 127);
			this->tbP->Name = L"tbP";
			this->tbP->Size = System::Drawing::Size(49, 20);
			this->tbP->TabIndex = 7;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(14, 52);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(18, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"y :";
			// 
			// tbR
			// 
			this->tbR->Location = System::Drawing::Point(40, 153);
			this->tbR->Name = L"tbR";
			this->tbR->Size = System::Drawing::Size(49, 20);
			this->tbR->TabIndex = 8;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(14, 26);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(18, 13);
			this->label12->TabIndex = 9;
			this->label12->Text = L"x :";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(179, 212);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(78, 23);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Calculate";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &SimForm::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &SimForm::timer1_Tick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(39, 212);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(78, 23);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Read Haptic";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &SimForm::button4_Click);
			// 
			// btnControl
			// 
			this->btnControl->Location = System::Drawing::Point(292, 12);
			this->btnControl->Name = L"btnControl";
			this->btnControl->Size = System::Drawing::Size(106, 23);
			this->btnControl->TabIndex = 19;
			this->btnControl->Text = L"Robot Control";
			this->btnControl->UseVisualStyleBackColor = true;
			this->btnControl->Click += gcnew System::EventHandler(this, &SimForm::btnControl_Click);
			// 
			// SimForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 243);
			this->Controls->Add(this->btnControl);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnConnect);
			this->MaximizeBox = false;
			this->Name = L"SimForm";
			this->Text = L"`";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		sim_connect();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		shift_left();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		shift_right();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		transform();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		on_timer_1();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		haptic_read();
	}
	private: System::Void btnControl_Click(System::Object^  sender, System::EventArgs^  e) {
		robot_control();
	}
};
}

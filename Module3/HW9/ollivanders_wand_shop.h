//
// TODO: When selecting an item in ComboBox, I needa get the price of the item from the DB and display it after "Price: "
//

#pragma once
#include "DataBase.h"

namespace HW9 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ollivanders_wand_shop : public System::Windows::Forms::Form {
	public:
		ollivanders_wand_shop(void) {
			InitializeComponent();
		}

	protected:
		~ollivanders_wand_shop() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(39) {
				L"Acacia", L"English oak", L"Hawthorn", L"Elderberry",
					L"Beech", L"Grapes", L"Cherry tree", L"Elm", L"Grab", L"Walnut", L"Pear tree", L"Spruce", L"Willow", L"Chestnut", L"Cedar", L"Kizil",
					L"Cypress", L"Maple", L"Red oak", L"Laurel tree", L"Lipa", L"Larch", L"Olkha", L"Nut tree", L"Aspen", L"Sharp leaf", L"Fir",
					L"Rosewood", L"Rowan", L"Sequoia", L"Pine", L"Blackthorn", L"Tees", L"Poplar", L"Black nut", L"Ebony", L"Javor (white maple)",
					L"Apple tree", L"Ash"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 39);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(173, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(23) {
				L"Unicorn hair", L"Phoenix feather", L"Dragon heart vein",
					L"Dragon scale", L"Dragons claw", L"Hippogriffs feather", L"Veils hair", L"Sphinx hair", L"Pegas feather", L"Pegas wool", L"Dried mandrake root",
					L"Vasilisk tooth", L"Wolf wool", L"Snake scale", L"Bat wing veins", L"Gryphons claw", L"Salamander scale", L"Eagle feather",
					L"Ravens feather", L"Owl feather", L"Falcons feather", L"Cock feather", L"Kelpie hair"
			});
			this->comboBox2->Location = System::Drawing::Point(206, 39);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(181, 21);
			this->comboBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
								  static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(77, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Wood";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
								  static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(273, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Core";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
								  static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(466, 397);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Price:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
								  static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(522, 396);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 5;
			// 
			// ollivanders_wand_shop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 422);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Name = L"ollivanders_wand_shop";
			this->Text = L"ollivanders_wand_shop";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
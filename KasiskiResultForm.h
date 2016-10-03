#include "MainForm.h"

#pragma once

namespace Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для KasiskiResultForm
	/// </summary>
	public ref class KasiskiResultForm : public System::Windows::Forms::Form
	{
	public:
		KasiskiResultForm(MainForm^ form)
		{
			parentForm = form;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~KasiskiResultForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MainForm^ parentForm;
	public: System::Windows::Forms::DataGridView^  dataGridViewResult;

	public:



	public: System::Windows::Forms::TextBox^  textBoxLength;
	private:

	private: System::Windows::Forms::Label^  labelLength;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Gramm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Distances;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Gcd;

	public:




	public:



	private:


	protected:

	protected:


	private:



	private:



	private:



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridViewResult = (gcnew System::Windows::Forms::DataGridView());
			this->textBoxLength = (gcnew System::Windows::Forms::TextBox());
			this->labelLength = (gcnew System::Windows::Forms::Label());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Gramm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Distances = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Gcd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResult))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewResult
			// 
			this->dataGridViewResult->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dataGridViewResult->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridViewResult->ColumnHeadersHeight = 47;
			this->dataGridViewResult->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Amount,
					this->Gramm, this->Distances, this->Gcd
			});
			this->dataGridViewResult->Location = System::Drawing::Point(12, 12);
			this->dataGridViewResult->Name = L"dataGridViewResult";
			this->dataGridViewResult->Size = System::Drawing::Size(471, 222);
			this->dataGridViewResult->TabIndex = 8;
			// 
			// textBoxLength
			// 
			this->textBoxLength->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxLength->Location = System::Drawing::Point(249, 245);
			this->textBoxLength->Name = L"textBoxLength";
			this->textBoxLength->ReadOnly = true;
			this->textBoxLength->Size = System::Drawing::Size(100, 20);
			this->textBoxLength->TabIndex = 9;
			// 
			// labelLength
			// 
			this->labelLength->AutoSize = true;
			this->labelLength->Location = System::Drawing::Point(114, 248);
			this->labelLength->Name = L"labelLength";
			this->labelLength->Size = System::Drawing::Size(133, 13);
			this->labelLength->TabIndex = 10;
			this->labelLength->Text = L"Возможная длина ключа";
			// 
			// Amount
			// 
			this->Amount->Frozen = true;
			this->Amount->HeaderText = L"Количество l-грамм";
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			this->Amount->Width = 80;
			// 
			// Gramm
			// 
			this->Gramm->Frozen = true;
			this->Gramm->HeaderText = L"l-грамма";
			this->Gramm->Name = L"Gramm";
			this->Gramm->ReadOnly = true;
			// 
			// Distances
			// 
			this->Distances->Frozen = true;
			this->Distances->HeaderText = L"Расстояния между l-граммами";
			this->Distances->Name = L"Distances";
			this->Distances->ReadOnly = true;
			this->Distances->Width = 150;
			// 
			// Gcd
			// 
			this->Gcd->Frozen = true;
			this->Gcd->HeaderText = L"НОД расстояний";
			this->Gcd->Name = L"Gcd";
			this->Gcd->ReadOnly = true;
			// 
			// KasiskiResultForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 284);
			this->Controls->Add(this->labelLength);
			this->Controls->Add(this->textBoxLength);
			this->Controls->Add(this->dataGridViewResult);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"KasiskiResultForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Тест Касиски";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &KasiskiResultForm::KasiskiResultForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResult))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void KasiskiResultForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
};
}

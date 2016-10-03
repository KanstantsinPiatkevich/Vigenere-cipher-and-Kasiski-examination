#pragma once

namespace Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для StatsForm
	/// </summary>
	public ref class StatsForm : public System::Windows::Forms::Form
	{
	public:
		StatsForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~StatsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  dataGridViewStats;
	protected:

	protected:




	public: System::Windows::Forms::DataGridView^  dataGridViewConclusion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Length;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RealKey;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PossibleKey;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Stat;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Range;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Possibility;
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
			this->dataGridViewStats = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewConclusion = (gcnew System::Windows::Forms::DataGridView());
			this->Length = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RealKey = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PossibleKey = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Stat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Range = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Possibility = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStats))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConclusion))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewStats
			// 
			this->dataGridViewStats->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridViewStats->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStats->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Length,
					this->RealKey, this->PossibleKey, this->Stat
			});
			this->dataGridViewStats->Location = System::Drawing::Point(12, 12);
			this->dataGridViewStats->Name = L"dataGridViewStats";
			this->dataGridViewStats->Size = System::Drawing::Size(475, 150);
			this->dataGridViewStats->TabIndex = 0;
			// 
			// dataGridViewConclusion
			// 
			this->dataGridViewConclusion->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridViewConclusion->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewConclusion->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Range,
					this->Amount, this->Possibility
			});
			this->dataGridViewConclusion->Location = System::Drawing::Point(12, 186);
			this->dataGridViewConclusion->Name = L"dataGridViewConclusion";
			this->dataGridViewConclusion->Size = System::Drawing::Size(475, 128);
			this->dataGridViewConclusion->TabIndex = 1;
			// 
			// Length
			// 
			this->Length->Frozen = true;
			this->Length->HeaderText = L"Длина шифротекста";
			this->Length->Name = L"Length";
			this->Length->ReadOnly = true;
			// 
			// RealKey
			// 
			this->RealKey->Frozen = true;
			this->RealKey->HeaderText = L"Возможная длина ключа";
			this->RealKey->Name = L"RealKey";
			this->RealKey->ReadOnly = true;
			// 
			// PossibleKey
			// 
			this->PossibleKey->Frozen = true;
			this->PossibleKey->HeaderText = L"Реальная длина ключа";
			this->PossibleKey->Name = L"PossibleKey";
			this->PossibleKey->ReadOnly = true;
			// 
			// Stat
			// 
			this->Stat->Frozen = true;
			this->Stat->HeaderText = L"Статус";
			this->Stat->Name = L"Stat";
			this->Stat->ReadOnly = true;
			this->Stat->Width = 150;
			// 
			// Range
			// 
			this->Range->Frozen = true;
			this->Range->HeaderText = L"Длина шифротекста";
			this->Range->Name = L"Range";
			this->Range->ReadOnly = true;
			this->Range->Width = 120;
			// 
			// Amount
			// 
			this->Amount->Frozen = true;
			this->Amount->HeaderText = L"Количество шифротекстов";
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			this->Amount->Width = 120;
			// 
			// Possibility
			// 
			this->Possibility->Frozen = true;
			this->Possibility->HeaderText = L"Вероятность успешного теста Касиски";
			this->Possibility->Name = L"Possibility";
			this->Possibility->ReadOnly = true;
			this->Possibility->Width = 220;
			// 
			// StatsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(499, 326);
			this->Controls->Add(this->dataGridViewConclusion);
			this->Controls->Add(this->dataGridViewStats);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"StatsForm";
			this->Text = L"Статистика";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStats))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConclusion))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

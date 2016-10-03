#include "KeyInfo.h"
#include <vector>

#pragma once

namespace Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxKey;
	private: String^ messageTextFile;
			 String^ cipherTextFile;
			 String^ statisticsFile;
	protected:
	private: System::Windows::Forms::Label^  labelKey;
	public: System::Windows::Forms::Button^  buttonMessage;
	private:
	public: System::Windows::Forms::Button^  buttonCipher;
	private: System::Windows::Forms::TextBox^  textBoxMessage;

	private: System::Windows::Forms::TextBox^  textBoxCipher;
	private: System::Windows::Forms::Button^  buttonEncrypt;
	private: System::Windows::Forms::Button^  buttonDecrypt;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	public: System::Windows::Forms::Button^  buttonKasiski;
	private: System::Windows::Forms::Button^  buttonStatistics;
	private: System::Windows::Forms::Button^  buttonStats;
	public:
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
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->labelKey = (gcnew System::Windows::Forms::Label());
			this->buttonMessage = (gcnew System::Windows::Forms::Button());
			this->buttonCipher = (gcnew System::Windows::Forms::Button());
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCipher = (gcnew System::Windows::Forms::TextBox());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonKasiski = (gcnew System::Windows::Forms::Button());
			this->buttonStatistics = (gcnew System::Windows::Forms::Button());
			this->buttonStats = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textBoxKey->Location = System::Drawing::Point(212, 21);
			this->textBoxKey->MaxLength = 15;
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(100, 20);
			this->textBoxKey->TabIndex = 0;
			this->textBoxKey->WordWrap = false;
			this->textBoxKey->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxKey_TextChanged);
			this->textBoxKey->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxKey_KeyPress);
			// 
			// labelKey
			// 
			this->labelKey->AutoSize = true;
			this->labelKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelKey->Location = System::Drawing::Point(178, 23);
			this->labelKey->Name = L"labelKey";
			this->labelKey->Size = System::Drawing::Size(33, 13);
			this->labelKey->TabIndex = 1;
			this->labelKey->Text = L"Ключ";
			// 
			// buttonMessage
			// 
			this->buttonMessage->Location = System::Drawing::Point(12, 58);
			this->buttonMessage->Name = L"buttonMessage";
			this->buttonMessage->Size = System::Drawing::Size(161, 23);
			this->buttonMessage->TabIndex = 2;
			this->buttonMessage->Text = L"Выбрать файл сообщения";
			this->buttonMessage->UseVisualStyleBackColor = true;
			this->buttonMessage->Click += gcnew System::EventHandler(this, &MainForm::buttonMessage_Click);
			// 
			// buttonCipher
			// 
			this->buttonCipher->Location = System::Drawing::Point(337, 58);
			this->buttonCipher->Name = L"buttonCipher";
			this->buttonCipher->Size = System::Drawing::Size(161, 23);
			this->buttonCipher->TabIndex = 3;
			this->buttonCipher->Text = L"Выбрать файл шифротекста";
			this->buttonCipher->UseVisualStyleBackColor = true;
			this->buttonCipher->Click += gcnew System::EventHandler(this, &MainForm::buttonCipher_Click);
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxMessage->Location = System::Drawing::Point(12, 87);
			this->textBoxMessage->Multiline = true;
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->ReadOnly = true;
			this->textBoxMessage->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxMessage->Size = System::Drawing::Size(161, 162);
			this->textBoxMessage->TabIndex = 4;
			// 
			// textBoxCipher
			// 
			this->textBoxCipher->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxCipher->Location = System::Drawing::Point(337, 87);
			this->textBoxCipher->Multiline = true;
			this->textBoxCipher->Name = L"textBoxCipher";
			this->textBoxCipher->ReadOnly = true;
			this->textBoxCipher->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxCipher->Size = System::Drawing::Size(161, 162);
			this->textBoxCipher->TabIndex = 5;
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Enabled = false;
			this->buttonEncrypt->Location = System::Drawing::Point(179, 87);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(152, 23);
			this->buttonEncrypt->TabIndex = 6;
			this->buttonEncrypt->Text = L"Зашифровать";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &MainForm::buttonEncrypt_Click);
			// 
			// buttonDecrypt
			// 
			this->buttonDecrypt->Enabled = false;
			this->buttonDecrypt->Location = System::Drawing::Point(179, 226);
			this->buttonDecrypt->Name = L"buttonDecrypt";
			this->buttonDecrypt->Size = System::Drawing::Size(152, 23);
			this->buttonDecrypt->TabIndex = 7;
			this->buttonDecrypt->Text = L"Расшифровать";
			this->buttonDecrypt->UseVisualStyleBackColor = true;
			this->buttonDecrypt->Click += gcnew System::EventHandler(this, &MainForm::buttonDecrypt_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->Filter = L"Text file(*.txt)|*.txt";
			// 
			// buttonKasiski
			// 
			this->buttonKasiski->Enabled = false;
			this->buttonKasiski->Location = System::Drawing::Point(179, 133);
			this->buttonKasiski->Name = L"buttonKasiski";
			this->buttonKasiski->Size = System::Drawing::Size(152, 23);
			this->buttonKasiski->TabIndex = 8;
			this->buttonKasiski->Text = L"Начать тест Касиски";
			this->buttonKasiski->UseVisualStyleBackColor = true;
			this->buttonKasiski->Click += gcnew System::EventHandler(this, &MainForm::buttonKasiski_Click);
			// 
			// buttonStatistics
			// 
			this->buttonStatistics->Location = System::Drawing::Point(179, 58);
			this->buttonStatistics->Name = L"buttonStatistics";
			this->buttonStatistics->Size = System::Drawing::Size(152, 23);
			this->buttonStatistics->TabIndex = 9;
			this->buttonStatistics->Text = L"Выбрать файл статистики";
			this->buttonStatistics->UseVisualStyleBackColor = true;
			this->buttonStatistics->Click += gcnew System::EventHandler(this, &MainForm::buttonStatistics_Click);
			// 
			// buttonStats
			// 
			this->buttonStats->Enabled = false;
			this->buttonStats->Location = System::Drawing::Point(179, 179);
			this->buttonStats->Name = L"buttonStats";
			this->buttonStats->Size = System::Drawing::Size(152, 23);
			this->buttonStats->TabIndex = 10;
			this->buttonStats->Text = L"Статистика";
			this->buttonStats->UseVisualStyleBackColor = true;
			this->buttonStats->Click += gcnew System::EventHandler(this, &MainForm::buttonStats_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(513, 269);
			this->Controls->Add(this->buttonStats);
			this->Controls->Add(this->buttonStatistics);
			this->Controls->Add(this->buttonKasiski);
			this->Controls->Add(this->buttonDecrypt);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->textBoxCipher);
			this->Controls->Add(this->textBoxMessage);
			this->Controls->Add(this->buttonCipher);
			this->Controls->Add(this->buttonMessage);
			this->Controls->Add(this->labelKey);
			this->Controls->Add(this->textBoxKey);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная 1 - Шифр Виженера и тест Касиски";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	String^ getFileName();

	void enableButtons();

	private: System::Void buttonMessage_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonCipher_Click(System::Object^  sender, System::EventArgs^  e);

	bool checkEmptyFile(String^ fileName);

	void showMessageText();

	String^ encryptText(String^ key);

	void writeCipherToFile(String^ cipherText);

	bool MainForm::checkSelectedStatistics();

	private: System::Void buttonEncrypt_Click(System::Object^  sender, System::EventArgs^  e);

	void showCipherText();

	String^ decryptText(String^ key);

	void writeSourceToFile();

	private: System::Void buttonDecrypt_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxKey_TextChanged(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void textBoxKey_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	void writeStatistics(int, int);

	private: System::Void buttonKasiski_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void buttonStatistics_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void buttonStats_Click(System::Object^  sender, System::EventArgs^  e);
};
}

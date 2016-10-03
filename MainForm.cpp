#include "MainForm.h"
#include "KasiskiResultForm.h"
#include "StatsForm.h"
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;

namespace Lab1
{
	KeyInfo^ getKeyLength(String^ text, KasiskiResultForm^ form);

	String^ MainForm::getFileName()
	{
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (openFileDialog->FileName != "")
			{
				return openFileDialog->FileName;
			}
		}
	}

	String^ getCipherSymbols(String^ text)
	{
		String^ result = nullptr;
		for (int i = 0; i < text->Length; i++)
		{
			if ((text[i] >= 1040 && text[i] <= 1103) || text[i] == 1025 || text[i] == 1105)
			{
				result = result + gcnew String(text[i], 1);
			}
		}
		return result;
	}

	void MainForm::enableButtons()
	{
		if (messageTextFile != nullptr && cipherTextFile != nullptr && textBoxKey->Text != "")
		{
			buttonEncrypt->Enabled = true;
			buttonDecrypt->Enabled = true;
		}
		else
		{
			buttonEncrypt->Enabled = false;
			buttonDecrypt->Enabled = false;
		}
	}

	System::Void MainForm::buttonMessage_Click(System::Object^  sender, System::EventArgs^  e)
	{
		messageTextFile = getFileName();
		enableButtons();
		textBoxMessage->Text = "";
		textBoxCipher->Text = "";
	}

	System::Void MainForm::buttonCipher_Click(System::Object^  sender, System::EventArgs^  e)
	{
		cipherTextFile = getFileName();
		if (cipherTextFile != nullptr)
			buttonKasiski->Enabled = true;
		enableButtons();
		textBoxMessage->Text = "";
		textBoxCipher->Text = "";
	}

	bool MainForm::checkEmptyFile(String^ fileName)
	{ 
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(fileName);
		if (reader->EndOfStream)
		{
			reader->Close();
			return true;
		}
		else
		{
			reader->Close();
			return false;
		}
	}

	void MainForm::showMessageText()
	{
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(messageTextFile, System::Text::Encoding::GetEncoding(1251));
		while (!reader->EndOfStream)
		{
			textBoxMessage->Text = textBoxMessage->Text + gcnew String(reader->Read(), 1);
		}
		reader->Close();
	}

	int getIndex(int symbol)
	{
		if (symbol == 1025 || symbol == 1105)
			return 6;
		else if (symbol <= 1045)
			return symbol - 1040;
		else if (symbol <= 1071)
			return symbol - 1039;
		else if (symbol <= 1077)
			return symbol - 1072;
		else
			return symbol - 1071;
	}

	int getSymbol(int index)
	{
		if (index <= 5)
			return index + 1040;
		else if (index == 6)
			return 1025;
		else
			return index + 1039;
	}

	String^ MainForm::encryptText(String^ key)
	{
		String^ cipherText;
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(messageTextFile, System::Text::Encoding::GetEncoding(1251));
		int step = 0;
		while (!reader->EndOfStream)
		{
			int cipherSymbol = 0;
			if ((reader->Peek() >= 1040 && reader->Peek() <= 1103) || reader->Peek() == 1025 || reader->Peek() == 1105)
			{
				if (reader->Peek() > 1071 || reader->Peek() == 1105)
					cipherSymbol += 32;
				int symbolIndex = getIndex(reader->Read());
				int keyIndex = getIndex(key[step % key->Length]);
				if (getSymbol((symbolIndex + keyIndex + (step / key->Length)) % 33) != 1025)
					cipherSymbol += getSymbol((symbolIndex + keyIndex + (step / key->Length)) % 33);
				else
					if (cipherSymbol != 0)
						cipherSymbol = 1105;
					else
						cipherSymbol = 1025;
				step++;
			}
			else
			{
				cipherSymbol = reader->Read();
			}
			cipherText = cipherText + gcnew String(cipherSymbol, 1);
		}
		reader->Close();
		return cipherText;
	}

	void MainForm::writeCipherToFile(String^ cipherText)
	{
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(cipherTextFile, false, System::Text::Encoding::GetEncoding(1251));
		for (int i = 0; i < cipherText->Length; i++)
		{
			writer->Write(cipherText[i]);
		}
		writer->Close();
	}

	void MainForm::writeStatistics(int cipherTextLength, int keyLength)
	{
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(statisticsFile, true, System::Text::Encoding::GetEncoding(1251));
		writer->WriteLine(cipherTextLength.ToString() + " " + keyLength.ToString() + " " + textBoxKey->Text->Length.ToString() + " " + (textBoxKey->Text->Length == keyLength ? "1" : "0"));
		writer->Close();
	}

	bool MainForm::checkSelectedStatistics()
	{
		if (statisticsFile == nullptr)
		{
			if (MessageBox::Show("Ôàéë ñòàòèñòèêè íå âûáðàí, ñòàòèñòèêà çàïèñàíà íå áóäåò! Ïðîäîëæèòü?", "Ñòàòèñòèêà",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				return true;
			else
				return false;
		}
		else
		{
			return true;
		}
	}

	System::Void MainForm::buttonEncrypt_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkSelectedStatistics())
		{
			textBoxMessage->Text = "";
			textBoxCipher->Text = "";
			if (!checkEmptyFile(messageTextFile))
			{
				String^ key = textBoxKey->Text;
				showMessageText();
				String^ cipherText = encryptText(key);
				textBoxCipher->Text = cipherText;
				writeCipherToFile(cipherText);
				String^ text = getCipherSymbols(cipherText);
				KeyInfo^ keyInfo = gcnew KeyInfo();
				KasiskiResultForm^ form = gcnew KasiskiResultForm(this);
				if (text != nullptr)
					keyInfo = getKeyLength(text, form);
				if (statisticsFile != nullptr)
					writeStatistics(text->Length, keyInfo->getLength());
			}
			else
			{
				MessageBox::Show("Âàø ôàéë ñîîáùåíèÿ ïóñò! Øèôðîâàíèå íåâîçìîæíî.", "Îøèáêà ÷òåíèÿ", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	void MainForm::showCipherText()
	{
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(cipherTextFile, System::Text::Encoding::GetEncoding(1251));
		while (!reader->EndOfStream)
		{
			textBoxCipher->Text = textBoxCipher->Text + gcnew String(reader->Read(), 1);
		}
		reader->Close();
	}

	String^ MainForm::decryptText(String^ key)
	{
		String^ sourceText;
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(cipherTextFile, System::Text::Encoding::GetEncoding(1251));
		int step = 0;
		while (!reader->EndOfStream)
		{
			int sourceSymbol = 0;
			if ((reader->Peek() >= 1040 && reader->Peek() <= 1103) || reader->Peek() == 1025 || reader->Peek() == 1105)
			{
				if (reader->Peek() > 1071 || reader->Peek() == 1105)
					sourceSymbol += 32;
				int symbolIndex = getIndex(reader->Read());
				int keyIndex = getIndex(key[step % key->Length]);
				if (getSymbol(((symbolIndex - keyIndex + 33) % 33 - ((step / key->Length) % 33) + 33) % 33) != 1025)
					sourceSymbol += getSymbol(((symbolIndex - keyIndex + 33) % 33 - ((step / key->Length) % 33) + 33) % 33);
				else
					if (sourceSymbol != 0)
						sourceSymbol = 1105;
					else
						sourceSymbol = 1025;
				step++;
			}
			else
			{
				sourceSymbol = reader->Read();
			}
			sourceText = sourceText + gcnew String(sourceSymbol, 1);
		}
		reader->Close();
		return sourceText;
	}

	void MainForm::writeSourceToFile()
	{
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(messageTextFile, false, System::Text::Encoding::GetEncoding(1251));
		for (int i = 0; i < textBoxMessage->Text->Length; i++)
		{
			writer->Write(textBoxMessage->Text[i]);
		}
		writer->Close();
	}

	System::Void MainForm::buttonDecrypt_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxMessage->Text = "";
		textBoxCipher->Text = "";
		if (!checkEmptyFile(cipherTextFile))
		{
			String^ key = textBoxKey->Text;
			showCipherText();
			String^ sourceText = decryptText(key);
			textBoxMessage->Text = sourceText;
			writeSourceToFile();
		}
		else
		{
			MessageBox::Show("Âàø ôàéë øèôðîòåêñòà ïóñò! Äåøèôðîâàíèå íåâîçìîæíî!", "Îøèáêà ÷òåíèÿ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void MainForm::textBoxKey_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		enableButtons();
	}

	System::Void MainForm::textBoxKey_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar < 1040 || e->KeyChar > 1103) && e->KeyChar != 8 && e->KeyChar != 1105)
		{
			e->KeyChar = 0;
		}
	}

	int getMaxCommonDivider(int firstNumber, int secondNumber)
	{
		while (secondNumber != 0)
		{
			int temp = firstNumber % secondNumber;
			firstNumber = secondNumber;
			secondNumber = temp;
		}
		return firstNumber;
	}

	String^ getGramm(int grammLength, int i, String^ text)
	{
		int add = 0;
		String^ gramm = nullptr;
		do
		{
			gramm = gramm + text[i + add];
			add++;
		} while (add != grammLength);
		return gramm;
	}

	vector<int> getDistances(KeyInfo^ keyInfo, String^ text)
	{
		vector<int> distance(0);
		String^ gramm = keyInfo->getRepGramm();
		keyInfo->setGcd(0);
		int prevEntrance = -1;
		for (int i = 0; i <= text->Length - (keyInfo->getRepGramm())->Length; i++)
		{
			String^ nextGramm;
			int tempMaxRep = 0;
			nextGramm = getGramm((keyInfo->getRepGramm())->Length, i, text);
			bool isConstSubmit = true;
			int prevSubmit = 0;
			if (nextGramm == keyInfo->getRepGramm())
			{
				if (prevEntrance != -1)
				{
					if ((i - prevEntrance) % 33 == 0)
					{
						distance.push_back((i - prevEntrance) / 33);
						keyInfo->setGcd(getMaxCommonDivider((i - prevEntrance) / 33, keyInfo->getGcd()));
						prevEntrance = i;
					}
				}
				else
					prevEntrance = i;
			}
		}
		return distance;
	}

	const int MIN_GRAMM_LENGTH = 3;
	const int MAX_GRAMM_LENGTH = 10;

	KeyInfo^ getKeyLength(String^ text, KasiskiResultForm^ form)
	{
		KeyInfo^ keyInfo = gcnew KeyInfo();
		for (int grammLength = MAX_GRAMM_LENGTH; grammLength >= MIN_GRAMM_LENGTH; grammLength--)
		{
			for (int i = 0; i <= text->Length - grammLength; i++)
			{
				int grammRepeatings = 1;
				String^ compGramm;
				String^ gramm = getGramm(grammLength, i, text);
				int tempMaxRep = 0;
				for (int k = i + gramm->Length; k <= text->Length - grammLength; k++)
				{
					compGramm = getGramm(grammLength, k, text);
					bool isConstSubmit = true;
					if (compGramm == gramm && (k - i) % 33 == 0)
					{
						grammRepeatings++;
						keyInfo->setRepGramm(gramm);
					}
				}
				if (grammRepeatings > 1)
				{
					String^ distances = "";
					for (int j = 0; j < getDistances(keyInfo, text).size(); j++)
						distances += getDistances(keyInfo, text).at(j).ToString() + " ";
					form->dataGridViewResult->Rows->Add(grammRepeatings.ToString(), gramm, distances, keyInfo->getGcd());
					keyInfo->setLength(getMaxCommonDivider(keyInfo->getGcd(), keyInfo->getLength()));
				}
			}
		}
		return keyInfo;
	}

	System::Void MainForm::buttonKasiski_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxCipher->Text = "";
		if (!checkEmptyFile(cipherTextFile))
		{
			showCipherText();
			KasiskiResultForm^ form = gcnew KasiskiResultForm(this);
			String^ text = getCipherSymbols(textBoxCipher->Text);
			KeyInfo^ keyInfo = gcnew KeyInfo();
			if (text != nullptr)
				keyInfo = getKeyLength(text, form);
			keyInfo->getLength();
			if (keyInfo->getLength() == 0)
				MessageBox::Show("Ïîâòîðåíèé íå íàéäåíî", "Òåñò Êàñèñêè", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else
			{
				form->Show();
				buttonKasiski->Enabled = false;
				buttonMessage->Enabled = false;
				buttonCipher->Enabled = false;
				form->textBoxLength->Text = keyInfo->getLength().ToString();
			}
		}
		else
		{
			MessageBox::Show("Âàø ôàéë øèôðîòåêñòà ïóñò! Ïðîâåäåíèå òåñòà Êàñèñêè íåâîçìîæíî.", "Îøèáêà ÷òåíèÿ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void MainForm::buttonStatistics_Click(System::Object^  sender, System::EventArgs^  e)
	{
		statisticsFile = getFileName();
		if (statisticsFile != nullptr)
		{
			buttonStats->Enabled = true;
		}
		else
		{
			buttonStats->Enabled = false;
		}
	}

	struct LengthRange{ int amount = 0; int success = 0; };

	System::Void MainForm::buttonStats_Click(System::Object^  sender, System::EventArgs^  e)
	{
		StatsForm^ form = gcnew StatsForm();
		ifstream reader;
		char* file = (char*)(void*)Marshal::StringToHGlobalAnsi(statisticsFile);
		reader.open(file);
		Marshal::FreeHGlobal((IntPtr)(file));
		int cipherTextLength, realKeyLength, possibleKeyLength, stat;
		LengthRange lengthRange[4];
		while (!reader.eof())
		{
			reader >> cipherTextLength;
			reader >> realKeyLength;
			reader >> possibleKeyLength;
			reader >> stat;
			if (cipherTextLength <= 250 && !reader.eof())
			{
				lengthRange[0].amount++;
				if (stat == 1)
				{
					lengthRange[0].success++;
				}
			}
			if (cipherTextLength > 250 && cipherTextLength <= 500 && !reader.eof())
			{
				lengthRange[1].amount++;
				if (stat == 1)
				{
					lengthRange[1].success++;
				}
			}
			if (cipherTextLength > 500 && cipherTextLength <= 1000 && !reader.eof())
			{
				lengthRange[2].amount++;
				if (stat == 1)
				{
					lengthRange[2].success++;
				}
			}
			if (cipherTextLength > 1000 && !reader.eof())
			{
				lengthRange[3].amount++;
				if (stat == 1)
				{
					lengthRange[3].success++;
				}
			}
			form->dataGridViewStats->Rows->Add(cipherTextLength.ToString(), realKeyLength.ToString(), possibleKeyLength.ToString(), stat == 1 ? "ÒÅÑÒ ÏÐÎÉÄÅÍ" : "ÒÅÑÒ ÍÅ ÏÐÎÉÄÅÍ");
		}
		form->dataGridViewStats->Rows->RemoveAt(form->dataGridViewStats->RowCount - 2);
		for (int i = 0; i < 4; i++)
		{
			if (lengthRange[i].amount != 0)
			{
				switch (i)
				{
				case 0:
					form->dataGridViewConclusion->Rows->Add("0 - 250", lengthRange[i].amount.ToString(), (lengthRange[i].success * 100 / lengthRange[i].amount).ToString() + "%");
					break;
				case 1:
					form->dataGridViewConclusion->Rows->Add("250 - 500", lengthRange[i].amount.ToString(), (lengthRange[i].success * 100 / lengthRange[i].amount).ToString() + "%");
					break;
				case 2:
					form->dataGridViewConclusion->Rows->Add("500 - 1000", lengthRange[i].amount.ToString(), (lengthRange[i].success * 100 / lengthRange[i].amount).ToString() + "%");
					break;
				case 3:
					form->dataGridViewConclusion->Rows->Add("1000 è áîëåå", lengthRange[i].amount.ToString(), (lengthRange[i].success * 100 / lengthRange[i].amount).ToString() + "%");
					break;
				}
			}
		}
		reader.close();
		form->Show();
	}
}

[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab1::MainForm form;
	Application::Run(%form);
}

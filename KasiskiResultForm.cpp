#include "KasiskiResultForm.h"

namespace Lab1
{
	System::Void KasiskiResultForm::KasiskiResultForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		parentForm->buttonKasiski->Enabled = true;
		parentForm->buttonMessage->Enabled = true;
		parentForm->buttonCipher->Enabled = true;
	}
}



//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Morse Coder-Decoder.
 *
 *	Morse Coder-Decoder is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Morse Coder-Decoder is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Morse Coder-Decoder.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


namespace MorseCoderDecoder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::TextBox^  morseBox;
	private: System::Windows::Forms::Label^  textLabel;
	private: System::Windows::Forms::Label^  morseLabel;
	private: System::Windows::Forms::CheckBox^  checkBox;


	protected: 

	protected: 




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->morseBox = (gcnew System::Windows::Forms::TextBox());
			this->textLabel = (gcnew System::Windows::Forms::Label());
			this->morseLabel = (gcnew System::Windows::Forms::Label());
			this->checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(12, 19);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(290, 20);
			this->textBox->TabIndex = 0;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxHandler);
			this->textBox->Enter += gcnew System::EventHandler(this, &Form1::textBox_Enter);
			// 
			// morseBox
			// 
			this->morseBox->Location = System::Drawing::Point(12, 57);
			this->morseBox->Name = L"morseBox";
			this->morseBox->Size = System::Drawing::Size(290, 20);
			this->morseBox->TabIndex = 1;
			this->morseBox->TextChanged += gcnew System::EventHandler(this, &Form1::morseBoxHandler);
			this->morseBox->Enter += gcnew System::EventHandler(this, &Form1::morseBox_Enter);
			// 
			// textLabel
			// 
			this->textLabel->AutoSize = true;
			this->textLabel->Location = System::Drawing::Point(12, 3);
			this->textLabel->Name = L"textLabel";
			this->textLabel->Size = System::Drawing::Size(72, 13);
			this->textLabel->TabIndex = 2;
			this->textLabel->Text = L"text message:";
			this->textLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// morseLabel
			// 
			this->morseLabel->AutoSize = true;
			this->morseLabel->Location = System::Drawing::Point(12, 41);
			this->morseLabel->Name = L"morseLabel";
			this->morseLabel->Size = System::Drawing::Size(110, 13);
			this->morseLabel->TabIndex = 3;
			this->morseLabel->Text = L"morse code message:";
			this->morseLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// checkBox
			// 
			this->checkBox->AutoSize = true;
			this->checkBox->Checked = true;
			this->checkBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox->Location = System::Drawing::Point(247, 40);
			this->checkBox->Name = L"checkBox";
			this->checkBox->Size = System::Drawing::Size(55, 17);
			this->checkBox->TabIndex = 4;
			this->checkBox->Text = L"Greek";
			this->checkBox->UseVisualStyleBackColor = true;
			this->checkBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(312, 93);
			this->Controls->Add(this->checkBox);
			this->Controls->Add(this->morseLabel);
			this->Controls->Add(this->textLabel);
			this->Controls->Add(this->morseBox);
			this->Controls->Add(this->textBox);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->MaximumSize = System::Drawing::Size(6000000, 120);
			this->MinimumSize = System::Drawing::Size(240, 120);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Morse Coder-Decoder";
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBoxHandler(System::Object^  sender, System::EventArgs^  e) {
				 System::CharEnumerator ^p;
				 System::String ^s, ^prev = gcnew System::String(L"//");
				 unsigned int c;
				 
				 
				 if(morseBox->ReadOnly)
				 {
					 morseBox->Text = "";
					 c = textBox->Text->Length;
					 p = textBox->Text->GetEnumerator();
					 while(c--)
					 {
						 p->MoveNext();
						 s = gcnew System::String(toMorse(p->Current));
						 if( s!=L"//" && s!=L"///" && prev!=L"//" && prev!=L"///" )
							 morseBox->Text += L'/';
						 morseBox->Text += s;
						 prev = s;
					 }
				 }
			 }

	private: System::Void morseBoxHandler(System::Object^  sender, System::EventArgs^  e) {
				 System::CharEnumerator ^p;
				 char temp[6];
				 unsigned int c;

				 if(textBox->ReadOnly)
				 {
					 textBox->Text = L"";
					 p = morseBox->Text->GetEnumerator();
					 c = 0;
					 while(p->MoveNext())
					 {
						 if(p->Current == L'/' || c == 6)
						 {
							 temp[c] = '\0';
							 c = 0;
							 if(checkBox->Checked)
								 textBox->Text += toTextG(temp);
							 else
								 textBox->Text += toTextE(temp);
							 if(p->Current == L'/')
							 {
								 if(p->MoveNext())	//if there is another character
								 {
									 if(p->Current == L'/')		
									 {// there are at least 2 '/'
										 if(p->MoveNext())	//if there is another character
										 {
											 if(p->Current == L'/')	
											 {// there are 3 '/'
												 textBox->Text += L'.';
											 }
											 else					
											 {// there are 2 '/'
												 textBox->Text += L' ';
												 if(p->Current == L'-')
													 temp[c++] = '-';
												 else if(p->Current == L'.')
													 temp[c++] = '.';
											 }
										 }
										 else
										 {
											 textBox->Text += L' ';
											 break;
										 }
									 }
									 else if(p->Current == L'-')
										 temp[c++] = '-';
									 else if(p->Current == L'.')
										 temp[c++] = '.';
								 }
							 }
							 else if(p->Current == L'-')
								 temp[c++] = '-';
							 else if(p->Current == L'.')
								 temp[c++] = '.';
						 }
						 else if(p->Current == L'-')
							 temp[c++] = '-';
						 else if(p->Current == L'.')
							 temp[c++] = '.';
					 }
					 temp[c] = '\0';
					 if(checkBox->Checked)
						 textBox->Text += toTextG(temp);
					 else
						 textBox->Text += toTextE(temp);
				 }
			}
private: System::Void morseBox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 textBox->ReadOnly = true;
			 morseBox->ReadOnly = false;
		 }
private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 textBox->ReadOnly = false;
			 morseBox->ReadOnly = true;
		 }
private: System::Void textBox_Leave(System::Object^  sender, System::EventArgs^  e) {
			morseBox->ReadOnly = false;
		 }
private: System::Void morseBox_Leave(System::Object^  sender, System::EventArgs^  e) {
			 textBox->ReadOnly = false;
		 }

private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBox->Width = Form1::Width - 30;
			 morseBox->Width = Form1::Width - 30;
			 checkBox->Left = Form1::Width - 73;
		 }

private: System::Void checkBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::String ^s;
			 s = morseBox->Text;
			 morseBox->Text = "";
			 morseBox->Text = s;
		 }
private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if(e->KeyChar == '\033')
				 exit(0);
		 }
};
}


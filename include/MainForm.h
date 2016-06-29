#pragma once

#include "image.h"

namespace Tarea1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loadButtom;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: Bitmap^ originalImage;
	private: System::Windows::Forms::Button^  applyNegative;
	private: System::Windows::Forms::Button^  cw_1;
	private: System::Windows::Forms::Button^  cw_2;
	private: System::Windows::Forms::Button^  cw_3;
	private: System::Windows::Forms::Button^  ccw_1;
	private: System::Windows::Forms::Button^  ccw_2;
	private: System::Windows::Forms::Button^  ccw_3;
	private: System::Windows::Forms::Button^  flipVertical;
	private: System::Windows::Forms::Button^  flipHorizontal;













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
			this->loadButtom = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->applyNegative = (gcnew System::Windows::Forms::Button());
			this->cw_1 = (gcnew System::Windows::Forms::Button());
			this->cw_2 = (gcnew System::Windows::Forms::Button());
			this->cw_3 = (gcnew System::Windows::Forms::Button());
			this->ccw_1 = (gcnew System::Windows::Forms::Button());
			this->ccw_2 = (gcnew System::Windows::Forms::Button());
			this->ccw_3 = (gcnew System::Windows::Forms::Button());
			this->flipVertical = (gcnew System::Windows::Forms::Button());
			this->flipHorizontal = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// loadButtom
			// 
			this->loadButtom->Location = System::Drawing::Point(29, 25);
			this->loadButtom->Name = L"loadButtom";
			this->loadButtom->Size = System::Drawing::Size(123, 23);
			this->loadButtom->TabIndex = 0;
			this->loadButtom->Text = L"Cargar Imagen";
			this->loadButtom->UseVisualStyleBackColor = true;
			this->loadButtom->Click += gcnew System::EventHandler(this, &MainForm::loadButtom_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(183, 25);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(441, 224);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// applyNegative
			// 
			this->applyNegative->Location = System::Drawing::Point(29, 54);
			this->applyNegative->Name = L"applyNegative";
			this->applyNegative->Size = System::Drawing::Size(123, 23);
			this->applyNegative->TabIndex = 2;
			this->applyNegative->Text = L"Negativo";
			this->applyNegative->UseVisualStyleBackColor = true;
			this->applyNegative->Visible = false;
			this->applyNegative->Click += gcnew System::EventHandler(this, &MainForm::applyNegative_Click);
			// 
			// cw_1
			// 
			this->cw_1->Location = System::Drawing::Point(29, 83);
			this->cw_1->Name = L"cw_1";
			this->cw_1->Size = System::Drawing::Size(123, 23);
			this->cw_1->TabIndex = 3;
			this->cw_1->Text = L"90 CW";
			this->cw_1->UseVisualStyleBackColor = true;
			this->cw_1->Visible = false;
			this->cw_1->Click += gcnew System::EventHandler(this, &MainForm::cw_1_Click);
			// 
			// cw_2
			// 
			this->cw_2->Location = System::Drawing::Point(29, 112);
			this->cw_2->Name = L"cw_2";
			this->cw_2->Size = System::Drawing::Size(123, 23);
			this->cw_2->TabIndex = 4;
			this->cw_2->Text = L"180 CW";
			this->cw_2->UseVisualStyleBackColor = true;
			this->cw_2->Visible = false;
			this->cw_2->Click += gcnew System::EventHandler(this, &MainForm::cw_2_Click);
			// 
			// cw_3
			// 
			this->cw_3->Location = System::Drawing::Point(29, 141);
			this->cw_3->Name = L"cw_3";
			this->cw_3->Size = System::Drawing::Size(123, 23);
			this->cw_3->TabIndex = 5;
			this->cw_3->Text = L"270 CW";
			this->cw_3->UseVisualStyleBackColor = true;
			this->cw_3->Visible = false;
			this->cw_3->Click += gcnew System::EventHandler(this, &MainForm::cw_3_Click);
			// 
			// ccw_1
			// 
			this->ccw_1->Location = System::Drawing::Point(29, 170);
			this->ccw_1->Name = L"ccw_1";
			this->ccw_1->Size = System::Drawing::Size(123, 23);
			this->ccw_1->TabIndex = 6;
			this->ccw_1->Text = L"90 CCW";
			this->ccw_1->UseVisualStyleBackColor = true;
			this->ccw_1->Visible = false;
			this->ccw_1->Click += gcnew System::EventHandler(this, &MainForm::ccw_1_Click);
			// 
			// ccw_2
			// 
			this->ccw_2->Location = System::Drawing::Point(29, 199);
			this->ccw_2->Name = L"ccw_2";
			this->ccw_2->Size = System::Drawing::Size(123, 23);
			this->ccw_2->TabIndex = 7;
			this->ccw_2->Text = L"CCW 180";
			this->ccw_2->UseVisualStyleBackColor = true;
			this->ccw_2->Visible = false;
			this->ccw_2->Click += gcnew System::EventHandler(this, &MainForm::ccw_2_Click);
			// 
			// ccw_3
			// 
			this->ccw_3->Location = System::Drawing::Point(29, 226);
			this->ccw_3->Name = L"ccw_3";
			this->ccw_3->Size = System::Drawing::Size(123, 23);
			this->ccw_3->TabIndex = 8;
			this->ccw_3->Text = L"CCW 270";
			this->ccw_3->UseVisualStyleBackColor = true;
			this->ccw_3->Visible = false;
			this->ccw_3->Click += gcnew System::EventHandler(this, &MainForm::ccw_3_Click);
			// 
			// flipVertical
			// 
			this->flipVertical->Location = System::Drawing::Point(29, 255);
			this->flipVertical->Name = L"flipVertical";
			this->flipVertical->Size = System::Drawing::Size(123, 23);
			this->flipVertical->TabIndex = 9;
			this->flipVertical->Text = L"FlipVertical";
			this->flipVertical->UseVisualStyleBackColor = true;
			this->flipVertical->Visible = false;
			this->flipVertical->Click += gcnew System::EventHandler(this, &MainForm::flipVertical_Click);
			// 
			// flipHorizontal
			// 
			this->flipHorizontal->Location = System::Drawing::Point(29, 284);
			this->flipHorizontal->Name = L"flipHorizontal";
			this->flipHorizontal->Size = System::Drawing::Size(123, 23);
			this->flipHorizontal->TabIndex = 10;
			this->flipHorizontal->Text = L"FlipHorizontal";
			this->flipHorizontal->UseVisualStyleBackColor = true;
			this->flipHorizontal->Visible = false;
			this->flipHorizontal->Click += gcnew System::EventHandler(this, &MainForm::flipHorizontal_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(636, 317);
			this->Controls->Add(this->flipHorizontal);
			this->Controls->Add(this->flipVertical);
			this->Controls->Add(this->ccw_3);
			this->Controls->Add(this->ccw_2);
			this->Controls->Add(this->ccw_1);
			this->Controls->Add(this->cw_3);
			this->Controls->Add(this->cw_2);
			this->Controls->Add(this->cw_1);
			this->Controls->Add(this->applyNegative);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->loadButtom);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		
		using namespace Runtime::InteropServices;

		OpenFileDialog ^ openFile = gcnew OpenFileDialog;
		openFile->Filter = "Images files|*.bmp";
		openFile->Title = "Seleccione una imagen por favor";

		if (openFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(openFile->FileName)).ToPointer();
			std::string fileName = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));

			originalImage = loadImage(fileName);

			pictureBox->Image = originalImage;

			applyNegative->Visible = true;
			cw_1->Visible = true;
			cw_2->Visible = true;
			cw_3->Visible = true;
			ccw_1->Visible = true;
			ccw_2->Visible = true;
			ccw_3->Visible = true;
			flipVertical->Visible = true;
			flipHorizontal->Visible = true;

		}

	}
	private: System::Void applyNegative_Click(System::Object^  sender, System::EventArgs^  e) {

		Bitmap^ negative = negativeImage(originalImage);

		pictureBox->Image = negative;

	}
private: System::Void cw_1_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = clockWise(originalImage);

	pictureBox->Image = nImage;
}
private: System::Void cw_2_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = clockWise(originalImage);
	nImage = clockWise(nImage);

	pictureBox->Image = nImage;
}
private: System::Void cw_3_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = clockWise(originalImage);
	nImage = clockWise(nImage);
	nImage = clockWise(nImage);

	pictureBox->Image = nImage;

}
private: System::Void ccw_1_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = counterClockWise(originalImage);

	pictureBox->Image = nImage;
}
private: System::Void ccw_2_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = counterClockWise(originalImage);
	nImage = counterClockWise(nImage);

	pictureBox->Image = nImage;
}
private: System::Void ccw_3_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = counterClockWise(originalImage);
	nImage = counterClockWise(nImage);
	nImage = counterClockWise(nImage);

	pictureBox->Image = nImage;
}
private: System::Void flipVertical_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = flipV(originalImage);

	pictureBox->Image = nImage;
}
private: System::Void flipHorizontal_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ nImage = flipH(originalImage);

	pictureBox->Image = nImage;
}
};
}

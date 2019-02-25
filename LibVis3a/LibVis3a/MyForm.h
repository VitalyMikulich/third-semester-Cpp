#pragma once
#include <math.h>

namespace LibVis3a {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(16, 15);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(645, 452);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 481);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"������� 9";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	private:
		int l, b, h, w;
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		h = pictureBox1->Height;
		w = pictureBox1->Width;
								
		e->Graphics->DrawLine(Pens::Black, 0, h / 2, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w / 2, 0, w / 2, h);
		
		e->Graphics->DrawLine(Pens::Black, w - 25, h / 2 + 8, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w - 25, h / 2 - 8, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w / 2 - 8, 25, w / 2, 0);
		e->Graphics->DrawLine(Pens::Black, w / 2 + 8, 25, w / 2, 0);
		
		e->Graphics->DrawString("X", this->Font, Brushes::Black, w - 15, h / 2 - 25);
		e->Graphics->DrawString("Y", this->Font, Brushes::Black, w / 2 - 25, 5);
		double x1, x2, y1, y2, x, y, mx, my, x0, y0, dx, dt;
		const double exp = 2.71828;
		x1 = -2;
		x2 = 2;
		dx = 0.001;
		y1 = -0.5*pow(exp, -5);
		y2 = -0.5*pow(exp, 5);
		x = x1;
		while (x <= x2)
		{
			y = -0.5*pow(exp, x);
			if (y < y1) y1 = y;
			if (y > y2) y2 = y;
			x += dx;
		}
		my = 0.5*h / (y2 - y1);
		mx = w / (x2 - x1);
		x = x1;
		y1 = -0.5*pow(exp, x);
		x += dx;
		// ������

		while (x <= x2)
		{
			y = -0.5*pow(exp, x);
			e->Graphics->DrawLine(Pens::Black, (int)(x1*mx + w / 2), (int)(h / 2 - y1 * my), (int)(x*mx + w / 2), (int)(h / 2 - y * my));
			x1 = x;
			y1 = y;
			x += dx;
		}
		x1 = -2; 
		x2 = 2; 
		dt = 0.001;
		y1 = -2;
		y2 = 2;
		my = h / (y2 - y1);
		mx = w / (x2 - x1); 
		double t = 0;

		// ������
		double pi = 3.1415926;
		x1 = (sqrt(2)*(Math::Tan(pi / 4 - t) + pow(Math::Tan(pi / 4 - t), 3))) / (1 + pow(Math::Tan(pi / 4 - t), 4));
		y1 = (sqrt(2)*(Math::Tan(pi / 4 - t) - pow(Math::Tan(pi / 4 - t), 3))) / (1 + pow(Math::Tan(pi / 4 - t), 4));
		t += dt;
		while (t <= 2 * 3.14)
		{
			x = (sqrt(2)*(Math::Tan(pi / 4 - t) + pow(Math::Tan(pi / 4 - t), 3))) / (1 + pow(Math::Tan(pi / 4 - t), 4));
			y = (sqrt(2)*(Math::Tan(pi / 4 - t) - pow(Math::Tan(pi / 4 - t), 3))) / (1 + pow(Math::Tan(pi / 4 - t), 4));
			e->Graphics->DrawLine(Pens::Red, (int)(x1*mx + w / 2), (int)(h / 2 - y1 * my), (int)(x*mx + w / 2), (int)(h / 2 - y * my));
			t += dt;
			x1 = x;
			y1 = y;
		}
	}
	};
}
#include "MyForm.h"
//
using namespace System;
using namespace System::Windows::Forms;

// Сместить минимальный элемент на выбранную позицию
[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LabVis2::MyForm form;
	Application::Run(%form);
}

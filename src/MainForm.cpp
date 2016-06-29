#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Tarea1::MainForm mainWindow;
	Application::Run(%mainWindow);
}


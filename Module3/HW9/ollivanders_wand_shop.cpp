#include "ollivanders_wand_shop.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();

    HW9::ollivanders_wand_shop form;
    Application::Run(% form);

	return 0;
}
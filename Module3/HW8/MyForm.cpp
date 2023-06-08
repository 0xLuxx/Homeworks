#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;

[STAThreadAttribute]
int main() {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();

    HW8::MyForm form;
    Application::Run(% form);

    return 0;
}
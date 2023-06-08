#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

DataTable^ ShowDB(String^ req) {
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    connStringBuilder->DataSource = "DESKTOP-HBA4NC5";
    connStringBuilder->InitialCatalog = "HW9DB";
    connStringBuilder->IntegratedSecurity = true;

    conn->ConnectionString = connStringBuilder->ToString();

    SqlCommand^ cmd = gcnew SqlCommand(req, conn);

    conn->Open();

    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    conn->Close();

    return dt;
}
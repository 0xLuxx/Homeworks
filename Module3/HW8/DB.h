#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;

DataTable^ ShowStudents() {
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    connStringBuilder->DataSource = "DESKTOP-HBA4NC5";
    connStringBuilder->InitialCatalog = "HW8DB";
    connStringBuilder->IntegratedSecurity = true;

    conn->ConnectionString = connStringBuilder->ToString();

    String^ sql = "SELECT Student_name FROM Students";
    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);

    conn->Open();

    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    conn->Close();

    return dt;
}

DataTable^ PersonalInfo(String^ sql) {
    SqlConnection^ conn = gcnew SqlConnection();
    SqlConnectionStringBuilder^ connStringBuilder = gcnew SqlConnectionStringBuilder();

    connStringBuilder->DataSource = "DESKTOP-HBA4NC5";
    connStringBuilder->InitialCatalog = "HW8DB";
    connStringBuilder->IntegratedSecurity = true;

    conn->ConnectionString = connStringBuilder->ToString();

    SqlCommand^ cmd = gcnew SqlCommand(sql, conn);

    conn->Open();

    SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
    DataTable^ dt = gcnew DataTable();
    da->Fill(dt);

    conn->Close();

    return dt;
}
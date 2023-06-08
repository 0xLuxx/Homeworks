#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iomanip>

int main() {
    SQLHENV env;
    SQLHDBC dbc;
    SQLHSTMT stmt;
    SQLRETURN ret;

    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    ret = SQLDriverConnect(dbc, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};" "Server=DESKTOP-HBA4NC5;" "Database=HW7DB;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
        ret = SQLExecDirect(stmt, (SQLWCHAR*)L"SELECT*FROM Games", SQL_NTS);

        if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
            //  DataType column_name[size]
            SQLWCHAR Game[50];
            SQLWCHAR Developers[150];
            SQLWCHAR Release[15];
            SQLWCHAR Platforms[150];

            while (SQLFetch(stmt) == SQL_SUCCESS) {
                //  SQLGetData(stmt, [column_number], SQL_C_WCHAR, [column_name], sizeof([column_name]), NULL);
                SQLGetData(stmt, 1, SQL_C_WCHAR, Game, sizeof(Game), NULL);
                SQLGetData(stmt, 2, SQL_C_WCHAR, Developers, sizeof(Developers), NULL);
                SQLGetData(stmt, 3, SQL_C_WCHAR, Release, sizeof(Release), NULL);
                SQLGetData(stmt, 4, SQL_C_WCHAR, Platforms, sizeof(Platforms), NULL);

                // output
            }
        }
        else {
            std::cout << "SQL query execution error!" << std::endl;
        }

        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(dbc);
        SQLFreeHandle(SQL_HANDLE_DBC, dbc);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
    }
    else {
        std::cout << "DB connection error!" << std::endl;
    }

    return 0;
}
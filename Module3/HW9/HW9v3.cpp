#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int getRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

struct Stick {
	SQLWCHAR corename[50];
	SQLWCHAR woodname[50];
	double cost;
};

bool compareSticks(const Stick& stick1, const Stick& stick2) {
	return stick1.cost < stick2.cost;
}

int main() {
	srand(time(nullptr));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string connectionStr = "DRIVER={SQL Server};SERVER=DESKTOP-HBA4NC5;DATABASE=HW9DB;Trusted_Connection=yes;";

	int size = MultiByteToWideChar(CP_UTF8, 0, connectionStr.c_str(), -1, NULL, 0);
	std::vector<SQLWCHAR> wconnStr(size);
	MultiByteToWideChar(CP_UTF8, 0, connectionStr.c_str(), -1, wconnStr.data(), size);
	SQLWCHAR* sqlConnectionStr = wconnStr.data();

	SQLHENV hEnv = NULL;
	SQLHDBC hDbc = NULL;
	SQLHSTMT hStmt = NULL;

	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
	SQLRETURN ret = SQLDriverConnectW(hDbc, NULL, sqlConnectionStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
	if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
		std::cout << "Connection Failed" << std::endl;
		exit(1);
	}

	std::vector<Stick> sticks;

	for (int i = 0; i < 10; ++i) {
		std::string query = "SELECT core.core_name, wood.wood_name, (core.core_cost + wood.wood_cost) * 1.4 AS cost FROM core, wood WHERE core.core_id = " +
			std::to_string(getRandomNumber(1, 23)) + " AND wood.wood_id = " + std::to_string(getRandomNumber(1, 40));

		int querySize = MultiByteToWideChar(CP_UTF8, 0, query.c_str(), -1, NULL, 0);
		std::vector<SQLWCHAR> wQuery(querySize);
		MultiByteToWideChar(CP_UTF8, 0, query.c_str(), -1, wQuery.data(), querySize);
		SQLWCHAR* sqlQuery = wQuery.data();

		SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
		SQLExecDirectW(hStmt, sqlQuery, SQL_NTS);

		while (SQLFetch(hStmt) == SQL_SUCCESS) {
			Stick stick;
			SQLGetData(hStmt, 1, SQL_WCHAR, stick.corename, 50, NULL);
			SQLGetData(hStmt, 2, SQL_WCHAR, stick.woodname, 50, NULL);
			SQLGetData(hStmt, 3, SQL_DOUBLE, &stick.cost, sizeof(stick.cost), NULL);

			sticks.push_back(stick);
		}

		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}

	SQLDisconnect(hDbc);
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	std::sort(sticks.begin(), sticks.end(), compareSticks);

	for (const auto& stick : sticks) {
		SetConsoleTextAttribute(hConsole, 2);
		std::cout << "Wood: ";
		SetConsoleTextAttribute(hConsole, 15);
		std::wcout << stick.woodname << std::endl;
		SetConsoleTextAttribute(hConsole, 2);
		std::cout << "Core: ";
		SetConsoleTextAttribute(hConsole, 15);
		std::wcout << stick.corename << std::endl;
		SetConsoleTextAttribute(hConsole, 2);
		std::cout << "Price: ";
		SetConsoleTextAttribute(hConsole, 15);
		std::wcout << stick.cost << std::endl << std::endl;
	}

	return 0;
}
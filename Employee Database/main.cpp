#include <iostream>

#include "sqlite3.h"
#include "./include/DBManager.h"
#include "./include/views/ViewMainMenu.h"


int main() {
	
	EmployeeDB::Console::viewMainMenu();

	return 0;
}
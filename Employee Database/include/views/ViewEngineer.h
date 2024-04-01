#ifndef _viewEngineer_h_
#define _viewEngineer_h_
#include "Engineer.h"

namespace EmployeeDB::Console {

	void engineerMenu() noexcept;
	void operationOfEng(const char& input) noexcept;
	bool insertEngineer();
	bool updateEngineer();
	bool deleteEngineer();
	bool viewEngineer();
}


#endif
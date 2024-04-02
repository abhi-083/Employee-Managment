#ifndef __DepartmentControllerTest_h__
#define __DepartmentControllerTest_h__

#include "pch.h"
#include "DepartmentController.h"
#include "Department.h"

class DepartmentControllerTest : public EmployeeDB::Controller::DepartmentController {
public:
	static std::string getUpdateQueryCondition(Department& dept) {
		return DepartmentController::getUpdateQueryCondition(dept);
	}
};

#endif
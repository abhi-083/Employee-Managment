#ifndef __FinanceControllerTest_h__
#define __FinanceControllerTest_h__

#include "FinanceController.h"

using EmployeeDB::Controller::FinanceController;

class FinanceControllerTest : public FinanceController {
public:
	static std::string getUpdateQueryCondition(Finance& finance) {
		return FinanceController::getUpdateQueryCondition(finance);
	}
};

#endif
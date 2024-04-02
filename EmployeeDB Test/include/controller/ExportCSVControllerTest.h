#ifndef __ExportControllerTest_h__
#define __ExportControllerTest_h__

#include "ExportCSVController.h"

using EmployeeDB::Controller::ExportCSVController;

class ExportControllerTest : public ExportCSVController {
public:
	static void removecommas(std::string& str) {
		ExportCSVController::removeCommas(str);
	}
};

#endif 
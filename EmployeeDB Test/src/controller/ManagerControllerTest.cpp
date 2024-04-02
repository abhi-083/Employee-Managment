#include "ManagerControllerTest.h"
#include "ManagerFixture.h"

using EmployeeDB::Controller::ManagerController;

TEST_F(ManagerFixture, Test_insertManager) {

	std::string_view queryStr = R"(SELECT * FROM Employee WHERE employeeID = 2)";
	EXPECT_EQ(EmployeeDB::DBManager::instance().executeRowCountQuery(queryStr.data()), 1);

	EXPECT_TRUE(ManagerController::insertManager(*manager));

	EXPECT_FALSE(ManagerController::insertManager(*manager));//FAIL
}

TEST_F(ManagerFixture, Test_selectManager) {

	EXPECT_TRUE(ManagerController::selectManager("employeeID" , "1"));
	EXPECT_FALSE(ManagerController::selectManager("manaID" , "1")); //FAIL
}
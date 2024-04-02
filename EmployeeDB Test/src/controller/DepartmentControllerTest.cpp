#include "DepartmentControllerTest.h"
#include "DepartmentFixture.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;

TEST_F(DepartmentFixture, Test_insertDepartment) {
	EXPECT_TRUE(DepartmentController::insertDepartment(*department));

	//EXPECT_FALSE(DepartmentController::insertDepartment(*department)); //FAIL
}
TEST_F(DepartmentFixture, Test_getDepartmentIDbyName) {
	EXPECT_EQ(DepartmentController::getDepartmentIDbyName("Engineer") , 1);
	EXPECT_EQ(DepartmentController::getDepartmentIDbyName("HR") , 3); 

	EXPECT_NE(DepartmentController::getDepartmentIDbyName("HR") , 2); //FAIL
	EXPECT_EQ(-1, DepartmentController::getDepartmentIDbyName("Robo")); //FAIL
}
TEST_F(DepartmentFixture, Test_checkDepartmentExistence) {
	EXPECT_TRUE(DepartmentController::checkDepartmentExistence("1"));
	EXPECT_TRUE(DepartmentController::checkDepartmentExistence("2"));

	EXPECT_FALSE(DepartmentController::checkDepartmentExistence("19")); //FAIL
}
TEST_F(DepartmentFixture, Test_selectDepartment) {
	EXPECT_TRUE(DepartmentController::selectDepartment("departmentName" , "Engineer"));

	EXPECT_FALSE(DepartmentController::selectDepartment("deptName", "Engineer")); //FAIL
}
TEST_F(DepartmentFixture, Test_deleteDepartmentByID) {
	EXPECT_TRUE(DepartmentController::deleteDepartmentByID(1));

	std::string_view queryStr = R"(SELECT * FROM Department WHERE departmentID = 1)";
	EXPECT_EQ(0, EmployeeDB::DBManager::instance().executeRowCountQuery(queryStr.data())); //FAIL
}
TEST_F(DepartmentFixture, Test_updateDepartment) {
	EXPECT_TRUE(DepartmentController::updateDepartment(*department));

	std::string_view queryStr = R"(SELECT * FROM Department WHERE departmentName = "Engineer")";
	EXPECT_EQ(0, EmployeeDB::DBManager::instance().executeRowCountQuery(queryStr.data())); //FAIL

	department->setDepartmentID(2);
	EXPECT_FALSE(DepartmentController::updateDepartment(*department)); // FAIL
}
TEST_F(DepartmentFixture, Test_getUpdateQueryCondition) {
	EXPECT_STREQ(DepartmentControllerTest::getUpdateQueryCondition(*department).c_str(), R"(departmentName = "Engineering", baseSalary = 50000.000000, allowance = 24000.000000, deduction = 500.000000)");
	EXPECT_STRNE(DepartmentControllerTest::getUpdateQueryCondition(*department).c_str() , R"(departmentName = "Engine", baseSalary = 50000.000000, allowance = 24000.000000, deduction = 500.000000)"); // FAIL
}
#include "EmployeeControllerTest.h"
#include "EmployeeFixture.h"

TEST_F(EmployeeFixture, Test_getEmployeeIDbyEmail) {
	EXPECT_EQ(EmployeeDB::Controller::EmployeeController::getEmployeeIDbyEmail("john.smith@example.com"), 1);
}

TEST_F(EmployeeFixture, Test_insertEmployee) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::insertEmployee(*employee));
}

TEST_F(EmployeeFixture, Test_getDepartmentIDbyEmployeeID) {
	EXPECT_EQ(EmployeeDB::Controller::EmployeeController::getDepartmentIDbyEmployeeID(1), 1);
}

TEST_F(EmployeeFixture, Test_checkEmployeeExistence) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::checkEmployeeExistence("1", "Engineer"));
}

TEST_F(EmployeeFixture, Test_getUpdateQueryCondition) {
	EXPECT_EQ(EmployeeControllerTest::getUpdateQueryCondition(*employee), "firstName = \"Abhi\", middleName = \"Narendrakumar\", lastName = \"Patel\", dateOfBirth = \"11-09-2002\", mobileNo = 7283902430, email = \"abhi.patel@zuru.com\", address = \"88, V.K.\", gender = \"Male\", dateOfJoining = \"01-01-2024\", mentorID = 1, performanceMetric = 5.000000, bonus = 100000.000000");
}

TEST_F(EmployeeFixture, Test_updateEmployee) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::updateEmployee(*employee));
}

TEST_F(EmployeeFixture, Test_getSalaryDetails) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::getSalaryDetails(*salary));
}

TEST_F(EmployeeFixture, Test_deleteEmployeeByID) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::deleteEmployeeByID(1));
}
#include "EmployeeControllerTest.h"
#include "EmployeeFixture.h"

TEST_F(EmployeeFixture, Test_getEmployeeIDbyEmail) {
	EXPECT_EQ(EmployeeDB::Controller::EmployeeController::getEmployeeIDbyEmail("john.smith@example.com"), 1);

	EXPECT_EQ(EmployeeDB::Controller::EmployeeController::getEmployeeIDbyEmail("johnnn.smith@example.com"), -1); // FAIL
	EXPECT_NE(EmployeeDB::Controller::EmployeeController::getEmployeeIDbyEmail("johnnn.smith@example.com"), 3); // FAIL
}

TEST_F(EmployeeFixture, Test_insertEmployee) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::insertEmployee(*employee));

	EXPECT_FALSE(EmployeeDB::Controller::EmployeeController::insertEmployee(*employee)); // FAIL
}

TEST_F(EmployeeFixture, Test_getDepartmentIDbyEmployeeID) {
	EXPECT_EQ(EmployeeDB::Controller::EmployeeController::getDepartmentIDbyEmployeeID(1), 1);

	EXPECT_NE(EmployeeDB::Controller::EmployeeController::getDepartmentIDbyEmployeeID(1000), 1); // FAIL
	EXPECT_NE(EmployeeDB::Controller::EmployeeController::getDepartmentIDbyEmployeeID(1), 5); // FAIL
}

TEST_F(EmployeeFixture, Test_checkEmployeeExistence) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::checkEmployeeExistence("1", "Engineer"));

	EXPECT_FALSE(EmployeeDB::Controller::EmployeeController::checkEmployeeExistence("5", "Engineer")); // FAIL
	EXPECT_FALSE(EmployeeDB::Controller::EmployeeController::checkEmployeeExistence("1", "HR")); // FAIL
}

TEST_F(EmployeeFixture, Test_getUpdateQueryCondition) {
	EXPECT_EQ(EmployeeControllerTest::getUpdateQueryCondition(*employee), R"(firstName = "Abhi", middleName = "Narendrakumar", lastName = "Patel", dateOfBirth = "11-09-2002", mobileNo = 7283902430, email = "abhi.patel@zuru.com", address = "88, V.K.", gender = "Male", dateOfJoining = "01-01-2024", mentorID = 1, performanceMetric = 5.000000, bonus = 100000.000000)");

	EXPECT_NE(EmployeeControllerTest::getUpdateQueryCondition(*employee), R"(firstName = "Abhiii", middleName = "Narendrakumar", lastName = "Patel", dateOfBirth = "11 - 09 - 2002", mobileNo = 7283902430, email = "abhi.patel@zuru.com", address = "88, V.K.", gender = "Male", dateOfJoining = "01 - 01 - 2024", mentorID = 1, performanceMetric = 5.000000, bonus = 100000.000000)"); // FAIL
}

TEST_F(EmployeeFixture, Test_updateEmployee) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::updateEmployee(*employee));

	std::string_view queryStr = "SELECT * FROM Employee WHERE lastName =\"Patel\"";
	EXPECT_EQ(1, EmployeeDB::DBManager::instance().executeRowCountQuery(queryStr.data()));

	employee->setEmail("david.brown@example.com");
	EXPECT_FALSE(EmployeeDB::Controller::EmployeeController::updateEmployee(*employee)); // FAIL
}

TEST_F(EmployeeFixture, Test_getSalaryDetails) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::getSalaryDetails(*salary));

	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::getSalaryDetails(*salary));
	ASSERT_DOUBLE_EQ(500.0, salary->getBonus());
	ASSERT_DOUBLE_EQ(0.85, salary->getPerformanceMetric());
	ASSERT_DOUBLE_EQ(3000.0, salary->getDeduction());
	ASSERT_DOUBLE_EQ(65000.0, salary->getBaseSalary());
	ASSERT_DOUBLE_EQ(7000.0, salary->getAllowance());
}

TEST_F(EmployeeFixture, Test_deleteEmployeeByID) {
	EXPECT_TRUE(EmployeeDB::Controller::EmployeeController::deleteEmployeeByID(1));

	std::string_view queryStr = R"(SELECT * FROM Employee WHERE employeeID = 1)";
	EXPECT_EQ(0, EmployeeDB::DBManager::instance().executeRowCountQuery(queryStr.data())); // FAIL
}
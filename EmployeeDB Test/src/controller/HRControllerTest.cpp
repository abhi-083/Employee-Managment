#include "HRFixture.h"
#include "HRControllerTest.h"


TEST_F(HRFixture, Test_insertHRSuccess) {
	ASSERT_TRUE(HRController::insertHR(*hr));

	std::string_view queryString = "SELECT * FROM Employee WHERE dateOfBirth = \"15/05/1995\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, Test_insertHRFailure) {
	emptyHR->setEmail("chris.martinez@example.com");
	ASSERT_FALSE(HRController::insertHR(*emptyHR));

	std::string_view queryString = "SELECT * FROM HR";
	ASSERT_NE(3, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM HR WHERE hrSpecialization = \"Training and Development\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, Test_selectHRSuccess) {
	ASSERT_TRUE(HRController::selectHR("hrSpecialization", "Recruitment"));
}

TEST_F(HRFixture, Test_selectHRFailure) {
	ASSERT_FALSE(HRController::selectHR("mobile", "6745678980"));
}

TEST_F(HRFixture, Test_updateHRSuccess) {
	emptyHR->setEmployeeID(1);
	emptyHR->setEmail("michael@example.com");
	emptyHR->setHRSpecialization("Senior Executive");

	ASSERT_TRUE(HRController::updateHR(*emptyHR));

	std::string_view queryString = "SELECT * FROM Employee WHERE email = \"michael@example.com\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM HR WHERE hrSpecialization = \"Senior Executive\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, Test_updateHRFailure) {
	emptyHR->setEmployeeID(2);
	emptyHR->setMobileNo(4567890128);

	ASSERT_FALSE(HRController::updateHR(*emptyHR));
}

TEST_F(HRFixture, Test_deleteHRByID) {
	ASSERT_TRUE(HRController::deleteHRByID(2));

	std::string_view queryString = "SELECT * FROM Employee WHERE employeeID = 2;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM HR;";
	ASSERT_EQ(1, DBManager::instance().executeSelectQuery(queryString.data()));

	ASSERT_TRUE(HRController::deleteHRByID(1));

	queryString = "SELECT * FROM Employee;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", HRControllerTest::getUpdateQueryCondition(*emptyHR).c_str());
}

TEST_F(HRFixture, Test_getUpdateQueryCondition) {
	emptyHR->setHRSpecialization("Sr. HR Executive");

	ASSERT_STREQ("hrSpecialization = \"Sr. HR Executive\"", HRControllerTest::getUpdateQueryCondition(*emptyHR).c_str());

	emptyHR->setFirstName("Himanshu");

	ASSERT_STREQ("hrSpecialization = \"Sr. HR Executive\"", HRControllerTest::getUpdateQueryCondition(*emptyHR).c_str());
}
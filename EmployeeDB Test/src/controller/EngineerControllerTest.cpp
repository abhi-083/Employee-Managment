#include "EngineerFixture.h"
#include "EngineerControllerTest.h"

TEST_F(EngineerFixture, Test_insertEngineerSuccess) { 
	ASSERT_TRUE(EngineerController::insertEngineer(*engineer)); 

	std::string_view queryString = "SELECT * FROM Engineer WHERE technology = \"React\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, Test_insertEngineerFailure) {
	emptyEngineer->setEmail("david.brown@example.com");
	emptyEngineer->setTechnology("Go");
	ASSERT_FALSE(EngineerController::insertEngineer(*emptyEngineer));

	std::string_view queryString = "SELECT * FROM Engineer";
	ASSERT_NE(3, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Engineer WHERE technology = \"Go\" COLLATE NOCASE;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, Test_selectEngineerSuccess) {
	ASSERT_TRUE(EngineerController::selectEngineer("firstName", "John"));
}

TEST_F(EngineerFixture, Test_selectEngineerFailure) {
	ASSERT_FALSE(EngineerController::selectEngineer("LASSTNAME", "1"));
}

TEST_F(EngineerFixture, Test_updateEngineerSuccess) {
	emptyEngineer->setEmployeeID(1);
	emptyEngineer->setFirstName("Alex");

	ASSERT_TRUE(EngineerController::updateEngineer(*emptyEngineer));

	std::string_view queryString = "SELECT * FROM Employee WHERE firstName = \"Alex\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE firstName = \"John\" COLLATE NOCASE;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, Test_updateEngineerFailure) {
	emptyEngineer->setEmployeeID(2);
	emptyEngineer->setEmail("john.smith@example.com");

	ASSERT_FALSE(EngineerController::updateEngineer(*emptyEngineer));
}

TEST_F(EngineerFixture, Test_deleteEngineerByID) {
	ASSERT_TRUE(EngineerController::deleteEngineerByID(1));
	ASSERT_TRUE(EngineerController::deleteEngineerByID(2));

	std::string_view queryString = "SELECT * FROM Employee WHERE employeeID = 1;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Engineer;";
	ASSERT_EQ(0, DBManager::instance().executeSelectQuery(queryString.data()));

	queryString = "SELECT * FROM Employee;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", EngineerControllerTest::getUpdateQueryCondition(*emptyEngineer).c_str());
}

TEST_F(EngineerFixture, Test_getUpdateQueryCondition) {
	emptyEngineer->setTechnology("c++");

	ASSERT_STREQ("technology = \"c++\"", EngineerControllerTest::getUpdateQueryCondition(*emptyEngineer).c_str());

	emptyEngineer->setMiddleName("Patel");

	ASSERT_STREQ("technology = \"c++\"", EngineerControllerTest::getUpdateQueryCondition(*emptyEngineer).c_str());
}
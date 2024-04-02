#include "QAFixture.h"
#include "QAControllerTest.h"

TEST_F(QAFixture, Test_insertQASuccess) {
	ASSERT_TRUE(QAController::insertQA(*qa));

	std::string_view queryString = "SELECT * FROM QA WHERE testingTool = \"JIRA\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(QAFixture, Test_insertQAFailure) {
	emptyQA->setEmail("jessica.taylor@example.com");
	ASSERT_FALSE(QAController::insertQA(*emptyQA));

	std::string_view queryString = "SELECT * FROM QA";
	ASSERT_NE(3, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM QA WHERE testingTool = \"Selenium\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(QAFixture, Test_selectQASuccess) {
	ASSERT_TRUE(QAController::selectQA("testingTool", "Selenium"));
}

TEST_F(QAFixture, Test_selectQAFailure) {
	ASSERT_FALSE(QAController::selectQA("mobile", "6745678980"));
}

TEST_F(QAFixture, Test_deleteQAByID) {
	ASSERT_TRUE(QAController::deleteQAByID(2));

	std::string_view queryString = "SELECT * FROM Employee WHERE employeeID = 2;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM QA;";
	ASSERT_EQ(1, DBManager::instance().executeSelectQuery(queryString.data()));

	ASSERT_TRUE(QAController::deleteQAByID(1));

	queryString = "SELECT * FROM Employee;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(QAFixture, Test_updateQASuccess) {
	emptyQA->setEmployeeID(1);
	emptyQA->setEmail("emilly@example.com");
	emptyQA->setTestingTool("JUnit");

	ASSERT_TRUE(QAController::updateQA(*emptyQA));

	std::string_view queryString = "SELECT * FROM Employee WHERE email = \"emilly@example.com\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM QA WHERE testingTool = \"Chai\" COLLATE NOCASE;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(QAFixture, Test_updateQAFailure) {
	emptyQA->setEmployeeID(2);
	emptyQA->setMobileNo(9870723456);

	ASSERT_FALSE(QAController::updateQA(*emptyQA));
}

TEST_F(QAFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", QAControllerTest::getUpdateQueryCondition(*emptyQA).c_str());
}

TEST_F(QAFixture, Test_getUpdateQueryCondition) {
	emptyQA->setTestingTool("Mocha");

	ASSERT_STREQ("testingTool = \"Mocha\"", QAControllerTest::getUpdateQueryCondition(*emptyQA).c_str());

	emptyQA->setBonus(25000.00);

	ASSERT_STREQ("testingTool = \"Mocha\"", QAControllerTest::getUpdateQueryCondition(*emptyQA).c_str());
}
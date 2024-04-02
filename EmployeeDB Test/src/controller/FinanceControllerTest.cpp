#include "FinanceFixture.h"
#include "FinanceControllerTest.h"

TEST_F(FinanceFixture, Test_insertFinanceSuccess) {
	ASSERT_TRUE(FinanceController::insertFinance(*finance));

	std::string_view queryString = "SELECT * FROM Finance WHERE accountingTool = \"SAP ERP\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, Test_insertFinanceFailure) {
	emptyFinance->setEmail("sarah.wilson@example.com");
	emptyFinance->setAccountingTool("Tally");
	ASSERT_FALSE(FinanceController::insertFinance(*emptyFinance));

	std::string_view queryString = "SELECT * FROM Finance";
	ASSERT_NE(3, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Finance WHERE accountingTool = \"Tally\" COLLATE NOCASE;";
	ASSERT_NE(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, Test_selectFinanceSuccess) {
	ASSERT_TRUE(FinanceController::selectFinance("accountingTool", "Tally"));
}

TEST_F(FinanceFixture, Test_selectFinanceFailure) {
	ASSERT_FALSE(FinanceController::selectFinance("mail", "rushi@gmail.com"));
}

TEST_F(FinanceFixture, Test_updateFinanceSuccess) {
	emptyFinance->setEmployeeID(1);
	emptyFinance->setFirstName("Alex");

	ASSERT_TRUE(FinanceController::updateFinance(*emptyFinance));

	std::string_view queryString = "SELECT * FROM Employee WHERE firstName = \"Alex\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE firstName = \"John\" COLLATE NOCASE;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, Test_updateFinanceFailure) {
	emptyFinance->setEmployeeID(2);
	emptyFinance->setMobileNo(9876543211);

	ASSERT_FALSE(FinanceController::updateFinance(*emptyFinance));
}

TEST_F(FinanceFixture, Test_deleteFinanceByID) {
	ASSERT_TRUE(FinanceController::deleteFinanceByID(2));

	std::string_view queryString = "SELECT * FROM Employee WHERE employeeID = 2;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Finance;";
	ASSERT_EQ(1, DBManager::instance().executeSelectQuery(queryString.data()));

	ASSERT_TRUE(FinanceController::deleteFinanceByID(1));

	queryString = "SELECT * FROM Employee;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", FinanceControllerTest::getUpdateQueryCondition(*emptyFinance).c_str());
}

TEST_F(FinanceFixture, Test_getUpdateQueryCondition) {
	emptyFinance->setAccountingTool("Excel");

	ASSERT_STREQ("accountingTool = \"Excel\"", FinanceControllerTest::getUpdateQueryCondition(*emptyFinance).c_str());

	emptyFinance->setMiddleName("Yadav");

	ASSERT_STREQ("accountingTool = \"Excel\"", FinanceControllerTest::getUpdateQueryCondition(*emptyFinance).c_str());
}
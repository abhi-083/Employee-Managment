#include "ExportCSVControllerTest.h"
#include "ExportCSVFixture.h"
#include "pch.h"
#include <filesystem>

namespace fs = std::filesystem;

TEST_F(ExportFixture, Test_exportToCSVSuccess) {
	EXPECT_TRUE(ExportCSVController::exportToCSV("Manager", "Manager"));
	EXPECT_TRUE(ExportCSVController::exportToCSV("Employee", "Employee"));
	EXPECT_TRUE(ExportCSVController::exportToCSV("Department", "Department"));

	fs::path exportPath{ "./tablesInCSV/Manager.csv" };
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/Employee.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/Department.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	EXPECT_FALSE(ExportCSVController::exportToCSV("Maaaaaanager", "Manager")); //FAIL
}

TEST_F(ExportFixture, Test_exportAll) {
	EXPECT_TRUE(ExportCSVController::exportAll());

	fs::path exportPath{ "./tablesInCSV/ManagerBackup.csv" };
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/EmployeeBackup.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/DepartmentBackup.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/EngineerBackup.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/HRBackup.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/QABackup.csv";
	EXPECT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/FinanceBackup.csv";
	EXPECT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, Test_removecommas) {
	std::string stringToTest{ "34, Grove Street, Ganton, Los Santos" };

	ExportControllerTest::removecommas(stringToTest);

	EXPECT_STREQ("34 Grove Street Ganton Los Santos", stringToTest.c_str());
}
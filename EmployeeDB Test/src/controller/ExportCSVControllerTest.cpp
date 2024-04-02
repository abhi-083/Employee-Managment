#include "ExportCSVControllerTest.h"
#include "ExportCSVFixture.h"
#include "pch.h"
#include <filesystem>

namespace fs = std::filesystem;

TEST_F(ExportFixture, Test_exportToCSVSuccess) {
	ASSERT_TRUE(ExportCSVController::exportToCSV("Manager", "Manager"));
	ASSERT_TRUE(ExportCSVController::exportToCSV("Employee", "Employee"));
	ASSERT_TRUE(ExportCSVController::exportToCSV("Department", "Department"));

	fs::path exportPath{ "./tablesInCSV/Manager.csv" };
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/Employee.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/Department.csv";
	ASSERT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, Test_exportToCSVFailure) {
	ASSERT_FALSE(ExportCSVController::exportToCSV("Maaaaaanager", "Manager"));
}

TEST_F(ExportFixture, Test_exportAll) {
	ASSERT_TRUE(ExportCSVController::exportAll());

	fs::path exportPath{ "./tablesInCSV/ManagerBackup.csv" };
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/EmployeeBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/DepartmentBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/EngineerBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/HRBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/QABackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./tablesInCSV/FinanceBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, Test_removecommas) {
	std::string stringToTest{ "34, Grove Street, Ganton, Los Santos" };

	ExportControllerTest::removecommas(stringToTest);

	ASSERT_STREQ("34 Grove Street Ganton Los Santos", stringToTest.c_str());
}
#ifndef __EmployeeFixture_h__
#define __EmployeeFixture_h__

#include "pch.h"
#include "Employee.h"
#include "Salary.h"
#include "DBManager.h"

struct EmployeeFixture: public testing::Test {
	std::unique_ptr<EmployeeDB::Model::Employee> employee;
	std::unique_ptr<EmployeeDB::Model::Salary> salary;

	void SetUp() {
		employee = std::make_unique<EmployeeDB::Model::Employee>();
		salary = std::make_unique<EmployeeDB::Model::Salary>();
		salary->setEmployeeID(1);

		employee->setEmployeeID(1);
		employee->setFirstName("Abhi");
		employee->setMiddleName("Narendrakumar");
		employee->setLastName("Patel");
		employee->setDateOfBirth("11-09-2002");
		employee->setMobileNo(7283902430);
		employee->setEmail("abhi.patel@zuru.com");
		employee->setAddress("88, V.K.");
		employee->setGender(EmployeeDB::Model::Gender::Male);
		employee->setDateOfJoining("01-01-2024");
		employee->setDepartmentID(1);
		employee->setMentorID(1);
		employee->setPerformanceMetric(5);
		employee->setBonus(100000);

		std::string query = R"(INSERT INTO Employee ("employeeID", "firstName", "middleName", "lastName", "dateOfBirth", "mobileNo", "email", "address", "gender", "dateOfJoining", "departmentID", "mentorID", "performanceMetric", "bonus") VALUES(1, "John", "Doe", "Smith", "15-05-1990", 1234567891, "john.smith@example.com", "123 Main St, City, Country", "Male", "10-01-2020", 1, 1, 0.85, 500), (2, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, 2, 0.78, 450);)";
		int m_ResultCode = EmployeeDB::DBManager::instance().executeQuery(query.c_str());



		query = R"(INSERT INTO Department ("departmentID", "departmentName", "baseSalary", "allowance", "deduction") VALUES(1, "Engineer", 65000, 7000, 3000))";
		m_ResultCode = EmployeeDB::DBManager::instance().executeQuery(query.c_str());
	}

	void TearDown() {
		EmployeeDB::DBManager::instance().executeTruncateQuery("Department");
		EmployeeDB::DBManager::instance().executeTruncateQuery("Employee");
	}
};

#endif

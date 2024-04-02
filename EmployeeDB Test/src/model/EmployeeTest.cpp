#include "EmployeeFixture.h"

using EmployeeDB::Model::Gender;

TEST(TestEmployee, Test_getGenderFromString) {
	ASSERT_EQ(Gender::Male, EmployeeDB::Model::getGenderFromString(std::string{ "Male" }));
	ASSERT_NE(Gender::Male, EmployeeDB::Model::getGenderFromString(std::string{ "female" }));
	ASSERT_EQ(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "female" }));
	ASSERT_EQ(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "FEMALE" }));
	ASSERT_NE(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "male" }));
	ASSERT_EQ(Gender::Other, EmployeeDB::Model::getGenderFromString(std::string{ "other" }));
	ASSERT_NE(Gender::Other, EmployeeDB::Model::getGenderFromString(std::string{ "male" }));
}

TEST(TestEmployee, Test_getGenderString) {
	ASSERT_STREQ("Male", EmployeeDB::Model::getGenderString(Gender::Male).c_str());
	ASSERT_STREQ("Female", EmployeeDB::Model::getGenderString(Gender::Female).c_str());
	ASSERT_STREQ("Other", EmployeeDB::Model::getGenderString(Gender::Other).c_str());
}
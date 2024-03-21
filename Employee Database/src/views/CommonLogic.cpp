#include<iostream>
#include"../../include/views/ViewEngineer.h"
#include "../../include/Validator.h"

std::string trim(std::string str, const std::string chars = "\t\n\v\f\r ") {
	if (str.size() == 0) {
		return str;
	}
	else {
		std::string tmp(str);
		tmp.erase(tmp.find_last_not_of(chars) + 1);
		tmp.erase(0, tmp.find_first_not_of(chars));

		std::string out_str;
		bool pre_space = false;
		int i = 0;
		while (i < tmp.size()) {
			if (tmp.at(i) != ' ') {
				if (pre_space) {
					out_str += ' ';
				}
				out_str += tmp.at(i);
				pre_space = false;
			}
			else {
				pre_space = true;
			}
			++i;
		}
		return out_str;
	}
}

bool repeatOperation(const std::string& operation)
{
	while (true) {
		char in;
		std::cout << "Do you want to " + operation + " another field?(0/1): ";
		in = std::cin.get();

		if (in == '\n') {
			std::cout << "Please enter valid input...\n";
		}
		else if (std::cin.peek() != '\n') {
			in = ' ';  // Validator will return false

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter valid input...\n";
		}
		else if (EmployeeDB::Validator::validateCharInput(in)) {
			if (in == '1') {
				return true;
			}
			else {
				std::cin.clear();
				std::cin.ignore();
				return false;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter valid input...\n";
		}
	}
}
void printEmpFields() {
	std::cout << "1. firstName*: " << '\n';
	std::cout << "2. middleName: " << '\n';
	std::cout << "3. lastName*: " << '\n';
	std::cout << "4. dateOfBirth: " << '\n';
	std::cout << "5. mobileNo*: " << '\n';
	std::cout << "6. email*:" << '\n';
	std::cout << "7. address*:" << '\n';
	std::cout << "8. gender*:" << '\n';
	std::cout << "9. dateOfJoining*:" << '\n';
	/*std::cout << "10. departmentID*:" << '\n';*/
	std::cout << "10. mentorID*:" << '\n';
	std::cout << "11. performanceMetric:" << '\n';
	std::cout << "12. bonus:" << '\n';
}

void printEmpFieldsWithID() {
	std::cout << "1. employee ID*:" << '\n';
	std::cout << "2. firstName*: " << '\n';
	std::cout << "3. middleName: " << '\n';
	std::cout << "4. lastName*: " << '\n';
	std::cout << "5. dateOfBirth: " << '\n';
	std::cout << "6. mobileNo*: " << '\n';
	std::cout << "7. email*:" << '\n';
	std::cout << "8. address*:" << '\n';
	std::cout << "9. gender*:" << '\n';
	std::cout << "10. dateOfJoining*:" << '\n';
	std::cout << "11. departmentID*:" << '\n';
	std::cout << "12. mentorID*:" << '\n';
	std::cout << "13. performanceMetric:" << '\n';
	std::cout << "14. bonus:" << '\n';
}

void askUserInput(EmployeeDB::Model::Employee& e) {
	std::string inputField;

	std::cin.ignore();
	while (true) {
		std::cout << "firstName*: ";
		std::getline(std::cin, inputField);
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "firstName is mandatory...Please enter again!!" << '\n';
		}
		else {
			e.setFirstName(inputField);
			break;
		}
	}

	while (true) {
		std::cout << "middleName: ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			break;
		}
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "Please enter some valid input...\n";
		}
		else {
			e.setMiddleName(inputField);
			break;
		}
	}

	while (true) {
		std::cout << "lastName*: ";
		std::getline(std::cin, inputField);
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "lastName is mandatory...Please enter again!!" << '\n';
		}
		else {
			e.setLastName(inputField);
			break;
		}
	}


	while (true) {
		std::cout << "dateOfBirth(dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy): ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			break;
		}
		inputField = trim(inputField);

		if (EmployeeDB::Validator::validateDate(inputField)) {
			e.setDateOfBirth(inputField);
			break;
		}
		else {
			std::cerr << "Wrong input...Please enter again!!\n";
		}
	}

	while (true) {
		std::cout << "mobileNo*(Starting from 6-9): ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			std::cout << "mobileNo is mandatory...Please enter again!!" << '\n';
		}
		else {
			inputField = trim(inputField);

			if (EmployeeDB::Validator::validateMobile(inputField)) {
				e.setMobileNo(std::stoll(inputField));
				break;
			}
			else {
				std::cerr << "Wrong input...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "email*: ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			std::cout << "email is mandatory...Please enter again!!" << '\n';
		}
		else {
			inputField = trim(inputField);
			if (EmployeeDB::Validator::validateEmail(inputField)) {
				e.setEmail(inputField);
				break;
			}
			else {
				std::cerr << "Wrong input...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "address*: ";
		std::getline(std::cin, inputField);
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "address is mandatory...Please enter again!!" << '\n';
		}
		else {
			e.setAddress(inputField);
			break;
		}
	}

	while (true) {
		std::cout << "gender*: ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			std::cout << "gender is mandatory...Please enter again!!" << '\n';
		}
		else {
			inputField = trim(inputField);
			int x = EmployeeDB::Validator::validateGender(inputField);
			if (x == 1) {
				e.setGender(EmployeeDB::Model::Gender::Male);
				break;
			}
			else if (x == 2) {
				e.setGender(EmployeeDB::Model::Gender::Female);
				break;
			}
			else if (x == 3) {
				e.setGender(EmployeeDB::Model::Gender::Other);
				break;
			}
			else {
				std::cerr << "Wrong input...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "dateOfJoining*(dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy): ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			std::cout << "dateOfJoining is mandatory...Please enter again!!" << '\n';
		}
		else {
			inputField = trim(inputField);

			if (EmployeeDB::Validator::validateDate(inputField)) {
				e.setDateOfJoining(inputField);
				break;
			}
			else {
				std::cerr << "Wrong input...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "mentorID*: ";
		std::getline(std::cin, inputField);
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "mentorID is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				e.setMentorID(std::stoi(inputField));
			}
			catch (...) {
				std::cout << "Wrong input...Please enter integer!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "performanceMetric: ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			break;
		}
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "Wrong input...Please enter integer!!\n";
		}
		else {
			try {
				e.setPerformanceMetric(std::stod(inputField));
			}
			catch (...) {
				std::cout << "Wrong input...Please enter integer!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "bonus: ";
		std::getline(std::cin, inputField);
		if (inputField.size() == 0) {
			break;
		}
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "Wrong input...Please enter integer!!\n";
		}
		else {
			try {
				e.setBonus(std::stoi(inputField));
			}
			catch (...) {
				std::cout << "Wrong input...Please enter integer!!\n";
				continue;
			}
			break;
		}
	}

}

std::string checkInput(const std::string& s) {
	std::string inputField;
	while (true) {
		std::cout << "Enter the " + s + ": ";
		std::getline(std::cin, inputField);
		inputField = trim(inputField);
		if (inputField.size() == 0) {
			std::cout << "The input can not be empty...Please enter something\n";
		}
		else {
			break;
		}
	}
	return inputField;
}

void matchInpField(const std::string& inputField, std::string& arg1, std::string& arg2) {
	switch (std::stoi(inputField)) {
	case 1: {
		while (true) {
			arg1 = "employeeID";
			arg2 = checkInput(arg1);
			try {
				[[maybe_unused]] int a = std::stoi(arg2);
				break;
			}
			catch (...) {
				std::cout << "Please enter integer value...\n";
			}
		}
		break;
	}
	case 2: {
		arg1 = "firstName";
		arg2 = checkInput(arg1);
		break;
	}
	case 3: {
		arg1 = "middleName";
		arg2 = checkInput(arg1);
		break;
	}
	case 4: {
		arg1 = "lastName";
		arg2 = checkInput(arg1);
		break;
	}
	case 5: {
		while (true) {
			arg1 = "dateOfBirth";
			arg2 = checkInput(arg1);
			if (EmployeeDB::Validator::validateDate(arg2)) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter again!!\n";
			}
		}
		break;
	}
	case 6: {
		while (true) {
			arg1 = "mobileNo";
			arg2 = checkInput(arg1);
			if (EmployeeDB::Validator::validateMobile(arg2)) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter again!!\n";
			}
		}
		break;
	}
	case 7: {
		while (true) {
			arg1 = "email";
			arg2 = checkInput(arg1);
			if (EmployeeDB::Validator::validateEmail(arg2)) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter again!!\n";
			}
		}
		break;
	}
	case 8: {
		arg1 = "address";
		arg2 = checkInput(arg1);
		break;
	}
	case 9: {
		while (true) {
			arg1 = "gender";
			arg2 = checkInput(arg1);
			if (EmployeeDB::Validator::validateGender(arg2) != -1) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter again!!\n";
			}
		}
		break;
	}
	case 10: {
		while (true) {
			arg1 = "dateOfJoining";
			arg2 = checkInput(arg1);
			if (EmployeeDB::Validator::validateDate(arg2)) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter again!!\n";
			}
		}
		break;
	}
	case 11: {
		while (true) {
			arg1 = "departmentID";
			arg2 = checkInput(arg1);
			try {
				[[maybe_unused]] int a = std::stoi(arg2);
				break;
			}
			catch (...) {
				std::cout << "Please enter integer value...\n";
			}
		}
		break;
	}
	case 12: {
		while (true) {
			arg1 = "mentorID";
			arg2 = checkInput(arg1);
			try {
				[[maybe_unused]] int a = std::stoi(arg2);
				break;
			}
			catch (...) {
				std::cout << "Please enter integer value...\n";
			}
		}
		break;
	}
	case 13: {
		while (true) {
			arg1 = "performanceMetric";
			arg2 = checkInput(arg1);
			try {
				[[maybe_unused]] double a = std::stod(arg2);
				break;
			}
			catch (...) {
				std::cout << "Please enter numeric value...\n";
			}
		}
		break;
	}
	case 14: {
		while (true) {
			arg1 = "bonus";
			arg2 = checkInput(arg1);
			try {
				[[maybe_unused]] double a = std::stod(arg2);
				break;
			}
			catch (...) {
				std::cout << "Please enter numeric value...\n";
			}
		}
		break;
	}
	default: {
		std::cout << "Invalid input...Please enter input in correct range!!\n";
	}
	}
}

void updateEmp(const std::string& input, EmployeeDB::Model::Employee& e) {
	switch (std::stoi(input)) {
	case 1:
	{
		while (true) {
			std::string inputField;
			std::cout << "firstName: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				e.setFirstName(inputField);
				break;
			}
		}
		break;
	}
	case 2:
	{
		while (true) {
			std::string inputField;
			std::cout << "middleName: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				e.setMiddleName(inputField);
				break;
			}
		}
		break;
	}
	case 3:
	{
		while (true) {
			std::string inputField;
			std::cout << "lastName: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				e.setLastName(inputField);
				break;
			}
		}
		break;
	}
	case 4:
	{
		while (true) {
			std::string inputField;
			std::cout << "dateOfBirth: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				if (EmployeeDB::Validator::validateDate(inputField)) {
					e.setDateOfBirth(inputField);
				}
				else {
					std::cout << "Please enter valid input...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 5:
	{
		while (true) {
			std::string inputField;
			std::cout << "mobileNo: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				if (EmployeeDB::Validator::validateMobile(inputField)) {
					e.setMobileNo(std::stoll(inputField));
				}
				else {
					std::cout << "Please enter valid input...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 6:
	{
		while (true) {
			std::string inputField;
			std::cout << "email: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				if (EmployeeDB::Validator::validateEmail(inputField)) {
					e.setEmail(inputField);
				}
				else {
					std::cout << "Please enter valid input...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 7:
	{
		while (true) {
			std::string inputField;
			std::cout << "address: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				e.setAddress(inputField);
				break;
			}
		}
		break;
	}
	case 8:
	{
		while (true) {
			std::string inputField;
			std::cout << "gender: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				if (EmployeeDB::Validator::validateGender(inputField) == 1) {
					e.setGender(EmployeeDB::Model::Gender::Male);
				}
				else if (EmployeeDB::Validator::validateGender(inputField) == 2) {
					e.setGender(EmployeeDB::Model::Gender::Female);
				}
				else if (EmployeeDB::Validator::validateGender(inputField) == 3) {
					e.setGender(EmployeeDB::Model::Gender::Other);
				}
				else {
					std::cout << "Please enter valid input...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 9:
	{
		while (true) {
			std::string inputField;
			std::cout << "dateOfJoining: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				if (EmployeeDB::Validator::validateDate(inputField)) {
					e.setDateOfJoining(inputField);
				}
				else {
					std::cout << "Please enter valid input...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 10:
	{
		while (true) {
			std::string inputField;
			std::cout << "mentorID: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				try {
					e.setMentorID(std::stoi(inputField));
				}
				catch (...) {
					std::cout << "Please enter a numeric value...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 11:
	{
		while (true) {
			std::string inputField;
			std::cout << "performanceMetric: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				try {
					e.setPerformanceMetric(std::stod(inputField));
				}
				catch (...) {
					std::cout << "Please enter a numeric value...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	case 12: {
		while (true) {
			std::string inputField;
			std::cout << "bonus: ";
			std::getline(std::cin, inputField);
			inputField = trim(inputField);
			if (inputField.size() == 0) {
				std::cout << "Please enter some value...\n";
			}
			else {
				try {
					e.setBonus(std::stoi(inputField));
				}
				catch (...) {
					std::cout << "Please enter a numeric value...\n";
					continue;
				}
				break;
			}
		}
		break;
	}
	}
}

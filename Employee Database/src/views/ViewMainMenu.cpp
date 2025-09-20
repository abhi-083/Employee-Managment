#include "ViewMainMenu.h"
#include "ConsoleManager.h"
#include "ViewTable.h"
#include "Validator.h"
#include "PlatformUtils.h"
#include <iostream>
#include <limits>

void EmployeeDB::Console::viewMainMenu() noexcept {
	while (true) {
		std::cout << "---------------------------------------------- Create Table Menu ------------------------------------------------------- \n";

		std::cout << "0. Quit\n";
		std::cout << "1. Create Table\n";
		std::cout << "2. Delete Table\n";
		std::cout << "3. EmployeeDB\n";
		std::cout << "\x1B[36mPlease select operation which you want to perform: \033[0m";

		char input;
		input = std::cin.get();
		if (input == '\n') {
			std::cerr << "\x1B[31mPlease enter valid input...\033[0m\n";
			std::cout << "\x1B[33mPress enter to continue...\033[0m\n";
			std::cin.get();
			EmployeeDB::Utils::clearScreen();
		}
		else if (std::cin.peek() != '\n') {
			input = ' ';

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "\x1B[31mPlease enter valid input in the given range(0-5)...\033[0m\n";

			std::cout << "\x1B[33mPress enter to continue...\033[0m\n";
			std::cin.get();
			EmployeeDB::Utils::clearScreen();
		}
		else if (EmployeeDB::Validator::validateCreateMenu(input)) {

			if (input == '0') {
				std::exit(0);
			}
			EmployeeDB::Utils::clearScreen();
			switch (input) {
			case '1':
				createTable();
				break;
			case '2':
				deleteTable();
				break;
			case '3':
				viewDBMenu();
				break;
			}

		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "\x1B[31mPlease enter valid input in the given range(0-5)...\033[0m\n";
			std::cout << "\x1B[33mPress enter to continue...\033[0m\n";
			std::cin.get();
			EmployeeDB::Utils::clearScreen();
		}
	}
}

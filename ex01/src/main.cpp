#include <iostream>
#include <cstring>
#include <string>
#include "header.hpp"
#include "phonebook.hpp"

int	main(void)
{
	int i = 0;
	std::string input;
	PhoneBook phone;
	
	while (input != "EXIT") {
		std::cout << GREEN << "ADD " << RESET << ORANGE << "SEARCH " << RESET << RED << "EXIT" << RESET << "\n";
		std::cin >> input;
		if (i >= 8)
			i = 0;
		if (input.empty()) continue;
		if (input.compare("ADD") != 0 && input.compare("EXIT") != 0 && input.compare("SEARCH") != 0)
			std::cout << "Invalid command\n";
		else if (input.compare("ADD") == 0)
			phone.addContact(i++);
		else if (input.compare("EXIT") == 0)
			return (std::cout << BRED << "Exiting!\n" << RESET, 0);
		else if (input.compare("SEARCH") == 0)
			phone.show();
	}
	return (0);
}


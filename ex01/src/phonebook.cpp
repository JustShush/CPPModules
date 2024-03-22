#include "phonebook.hpp"
#include "contact.hpp"
#include "header.hpp"

PhoneBook::PhoneBook() {
	std::cout << BGREEN << "New PhoneBook Obj Created!" << RESET << "\n";
}

PhoneBook::~PhoneBook() {
	std::cout << BRED << "PhoneBook Obj Destroyed!" << RESET << "\n";
}

void PhoneBook::addContact(int index) {
	Contact contact;
	contacts[index] = contact.add();
}

std::string	PhoneBook::truncate(std::string str)
{
	if (str.length() > 14)
		return (str.substr(0, 12) + "..");
	return (str);
}

void PhoneBook::show() {
	int i = 0;
	std::string input;

	std::cout << "|" << std::setw(14) << "INDEX" << "|";
	std::cout << std::setw (14) << "FIRST NAME" << "|";
	std::cout << std::setw (14) << "LAST NAME" << "|";
	std::cout << std::setw (14) << "NICKNAME" << "|";
	std::cout << std::setw (14) << "PHONE NUMBER" << "|";
	std::cout << std::setw (14) << "DARKEST SECRET" << "|";
	std::cout << "\n";

	while (i < 8) {

		std::cout << "|" << std::setw(14) << i << "|";
		std::cout << std::setw (14) << truncate(contacts[i].get_field(1)) << "|";
		std::cout << std::setw (14) << truncate(contacts[i].get_field(2)) << "|";
		std::cout << std::setw (14) << truncate(contacts[i].get_field(3)) << "|";
		std::cout << std::setw (14) << truncate(contacts[i].get_field(4)) << "|";
		std::cout << std::setw (14) << truncate(contacts[i].get_field(5)) << "|";
		std::cout << "\n";
		i++;
	}
	while (1) {
		i = 0;
		std::cout << "Enter the Index: ";
		std::cin >> input;
		if (input.empty())
			return ;
		i = atoi(input.c_str());
		if (i < 0 || i > 7) {
			std::cout << BRED << "Invalid index!!\n" << RESET;
			continue;
		} else {
			std::cout << "First Name: ----- " << contacts[i].get_field(1) << "\n";
			std::cout << "Last Name: ------ " << contacts[i].get_field(2) << "\n";
			std::cout << "NickName: ------- " << contacts[i].get_field(3) << "\n";
			std::cout << "Phone Number: --- " << contacts[i].get_field(4) << "\n";
			std::cout << "Darkest Secret: - " << contacts[i].get_field(5) << "\n";
		}
		return ;
	}
}

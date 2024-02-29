#include "contact.hpp"

Contact::Contact() {
	std::cout << BGREEN << "New Contact Created!" << RESET << "\n";
}

Contact::~Contact() {
	std::cout << BRED << "Contact Destroyed!" << RESET << "\n";
}

std::string Contact::input_field(std::string str) {
	std::string field;
	while (1) {
		std::cout << "Enter " << str << ": ";
		//std::cout << std::getline(std::cin, field);
		//if (!getline(std::cin, field)) break;
		std::cin >> field;
		std::cout << field << "\n";
		if (field.empty()) {
			std::cout << BRED << "Field can\'t be EMPTY!\n" << RESET;
			continue;
		}
		if (str.compare("Phone Number") == 0 && s_isdigit(field)) {
			std::cout << BRED << "Ivalid Phone Number!!\n" << RESET;
			continue;
		}
		return (field);
	}
	return ("undefined");
}

Contact Contact::add(void) {
	Contact contact;

	contact.firstName = input_field("First Name");
	contact.lastName = input_field("Last Name");
	contact.nickName = input_field("NickName");
	contact.phoneNbr = input_field("Phone Number");
	contact.darkS = input_field("Dark Secret");

	return (contact);
}

std::string Contact::get_field(int i) {
	if (i == 1)
		return (firstName);
	if (i == 2)
		return (lastName);
	if (i == 3)
		return (nickName);
	if (i == 4)
		return (phoneNbr);
	if (i == 5)
		return (darkS);
	return (0);
}

int Contact::s_isdigit(std::string str) {
	if (str.empty())
		return (0);

	size_t i = 0;
	if (i >= str.length() || !isdigit(str[i])) {
		std::cout << BCYAN << str[i] << "\n";
		return (0);
	}

	while (i < str.length()) {
		if (!isdigit(str[i]))
			return (0);
		std::cout << BCYAN << str[i] << "\n";
		++i;
	}
	return (1);
}

#include "../inc/Base.hpp"

Base::Base() {
	std::cout << GREEN << "Base Constructor Called" << RESET << "\n";
}

Base::~Base() {
	std::cout << RED << "Base Destructor Called" << RESET << "\n";
}
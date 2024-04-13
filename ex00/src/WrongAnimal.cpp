#include "../inc/WrongAnimal.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
WrongAnimal::WrongAnimal() {
	std::cout << GREEN << "WrongAnimal Default Constructor Called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy_a) {
	type = copy_a.type;
	std::cout << GREEN << "WrongAnimal Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
	std::cout << GREEN << "WrongAnimal Copy Constructor Called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal Destructor Called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

std::string	WrongAnimal::getType(void) const {
	return(type);
}

void	WrongAnimal::setType(std::string name) {
	type = name;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Wrong Standard Animal Noise" << std::endl;
}

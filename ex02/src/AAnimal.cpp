#include "../inc/AAnimal.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
AAnimal::AAnimal() {
	std::cout << GREEN << "Animal Default Constructor Called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &_copy) {
	*this = _copy;
	std::cout << GREEN << "Copy Constructor Called" << RESET << "\n";
}

AAnimal::~AAnimal() {
	std::cout << RED << "A Random Animal has left" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &_copy) {
	std::cout << GREEN << "Copy Assignment Operator Called" << RESET << "\n";
	this->type = _copy.type;
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void AAnimal::makeSound(void) const {
	std::cout << ORANGE <<"Random Animal has made a sound: **Random Animal Sound**" << RESET << std::endl;
}

std::string AAnimal::getType(void) const {
	return (type);
}

void	AAnimal::setType(std::string type) {
	this->type = type;
}

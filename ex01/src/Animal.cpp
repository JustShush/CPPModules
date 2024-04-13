#include "../inc/Animal.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Animal::Animal() {
	std::cout << GREEN << "Animal Default Constructor Called" << RESET << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;
	std::cout << GREEN << "Copy Constructor Called" << RESET << "\n";
}

Animal::~Animal() {
	std::cout << RED << "A Random Animal has left" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal &t) {
	std::cout << GREEN << "Copy Assignment Operator Called" << RESET << "\n";
	this->type = t.type;
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

Animal::Animal(std::string type) {
	this->type = type;
}

void Animal::makeSound(void) const {
	std::cout << ORANGE <<"Random Animal has made a sound: **Random Animal Sound**" << RESET << std::endl;
}

std::string Animal::getType(void) const {
	return (this->type);
}

void	Animal::setType(std::string type) {
	this->type = type;
}

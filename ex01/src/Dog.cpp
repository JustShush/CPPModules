#include "../inc/Dog.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << GREEN << "A new Dog as joined" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout << GREEN << "Dog Copy Constructor Called" << RESET << "\n";
}

Dog::~Dog() {
	std::cout << RED << "A " << type << " has left" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &t) {
	std::cout << GREEN << "Dog Copy Assignment Operator Called" << RESET << "\n";
	this->type = t.type;
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void Dog::makeSound(void) const {
	std::cout << ORANGE << type << " has made a Dog sound: **Bark**🐶" << RESET << std::endl;
}

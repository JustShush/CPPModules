#include "../inc/Cat.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << GREEN << "A new Cat as joined" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) {
	*this = copy;
	std::cout << GREEN << "Cat Copy Constructor Called" << RESET << "\n";
}

Cat::~Cat() {
	std::cout << RED << "A " << type << " has left" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &t) {
	std::cout << GREEN << "Cat Copy Assignment Operator Called" << RESET << "\n";
	this->type = t.type;
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void Cat::makeSound(void) const {
	std::cout << ORANGE << type << " has made a Cat sound: **Meow**🐱" << RESET << std::endl;
}

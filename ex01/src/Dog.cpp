#include "../inc/Dog.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain();
	std::cout << GREEN << "A new Dog as joined" << RESET << std::endl;
}

Dog::Dog(const Dog &_copy) : Animal() {
	this->brain = NULL;
	*this = _copy;
	std::cout << GREEN << "Dog Copy Constructor Called" << RESET << "\n";
}

Dog::~Dog() {
	std::cout << RED << "A " << type << " has left" << RESET << std::endl;
	if (brain)
		delete(brain);
}

Dog& Dog::operator=(const Dog &_copy) {
	if (brain)
		delete(brain);
	Animal::operator=(_copy);
	this->type = _copy.type;
	this->brain = new Brain(*_copy.brain);
	std::cout << GREEN << "Dog Copy Assignment Operator Called" << RESET << "\n";
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void Dog::makeSound(void) const {
	std::cout << ORANGE << type << " has made a Dog sound: **Bark**🐶" << RESET << std::endl;
}

Brain *Dog::getBrain(void) {
	return (brain);
}
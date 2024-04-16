#include "../inc/Cat.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Cat::Cat() {
	setType("Cat");
	brain = new Brain();
	std::cout << GREEN << "A new Cat as joined" << RESET << std::endl;
}

Cat::Cat(const Cat &_copy) : AAnimal() {
	this->brain = NULL;
	*this = _copy;
	std::cout << GREEN << "Cat Copy Constructor Called" << RESET << "\n";
}

Cat::~Cat() {
	std::cout << RED << "A " << type << " has left" << RESET << std::endl;
	if (brain)
		delete(brain);
}

Cat& Cat::operator=(const Cat &_copy) {
	if (brain)
		delete(brain);
	AAnimal::operator=(_copy);
	this->type = _copy.type;
	this->brain = new Brain(*_copy.brain);
	std::cout << GREEN << "Cat Copy Assignment Operator Called" << RESET << "\n";
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void Cat::makeSound(void) const {
	std::cout << ORANGE << getType() << " has made a Cat sound: **Meow**🐱" << RESET << std::endl;
}

Brain *Cat::getBrain(void) {
	return (brain);
}

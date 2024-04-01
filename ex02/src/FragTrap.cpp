#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	setHp(100);
	setEnergy(100);
	setAttack(30);
	std::cout << GREEN << "FragTrap Default Constructor Called" << RESET << "\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHp(100);
	setEnergy(100);
	setAttack(30);
	std::cout << GREEN << "FragTrap Name Constructor Called" << RESET << "\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap() {
	*this = copy;
	std::cout << GREEN << "FragTrap Copy Constructor Called" << RESET << "\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy_a) {
	ClapTrap::operator=(copy_a);
	std::cout << GREEN << "FragTrap Copy Assignment Operator Called" << RESET << "\n";
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap Destructor Called" << RESET << "\n";
}

void FragTrap::attack(const std::string& target) {
	if (check()) return ;

	setEnergy(getEnergy() - 10);
	std::cout << "FragTrap " << getName() << " attacked " << target << " dealing " << getAttack() << " points of damage!\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << ORANGE << getName() << RESET << " wants a high five\n";
}

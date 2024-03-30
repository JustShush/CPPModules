#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	setHp(100);
	setEnergy(50);
	setAttack(20);
	std::cout << GREEN << "ScavTrap Default Constructor Called" << RESET << "\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHp(100);
	setEnergy(50);
	setAttack(20);
	std::cout << GREEN << "ScavTrap Name Constructor Called" << RESET << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap() {
	*this = copy;
	std::cout << GREEN << "ScavTrap Copy Constructor Called" << RESET << "\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy_a) {
	ClapTrap::operator=(copy_a);
	std::cout << GREEN << "ScavTrap Copy Assignment Operator Called" << RESET << "\n";
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap Destructor Called" << RESET << "\n";
}

void ScavTrap::attack(const std::string& target) {
	if (check()) return ;

	int energy = getEnergy();
	setEnergy(energy -= 1);
	std::cout << "ScavTrap " << getName() << " attacked " << target << " dealing " << getAttack() << " points of damage!\n";
}

void	ScavTrap::guardGate(void) {
	std::cout << RED << "ScavTrap " << getName() << " is in Gate Keeper mode." << RESET << "\n";
}

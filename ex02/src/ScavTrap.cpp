#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hp = 100;
	_energy = 50;
	_attack = 20;
	std::cout << GREEN << "ScavTrap Default Constructor Called" << RESET << "\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hp = 100;
	_energy = 50;
	_attack = 20;
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

	_energy -= 1;
	std::cout << "ScavTrap " << _name << " attacked " << target << " dealing " << _attack << " points of damage!\n";
}

void	ScavTrap::guardGate(void) {
	std::cout << RED << "ScavTrap " << _name << " is in Gate Keeper mode." << RESET << "\n";
}

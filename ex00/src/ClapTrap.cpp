#include "../inc/ClapTrap.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
ClapTrap::ClapTrap() : _hp(10), _energy(10), _attack(0)
{
	std::cout << GREEN << "Default Constructor Called" << RESET << "\n";
}

ClapTrap::ClapTrap(std::string name) : _hp(10), _energy(10), _attack(0)
{
	_name = name;
	std::cout << ORANGE << name << GREEN << " Constructor Called" << RESET << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << GREEN << "Copy Constructor Called" << RESET << "\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor Called" << RESET << "\n";
}
// ---------------------- Orthodox Canonical Form -----------------------------

void ClapTrap::attack(const std::string &target) {
	// check if the player still has energy to attack
	_energy -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
}

void	ClapTrap::beRepaired(unsigned int amount) {

}

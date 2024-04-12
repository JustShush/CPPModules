#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : _hp(10), _energy(10), _attack(0) {
	std::cout << GREEN << "Default Constructor Called" << RESET << "\n";
}

ClapTrap::ClapTrap(std::string name) : _hp(10), _energy(10), _attack(0) {
	_name = name;
	std::cout << ORANGE << name << GREEN << " Constructor Called" << RESET << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << GREEN << "Copy Constructor Called" << RESET << "\n";
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "Destructor Called" << RESET << "\n";
}

// Getters | Setters
std::string ClapTrap::getName() {
	return (_name);
}

int ClapTrap::getHp() {
	return (_hp);
}

int ClapTrap::getEnergy() {
	return (_energy);
}

int ClapTrap::getAttack() {
	return (_attack);
}

void	ClapTrap::setName(std::string name) {
	_name = name;
}

void	ClapTrap::setHp(unsigned int amount) {
	_hp = amount;
}

void	ClapTrap::setEnergy(unsigned int amount) {
	_energy = amount;
}

void	ClapTrap::setAttack(unsigned int amount) {
	_attack = amount;
}

void ClapTrap::getStats() {
	std::cout << ORANGE << _name << " Stats\n" << RESET << "HP: " << _hp << "\nEnergy: " << _energy << "\nAttack: " << _attack << "\n";
}

int	ClapTrap::check() {
	if (_energy <= 0) {
		std::cout << this->getName() << " is out of energy points!\n";
		return (1);
	}
	if (_hp <= 0) {
		std::cout << getName() << " has no hp left!\n";
		return (1);
	}
	return (0);
}

void ClapTrap::attack(const std::string &target) {
	if (check()) return ;
	_energy -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > 0) {
		_hp -= amount;
		std::cout << "ClapTrap " << getName() << " took " << amount << " points of damage.\n";
	}
	if (_hp <= 0) {
		_hp = 0;
		_attack = 0;
		std::cout << "ClapTrap " << getName() << " died!\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (check()) return ;
	if (amount + _hp > 10)
		_hp = 10;
	else
		_hp += amount;
	_energy--;
	std::cout << "ClapTrap " << getName() << " repaired " << amount << " health points\n";
}

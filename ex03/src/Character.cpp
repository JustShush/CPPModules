#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Character::Character() {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << GREEN << "Character Default Constructor Called" << RESET << std::endl;
}

Character& Character::operator=(const Character &copy_a) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = copy_a.inventory[i];
	this->name = copy_a.name;
	std::cout << GREEN << "Character Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

Character::Character(const Character &copy) {
	*this = copy;
	std::cout << GREEN << "Character Copy Constructor Called" << RESET << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete(this->inventory[i]);
		this->inventory[i] = NULL;
	}
	std::cout << RED << "Character Destructor Called" << RESET << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << GREEN << "Character Name Constructor Called" << RESET << std::endl;
}

std::string const &Character::getName() const {
	return (this->name);
}

void	Character::equip(AMateria* m) {
	if (!m)
	{
		std::cout << "Invalid Materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			continue ;
		else
		{
			inventory[i] = m;
			std::cout << "Equiped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	if (!inventory[idx])
	{
		std::cout << "Empty Slot" << std::endl;
		return ;
	}
	std::cout << "Unequiped " << inventory[idx]->getType() << " in slot " << idx << std::endl;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	if (!inventory[idx])
	{
		std::cout << "Empty Slot" << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

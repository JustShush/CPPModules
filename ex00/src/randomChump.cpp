#include "../inc/Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie _zombie;

	_zombie._name = name;
	_zombie.announce();
}

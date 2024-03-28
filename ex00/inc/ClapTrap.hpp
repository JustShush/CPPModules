#ifndef FIXED_HPP
# define FIXED_HPP

# include "./header.hpp"

#include <iostream>

class	ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_attack;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
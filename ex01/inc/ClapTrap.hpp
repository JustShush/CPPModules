#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "./header.hpp"

#include <iostream>

class	ClapTrap
{
	protected:
		std::string		_name;
		int	_hp;
		int	_energy;
		int	_attack;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		// Getters
		void			getStats();
		std::string		getName();
		int				getHp();
		int				getEnergy();
		int				getAttack();

		int		check(void);
		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
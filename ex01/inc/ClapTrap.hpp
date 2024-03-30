#ifndef FIXED_HPP
# define FIXED_HPP

# include "./header.hpp"

#include <iostream>

class	ClapTrap
{
	private:
		std::string		_name;
		int	_hp;
		int	_energy;
		int	_attack;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		// Getters | Setters
		void			getStats();
		std::string		getName();
		int				getHp();
		int				getEnergy();
		int				getAttack();
		void			setHp(unsigned int amount);
		void			setEnergy(unsigned int amount);
		void			setAttack(unsigned int amount);

		/**
		 * Just Checks if the player can attack or not
		 * @returns true if the player cant attack
		*/
		int		check(void);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
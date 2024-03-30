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

		// Getters | Setters
		std::string	getName();
		int			getHp();
		int			getEnergy();
		int			getAttack();
		void		getStats(); // just gets all the stats in just one function.
		void		setName(std::string name);
		void		setHp(unsigned int hp);
		void		setEnergy(unsigned int energy);
		void		setAttack(unsigned int attack);

		int		check();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
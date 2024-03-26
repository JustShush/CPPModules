#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "header.hpp"
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon &_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
		void	setWeapon(Weapon weapon);
};

#endif
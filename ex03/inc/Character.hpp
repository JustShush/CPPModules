#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./header.hpp"

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *inventory[4];
		std::string name;

	public:
		/* ++ Orthodox Canonical Form ++ */
		Character();
		Character(std::string name);
		~Character();
		Character& operator=(const Character &copy_a);
		Character(const Character &copy);
		/* ++ Orthodox Canonical Form ++ */

		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

};

#endif
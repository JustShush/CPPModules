#ifndef ICE_HPP
# define ICE_HPP

# include "./header.hpp"

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice& operator=(const Ice &copy_a);
		Ice(const Ice &copy);

		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif
#ifndef CURE_HPP
# define CURE_HPP

# include "./header.hpp"

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure& operator=(const Cure &copy_a);
		Cure(const Cure &copy);

		void use(ICharacter& target);
		virtual AMateria* clone() const;

};

#endif
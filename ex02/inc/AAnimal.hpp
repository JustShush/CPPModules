#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "./header.hpp"

#include <iostream>

class	AAnimal
{
	protected:
		std::string	type;

	public:
		/* ++ Orthodox Canonical Form ++ */
		AAnimal();
		AAnimal(const AAnimal &_copy);
		virtual ~AAnimal();
		AAnimal&	operator=(const AAnimal &_copy);
		/* ++ Orthodox Canonical Form ++ */

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		void			setType(std::string type);

};

#endif
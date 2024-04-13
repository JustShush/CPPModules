#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "./header.hpp"

#include <iostream>

class	Animal
{
	protected:
		std::string	type;

	public:
		/* ++ Orthodox Canonical Form ++ */
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal&	operator=(const Animal &t);
		/* ++ Orthodox Canonical Form ++ */

		Animal(std::string type);
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		void	setType(std::string type);

};

#endif
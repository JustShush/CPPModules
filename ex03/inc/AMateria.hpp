#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "./header.hpp"

# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		/* ++ Orthodox Canonical Form ++ */
		AMateria();
		AMateria(const AMateria &copy);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		AMateria(std::string const &type);

		std::string const &getType() const; //Returns the materia type
		void	setType(std::string const &type);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
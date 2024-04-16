#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "./header.hpp"

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource &copy_a);
		MateriaSource(const MateriaSource &copy);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
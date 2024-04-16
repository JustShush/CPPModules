#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "./header.hpp"

# include <iostream>
# include <string>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		/* ++ Orthodox Canonical Form ++ */
		Brain();
		Brain(const Brain &_copy);
		~Brain();
		Brain&	operator=(const Brain &t);
		/* ++ Orthodox Canonical Form ++ */

		void	setIdeas(char idea);
		void	printIdea(std::string Owner);

};

#endif
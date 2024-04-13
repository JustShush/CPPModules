#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "./header.hpp"

#include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		/* ++ Orthodox Canonical Form ++ */
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain&	operator=(const Brain &t);
		/* ++ Orthodox Canonical Form ++ */

		void setIdeas(char idea);
		void getIdea(std::string Owner);

};

#endif
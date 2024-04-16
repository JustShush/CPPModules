#include "../inc/Brain.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Brain::Brain()
{
	std::cout << GREEN << "Brain Default Constructor Called" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain &copy_a)
{
	std::cout << GREEN << "Brain Copy Assignment Operator Called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy_a.ideas[i];
	return (*this);
}

Brain::Brain(const Brain &copy)
{
	std::cout << GREEN << "Brain Copy Constructor Called" << RESET << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << RED << "Brain Destructor Called" << RESET << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	Brain::setIdeas(char c)
{
	if (isalpha(c))
	{
		for (int i = 0; i < 100; i++)
		{
			for (int alpha = 0; alpha < 26 && i < 100; alpha++)
			{
				this->ideas[i] = 'a' + alpha;
				i++;
			}
			i--;
		}
	}
	else if (isdigit(c))
	{
		for (int i = 0; i < 100; i++)
		{
			for (int dig = 0; dig < 10 && i < 100; dig++)
			{
				this->ideas[i] = 48 + dig;
				i++;
			}
			i--;
		}
	}
}

void	Brain::printIdea(std::string Owner)
{
	std::cout << Owner << "'s Ideas = {";
	for (int i = 0; i < 100; i++)
		std::cout << this->ideas[i] << ", ";
	std::cout << "}" << std::endl;
}
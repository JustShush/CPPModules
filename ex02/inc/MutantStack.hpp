#ifndef MUTANT_HPP
# define MUTANT_HPP

# include "header.hpp"

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack <T, std::deque<T> > {
public:
	typedef typename std::deque<T>::iterator itM;

	/* ++ Orthodox Canonical Form ++ */
	MutantStack();
	MutantStack(const MutantStack<T> &copy);
	MutantStack<T>& operator=(const MutantStack<T> &copy_a);
	~MutantStack();
	/* ++ Orthodox Canonical Form ++ */

	itM begin();
	itM end();
};

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
template <typename T> MutantStack<T>::MutantStack() {
	std::cout << BGREEN << "MutantStack Default Constructor called" << RESET << std::endl;
}

template <typename T> MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {
	std::cout << BGREEN << "MutantStack Copy Constructor called" << RESET << std::endl;
}

template <typename T> MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &copy_a) {
	std::stack<T>::operator=(copy_a);
	std::cout << BGREEN << "MutantStack Copy Assignment Operator called" << RESET << std::endl;
	return (*this);
}

template <typename T> MutantStack<T>::~MutantStack() {
	std::cout << BRED << "MutantStack Destructor called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

template <typename T> typename MutantStack<T>::itM MutantStack<T>::begin() {
	return (std::stack<T>::c.begin());
}

template <typename T> typename MutantStack<T>::itM MutantStack<T>::end() {
	return (std::stack<T>::c.end());
}

#endif
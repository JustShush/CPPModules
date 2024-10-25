#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "./header.hpp"

# include <iostream>
# include <stack>
# include <cstring>
# include <stdlib.h>
# include <sstream>

class Pmerge {
private:
	std::stack<int> _stack;
	int _numb;
	int _op;
public:
	/* ++ Orthodox Canonical Form ++ */
	Pmerge();
	Pmerge(const Pmerge &copy);
	Pmerge &operator=(const Pmerge &copy_a);
	~Pmerge();
	/* ++ Orthodox Canonical Form ++ */

};

#endif
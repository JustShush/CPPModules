#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "./header.hpp"

# include <iostream>
# include <algorithm>
# include <stdlib.h>
# include <vector>
# include <ctime>
# include <cstdlib>
# include <exception>
# include <list>

class Pmerge {
private:
	int numb;
	std::vector<u_int64_t> jacob;
	std::vector<std::pair<int, int> > vec;
	std::vector<int> sortedVec;
	std::list<int> sortedList;
public:
	/* ++ Orthodox Canonical Form ++ */
	Pmerge();
	Pmerge(const Pmerge &copy);
	Pmerge &operator=(const Pmerge &copy_a);
	~Pmerge();
	/* ++ Orthodox Canonical Form ++ */

	std::pair<int, int> makePair(int n1, int n2);

};

#endif
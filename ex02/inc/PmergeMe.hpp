#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "./header.hpp"

# include <iostream>
# include <algorithm>
# include <stdlib.h>
# include <string.h>
# include <vector>
# include <ctime>
# include <cstdlib>
# include <exception>
# include <list>

class PmergeMe {
private:
	int numb;
	std::vector<std::pair<int, int> > vec;
	std::vector<int> sortedVec;
	std::list<int> sortedList;
	std::vector<u_int64_t> JBSequence;
public:
	/* ++ Orthodox Canonical Form ++ */
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy_a);
	~PmergeMe();
	/* ++ Orthodox Canonical Form ++ */

	std::pair<int, int> makePair(int n1, int n2);
	/**
	 * Adds the Jacobsthal Sequence to a vector to use later.
	 */
	void populateJBSequence(void);

	void firstSortVector(int start);
	void pairToVetor(int argc, char *argv[]);


	void start(int argc, char *argv[]);


	/**
	 *  it inserts the first element of each pair
	 * into the sortedVector if the first element is not -1
	 */
	void insertFirst(std::vector<std::pair<int, int> > &vec);
	void FordJohnson(void);

};

#endif
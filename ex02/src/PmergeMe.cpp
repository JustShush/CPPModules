#include "../inc/PmergeMe.hpp"

std::pair<int, int>	Pmerge::makePair(int n1, int n2) {

	std::pair<int, int>	p;

	if (n1 <= n2) {
		p.first = n1;
		p.second = n2;
	} else {
		p.first = n2;
		p.second = n1;
	}
	return (p);
}
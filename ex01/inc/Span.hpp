#ifndef SPAN_HPP
# define SPAN_HPP

# include "header.hpp"

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>

class Span
{
private:
	unsigned int N;
	std::vector<int> vec;
public:
	/* ++ Orthodox Canonical Form ++ */
	Span();
	Span(const Span &copy);
	Span& operator=(const Span &copy_a);
	~Span();
	/* ++ Orthodox Canonical Form ++ */

	Span(unsigned int n);

	void addNumber(int i);
	int shortestSpan();
	int longestSpan();
	std::vector<int> &getArray();
	void printArray();
};

#endif
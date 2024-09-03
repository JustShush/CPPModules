#include "../inc/Span.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Span::Span() {
	std::cout << BGREEN << "Span Default Constructor called" << RESET << std::endl;
}

Span::Span(const Span &copy) {
	*this = copy;
	std::cout << BGREEN << "Span Copy Constructor called" << RESET << std::endl;
}

Span &Span::operator=(const Span &copy_a) {
	if (this != &copy_a) {
		vec = copy_a.vec;
		vec.reserve(copy_a.vec.capacity());
		N = copy_a.N;
	}
	std::cout << BGREEN << "Span Copy Assignment Operator called" << RESET << std::endl;
	return *this;
}

Span::~Span() {
	std::cout << BRED << "Span Destructor called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

Span::Span(unsigned int n) {
	N = n;
	vec.reserve(n);
	std::cout << ORANGE << "Span Size Constructor called" << RESET << std::endl;
}

void Span::addNumber(int i) {
	if (vec.size() >= vec.capacity())
		throw std::runtime_error("No free Space, The array is full!");
	vec.push_back(i);
}

int Span::shortestSpan() {
	if (vec.size() < 2) {
		std::cout << RED << "Can't!" << RESET << std::endl;
		return -1;
	}

	std::vector<int> temp = vec;
	sort(temp.begin(), temp.end());

	int minSpan = abs(temp[1] - temp[0]);

	for (std::vector<int>::iterator it = temp.begin() + 1; it != temp.end() - 1; ++it) {
		int span = abs(*(it + 1) - *it);
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (vec.size() < 2) {
		std::cout << RED << "Can't!" << RESET << std::endl;
		return -1;
	}

	std::vector<int> temp = vec;
	sort(temp.begin(), temp.end());

	int maxSpan = abs(temp.back() - temp.front());
	return maxSpan;
}

std::vector<int> &Span::getArray() {
	return vec;
}

void	Span::printArray() {
	std::vector<int>::iterator it;
	std::cout << YELLOW << "Array: ";
	for (it = vec.begin(); it < vec.end() - 1; it++)
		std::cout << *it << ", ";
	std::cout << *it << RESET << std::endl;
}
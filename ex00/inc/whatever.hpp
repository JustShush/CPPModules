#ifndef WHATEVER_H
# define WHATEVER_H

# include "./header.hpp"

# include <iostream>

template <typename T> void swap(T &a, T &b) {
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T> T min(T a ,T b) {
	return ((a <= b) ? ((a < b) ? a : b) : b);
}

template <typename T> T max(T a, T b) {
	return ((a >= b) ? ((a > b) ? a : b) : b);
}

#endif
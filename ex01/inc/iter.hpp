#ifndef ITER_H
# define ITER_H

# include "./header.hpp"

# include <iostream>

template <typename T, typename F> void iter(T array[], int len, F func) {
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template <typename T> void myPrint(const T& value) {
	std::cout << value << std::endl;
}

#endif
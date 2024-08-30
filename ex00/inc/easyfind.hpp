#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "header.hpp"

# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>
# include <vector>

class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return "Element not found in the container";
	}
};

template<typename T> typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it != container.end()) {
		return it;
	}

	throw NotFoundException();
}

#endif
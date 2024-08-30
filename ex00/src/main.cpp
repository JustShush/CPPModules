#include "../inc/easyfind.hpp"

int main() {

	std::vector<int> vec;

	for (int i = 0; i < 5; i++)
		vec.push_back(i);

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << GREEN << "Element found at position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
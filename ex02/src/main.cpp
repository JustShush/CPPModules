#include "../inc/PmergeMe.hpp"

bool same(int argc, char *argv[]) {

}

bool checkNumb(char *str) {

}

bool checks(int argc, char *argv[]) {

	int i = 1;
	bool sorted = false;

	if (same(argc, argv))
		throw std::runtime_error(std::string(URED) + "ERROR: Repeating numbers!!!!" + std::string(RESET));
	while (i < argc) {
		if (checkNumb(argv[i]))
			throw std::runtime_error(std::string(URED) + "ERROR: Invalid Number!" + std::string(RESET)); // std::string(argv[i])
		if (i + 1 < argc && atoi(argv[i]) > atoi(argv[i + 1]))
			sorted = true;
		i++;
	}
	if (!sorted)
		throw std::runtime_error(std::string(URED) + "ERROR: Already Sorted!" + std::string(RESET));
	return false;
}

int main(int argc, char *argv[])  {

	if (argc <= 1) {
		std::cerr << BRED << "ERROR:" << URED << "Invalid input!" << std::endl;
		std::cerr << ORANGE << "Usage: ./PmergeMe \"<numbers>\"" << RESET << std::endl;
		return 1;
	}
	try {
		checks(argc, argv);
	} catch(const std::exception& e) {
		std::cerr << RED << 'ERROR:' << e.what() << RESET << '\n';
		return 1;
	}

	return 0;
}
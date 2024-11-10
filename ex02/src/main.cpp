#include "../inc/PmergeMe.hpp"

bool same(int argc, char *argv[]) {

	for (int i = 1; i < argc; i++)
		for (int j = i + 1; j < argc; j++)
			if (std::string(argv[j]) == std::string(argv[i]))
				return true;
	return false;
}

bool checkNumb(char *str) {

	if (!str || !*str || atoi(str) < 0)
		return false;
	if (*str == '+' && strlen(str) > 1)
		str++;
	while (*str) {
		if (!isdigit(*str))
			return false;
		str++;
	}
	return true;
}

bool is_sorted(int argc, char *argv[]) {
	for(int i = 1; i < argc - 1; i++) {
		int current = atoi(argv[i]);
		int next = atoi(argv[i + 1]);

		if (current > next)
			return false;
	}
	return true;
}

bool checks(int argc, char *argv[]) {

	int i = 1;

	if (same(argc, argv))
		throw std::runtime_error(std::string(URED) + "Repeating numbers!!!!" + std::string(RESET));
	while (i < argc) {
		if (!checkNumb(argv[i]))
			throw std::runtime_error(std::string(URED) + "Invalid Number!" + std::string(RESET)); // std::string(argv[i])
		i++;
	}
	if (is_sorted(argc, argv))
		throw std::runtime_error(std::string(URED) + "Already Sorted!" + std::string(RESET));
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
		std::cerr << RED << "ERROR:" << e.what() << RESET << '\n';
		return 1;
	}

	PmergeMe me;

	me.start(argc, argv);

	return 0;
}
#include "../inc/RPN.hpp"

int	main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cerr << ON_RED << "ERROR: Missing Arguments!" << RESET << std::endl;
		std::cerr << ORANGE << "Usage: ./RPN <args>" << RESET << std::endl;
		return -1;
	}
	if (argv[1] == NULL || argv[1][0] == '\0') {
		std::cerr << URED << "ERROR: Invalid args! Can\'t be an empty string!" << RESET << std::endl;
		return -1;
	}

	RPN	rpn;
	std::string	str = argv[1];

	rpn.start(str);
	return 0;
}
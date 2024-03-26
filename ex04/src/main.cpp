#include "../inc/Replacer.h"

int	main(int argc, char *argv[]) {

	if (argc <= 4) {
		std::cout << "Invalid number of args\n";
		return (-1);
	}

	replace(argv[1], argv[2], argv[3]);

	return (0);
}

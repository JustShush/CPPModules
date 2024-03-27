#include "../inc/Harl.hpp"

int	main(int argc, char *argv[]) {

	Harl	object;
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments!" << std::endl;
		return (1);
	}
	object.complain(argv[1]);
	return (0);
}
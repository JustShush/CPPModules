#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::string tmp;
	while (1) {
		std::cin >> tmp;
		if (tmp == "1")
			break;
	}
	return (0);
}


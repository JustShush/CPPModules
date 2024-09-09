#include "../inc/array.hpp"
#include <cstdlib>
#include <ctime>

int	main(void) {
	{
		// Default constructor test
		Array<int> arr;
		std::cout << "Size of the arr: " << arr.size() << std::endl;
	}
	{
		Array<int> arr(0);
		std::cout << ORANGE;
		arr.Print();
		std::cout << RESET << std::endl;
	}
	{
		int size = 5;
		Array<int> arr(size);
		// Seed the random number generator with the current time
		srand(static_cast<unsigned>(time(0)));
		for (int i = 0; i < arr.size(); i++)
			arr[i] = rand() % 100;
		std::cout << ORANGE;
		arr.Print();
		std::cout << RESET;

		try {
			arr[-1] = 42;
			arr[size + 1] = 42;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
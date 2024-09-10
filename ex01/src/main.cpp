#include "../inc/Serializer.hpp"

int	main() {
	Data data;
	uintptr_t ptr;

	data.i = 42;
	data.str = "Forty Two";

	std::cout << "Data address: " << ORANGE << &data << RESET << std::endl;
	std::cout << "uint_ptr address: " << PURPLE << &ptr << RESET << "\n\n";

	ptr = Serializer::serialize(&data);

	std::cout << "Data.i: " << data.i << std::endl;
	std::cout << "Data.str: " << data.str << std::endl;
	std::cout << "Data address: " << ORANGE << &data << RESET << std::endl;
	std::cout << "uint_ptr address: " << PURPLE << &ptr <<  RESET <<"\n\n";

	Data *data2;

	data2 = Serializer::deserialize(ptr);

	std::cout << "Data2->i: " << data2->i << std::endl;
	std::cout << "Data2->str: " << data2->str << std::endl;
	std::cout << "Data2 address: " << ORANGE << &data2 << RESET << std::endl;
	std::cout << "uint_ptr address: " << PURPLE << &ptr << RESET << std::endl;

	return 0;
}
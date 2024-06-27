#include "../inc/Serializer.hpp"

int	main(void)
{
	Data data;
	uintptr_t ptr;

	data.i = 42;
	data.str = "Forty Two";

	std::cout << "Data address: " << &data << "\n";
	std::cout << "uint_ptr address: " << &ptr << "\n\n";

	ptr = Serializer::serialize(&data);

	std::cout << "Data.i: " << data.i << "\n";
	std::cout << "Data.str: " << data.str << "\n";
	std::cout << "Data address: " << &data << "\n";
	std::cout << "uint_ptr address: " << &ptr << "\n\n";

	Data *data2;

	data2 = Serializer::deserialize(ptr);

	std::cout << "Data2->i: " << data2->i << "\n";
	std::cout << "Data2->str: " << data2->str << "\n";
	std::cout << "Data2 address: " << &data2 << "\n";
	std::cout << "uint_ptr address: " << &ptr << "\n";

	return 0;
}
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "./header.hpp"

# include <iostream>
# include <inttypes.h>

typedef struct Data {
	std::string str;
	int i;
} data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer& operator=(const Serializer &copy_a);
		~Serializer();

	public:
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};

#endif
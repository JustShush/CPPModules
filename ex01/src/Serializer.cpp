#include "../inc/Serializer.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Serializer::Serializer() {
	std::cout << GREEN << "Serializer Default Constructor Called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
	*this = copy;
	std::cout << GREEN << "Serializer Copy Constructor Called" << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer &copy_a) {
	(void)copy_a;
	std::cout << GREEN << "Serializer Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

Serializer::~Serializer() {
	std::cout << RED << "Serializer Destructor Called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

uintptr_t Serializer::serialize(Data* ptr) {
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return(reinterpret_cast<Data*>(raw));
}
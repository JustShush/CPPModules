#include "../inc/Base.hpp"

Base* generate(void) {
	int random = std::rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

// Identify type using pointer
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Ptr: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Ptr: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Ptr: C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

// Identify type using reference (without using a pointer inside the function)
void identify(Base& p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "Ref: A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "Ref: B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "Ref: C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base* randomInstance = generate();

	// Identify the type using pointer
	identify(randomInstance);

	// Identify the type using reference
	identify(*randomInstance);

	delete randomInstance;

	return 0;
}

#include "../inc/Base.hpp"

Base *generate(void) {
	int random;

	srand((unsigned) time(NULL));
	random = rand() % 3;

	switch (random) {
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Ptr: A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "Ptr: B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "Ptr: C\n";
}

//Pointers are forbidden
void identify(Base& p) {
	A a;
	B b;
	C c;

	try {
		a = dynamic_cast<A&>(p);
		std::cout << "Ref: A\n";
	}
	catch(const std::exception& e) {
		try {
			b = dynamic_cast<B&>(p);
			std::cout << "Ref: B\n";
		}
		catch(const std::exception& e) {
			try {
				c = dynamic_cast<C&>(p);
				std::cout << "Ref: C\n";
			}
			catch(const std::exception& e) {
				return ;
			}
		}
	}
}

int main(void) {
	Base *p;

	p = generate();
	identify(p);
	identify(*p);
	delete p;

	return 0;
}
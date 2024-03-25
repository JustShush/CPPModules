#include <iostream>

int	main() {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "String " << &str << std::endl;
	std::cout << "PTR " << &stringPTR << std::endl;
	std::cout << "REF " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String Value: " << str << std::endl;
	std::cout << "PTR Value: " << stringPTR << std::endl;
	std::cout << "REF Value: " << stringREF << std::endl;

	return (0);
}
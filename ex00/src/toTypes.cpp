#include "../inc/ScalarConverter.hpp"

void	ScalarConverter::toInt(ScalarConverter &conv, std::string str) {
	int i = std::atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	try {
		conv.checkImpossible(std::atof(str.c_str()));
		conv.checkIsPrint(i);
	} catch(const ImpossibleException& e) {
		printException2(e.what());
		return;
	} catch(const NonDisplayableException& e) {
		printException(i, f, d, e.what());
		return ;
	}
	printIntChar(i, c, f, d);
	return ;
}

void	ScalarConverter::toChar(ScalarConverter &conv, std::string str) {
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	try {
		conv.checkIsPrint(c);
	} catch(const std::exception& e) {
		printException(i, f, d, e.what());
		return ;
	}
	printIntChar(i, c, f, d);
	return ;
}

void	ScalarConverter::toFloat(ScalarConverter &conv, std::string str) {
	float f = std::atof(str.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	size_t decimal = str.length() - str.find_first_of(".") - 2;

	try {
		conv.checkImpossible(std::atof(str.c_str()));
		conv.checkIsPrint(c);
	} catch(const ImpossibleException& e) {
		printException2(e.what());
		return ;
	} catch(const NonDisplayableException& e) {
		std::cout << "char: " << e.what() << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
		std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << std::endl;
		return ;
	}
	printFloatDouble(i, c, f, d, decimal);
	return ;
}
 
void	ScalarConverter::toDouble(ScalarConverter &conv, std::string str) {
	double d = std::atof(str.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	size_t	decimal = str.length() - str.find_first_of(".") - 1;

	try {
		conv.checkImpossible(d);
		conv.checkIsPrint(d);
	} catch(const ImpossibleException& e) {
		printException2(e.what());
		return ;
	} catch(const NonDisplayableException& e) {
		std::cout << "char: " << e.what() << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
		std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << std::endl;
		return ;
	}
	printFloatDouble(i, c, f, d, decimal);
	return ;
}
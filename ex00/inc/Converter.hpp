#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include "./header.hpp"

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <string>
# include <iomanip>

class Converter
{
	private:
		/* ++ Orthodox Canonical Form ++ */
		Converter();
		~Converter();

	public:
		Converter(const Converter &copy);
		Converter& operator=(const Converter &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		static void Convert(std::string str);
		static void checkType(std::string str);
		static void handlePseudo(std::string str);
		static void Pseudo(std::string str);
		static void toDouble(Converter &conv, std::string str);
		static void toFloat(Converter &conv, std::string str);
		static void toInt(Converter &conv, std::string str);
		static void toChar(Converter &conv, std::string str);
		static void checkIsPrint(int i);
		static void checkImpossible(double d);

		/* -- Exceptions -- */
		class	NonDisplayableException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class	ImpossibleException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class	InvalidTypeException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		/* -- Exceptions -- */

};

// Adicional functions
void printException(int i, float f, double d, const char *e);
void printException2(const char *e);
void printIntChar(int i, char c, float f, double d);
void printFloatDouble(int i, char c, float f, double d, size_t decimal);

#endif


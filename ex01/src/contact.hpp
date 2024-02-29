#ifndef CONTACT_H
# define CONTACT_H

# include "header.hpp"

# include <iostream>
# include <iomanip>		// std::setw
# include <stdlib.h>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNbr;
		std::string darkS;
	public:
		Contact();
		~Contact();
		Contact add(void);
		std::string input_field(std::string str);
		std::string get_field(int i);
		int s_isdigit(std::string str);
};

#endif
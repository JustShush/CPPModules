#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		int phoneNbr;
		std::string darkS;
	public:
		Contact();
		~Contact();
};

#endif
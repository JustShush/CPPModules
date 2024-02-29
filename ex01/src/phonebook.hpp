#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		PhoneBook();
		~PhoneBook();
};

#endif
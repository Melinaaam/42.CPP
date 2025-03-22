#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include<string>
#include<sstream>
#include <iomanip>  // Pour std::setw et std::right
#include "Contact.hpp"

class PhoneBook
{
	public :
	PhoneBook(void);

	Contact Phone_Book[8];

	void CreateContact();
	void afficherContact(int i) const;
	void searchContact();
	void DisplayPhonebook();

	private :
	Contact m_contact;
	int	count;
	int new_count;
};

#endif

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include<string>
#include<sstream>
#include <iomanip>  // Pour std::setw et std::right
#include "Contact.hpp"

/*Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.*/

    //Représente le répertoire.
    //Contient un tableau de contacts.
    //Peut enregistrer 8 contacts maximum.
    //Si l’utilisateur tente d’ajouter un 9ème
    //contact, remplacez le plus ancien par celui-ci.
    //Notez que l’allocation dynamique est interdite

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

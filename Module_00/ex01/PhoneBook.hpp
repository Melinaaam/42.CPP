#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include<string>
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

	Contact all_contacts[8];

	void CreateContact();
	void afficherContact() const;

	private :
	Contact m_contact;
};

#endif

#include "PhoneBook.hpp"
#include "Contact.hpp"

/*Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.*/

PhoneBook::PhoneBook(void)
{

	for (int i = 0; i < 8; i++)
	{
		CreateContact();
	}

	afficherContact();
	return;
}

void    PhoneBook::afficherContact() const
{
	std::cout << "FIRST CONTACT: " << std::endl;
	m_contact.afficher();
}

void    PhoneBook::CreateContact()
{
	m_contact.Create();
}

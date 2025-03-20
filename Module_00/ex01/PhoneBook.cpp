#include "PhoneBook.hpp"
#include "Contact.hpp"

/*Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.*/

PhoneBook::PhoneBook(void)
{
	std::cout << "Entrez un contact :" << std::endl;

	Contact contact;
	// std::cout << "one contact : " << one_contact.FirstName << std::endl;

	return;
}

void    PhoneBook::afficherContact() const
{
    std::cout << "FIRST CONTACT: " << std::endl;
    m_contact.afficher();
}

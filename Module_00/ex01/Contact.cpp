#include "Contact.hpp"
/*Représente un contact dans le répertoire.*/
Contact::Contact(void)
{
    //Représente un contact dans le répertoire
    // first name (prénom)
    //last name (nom de famille)
    //nickname (surnom)
    //phone number (numéro de téléphone)
    //darkest secret (son plus lourd secret)

	//creer save

	std::cout << "Enter first name : " << std::endl;
	std::cin >> FirstName;
	//sauve le first name etc...
	std::cout << "first name  is : " << FirstName << std::endl;
	return;
};
void Contact::afficher() const
{
	std::cout << FirstName << std::endl;
}
//ft qui cree le contact et qui le sauvegarde

#include "Contact.hpp"
/*Représente un contact dans le répertoire.*/
    //Représente un contact dans le répertoire
    // first name (prénom)
    //last name (nom de famille)
    //nickname (surnom)
    //phone number (numéro de téléphone)
    //darkest secret (son plus lourd secret)
Contact::Contact(void)
{
	Create();
	return;
};
void Contact::afficher() const
{
	std::cout << FirstName << std::endl;
	std::cout << LastName << std::endl;
	std::cout << NickName << std::endl;
	std::cout << PhoneNumber << std::endl;
	std::cout << Secret << std::endl;
}

void Contact::Create()
{
	std::cout << "Enter first name : " << std::endl;
	std::cin >> FirstName;
	//sauve le first name etc...

	std::cout << "Enter last name : " << std::endl;
	std::cin >> LastName;

	std::cout << "Enter nick name : " << std::endl;
	std::cin >> NickName;

	std::cout << "Enter phone number : " << std::endl;
	std::cin >> PhoneNumber;

	std::cout << "darkest secret : " << std::endl;
	std::cin >> Secret;

	std::cout << "contact creer " << std::endl;
}

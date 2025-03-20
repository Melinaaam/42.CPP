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
//ft qui cree le contact et qui le sauvegarde
void Contact::Create()
{
	std::cout << "Enter first name : " << std::endl;
	std::cin >> FirstName;
	//sauve le first name etc...
	// std::cout << "first name  is : " << FirstName << std::endl;

	std::cout << "Enter last name : " << std::endl;
	std::cin >> LastName;
	// std::cout << "Last name  is : " << LastName << std::endl;

	std::cout << "Enter nick name : " << std::endl;
	std::cin >> NickName;
	// std::cout << "Nick name  is : " << NickName << std::endl;

	std::cout << "Enter phone number : " << std::endl;
	std::cin >> PhoneNumber;
	// std::cout << "PhoneNumber  is : " << PhoneNumber << std::endl;

	std::cout << "darkest secret : " << std::endl;
	std::cin >> Secret;
	// std::cout << "darkest secret  is : " << Secret << std::endl;
}

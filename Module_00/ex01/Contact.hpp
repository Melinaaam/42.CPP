#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include<string>

/*Représente un contact dans le répertoire.*/
	//Représente un contact dans le répertoire
    // first name (prénom)
    //last name (nom de famille)
    //nickname (surnom)
    //phone number (numéro de téléphone)
    //darkest secret (son plus lourd secret)
class Contact
{
	public:
	//constructeur
	Contact(void);
	void Create();

	std::string FirstName;
	std::string LastName;
	std::string NickName;
	int PhoneNumber;
	std::string Secret;
	
	void afficher() const;
};

#endif

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
};

void Contact::Create_First_Name()
{
	std::cout << "Enter first name : " << std::endl;
    std::getline(std::cin, FirstName);
}
void Contact::Create_Last_Name()
{
	std::cout << "Enter last name : " << std::endl;
    std::getline(std::cin, LastName);
}
void Contact::Create_Nick_Name()
{
	std::cout << "Enter nick name : " << std::endl;
    std::getline(std::cin, NickName);
}
void Contact::Create_Phone_Number()
{
	std::cout << "Enter phone number : " << std::endl;
    std::getline(std::cin, PhoneNumber);
}
void Contact::Create_Darkest_Secret()
{
	std::cout << "Enter your darkest secret : " << std::endl;
    std::getline(std::cin, Secret);
}

void Contact::Create_One_Contact()//manque getion multiple espaces et tabs
{
	do {
		Create_First_Name();
		if (FirstName.empty())
            std::cout << "First Name can't be empty. Please retry." << std::endl;
	}while (FirstName.empty());

	do {
		Create_Last_Name();
		if (LastName.empty())
			std::cout << "Last Name can't be empty. Please retry." << std::endl;
	}while(LastName.empty());

	do{
		Create_Nick_Name();
		if (NickName.empty())
			std::cout << "Nick Name can't be empty. Please retry." << std::endl;
	}while(NickName.empty());

	do{
		Create_Phone_Number();
		if (PhoneNumber.empty())
			std::cout << "Phone Number can't be empty. Please retry." << std::endl;
	}while(PhoneNumber.empty());

	do{
		Create_Darkest_Secret();
		if (Secret.empty())
			std::cout << "Your darkest secret can't be empty. Please retry." << std::endl;
	}while(Secret.empty());
}


/*****************AFFICHER******************* */
std::string Contact::getFirstName() const
{
	return FirstName;
}

std::string Contact::getLastName() const
{
	return LastName;
}

std::string Contact::getNickName() const{
	return NickName;
}

std::string	Contact::getPhoneNumber() const{
	return PhoneNumber;
}

std::string Contact::getSecret() const{
	return Secret;
}
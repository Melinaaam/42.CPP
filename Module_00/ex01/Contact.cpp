#include "Contact.hpp"

Contact::Contact(void)
{
	return;
};

bool	is_just_space(const std::string &str)
{
	for(std::string::const_iterator i = str.begin(); i != str.end(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(*i)))
				return false;
	}
	return true;
}

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

void Contact::Create_One_Contact()
{
	do {
		Create_First_Name();
		if (FirstName.empty() || is_just_space(FirstName))
			std::cout << "First Name can't be empty. Please retry." << std::endl;
	}while (FirstName.empty() || is_just_space(FirstName));

	do {
		Create_Last_Name();
		if (LastName.empty() || is_just_space(LastName))
			std::cout << "Last Name can't be empty. Please retry." << std::endl;
	}while(LastName.empty() || is_just_space(LastName));

	do{
		Create_Nick_Name();
		if (NickName.empty() || is_just_space(NickName))
			std::cout << "Nick Name can't be empty. Please retry." << std::endl;
	}while(NickName.empty() || is_just_space(NickName));

	do{
		Create_Phone_Number();
		if (PhoneNumber.empty() || is_just_space(PhoneNumber))
			std::cout << "Phone Number can't be empty. Please retry." << std::endl;
	}while(PhoneNumber.empty() || is_just_space(PhoneNumber));

	do{
		Create_Darkest_Secret();
		if (Secret.empty() || is_just_space(Secret))
			std::cout << "Your darkest secret can't be empty. Please retry." << std::endl;
	}while(Secret.empty() || is_just_space(Secret));
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

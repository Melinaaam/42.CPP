#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	count = 0;
	new_count = 0;
	return;
}
void	PhoneBook::CreateContact()
{
	Phone_Book[new_count].Create_One_Contact();

	if(count < 8)
		count ++;
	new_count = (new_count + 1) % 8;
}
std::string SearchFormat(const std::string &str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + ".";
	else{
		std::stringstream ss;
		ss << std::right << std::setw(10) << str;
		return ss.str();
	}
}

void PhoneBook::DisplayPhonebook()
{
	std::cout << "|**********|**********|**********|**********|" << std::endl;
	std::cout << "|"
		<< "   Index  "
		<< "|" << SearchFormat("First name")
		<< "|" << SearchFormat("Last name")
		<< "|" << SearchFormat("Nick name") << "|" << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::stringstream string;
		string << i;
		std::string indexStr = string.str();
		std::cout << "|" << SearchFormat(indexStr)
				<< "|" << SearchFormat(Phone_Book[i].getFirstName())
				<< "|" << SearchFormat(Phone_Book[i].getLastName())
				<< "|" << SearchFormat(Phone_Book[i].getNickName()) << "|" << std::endl;
	}
	std::cout << "|**********|**********|**********|**********|" << std::endl;
}

void PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "The PhoneBook is empty" << std::endl;
		return;
	}
	DisplayPhonebook();
	std::string answer;
	std::cout << "Wich contact do you want see?" << std::endl;
	std::getline(std::cin, answer);

	int num_contact;
	std::istringstream iss(answer);
	iss >> num_contact;
	std::cout << "You choose contact nb : " << num_contact << std::endl;
	afficherContact(num_contact);
}
/*****************AFFICHER******************* */
void    PhoneBook::afficherContact(int i) const
{
	if (i < 0 || i >= 8){
		std::cout << "Invalide i" << std::endl;
		return;
	}
	std::cout << "First name : " << Phone_Book[i].getFirstName() << std::endl;
	std::cout << "Lastname : " << Phone_Book[i].getLastName() << std::endl;
	std::cout << "Nick name : " << Phone_Book[i].getNickName() << std::endl;
	std::cout << "Phone number : " << Phone_Book[i].getPhoneNumber() << std::endl;
	std::cout << "Darck secret : " << Phone_Book[i].getSecret() << std::endl;
}

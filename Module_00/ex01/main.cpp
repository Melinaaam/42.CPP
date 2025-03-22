#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string answer;
	while(true)
	{
		std::cout << "Type ADD, SEARCH or EXIT : " << std::endl;
		std::getline(std::cin, answer);
		if (answer == "ADD")
		{
			phonebook.CreateContact();
		}
		else if (answer == "SEARCH")
		{
			phonebook.searchContact();
		}
		else if (answer == "EXIT")
		{
			std::cout << "GoodBye !" << std::endl;
			// std::getline(std::cin, answer);
			return 1;
		}
	}
	return 0;
}


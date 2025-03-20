#include "PhoneBook.hpp"

// struct args
// {
//     if ()
// }

int main()
{
	std::string answer;
	while(answer != "ADD" || answer != "SEARCH" || answer != "EXIT")
	{
		std::cout << "Type ADD, SEARCH or EXIT : " << std::endl;
		std::cin >> answer;
		if (answer == "ADD")
		{
			// std::cout << "Ok your answer is ADD" << std::endl;
			PhoneBook Phonebook;
			return 1;
		}
		else if (answer == "SEARCH")
		{
			// std::cout << "Ok your answer is SEARCH" << std::endl;
			return 1;
		}
		else if (answer == "EXIT")
		{
			// std::cout << "Ok your answer is EXIT" << std::endl;
			std::cout << "GoodBye !" << std::endl;
			return 1;
		}
	}
	return 0;
}


#include "PhoneBook.hpp"

/*1. Demander à l'utilisateur : "Quel contact voulez-vous modifier ? (0 à 7)"
2. Lire le nombre avec std::cin.
3. Vérifier que le nombre est entre 0 et 7.
4. Si oui, alors :
    - demander le nom
    - demander le numéro
    - stocker ces infos dans Phone_Book[index]
*/
int main()
{
	PhoneBook phonebook;
	std::string answer;
	while(true)
	{
		std::cout << "Type ADD, SEARCH or EXIT : " << std::endl;
		// std::cin >> answer;
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
			// std::cout << "GoodBye !" << std::endl;
			std::getline(std::cin, answer);
			return 1;
		}
	}
	return 0;
}


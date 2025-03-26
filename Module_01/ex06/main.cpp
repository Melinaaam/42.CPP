#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
		return 1;
	else
	{
		Harl harl;	
		std::string levelstr = av[1];
		int level = harl.GetStringLevel(levelstr);
			
		switch (level)
		{
			case 0 :
			harl.complain("DEBUG");
			break;

			case 1 :
			harl.complain("INFO");
			break;

			case 2 :
			harl.complain("WARNING");
			break;

			case 3 :
			harl.complain("ERROR");
			break;

			default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}

	}
    return 0;
}
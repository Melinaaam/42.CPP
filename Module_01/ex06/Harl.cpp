#include "Harl.hpp"

Harl::Harl(void)
{

}


void Harl::complain( std::string level )
{
    //declenche l'appel a l'une de ft prives
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    ptr functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Invalid level: " << level << std::endl;
}

int Harl::GetStringLevel(const std::string& str)
{
    if(str == "DEBUG") 
        return 0;
    if (str == "INFO") 
        return 1;
    if (str == "WARNING") 
        return 2;
    if (str == "ERROR") 
        return 3;
    return 4;
}

/*private*/
void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::~Harl(void)
{

}
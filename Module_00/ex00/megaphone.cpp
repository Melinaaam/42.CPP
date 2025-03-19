#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char *av[])
{
    if(ac > 1)
    {
        for(int i = 1; i < ac; i++)
       { 
            std::string argument = av[i];
            for (char &c : argument)
                c = std::toupper(c);
            std::cout << argument;
        }
        std::cout << std::endl;
    }
    else 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

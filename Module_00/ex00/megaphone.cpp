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
            for (std::size_t i = 0; i < argument.size(); ++i)
                argument[i] = std::toupper(argument[i]);
            std::cout << argument;
        }
        std::cout << std::endl;
    }
    else 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
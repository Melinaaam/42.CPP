#include"Ice.hpp"

Ice::Ice(void) : AMateria()
{
    _type = "ice";
    std::cout << MAGENTA << _type << " default constructor called !" << RESET << std::endl;
}

Ice::Ice(const Ice& copy): AMateria(copy)
{
    std::cout << MAGENTA << _type << " copy constructor called !" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
std::cout << MAGENTA << _type << " default constructor called !" << RESET << std::endl;
}

Ice::~Ice(void)
{
    std::cout << MAGENTA << _type << " destructor called !" << RESET << std::endl;
}

AMateria* Ice::clone() const
{

}

void Ice::use(ICharacter& target)
{
    std::cout << MAGENTA << "* shoots an ice bolt at " << RESET << "<name>" << std::endl;
    //<name> est le nom du Character (personnage) passé en paramètre.
}
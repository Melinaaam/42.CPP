#include"Cure.hpp"

Cure::Cure(void): AMateria(), ICharacter()
{
    _type = "cure";
    std::cout << MAGENTA << _type << " default constructor called !" << RESET << std::endl;
}

Cure::Cure(const Cure& copy): AMateria(copy), ICharacter(copy)
{
    _type = copy._type;
    std::cout << MAGENTA << _type << " copy constructor called !" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
	{
		AMateria::operator=(other);
        _type = other._type;
	}
    return *this;
}

Cure::~Cure(void)
{
    std::cout << MAGENTA << _type << " destructor called !" << RESET << std::endl;
}

AMateria* Cure::clone() const
{

}

void Cure::use(ICharacter& target)
{
    std::cout << MAGENTA << "* heals " << RESET << "<name>" << "’s wounds *" << std::endl;
    //<name> est le nom du Character (personnage) passé en paramètre.
}
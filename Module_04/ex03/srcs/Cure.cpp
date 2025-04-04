#include"Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
    std::cout << MAGENTA << _type << " default constructor called !" << RESET << std::endl;
}

Cure::Cure(const Cure& copy): AMateria(copy)
{
    std::cout << MAGENTA << _type << " copy constructor called !" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
		AMateria::operator=(other);
    return *this;
}

Cure::~Cure(void)
{
    std::cout << MAGENTA << _type << " destructor called !" << RESET << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << MAGENTA << "* heals " << RESET << target.getName() << "’s wounds *" << std::endl;
    //<name> est le nom du Character (personnage) passé en paramètre.
}

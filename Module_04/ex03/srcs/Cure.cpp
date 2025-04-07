#include"Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	// std::cout << MAGENTA << _type << " default constructor called !" << RESET << std::endl;
}

Cure::Cure(const Cure& copy): AMateria(copy)
{
	// std::cout << MAGENTA1 << _type << " copy constructor called !" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if(this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure(void)
{
	// std::cout << MAGENTA1 << _type << " destructor called !" << RESET << std::endl;
}

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << RESET << YELLOW << target.getName() << RESET << "’s wounds *" << RESET << std::endl;
}

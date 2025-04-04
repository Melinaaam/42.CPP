#include"AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << MAGENTA << "AMateria default constructor called !" << RESET << std::endl;

}
AMateria::AMateria(std::string const & type) : _type(type)
{

}
AMateria::AMateria(const AMateria& copy) : _type(copy._type)
{
    std::cout << MAGENTA << "AMateria copy constructor called !" << RESET << std::endl;
}
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria(void)
{
    std::cout << MAGENTA << "AMateria deconstructor called !" << RESET << std::endl;
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Using AMateria of type " << _type << " on " << target.getName() << std::endl;
}

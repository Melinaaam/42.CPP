#ifndef AM_ATERIA_HPP
#define AM_ATERIA_HPP
#include<string>
#include<iostream>
/*La class Animal est maintenant abstraite car makesound est defini  0
DONC on est oblige de les param dans les class filles*/
class AMateria
{
protected:

public:
    AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& other);
	~AMateria(void);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif

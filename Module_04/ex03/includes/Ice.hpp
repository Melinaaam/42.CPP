#ifndef ICE_HPP
#define ICE_HPP
#include"AMateria.hpp"
#include"ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice& copy);
	Ice& operator=(const Ice& other);
	~Ice(void);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif

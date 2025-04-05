#ifndef CURE_HPP
#define CURE_HPP
#include"AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure& copy);
	Cure& operator=(const Cure& other);
	virtual ~Cure(void);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif

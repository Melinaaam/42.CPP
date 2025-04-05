#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include<string>
#include<iostream>
#include"ICharacter.hpp"

class ICharacter;  // déclaration anticipée permet de reduire le temps de compilation
					// pour éviter la dépendance circulaire: 2 fichiers ou modules s'incluent mutuellement,direct ou indirectmt.
					//Ex: si A.hpp inclut B.hpp et que B.hpp inclut à son tour A.hpp ->boucle infinie d'inclusions.
class AMateria
{
protected:
	std::string _type;
public:
    AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria(void);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;5;220m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35;1m"
#define MAGENTA1 "\033[0;35;2m"
#define MAGENTA2 "\033[0;35;4m"
#define CYAN    "\033[38;5;45m"
#define PINK    "\033[38;5;213m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"
#define CLIGNOTE "\033[0;35;5m"

#endif

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<string>
#include<iostream>
/*La class Animal est maintenant abstraite car makesound est defini  0
DONC on est oblige de les param dans les class filles*/
class AAnimal
{
protected:
    std::string _type;
public:
    AAnimal(void);
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal(void);

    std::string getType() const;
    virtual void makeSound() const = 0; // Fonction virtuelle pure
};

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;5;220m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[38;5;45m"
#define PINK    "\033[38;5;213m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

#endif

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<string>
#include<iostream>
/*La class Animal est maintenant abstraite car makesound est defini  0
DONC on est oblige de les param dans les class filles*/
class Animal
{
protected:
    std::string _type;
public:
    Animal(void);
	Animal(const Animal& copy);
	Animal& operator=(const Animal& other);
	virtual ~Animal(void);

    std::string getType() const;
    virtual void makeSound() const = 0; // Fonction virtuelle pure
};

#endif

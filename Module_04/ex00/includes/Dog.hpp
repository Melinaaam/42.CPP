#ifndef DOG_HPP
#define DOG_HPP

#include"Animal.hpp"

class Dog : public Animal
{
    Dog(void);
    Dog(std::string name);
	Dog(const Dog& copy);
	Dog& operator=(const Dog& other);
    ~Dog(void);

    virtual void makeSound();
};

#endif
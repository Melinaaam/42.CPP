#ifndef DOG_HPP
#define DOG_HPP

#include"Animal.hpp"

class Dog : public Animal
{
public:
    Dog(void);
    Dog(std::string Type);
	Dog(const Dog& copy);
	Dog& operator=(const Dog& other);
    virtual ~Dog(void);

    virtual void makeSound() const;
};

#endif
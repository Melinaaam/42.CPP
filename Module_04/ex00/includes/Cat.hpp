#ifndef CAT_HPP
#define CAT_HPP

#include"Animal.hpp"

class Cat : public Animal
{
    Cat(void);
    Cat(std::string name);
	Cat(const Cat& copy);
	Cat& operator=(const Cat& other);
    ~Cat(void);

    virtual void makeSound();
};

#endif
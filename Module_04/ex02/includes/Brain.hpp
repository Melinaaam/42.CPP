#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<string>
#include<iostream>

class Brain
{
private:
    std::string _ideas[100];
public:
    Brain(void);
    Brain(const Brain& copy);
	Brain & operator=(const Brain& other);
    ~Brain();
};

#endif

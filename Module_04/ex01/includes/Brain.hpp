#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<string.h>
#include<iostream>

class Brain
{
public:
    Brain(void);
    Brain();
    Brain(const Brain& copy);
	Brain & operator=(const Brain& other);
    ~Brain();
    std::string ideas[100];
};

#endif
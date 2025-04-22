#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include<iostream>
#include<string>
#include <stdint.h>

struct Data
{
	int value;
	std::string name;
};

class Serializer 
{
public : 
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
private : 
    Serializer();
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#endif

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
#define UNDER_	"\x1b[4m"
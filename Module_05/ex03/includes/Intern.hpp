#ifndef INTERN_HPP
#define INTERN_HPP

#include"AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern&copy);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string nameForm, std::string targetForm) const;
};

#endif
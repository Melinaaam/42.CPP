#include "Intern.hpp"
#include"PresidentialPardonForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"

Intern::Intern(){ std::cout << CYAN << "Intern default constructor called" << RESET << std::endl;}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern& Intern::operator=(const Intern& other)
{ 
    (void) other;
    return *this;
}


Intern::~Intern(){std::cout << CYAN << "Intern deconstructor called" << RESET << std::endl;}

AForm *makeShrubberyForm(const std::string target) {
	return new ShrubberyCreationForm(target);}


AForm *makeRobotomyForm(const std::string target) {
	return new RobotomyRequestForm(target);}


AForm *makePresidentialForm(const std::string target) {
	return new PresidentialPardonForm(target);}

AForm* Intern::makeForm(std::string nameForm, std::string targetForm) const
{
    std::string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*ptr[3])(const std::string str) = {&makeShrubberyForm, &makeRobotomyForm, &makePresidentialForm};

    for(int i = 0; i < 3; i++){
        if(nameForm == tab[i]){
            std::cout << "Intern creates " << nameForm << std::endl;
            return ptr[i](targetForm);
        }
    }
    std::cout << "Intern could not create " << nameForm << ", no such form found." << std::endl;
    return NULL;
}
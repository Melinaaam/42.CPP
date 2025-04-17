#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << CYAN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << CYAN << "PresidentialPardonForm( " << target << " ) constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : _target(copy._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
        this->_target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << CYAN << "PresidentialPardonForm deconstructor called" << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    beExecuted(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name) : _name(name)
{
    std::cout << "default constrcutor call for " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "deconstrcutor call" << std::endl;
}

std::string Bureaucrat::getName() const{return _name;}

int Bureaucrat::getGrade() const { return _grade;}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat) {
    out << Bureaucrat.getName();
    // std::cout << "bureaucrat grade" << Bureaucrat.getGrade() << std::endl;
    // std::cout << "bureaucrat grade" << std::endl;
    return out;
}
/*********************************************************************** */

// Bureaucrat::radeTooHighException& Bureaucrat::radeTooHighException::operator++()
// {
    
// }

// Bureaucrat::radeTooHighException& Bureaucrat::radeTooHighException::operator--(){}

// std::string Bureaucrat::radeTooHighException::getName() const
// {
//     return Bureaucrat::getName();
// }

// int Bureaucrat::getGrade() const { return _grade;}
// /************************************************************************************ */

// Bureaucrat::radeTooLowException& Bureaucrat::radeTooLowException::operator++(){}

// Bureaucrat::radeTooLowException& Bureaucrat::radeTooLowException::operator--(){}
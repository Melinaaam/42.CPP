#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << CYAN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException(); 
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const{return _name;}

int Bureaucrat::getGrade() const { return _grade;}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << " , bureaucrat grade " << b.getGrade();
    return out;
}

Bureaucrat& Bureaucrat::operator++(){
    if (this->_grade <= 1){
        throw GradeTooHighException();
    }
    this->_grade--;
    return *this;
}

Bureaucrat& Bureaucrat::operator--(){
    if (this->_grade >= 150){
        throw GradeTooLowException();
    }
    this->_grade++;
    return *this;
}

void Bureaucrat::signForm(Form& form){
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e){

        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

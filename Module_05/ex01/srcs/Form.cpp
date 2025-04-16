#include "Form.hpp"

Form::Form(): _formName("default"), _isSign(false), _gradeSign(1), _gradeExec(1){
    std::cout << CYAN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(const std::string formName, const int gradeSign, const int gradeExec) : _formName(formName), _isSign(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy): _formName(copy._formName), _isSign(copy._isSign), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
}

Form& Form::operator=(const Form& other){
    if (this != &other)
    {
        _isSign = other._isSign;
    }
    return *this;
}
Form::~Form(){}

std::string Form::getName() const {return _formName;}
bool Form::getIsSign() const{return _isSign;}
int Form::getGradeSign() const{return _gradeSign;}
int Form::getGradeExec() const{return _gradeExec;}

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
    if(Bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    else 
        this->_isSign = true;
}
std::ostream &operator<<(std::ostream &out, const Form &Form){
    out << "Form's name : " << Form.getName()
    << std::endl << "Grade required to sign : " << Form.getGradeSign() 
    << std::endl << "Grade required to execute : " << Form.getGradeExec() << std::endl;
    return out;
}

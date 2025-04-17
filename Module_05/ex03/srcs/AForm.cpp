#include"AForm.hpp"

AForm::AForm(): _formName("default"), _isSign(false), _gradeSign(1), _gradeExec(1){
    std::cout << CYAN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string formName, const int gradeSign, const int gradeExec) : _formName(formName), _isSign(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    std::cout << CYAN << "AForm constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& copy): _formName(copy._formName), _isSign(copy._isSign), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
}

AForm& AForm::operator=(const AForm& other){
    if (this != &other)
    {
        _isSign = other._isSign;
    }
    return *this;
}

AForm::~AForm(){std::cout << CYAN << "AForm deconstructor called" << RESET << std::endl;}

std::string AForm::getName() const {return _formName;}
bool AForm::getIsSign() const{return _isSign;}
int AForm::getGradeSign() const{return _gradeSign;}
int AForm::getGradeExec() const{return _gradeExec;}

void AForm::beSigned(const Bureaucrat& Bureaucrat)
{
    if(Bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    else 
        this->_isSign = true;
}

void AForm::beExecuted(const Bureaucrat& Bureaucrat) const
{
    if(!_isSign)
        throw NoSignedException();
    if(Bureaucrat.getGrade() > _gradeExec)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &Form){
    out << "Form's name : " << Form.getName()
    << std::endl << "Grade required to sign : " << Form.getGradeSign() 
    << std::endl << "Grade required to execute : " << Form.getGradeExec() << std::endl;
    return out;
}
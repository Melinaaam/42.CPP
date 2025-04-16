#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>
#include<exception>
#include"Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   _formName;
    bool                _isSign;
    const int           _gradeSign;
    const int           _gradeExec;
public:
    Form();
    Form(const std::string formName, const int gradeSign, const int gradeExec);
    Form(const Form& copy);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    bool getIsSign() const;
    int getGradeSign() const;
    int getGradeExec() const;

    void beSigned(const Bureaucrat& Bureaucrat);

    class GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw(){
            return "the grade is too high";
        }
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw(){
            return "the grade is too low";
        }
    };
};
std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif
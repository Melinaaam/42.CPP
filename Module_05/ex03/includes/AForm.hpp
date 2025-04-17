#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>
#include<string>
#include<exception>
#include"Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   _formName;
    bool                _isSign;
    const int           _gradeSign;
    const int           _gradeExec;
public:
    AForm();
    AForm(const std::string formName, const int gradeSign, const int gradeExec);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSign() const;
    int getGradeSign() const;
    int getGradeExec() const;

    void beSigned(const Bureaucrat& Bureaucrat);
    void beExecuted(const Bureaucrat& Bureaucrat) const;
    virtual void execute(Bureaucrat const & executor) const = 0;

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
    class NoSignedException: public std::exception
    {
        virtual const char* what() const throw(){
            return "the form has not been signed!";
        }
    };
};
std::ostream &operator<<(std::ostream &out, const AForm &aform);

#endif
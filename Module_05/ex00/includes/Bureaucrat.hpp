#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include<string>
#include<exception>


class Bureaucrat 
{
private:
    std::string _name;
    int         _grade;
public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat& operator++();
    Bureaucrat& operator--();

    std::string getName() const;
    int getGrade() const;

    class GradeTooHighException
    {
        virtual const char* what() const throw()
        {
            return "Errrrror hight";
        }
    };

    class GradeTooLowException
    {
        virtual const char* what() const throw()
        {
            return "Errrrror low";
        }
    };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);



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


#endif
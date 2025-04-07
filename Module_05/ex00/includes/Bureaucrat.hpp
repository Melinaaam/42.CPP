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
    Bureaucrat(const std::string name);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    // class radeTooHighException
    // {
    //     radeTooHighException& operator++();
    //     radeTooHighException& operator--();
    //     std::string getName() const;
    //     int getGrade() const;
    // };

    // class radeTooLowException
    // {
    //     radeTooLowException& operator++();
    //     radeTooLowException& operator--();
    //     std::string getName() const;
    //     int getGrade() const;
    // };
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
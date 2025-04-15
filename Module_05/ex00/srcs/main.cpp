#include"Bureaucrat.hpp"

int main()
{
    Bureaucrat* miss = new Bureaucrat("miss", 10);

    std::cout << "Try operator : " << RED << *miss << RESET << std::endl;

    // std::cout << GREEN << *miss++ << RESET << std::endl;
    // std::cout << GREEN << *++miss << RESET << std::endl;
    // std::cout << "Try operator : " << RED << *miss << RESET << std::endl;
    try
    {
        // throw Bureaucrat::GradeTooHighException();
        std::cout << GREEN << *miss++ << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete miss;
}
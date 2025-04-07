#include"Bureaucrat.hpp"

int main()
{
    Bureaucrat* miss = new Bureaucrat("miss");

    std::cout << "miss->getName() : " << miss->getName() << std::endl;
    std::cout << "miss->getGrade() : " << miss->getGrade() << std::endl;

    std::cout << std::endl;

    std::cout << "Try operator : " << RED << miss << RESET << std::endl;

    std::cout << std:: endl << " with gets : " << miss->getName() << " || " << miss->getGrade() << RESET << std::endl;

    delete miss;
}
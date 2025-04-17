#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"


int main()
{
    std::cout << CYAN << "====== Creation forms ======" << RESET << std::endl;
    ShrubberyCreationForm tree("tree");
    std::cout << MAGENTA << tree << RESET << std::endl;
    RobotomyRequestForm robot("robot");
    std::cout << MAGENTA << robot << RESET << std::endl;
    PresidentialPardonForm form("Bureau Ovale");
    std::cout << MAGENTA << form << RESET << std::endl;

    std::cout << CYAN << "====== Creation Bureaucrats ======" << RESET << std::endl;
    Bureaucrat LeChef("LeChef", 1);
    std::cout << MAGENTA << LeChef << RESET << std::endl;
    Bureaucrat miss("miss", 150);
    std::cout << MAGENTA << miss << RESET << std::endl;
    Bureaucrat mister("mister", 150);
    std::cout << MAGENTA << mister << RESET << std::endl;
    Bureaucrat Bertille("Bertille", 150);
    std::cout << MAGENTA << Bertille << RESET << std::endl;

    std::cout << CYAN << "====== ShrubberyCreationForm ======" << RESET << std::endl;

    miss.signForm(tree);
    miss.executeForm(tree);
    std::cout << std::endl;

    std::cout << MAGENTA << "miss got a promotion : " << RESET << std::endl;
    for(int i = 0; i < 13; i++)
    ++miss;
    std::cout << MAGENTA << miss << RESET << std::endl;
    miss.signForm(tree);
    miss.executeForm(tree);
    std::cout << std::endl;
    
    LeChef.signForm(tree);
    LeChef.executeForm(tree);
    std::cout << std::endl;

    std::cout << CYAN << "====== RobotomyRequestForm ======" << RESET << std::endl;

    mister.signForm(robot);
    mister.executeForm(robot);
    std::cout << std::endl;

    std::cout << MAGENTA << "mister got a promotion : " << RESET << std::endl;
    for(int i = 0; i < 105; i++)
    ++mister;
    std::cout << MAGENTA << mister << RESET << std::endl;
    mister.signForm(robot);
    mister.executeForm(robot);
    std::cout << std::endl;

    LeChef.signForm(robot);
    LeChef.executeForm(robot);
    std::cout << std::endl;

    std::cout << CYAN << "====== PresidentialPardonForm ======" << RESET << std::endl;

    Bertille.signForm(form);
    Bertille.executeForm(form);
    std::cout << std::endl;

    std::cout << MAGENTA << "Bertille got a promotion : " << RESET << std::endl;
    for(int i = 0; i < 145; i++)
    ++Bertille;
    std::cout << MAGENTA << Bertille << RESET << std::endl;
    Bertille.signForm(form);
    Bertille.executeForm(form);
    std::cout << std::endl;

    LeChef.signForm(form);
    LeChef.executeForm(form);
    std::cout << std::endl;
   
    return 0;
}

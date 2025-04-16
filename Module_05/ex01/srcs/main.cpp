#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{
    std::cout << CYAN << "====== Test too low grade ======" << RESET << std::endl;

    Bureaucrat miss("miss", 111);
    Form contrat("Contract", 40, 20);

    std::cout << MAGENTA << miss << RESET << std::endl;
    std::cout << contrat << std::endl;
    
    miss.signForm(contrat);

    std::cout << std::endl << CYAN << "====== Test too high grade ======" << RESET << std::endl;

    Bureaucrat mister("mister", 1);
    Form forms("forms", 40, 20);

    std::cout << MAGENTA << mister << RESET << std::endl;
    std::cout << forms << std::endl;
    
    mister.signForm(forms);

    std::cout << std::endl << CYAN << "====== Test no initialize bureaucrat ======" << RESET << std::endl;
    Bureaucrat anyone;
    std::cout << MAGENTA << anyone << RESET << std::endl;
    anyone.signForm(contrat);
    anyone.signForm(forms);
        
    return 0;
}

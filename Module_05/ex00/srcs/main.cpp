#include"Bureaucrat.hpp"

int main()
{
    std::cout << CYAN << "====== Test opeartor ++ ======" << RESET << std::endl;

    Bureaucrat miss("miss", 11);
    std::cout << MAGENTA << miss << RESET << std::endl;

    for (int i = 0; i < 10; i++){
        ++miss;
        std::cout << GREEN << miss << RESET << std::endl;
    }
    std::cout << "Miss grade : " << MAGENTA << miss.getGrade() << RESET << std::endl;
    for (int i = 0; i < 149; i++){
        --miss;
        std::cout << GREEN << miss << RESET << std::endl;
    }
    std::cout << "Miss grade : " << MAGENTA << miss.getGrade() << RESET << std::endl;

    std::cout << CYAN << "====== Test opeartor -- ======" << RESET << std::endl;
    Bureaucrat mister("mister", 100);
    std::cout << MAGENTA << mister << RESET << std::endl;

    for (int i = 0; i < 15; i++){
        --mister;
        std::cout << RED << mister << RESET << std::endl;
    }

    std::cout << CYAN << "====== Test exceptions ======" << std::endl;
    std::cout << " Test oma : grade 0" << RESET << std::endl;
    try {
        Bureaucrat oma("oma", 0);
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    std::cout << CYAN << " Test julia grade 151" << RESET << std::endl;
    try {
        Bureaucrat julia("julia", 151);
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    std::cout << CYAN << " lilia : test decrementation au dela du grade 150" << RESET << std::endl;
    try {
        Bureaucrat lilia("lilia", 141);
        std::cout << lilia << std::endl;
        for (int i = 0; i < 10; i++){
            --lilia;
            std::cout << RED << lilia << RESET << std::endl;
        }
    }
    catch (std::exception & e){
        std::cerr << "Error : " << e.what() << std::endl;
    }

    std::cout << std::endl << CYAN << " bertille : test incrementation au dela de 1" << RESET << std::endl;
    try {
        Bureaucrat bertille("bertille", 10);
        std::cout << bertille << std::endl;
        for (int i = 0; i < 10; i++){
            ++bertille;
            std::cout << GREEN << bertille << RESET << std::endl;
        }
    }
    catch (std::exception & e){
        std::cerr << "Error : " << e.what() << std::endl;
    }

   return 0;
}

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("defaut")
{
	// std::cout << CYAN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    // std::cout << CYAN << "RobotomyRequestForm( " << target << " ) constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : _target(copy._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
        this->_target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << CYAN << "RobotomyRequestForm deconstructor called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    beExecuted(executor);
    std::cout << YELLOW << "Driiiiiiiiiiiiiiiiiiiiiiii..." << RESET << std::endl;

	srand(time(0));
	if (rand() % 2)
		std::cout << _target << GREEN << " has been successfully robotomized." << RESET << std::endl;
	else
		std::cout << _target << RED << " has failed to be robotomized." << RESET << std::endl;
}
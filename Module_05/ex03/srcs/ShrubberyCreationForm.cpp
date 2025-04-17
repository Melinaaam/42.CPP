#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("defaut")
{
	std::cout << CYAN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << CYAN << "ShrubberyCreationForm( " << target << " ) constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : _target(copy._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
        this->_target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << CYAN << "ShrubberyCreationForm deconstructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    beExecuted(executor);
    std::ofstream file(std::string(_target + "_shrubbery").c_str());
    if (!file.is_open()){
        std::cerr << "Error : impossible to create the file " << _target << "shrubbery" << std::endl;
        return;
    }
    file << "                   &&& &&  & &&\n\
    && &\\/&\\|& ()|/ @, &&\n\
    &\\/(/&/&||/& /_/)_&/_&\n\
 &() &\\/&|()|/&\\/ '%\" & ()\n\
&_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
()&_---()&\\&\\|&&-&&--%---()~\n\
   &&     \\|||\n\
           |||\n\
           |||\n\
           |||\n\
     , -=-~  .-^- _";
     file.close();
}
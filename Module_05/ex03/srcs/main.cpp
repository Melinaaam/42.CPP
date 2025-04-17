#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"


// int main()
// {
//     Intern someRandomIntern;
//     AForm* rrf;
//     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//     return 0;
// }
int	main(void)
{
	std::cout << "\033[38;5;45m==========Intern tests==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		try
		{
			n.signForm(*rrf);
			rrf->execute(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat n("Melina", 25);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		try
		{
			n.signForm(*rrf);
			rrf->execute(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat n("Melina", 146);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		try
		{
			n.signForm(*rrf);
			rrf->execute(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[38;5;45m==========Incorrect form==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request ihihi", "Bender");
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
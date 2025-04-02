#include"Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called !" << std::endl;
	for (int i(0); i < 100; i++)
		_ideas[i] = "idea";
}
Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called !" << std::endl;
	*this = copy;
}
Brain & Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assigment operator called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain detructor called !" << std::endl;
}


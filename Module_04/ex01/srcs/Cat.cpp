#include"Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
	_brain = new Brain();
    std::cout << _type << " default constructor called !" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << _type << " copy constructor called !" << std::endl;
	this->_brain = new Brain(*(copy._brain)); // Copie profonde : Une copie "superficielle" (ou shallow copy) copierait simplement le pointeur Brain*, ce qui signifierait que deux objets Dog pointeraient vers le même Brain. Si l'un des objets est détruit, il va supprimer le Brain, laissant l'autre objet avec un pointeur invalide
}
Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
        this->_brain = new Brain(*(other._brain));
	}
    return *this;
}

Cat::~Cat(void)
{
	std::cout << _type << " destructor called !" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
        std::cout << "🐈 Miaou Miaou 🐈" << std::endl;
}

void Cat::getIdeas(int index, int nbIdeasDisplay) const
{
	std::cout << "Cat's ideas : " << std::endl;
	_brain->getIdeas(index, nbIdeasDisplay);
}
#include"Dog.hpp"

Dog::Dog() : AAnimal()
{
    _type = "Dog";
	_brain = new Brain();
    std::cout << _type << " default constructor called !" << std::endl;
}

Dog::Dog(const Dog& copy) : AAnimal(copy)
{
    std::cout << _type << " copy constructor called !" << std::endl;
	this->_brain = new Brain(*(copy._brain)); // Copie profonde : Une copie "superficielle" (ou shallow copy) copierait simplement le pointeur Brain*, ce qui signifierait que deux objets Dog pointeraient vers le même Brain. Si l'un des objets est détruit, il va supprimer le Brain, laissant l'autre objet avec un pointeur invalide
}
Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;  // Libérer ancien brain
		this->_brain = new Brain(*(other._brain));  // Copie profonde
	}
    return *this;
}

Dog::~Dog(void)
{
    std::cout << _type << " detructor called !" << std::endl;
	delete _brain;
}
void Dog::makeSound() const{std::cout << "🐶 Waf Waf 🐶" << std::endl;}

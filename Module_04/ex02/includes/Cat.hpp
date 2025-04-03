#ifndef CAT_HPP
#define CAT_HPP

#include"Animal.hpp"
#include"Brain.hpp"
class Cat : public AAnimal
{
private:
	Brain* _brain;
public:
	Cat(void);
	Cat(const Cat& copy);
	Cat& operator=(const Cat& other);
	virtual ~Cat(void);

	void makeSound() const;
};

#endif

/*Le destructeur est déclaré comme virtual car lorsque
tu as une classe de base comme Animal avec des classes dérivées comme Cat,
car si tu détruis un objet de type Cat via un pointeur de type Animal*,
le compilateur doit savoir qu'il doit appeler le destructeur de Cat avant celui d'Animal.
Sans le mot-clé virtual, seul le destructeur d'Animal serait appelé,
ce qui pourrait causer des fuites de mémoire si Cat alloue des ressources supplémentaires.*/

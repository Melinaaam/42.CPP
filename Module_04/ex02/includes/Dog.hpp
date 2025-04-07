#ifndef DOG_HPP
#define DOG_HPP

#include"AAnimal.hpp"
#include"Brain.hpp"
class Dog : public AAnimal
{
private:
	Brain* _brain;
public:
    Dog(void);
	Dog(const Dog& copy);
	Dog& operator=(const Dog& other);
    ~Dog(void);

	void makeSound() const;
	void getIdeas(int index, int nbIdeasDisplay) const;
};

#endif

#ifndef CAT_HPP
#define CAT_HPP

#include"AAnimal.hpp"
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
	void getIdeas(int index, int nbIdeasDisplay) const;
};

#endif

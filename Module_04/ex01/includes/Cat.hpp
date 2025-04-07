#ifndef CAT_HPP
#define CAT_HPP

#include"Animal.hpp"
#include"Brain.hpp"
class Cat : public Animal
{
private:
	Brain* _brain;
public:
	Cat(void);
	Cat(const Cat& copy);
	Cat& operator=(const Cat& other);
	virtual ~Cat(void);

	virtual void makeSound() const;
	void getIdeas(int index, int nbIdeasDisplay) const;
};

#endif

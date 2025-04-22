#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*srand pour random A, B ou C et return new class*/
Base * generate(void)
{
    srand(time(NULL));
    int r = std::rand() % 3;
    if (r == 0)
        return (new A());
    else if (r == 1) 
        return (new B());
    else
        return (new C());
}
/* on utilise pas tydeinfo mais on cast p avec la class A, B ou C*/
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p) {
    try {
        A& temp_a = dynamic_cast<A&>(p);
        (void) temp_a;
        std::cout << "A" << std::endl;
    } 
    catch (std::exception &e) 
    {
        try {
            B& temp_b = dynamic_cast<B&>(p);
            (void) temp_b;
            std::cout << "B" << std::endl;;
        }
        catch (std::exception &e) {
            try {
                C& temp_c = dynamic_cast<C&>(p);
                (void) temp_c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e){
                std::cerr << "It's a wrong type" << std::endl;
            }
        }

    }

}

int main() 
{
	Base* base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
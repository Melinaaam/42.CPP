#include"iter.hpp"

void printInt(int const& i){
    std::cout << i;
}

void printStr(std::string const& str){
    std::cout << str;
}
void printChar(char const& c) { 
    std::cout << c; 
}

int main( void ) 
{
    int tab[] = { 1, 2, 3 , 4};
    std::string tab2[] = { "hello", "world" };
    char tab3[] = {'H','E'};
    
    std::cout << CYAN << "--- iter with int ---" << RESET << std::endl;
    iter(tab, 4, printInt);

    std::cout << std::endl << CYAN << "--- iter with str ---" << RESET << std::endl;
    iter(tab2, sizeof(tab2)/sizeof(tab2[0]), printStr);

    std::cout << std::endl << CYAN << "--- iter with char ---" << RESET  << std::endl;
    iter(tab3, sizeof(tab3)/sizeof(tab3[0]), printChar);
    return 0;
}
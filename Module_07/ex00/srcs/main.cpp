#include"whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;

    std::cout << YELLOW << " --- tests with int ---"<< RESET << std::endl;
    std::cout << CYAN << "int a = " << a << ", int b = " << b << RESET << std::endl;
    std::cout << std::endl << MAGENTA << "call template swap"<< RESET << std::endl;
    ::swap( a, b );
    std::cout << CYAN << "int a = " << a << ", int b = "  << b << RESET << std::endl;

    std::cout << std::endl << MAGENTA << "call template min & max"<< RESET << std::endl;
    std::cout << CYAN << "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;
    std::cout << CYAN << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;

    std::cout << YELLOW << " --- tests with float ---"<< RESET << std::endl;
    float e = 2.14f;
    float f = 3.35f;
    std::cout << CYAN << "float e = " << e << "; float f = " << f << RESET << std::endl;
    std::cout << std::endl << MAGENTA << "call template swap"<< RESET << std::endl;
    ::swap( e, f );
    std::cout << CYAN << "int e = " << e << "; int f = "  << f << RESET << std::endl;

    std::cout << std::endl << MAGENTA << "call template min & max"<< RESET << std::endl;
    std::cout << CYAN << "min( e, f ) = " << ::min( e, f ) << RESET << std::endl;
    std::cout << CYAN << "max( e, f ) = " << ::max( e, f ) << RESET << std::endl;

    std::cout << YELLOW << " --- tests with double ---"<< RESET << std::endl;
    double g = 42.42;
    double h = 24.24;
    std::cout << CYAN << "double g = " << e << "; double h = " << f << RESET << std::endl;
    std::cout << std::endl << MAGENTA << "call template swap"<< RESET << std::endl;
    ::swap( g, h );
    std::cout << CYAN << "double g = " << e << "; double h = " << f << RESET << std::endl;

    std::cout << std::endl << MAGENTA << "call template min & max"<< RESET << std::endl;
    std::cout << CYAN << "min( g, h ) = " << ::min( g, h ) << RESET << std::endl;
    std::cout << CYAN << "max( g, h ) = " << ::max( g, h ) << RESET << std::endl;
    
    std::cout << YELLOW << " --- tests with string ---"<< RESET << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << CYAN << "string c = " << c << ", string d = " << d << RESET << std::endl;
    std::cout << std::endl << MAGENTA << "call template swap"<< RESET << std::endl;
    ::swap(c, d);
    std::cout << CYAN << "string c = " << c << ", string d = " << d << RESET << std::endl;

    std::cout << std::endl << MAGENTA << "call template min & max"<< RESET << std::endl;
    std::cout << CYAN << "min( c, d ) = " << ::min( c, d ) << RESET << std::endl;
    std::cout << CYAN << "max( c, d ) = " << ::max( c, d ) << RESET << std::endl;
    return 0;
    }
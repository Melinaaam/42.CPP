#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

// int main() {
//     Fixed a;
//     Fixed b(10);
//     Fixed c(42.42f);
//     Fixed d(b);
//     a = Fixed(1234.4321f);

//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << "d: " << d << std::endl;

//     std::cout << "\n---- Comparaisons ----" << std::endl;
//     std::cout << "b > c: " << (b > c) << std::endl;
//     std::cout << "b < c: " << (b < c) << std::endl;
//     std::cout << "b >= d: " << (b >= d) << std::endl;
//     std::cout << "b <= d: " << (b <= d) << std::endl;
//     std::cout << "b == d: " << (b == d) << std::endl;
//     std::cout << "b != c: " << (b != c) << std::endl;

//     std::cout << "\n---- Opérateurs arithmétiques ----" << std::endl;
//     Fixed x(5.05f);
//     Fixed y(2);
//     std::cout << "x: " << x << ", y: " << y << std::endl;
//     std::cout << "x + y: " << (x + y) << std::endl;
//     std::cout << "x - y: " << (x - y) << std::endl;
//     std::cout << "x * y: " << (x * y) << std::endl;
//     std::cout << "x / y: " << (x / y) << std::endl;

//     std::cout << "\n---- Incrémentation/Décrémentation ----" << std::endl;
//     Fixed z;
//     std::cout << "z: " << z << std::endl;
//     std::cout << "++z: " << ++z << std::endl;
//     std::cout << "z: " << z << std::endl;
//     std::cout << "z++: " << z++ << std::endl;
//     std::cout << "z: " << z << std::endl;
//     std::cout << "--z: " << --z << std::endl;
//     std::cout << "z: " << z << std::endl;
//     std::cout << "z--: " << z-- << std::endl;
//     std::cout << "z: " << z << std::endl;

//     std::cout << "\n---- Min / Max ----" << std::endl;
//     Fixed e(3.14f);
//     Fixed f(42.0f);
//     std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
//     std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;
//     const Fixed g(100.1f);
//     const Fixed h(99.9f);
//     std::cout << "const min(g, h): " << Fixed::min(g, h) << std::endl;
//     std::cout << "const max(g, h): " << Fixed::max(g, h) << std::endl;

//     return 0;
// }

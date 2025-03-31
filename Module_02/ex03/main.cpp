#include "Fixed.hpp"
#include"Point.hpp"


// Déclaration de la fonction bsp
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    // Création des sommets du triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test avec un point intérieur
    Point pInt(5.0f, 5.0f);
    // Test avec un point sur une arrête
    Point pEdge(5.0f, 0.0f);
    // Test avec un point extérieur
    Point pExt(10.0f, 10.0f);

    std::cout << "Point interieur (5,5): " << (bsp(a, b, c, pInt) ? "inside" : "outside") << std::endl;
    std::cout << "Point sur une arete (5,0): " << (bsp(a, b, c, pEdge) ? "inside" : "outside") << std::endl;
    std::cout << "Point exterieur (10,10): " << (bsp(a, b, c, pExt) ? "inside" : "outside") << std::endl;

    return 0;
}

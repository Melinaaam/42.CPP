#include"Point.hpp"

/*Calcul de "sign" :
La fonction sign calcule une valeur qui représente le double de l'aire orientée du triangle formé par les points. Ce calcul se base sur l’équation :
sign(p1,p2,p3)=(p1x−p3x)×(p2y−p3y)−(p2x−p3x)×(p1y−p3y)
sign(p1,p2,p3)=(p1x​−p3x​)×(p2y​−p3y​)−(p2x​−p3x​)×(p1y​−p3y​)

Si cette valeur est nulle, cela signifie que les trois points sont alignés (donc le point se trouve sur l’arrête ou est confondu avec un sommet).

Test d’intérieur du triangle :
En calculant les trois valeurs d1d1, d2d2 et d3d3 pour les combinaisons (point, a, b), (point, b, c) et (point, c, a), on vérifie :

    Si l’un d’entre elles est zéro, le point est sur une arrête ou un sommet → retour de false.

    Si elles sont toutes positives ou toutes négatives, le point est strictement à l’intérieur du triangle.

    Sinon, le point est à l’extérieur.*/

// Fonction auxiliaire : calcule le "produit vectoriel" (aire orientée) de (p1, p2, p3)
static Fixed sign(Point const p1, Point const p2, Point const p3)
{
    // Calcul : (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y)
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
         - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
/*

• a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on an edge, it will return False.
Implement and turn in your own tests to ensure that your class behaves as expected
*/
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    // Si l'un des signes est exactement 0, le point est sur une arrête ou sur un sommet.
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
        return false;

    // Vérifie si tous les signes sont positifs ou tous négatifs.
    bool has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(has_neg && has_pos);
}

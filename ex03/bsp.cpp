#include "Point.hpp"

static Fixed abs(Fixed n)
{
    if(n >= 0)
        return n;
    return n * -1;
}

static Fixed   areaTriangle(Point const a, Point const b, Point const c)
{
    return abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY())) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = areaTriangle(a, b, c);
    Fixed abpArea = areaTriangle(a, b, point);
    Fixed acpArea = areaTriangle(a, c, point);
    Fixed bcpArea = areaTriangle(b, c, point);

    std::cout << "somme des aires = " << abpArea + acpArea + bcpArea << std::endl;
    std::cout << "aire triangle totale = " << abcArea << std::endl;

    Fixed epsilon = Fixed(0.01f); // Tolerance for comparison
    return ((abpArea + acpArea + bcpArea) - abcArea) < epsilon;
}
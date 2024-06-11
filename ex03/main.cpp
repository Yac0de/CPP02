#include "Point.hpp"

void testPointInTriangle(Point pt, Point v1, Point v2, Point v3)
{
    if (bsp(v1, v2, v3, pt))
        std::cout << "Le point (" << pt.getX() << ", " << pt.getY() << ") est à l'intérieur du triangle." << std::endl;
    else
        std::cout << "Le point (" << pt.getX() << ", " << pt.getY() << ") est à l'extérieur du triangle." << std::endl;
}

int main()
{
    Point v1(0, 0);
    Point v2(1, 0);
    Point v3(0, 1);

    std::cout << "Test 1: Point à l'intérieur du triangle" << std::endl;
    Point pt1(0.2, 0.2);
    testPointInTriangle(pt1, v1, v2, v3);

    std::cout << "\nTest 2: Point à l'extérieur du triangle" << std::endl;
    Point pt2(10, 10);
    testPointInTriangle(pt2, v1, v2, v3);

    std::cout << "\nTest 3: Point proche mais à l'extérieur du triangle" << std::endl;
    Point pt3(5, 6);
    testPointInTriangle(pt3, v1, v2, v3);

    std::cout << "\nTest 4: Point sur le bord du triangle" << std::endl;
    Point pt4(4, 0);
    testPointInTriangle(pt4, v1, v2, v3);

    std::cout << "\nTest 5: Point coïncidant avec un sommet du triangle" << std::endl;
    Point pt5(10, 0);
    testPointInTriangle(pt5, v1, v2, v3);

    return 0;
}

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point & rhs);
    ~Point(void);

    const Fixed getX(void) const;
    const Fixed getY(void) const;

    Point & operator=(const Point & rhs);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
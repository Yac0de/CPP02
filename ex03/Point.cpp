#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {return;}

Point::Point(const float x, const float y) : _x(x), _y(y) {return;}

Point::Point(const Point & rhs) :_x(rhs._x), _y(rhs._y) {return;}

Point::~Point(void) {return;}

const Fixed Point::getX(void) const {return this->_x;}

const Fixed Point::getY(void) const {return this->_y;}

Point & Point::operator=(const Point & rhs)
{
    if(this != &rhs)
    {
        const_cast<Fixed&>(this->_x) = rhs.getX();
        const_cast<Fixed&>(this->_y) = rhs.getY();
    }
    return *this;
}
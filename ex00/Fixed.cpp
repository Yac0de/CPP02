#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNum(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed & rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
    return;
}

Fixed & Fixed::operator=(const Fixed & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointNum = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNum = raw;
    return;
}

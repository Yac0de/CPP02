#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNum(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int n_int) : _fixedPointNum(n_int << _fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed(const float n_float) : _fixedPointNum(roundf(n_float * (1 << _fractional_bits)))
{
    std::cout << "Float constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &rhs)
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
    return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNum = raw;
    return;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_fixedPointNum) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointNum >> _fractional_bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}

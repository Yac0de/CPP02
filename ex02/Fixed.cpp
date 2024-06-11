#include "Fixed.hpp"

///////////////////// CONSTRUCTORS /////////////////////
Fixed::Fixed(void) : _fixedPointNum(0)
{
    return;
}

Fixed::Fixed(const int n_int) : _fixedPointNum(n_int << _fractional_bits)
{
    return;
}

Fixed::Fixed(const float n_float) : _fixedPointNum(roundf(n_float * (1 << _fractional_bits)))
{
    return;
}

Fixed::Fixed(const Fixed &rhs)
{
    *this = rhs;
    return;
}

///////////////////// DESTRUCTOR /////////////////////
Fixed::~Fixed(void)
{
    return;
}

///////////////////// GETTERS AND SETTERS /////////////////////
int Fixed::getRawBits(void) const
{
    return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNum = raw;
    return;
}

///////////////////// COVERSION FUNCTIONS /////////////////////
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_fixedPointNum) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointNum >> _fractional_bits;
}

///////////////////// MIN MAX, OVERLOADED FUNCTIONS /////////////////////
Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    return a.getRawBits() > b.getRawBits() ? b : a;
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() > b.getRawBits() ? b : a;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() > b.getRawBits() ? a : b;
}

///////////////////// INSERTION OPERATOR OVERLOAD /////////////////////
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}

///////////////////// COPY ASSIGNEMENT OPERATOR /////////////////////
Fixed & Fixed::operator=(const Fixed & rhs)
{
    if (this != &rhs)
        this->_fixedPointNum = rhs.getRawBits();
    return *this;
}

///////////////////// COMPARISON OPERATORS /////////////////////
bool Fixed::operator==(Fixed const & rhs) const
{
    return(this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const
{
    return(this->getRawBits() != rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs) const
{
    return(this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const
{
    return(this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator>(Fixed const & rhs) const
{
    return(this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) const
{
    return(this->getRawBits() >= rhs.getRawBits());
}

///////////////////// ARITHMETIC OPERATORS /////////////////////
Fixed Fixed::operator+(Fixed const & rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

///////////////////// INCREMENT AND DECREMENT OPERATORS /////////////////////
Fixed& Fixed::operator++(void)
{
    ++this->_fixedPointNum;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    tmp._fixedPointNum = this->_fixedPointNum++;
    return tmp;
}

Fixed& Fixed::operator--(void)
{
    --this->_fixedPointNum;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    tmp._fixedPointNum = this->_fixedPointNum--;
    return tmp;
}
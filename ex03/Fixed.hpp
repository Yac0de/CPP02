#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _fixedPointNum;
    static const int _fractional_bits = 8;
public:
    Fixed(void);
    Fixed(const int n_int);
    Fixed(const float n_float);
    Fixed(const Fixed &rhs);
    Fixed& operator=(const Fixed &rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    static Fixed & min(Fixed &a, Fixed &b);
    static const Fixed & min(Fixed const &a, Fixed const &b);
    static Fixed & max(Fixed &a, Fixed &b);
    static const Fixed & max(Fixed const &a, Fixed const &b);

    bool operator<(Fixed const & rhs) const;
    bool operator<=(Fixed const & rhs) const;
    bool operator>(Fixed const & rhs) const;
    bool operator>=(Fixed const & rhs) const;
    bool operator==(Fixed const & rhs) const;
    bool operator!=(Fixed const & rhs) const;

    Fixed operator+(Fixed const & rhs) const;
    Fixed operator-(Fixed const & rhs) const;
    Fixed operator*(Fixed const & rhs) const;
    Fixed operator/(Fixed const & rhs) const;

    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );



#endif
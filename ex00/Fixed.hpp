#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedPointNum;
    static const int fractional_bits = 8;
public:
    Fixed(void);
    Fixed(const Fixed & rhs);
    Fixed & operator=(const Fixed & rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	int val;
	static const int fract = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int num);
	Fixed(const float num);

	Fixed &operator=(const Fixed& other);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);
#endif
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
	Fixed(const Fixed &other);
	Fixed(const int num);
	Fixed(const float num);

	Fixed &operator=(const Fixed other);
	bool operator>(const Fixed other);
	bool operator<(const Fixed other);
	bool operator>=(const Fixed other);
	bool operator<=(const Fixed other);
	bool operator==(const Fixed other);
	bool operator!=(const Fixed other);

	Fixed operator+(const Fixed other);
	Fixed operator*(const Fixed other);
	Fixed operator-(const Fixed other);
	Fixed operator/(const Fixed other);

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);
#endif
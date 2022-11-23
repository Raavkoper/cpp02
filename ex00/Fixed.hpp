#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
	int val;
	static const int fract = 8;

public:
	Fixed(); 
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed& operator=(const Fixed& obj);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
#endif
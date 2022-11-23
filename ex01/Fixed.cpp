#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "copy constructor called" << std::endl;
	this->val = other.getRawBits();
}

Fixed::Fixed(const int num) {
	std::cout << "int constructer called" << std::endl;
	this->val = num << this->fract;
}

Fixed::Fixed(const float num) {
	std::cout << "float constructer called" << std::endl;
	this->val = roundf(num *(1 << this->fract));
}

Fixed::~Fixed() {	
	std::cout << "deconstructor called" << std::endl;
};

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "operator assignement called" << std::endl;
	this->val = other.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const {
	return (this->val);
}

void Fixed::setRawBits(int const raw) {
	this->val = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->val / (1 << this->fract));
}

int Fixed::toInt(void) const {
	return (this->val >> this->fract);
}

std::ostream &operator << (std::ostream &out, const Fixed &other) {
	out << other.toFloat();
	return (out);
}
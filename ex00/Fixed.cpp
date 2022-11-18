#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "copy constructor called" << std::endl;
	this->val = obj.getRawBits();
}

Fixed::~Fixed() {	
	std::cout << "deconstructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "operator assignement called" << std::endl;
	this->val = obj.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (this->val);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function called" << std::endl;
	this->val = raw;
}
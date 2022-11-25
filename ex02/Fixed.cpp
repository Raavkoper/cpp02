#include "Fixed.hpp"

/* constructers */

Fixed::Fixed() {
	this->val = 0;
}

Fixed::Fixed(const Fixed &other) {
	this->val = other.getRawBits();
}

Fixed::Fixed(const int num) {
	this->val = num << this->fract;
}

Fixed::Fixed(const float num) {
	this->val = roundf(num *(1 << this->fract));
}

/* destructer */

Fixed::~Fixed() {};

/* operators */
Fixed &Fixed::operator=(const Fixed other) {
	this->val = other.getRawBits();

	return *this;
}

std::ostream &operator << (std::ostream &out, const Fixed &other) {
	out << other.toFloat();
	return (out);
}

/* comparison operators */

bool Fixed::operator>(const Fixed other) {
	return (this->val > other.val);
}

bool Fixed::operator<(const Fixed other) {
	return (this->val < other.val);
}

bool Fixed::operator>=(const Fixed other) {
	return (this->val >= other.val);
}

bool Fixed::operator<=(const Fixed other) {
	return (this->val <= other.val);
}

bool Fixed::operator==(const Fixed other) {
	return (this->val == other.val);
}

bool Fixed::operator!=(const Fixed other) {
	return (this->val != other.val);
}

/* arithmetic operators */

Fixed	Fixed::operator+(const Fixed other) {
	Fixed new_object;
	new_object.setRawBits(this->val + other.val);
	return (new_object);
}

Fixed Fixed::operator*(const Fixed other) {
	Fixed new_object;
	new_object.setRawBits(val * other.val);
	return (new_object);
}

Fixed Fixed::operator-(const Fixed other) {
	Fixed new_object;
	new_object.setRawBits(val - other.val);
	return (new_object);
}

Fixed Fixed::operator/(const Fixed other) {
	Fixed new_object;
	new_object.setRawBits(val / other.val);
	return (new_object);
}

/* ..crement operators */

Fixed Fixed::operator++() {
	Fixed new_object;
	new_object.val = ++this->val;
	return (new_object);
}

Fixed Fixed::operator--() {
	Fixed new_object;
	new_object.val = --this->val;
	return (new_object);
}

Fixed Fixed::operator++(int) {
	Fixed new_object;
	new_object.val = this->val++;
	return (new_object);
}

Fixed Fixed::operator--(int) {
	Fixed new_object;
	new_object.val = this->val--;
	return (new_object);
}

/* other member functions */

int	Fixed::getRawBits(void) const {
	return (this->val);
}

void Fixed::setRawBits(int const raw) {
	this->val = raw >> this->fract;
}

float Fixed::toFloat(void) const {
	return ((float)this->val / (1 << this->fract));
}

int Fixed::toInt(void) const {
	return (this->val >> this->fract);
}

/* min max functions */

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}
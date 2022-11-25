#include "Fixed.hpp"

int main(void) {

	/* subject tests */
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	/* more operator tests */
	{
		Fixed a(10);
		Fixed c = a;
		Fixed d(a);

		if (c == d)
			std::cout << "both are a copy of a so therefor equal" << std::endl;

		c++;

		if (c != d)
			std::cout << "value of c: " << c << " value of d: " << d << std::endl;

		if (c > d)
			std::cout << "the value of c is bigger than the value of d" << std::endl;

		c = c - a;

		if (d >= c)
			std::cout << "value of c: " << c << " value of d: " << d << std::endl;
	}
	std::cout << std::endl;
	/* min max tests */
	{
		Fixed a(5);
		Fixed b(5.45f);
		Fixed c(10);
		
		std::cout << "value of a: " << a << std::endl;
		std::cout << "value of b: " << b << std::endl;
		std::cout << "value of c: " << c << std::endl;

		std::cout << c.min(a, b) << std::endl;

		std::cout << Fixed::min(c, b) << std::endl;

		std::cout << b.max(a, c) << std::endl;
	}
}
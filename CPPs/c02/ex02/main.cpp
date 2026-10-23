#include "Fixed.hpp"

int main( void )
{
	Fixed a;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "----------------------------\n";

	//Arithmetic Operations
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Mult     '*' = " << b << std::endl;
	Fixed const c(Fixed(13.05f) / Fixed(2));
	std::cout << "Division '/' = " << c << std::endl;
	Fixed const d(Fixed(10.05f) + Fixed(5.05f));
	std::cout << "Suma     '+' = " << d << std::endl;
	Fixed const e(Fixed(10.05f) - Fixed(5.05f));
	std::cout << "Resta    '-' = " << e << std::endl;
	std::cout << "----------------------------\n";

	//Comparison Operators
	std::cout << "b = " << b << " -- c = " << c << std::endl << std::endl;
	if (b < c)
		std::cout << "b es menor\n";
	else
		std::cout << "b es mayor\n";
	if (b != c)
		std::cout << "b y c no son iguales\n";
	else
		std::cout << "b y c son iguales\n";
	std::cout << "----------------------------\n";

	//Min - Max
	std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min: " << Fixed::min(a, b) << std::endl;
	return 0;
}

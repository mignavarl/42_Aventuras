#include "Functions.hpp"

int main (void)
{
	Base* base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
}
#include "Functions.hpp"

Base * generate(void)
{
	srand(time(0));
	int r = rand() % 3;

	Base *gen;
	//std::cout << r << std::endl;
	switch (r)
	{
	case 0:
		gen = new A;
		break;
	case 1:
		gen = new B;
		break;
	case 2:
		gen = new C;
		break;
	}
	return (gen);
}


void identify(Base* p)
{
	std::cout << "* = ";
	if (dynamic_cast<A*>(p))
		std::cout << "Class A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C\n";
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A\n";
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class B\n";
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class C\n";
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
}

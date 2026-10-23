#include "iter.hpp"

template <typename T_string, typename T_size ,typename T_func>
void iter(T_string &str, T_size len, T_func f)
{
	for (T_size i = 0; i < len; i++)
	{
		f(str[i]);
	}
}

int main(void)
{
	std::string a;
	std::cin >> a;
	
	std::cout << "Antes = " << a << std::endl;
	iter(a, a.length(), toupper);
	std::cout << "Después = " << a << std::endl;
}
#include "iter.hpp"

template <typename T_string, typename T_size ,typename T_func>
void iter(T_string &str, T_size len, T_func f)
{
	for (size_t i = 0; i < len; i++)
	{
		str[i] = f(str[i]);
	}
}

int main(void)
{
	std::string a = "Patata";
	std::cout << "Antes = " << a << std::endl;
	iter(a, a.length(), toupper);
	std::cout << "Después = " << a << std::endl;
}
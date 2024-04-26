#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	char c = 'z';
	int i = -2147483648;
	int d = -(5/2);
	int u = -45;
	char s[] = "Roscón de reyes";
	int x = -4278;
	int p;

	ft_printf("\033[1;96mFT\n");
	p = ft_printf("Letra (c): %c %s", c, s);
	ft_printf(" (%7i)\n", p);
	p = ft_printf("String (s): %s", s);
	ft_printf(" (%i)\n", p);
	p = ft_printf("Decimal (d): %d", d);
	ft_printf(" (%i)\n", p);
	p = ft_printf("Número (i): %i", i);
	ft_printf(" (%i)\n", p);
	p = ft_printf("Dec. sin signo (u): %u", u);
	ft_printf(" (%i)\n", p);
	p = ft_printf("Porcentaje: %%");
	ft_printf(" (%i)\n", p);
	p = ft_printf("Hexa: %x", x);
	ft_printf(" (%i)\n", p);
	p = ft_printf("HEXA: %X", x);
	ft_printf(" (%i)\n", p);
	p = ft_printf("Void: %p", s);
	ft_printf(" (%i)\n", p);
	p = ft_printf("Sin flag: %%%m");
	ft_printf(" (%i)\n", p);
	ft_printf("---------------------\n");
	printf("PRINFT:\n");
	p = printf("Letra (c): %c", c);
	printf(" (%i)\n", p);
	p = printf("String (s): %s", s);
	printf(" (%i)\n", p);
	p = printf("Decimal (d): %d", d);
	printf(" (%i)\n", p);
	p = printf("Número (i): %i", i);
	printf(" (%i)\n", p);
	p = printf("Dec. sin signo (u): %u", u);
	printf(" (%i)\n", p);
	p = printf("Porcentaje: %%");
	printf(" (%i)\n", p);
	p = printf("Hexa: %x", x);
	printf(" (%i)\n", p);
	p = printf("HEXA: %X", x);
	printf(" (%i)\n", p);
	p = ft_printf("Void: %p", s);
	ft_printf(" (%i)\n", p);
	p = printf("Sin flag: %%%m");
	printf(" (%i)\n\033[0m", p);
	return (0);
}
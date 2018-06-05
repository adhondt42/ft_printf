#include "inc/ft_printf.h"
#include <limits.h>
int main()
{
int i;
int j;
/*
	str = "!%%-i 42 == %-i!";
	i = ft_printf(str, 42);
	j = printf(str, 42);
	i = printf("%%-i 42 == %-i\n", 42);
	*/ft_printf("!42%02.1u42!\n", 0);
	printf("!42%02.1u42!\n", 0);

}

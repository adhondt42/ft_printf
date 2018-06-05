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
	*/ft_printf("!%#2.2x!\n", -488933156);
	printf("!%#2.2x!\n", -488933156);
	ft_printf("%#-24.26hhx\n", 256);
	printf("%#-24.26hhx\n", 256);
	printf("i:%d, j:%d\n", i, j);

}

#include "inc/ft_printf.h"

int main()
{
int i;
int j;
char *str;

	str = "!%%-i 42 == %-i!\n";
	i = ft_printf(str, 42);
	j = printf(str, 42);
	printf("i:%d, j:%d\n", i, j);
	//i = ft_printf(str, 4);
	//j = printf(str, 4);

}

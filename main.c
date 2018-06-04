#include "inc/ft_printf.h"

int main()
{
int i;
int j;
char *str;

	str = "TEST :!%+-.1zi!\n";
	i = ft_printf(str, 0);
	j = printf(str, 0);
	str = "TEST :!et %+.i et!\n";
	i = ft_printf(str, 0);
	j = printf(str, 0);
	printf("i:%d, j:%d\n", i, j);
	//i = ft_printf(str, 4);
	//j = printf(str, 4);


}

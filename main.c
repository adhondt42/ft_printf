#include "inc/ft_printf.h"

int main()
{
int i;
int j;
char *str;

/*	str = "TEST :42%+02.1zd42!\n";
	i = ft_printf(str, 0);
	j = printf(str, 0);
	printf("i:%d, j:%d\n", i, j);
	//i = ft_printf(str, 4);
	//j = printf(str, 4);
*/
	ft_printf("%%d Lydie == |%d|", 503);
	ft_printf("\n");
	printf("%%d Lydie == |%d|", 503);

}

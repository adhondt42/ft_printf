#include "inc/ft_printf.h"

int main()
{
int i;
int j;
char *str;
#include <limits.h>
/*
	str = "!%%-i 42 == %-i!";
	i = ft_printf(str, 42);
	j = printf(str, 42);
	printf("i:%d, j:%d\n", i, j);
	*/i = ft_printf("!/!%#5hx!/!", 937080078);
	printf("\n");
	i = printf("!/!%#5hx!/!", 937080078);
	printf("\n");

}

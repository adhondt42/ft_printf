/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:28:18 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:24:03 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_neg(long long *n, int *count, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*count += 1;
		*neg = 1;
	}
	else
		*neg = 0;
}

char			*ft_litoa(long long n)
{
	int			count;
	long long	j;
	char		*num;
	int			neg;

	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	count = 1;
	ft_neg(&n, &count, &neg);
	j = n;
	while (j /= 10)
		count++;
	if ((num = (char *)malloc(sizeof(char) * count + 1)) == NULL)
		return (NULL);
	num[count] = '\0';
	while (count-- > 0)
	{
		num[count] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == 1)
		num[0] = '-';
	return (num);
}

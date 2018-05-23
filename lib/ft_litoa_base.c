/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:44:47 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/16 21:34:15 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_litoa_base(long long value, int base, int upper)
{
	char		*str;
	long long	temp;
	int			count;

	count = 0;
	temp = value;
	while (temp != 0)
	{
		count++;
		temp /= base;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	str[count--] = '\0';
	while (value != 0)
	{
		str[count] = value % base;
		if (upper)
			str[count] > 9 ? str[count--] += 55 : (str[count--] += '0');
		else
			str[count] > 9 ? str[count--] += 87 : (str[count--] += '0');
		value /= base;
	}
	return (str);
}

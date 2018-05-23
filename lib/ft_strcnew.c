/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:46:24 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:24:55 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_strcnew(size_t n, char c)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ret[n] = '\0';
	while (i != n)
		ret[i++] = c;
	return (ret);
}

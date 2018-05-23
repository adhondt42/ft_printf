/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nendchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:45:25 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:22:23 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char					*add_nendchar(char *str, char c, size_t n)
{
	char				*ret;
	unsigned long		i;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + n + 1))))
		return (NULL);
	ret[ft_strlen(str) + n] = '\0';
	ft_strcpy(ret, str);
	i = 0;
	while (ft_strlen(str) + i != ft_strlen(str) + n)
		ret[ft_strlen(str) + i++] = c;
	free(str);
	return (ret);
}

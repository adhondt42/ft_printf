/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nfrontchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:44:13 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:22:03 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*add_nfrontchar(char *str, char c, size_t n)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1 + n))))
		return (NULL);
	ret[ft_strlen(str) + n] = '\0';
	while (i != n)
		ret[i++] = c;
	ft_strcpy(ret + n, str);
	free(str);
	return (ret);
}

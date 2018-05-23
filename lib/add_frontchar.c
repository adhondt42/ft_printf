/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_frontchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:40:43 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:21:49 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*add_frontchar(char *str, char c)
{
	char	*ret;

	if (!str)
	{
		free(str);
		return (ft_strdup("\0"));
	}
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	ret[0] = c;
	ret[ft_strlen(str)] = '\0';
	ft_strcpy(ret + 1, str);
	free(str);
	return (ret);
}

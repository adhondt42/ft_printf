/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_in_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:37:01 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/27 15:37:16 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				pos_in_str(char c, char *str)
{
	int			i;

	i = 0;
	if (c == 0 || !str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	return (-1);
}

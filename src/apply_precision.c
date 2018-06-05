/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:28:47 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 19:01:34 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*o_exception(char *str)
{
	free(str);
	return (ft_strdup(""));
}

char		*apply_precision_ii(t_pm *s, char *str)
{
	char *ret;

	if (s->precision > 0)
	{
		if ((ret = ft_memalloc_c(s->precision, '0')) == NULL)
		{
			ft_putstr("\nMalloc Error\n");
			exit(0);
		}
		free(str);
	}
	else
	{
		ret = (s->i == 2) ? ft_strdup("") : ft_strdup("0");
		free(str);
	}
	return (ret);
}

char		*apply_precision(t_pm *s, char *str)
{
	char	*ret;
	int		neg;

	neg = (str[0] == '-') ? 1 : 0;
	if (ft_strlen(str) == 0 && (s->i == 6 || s->i == 7) && s->precision >= 0)
	{
		ret = ft_strdup("");
	}
	else if (ft_strlen(str) == 0)
		ret = apply_precision_ii(s, str);
	else if (s->precision > 0 && s->precision > (ft_strlen(str) - neg))
	{
		ret = ft_strcnew(s->precision + neg, '0');
		ft_strcpy(ret + (ft_strlen(ret) - (ft_strlen(str) - neg)), str + neg);
		neg ? ret[0] = '-' : 0;
		free(str);
	}
	else
	{
		ret = ft_strdup(str);
		free(str);
	}
	return (ret);
}

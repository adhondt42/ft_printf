/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:49:36 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 17:50:25 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*apply_flags_u_ii(t_pm *s, char *str, int *i)
{
	char	*ret;

	(void)s;
	ret = NULL;
	if (str[0] == '0' && str[1] == '\0' && s->precision >= 0 &&
	((s->i != 8 && s->i != 9) || ((s->i == 8 && s->precision <= 0) || (s->i == 9 && s->precision <= 0))))
		ret = ft_chardup('+');
	else
		ret = add_frontchar(str, '+');
		*i = 1;
	return (ret);
}

char		*apply_flags_u(t_pm *s, char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (s->flags[4] == ' ' && s->flags[3] != '+' && str[0] != '-' && s->i != 10
			&& s->i != 11 && s->i != 12 && s->i >= 0)
	{
		if (str[0] == '0' && str[1] == '\0' && s->precision >= 0 && s->i != 8
		&& s->i != 9)
			ret = ft_chardup(' ');
		else
		{
			ret = add_frontchar(str, ' ');
			i = 1;
		}
	}
	else if (s->flags[3] == '+' && str[0] != '-' && s->i != 10 && s->i != 11 &&
			s->i >= 0)
		ret = apply_flags_u_ii(s, str, &i);
	else if (str[0] == '0' && str[1] == '\0' && s->precision >= 0 && (
	(s->i != 9 && s->i != 8) || ((s->i == 8 && s->precision < 1) || (s->i == 9 && s->precision < 1))))
		ret = ft_chardup('\0');
	else
		ret = ft_strdup(str);
	i == 0 ? free(str) : 0;
	return (ret);
}

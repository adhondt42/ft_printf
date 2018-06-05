/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:49:36 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 20:47:20 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*apply_flags_u_ii(t_pm *s, char *str)
{
	char	*ret;

	(void)s;
	ret = NULL;
	if (str[0] == '0' && str[1] == '\0' && s->precision >= 0 &&
			((s->i != 8 && s->i != 9) || ((s->i == 8 && s->precision <= 0) ||
				(s->i == 9 && s->precision <= 0))))
		ret = ft_chardup('+');
	else
		ret = add_frontchar(str, '+');
	return (ret);
}

char		*apply_flags_u(t_pm *s, char *str)
{
	char	*ret;

	if (s->flags[4] == ' ' && s->flags[3] != '+' && str[0] != '-' &&
			!inteq(10, 11, 12, s->i))
	{
		if (str[0] == '0' && str[1] == '\0' && s->precision >= 0 && s->i != 8
				&& s->i != 9)
			ret = ft_chardup(' ');
		else
			ret = add_frontchar(str, ' ');
	}
	else if (s->flags[3] == '+' && str[0] != '-' && !inteq(10, 11, 11, s->i))
		ret = apply_flags_u_ii(s, str);
	else if (str[0] == '0' && str[1] == '\0' && s->precision >= 0 && (
				(s->i != 9 && s->i != 8) || ((s->i == 8 && s->precision < 1) ||
					(s->i == 9 && s->precision < 1))))
		ret = ft_chardup('\0');
	else
		ret = ft_strdup(str);
	free(str);
	return (ret);
}

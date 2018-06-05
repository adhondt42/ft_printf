/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_min_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:18:05 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 20:43:13 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		get_sign(char *str)
{
	if (str[0] == '+' || str[1] == '+')
		return ('+');
	else if (str[0] == '-' || str[1] == '-')
		return ('-');
	else
		return (0);
}

char		*adapt_min_size(char *ret, int sp, char sign)
{
	if (sp)
	{
		ret[0] = ' ';
		ret[0 + pos_in_str(' ', ret + 1) + 1] = '0';
	}
	if (sign)
	{
		ret[0 + sp] = sign;
		ret[pos_in_str(sign, (ret + sp + (sign != 0))) + 1] = '0';
	}
	return (ret);
}

char		*apply_min_size_ii(t_pm *s, char *str)
{
	char	*ret;

	ret = NULL;
	if ((s->i != 14 || (s->i == 14 && s->precision < 0)) &&
			(!s->letter || (s->letter > 0 && s->flags[1] != '0')))
		ret = add_nfrontchar(str, ' ', s->min_size - ft_strlen(str));
	else if ((s->i == 14 && s->precision >= 0 && s->flags[1] == '0')
			|| (s->letter > 0 && s->flags[1] == '0'))
		ret = add_nfrontchar(str, '0', s->min_size - ft_strlen(str));
	return (ret);
}

char		*apply_min_size(t_pm *s, char *str)
{
	char	*ret;
	char	sign;
	int		sp;

	if (s->min_size <= ft_strlen(str))
		return (str);
	if ((s->i == 10 || s->i == 11) && s->flags[0] == '#' && s->exception == 1
			&& ft_strcmp(str, "0") != 0)
		s->min_size -= 2;
	if (s->flags[2] != '-')
	{
		if (s->precision >= 0 || s->flags[1] != '0')
			ret = apply_min_size_ii(s, str);
		else
		{
			sp = (str[0] == ' ') ? 1 : 0;
			sign = get_sign(str);
			ret = add_nfrontchar(str, '0', s->min_size - ft_strlen(str));
			ret = adapt_min_size(ret, sp, sign);
		}
	}
	else
		ret = (s->min_size - ft_strlen(str) > 0) ? add_nendchar(str, ' ',
				s->min_size - ft_strlen(str)) : ft_strdup(str);
	return (ret);
}

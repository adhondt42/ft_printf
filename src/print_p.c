/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:48:51 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:19:04 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char					*apply_p_minsize(t_pm *s, char *str, char c)
{
	char				*ret;

	if (s->min_size > ft_strlen(str) && s->flags[2] != '-'
			&& s->flags[1] != '0')
	{
		ret = add_nfrontchar(str, c, s->min_size - ft_strlen(str));
	}
	else if ((s->min_size > ft_strlen(str) && s->flags[2] == '-') ||
			(s->min_size > ft_strlen(str) && s->flags[1] == '0'))
		ret = add_nendchar(str, c, s->min_size - ft_strlen(str));
	else
		ret = str;
	return (ret);
}

void					print_p(t_pm *s, void *elem)
{
	char				*str;
	unsigned long int	i;

	if (!elem && s->precision < 0)
		str = ft_strdup("0");
	else if (!elem && s->precision >= 0)
		str = ft_strdup("");
	else
	{
		i = (unsigned long int)elem;
		str = ft_ulitoa_base(i, 16, 0);
	}
	str = apply_precision(s, str);
	str = ft_strjoin_f("0x", str, 2);
	str = s->flags[1] == '0' ? apply_p_minsize(s, str, '0') :
		apply_p_minsize(s, str, ' ');
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
	return ;
}

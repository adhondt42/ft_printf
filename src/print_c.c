/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:13:04 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/12 19:34:28 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*delete_sp(t_pm *s, char *str)
{
	char	*ret;

	ret = ft_strcnew(ft_strlen(str) - 1, ' ');
	s->ret += 1;
	return (ret);
}

void		print_c_ii(t_pm *s)
{
	if (s->min_size >= 2 && s->flags[2] != '-')
	{
		s->flags[1] == '0' ? ft_putnchar('0', s->min_size - 1) :
			ft_putnchar(' ', s->min_size - 1);
		s->ret += s->min_size - 1;
	}
	ft_putchar(0);
	if (s->min_size >= 2 && s->flags[2] == '-')
	{
		ft_putnchar(' ', s->min_size - 1);
		s->ret += s->min_size - 1;
	}
	s->ret += 1;
	return ;
}

void		print_c(t_pm *s, void *elem)
{
	char	*str;

	if ((char)elem == 0)
	{
		print_c_ii(s);
		return ;
	}
	else
		str = ft_chardup((char)elem);
	str = apply_flags(s, str);
	str = apply_min_size(s, str);
	if ((char)elem == 0)
		str = delete_sp(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

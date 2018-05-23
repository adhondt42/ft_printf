/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_each_style.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:15:18 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:53:16 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_ret(t_pm *s, int size)
{
	if (size <= 0)
		return ;
	else
		s->ret += size;
}

void			nada(void)
{
	return ;
}

void			print_s_ii(t_pm *s, char *str)
{
	s->ret += ft_strlen(str);
	ft_putstr(str);
	if (s->min_size && s->flags[2] == '-')
	{
		if (s->flags[1] == '0')
			ft_putnchar('0', (s->min_size - ft_strlen(str)));
		else
			ft_putnchar(' ', (s->min_size - ft_strlen(str)));
		s->ret += (s->min_size - ft_strlen(str));
	}
}

void			print_s(t_pm *s, void *elem)
{
	char		*str;

	if (elem == NULL || (int)elem < 32)
		str = ft_strdup("(null)");
	else
		str = ft_strdup((char *)elem);
	if (s->precision >= 0 && s->precision < ft_strlen(str))
		str[s->precision] = '\0';
	if (s->min_size && s->flags[2] != '-')
	{
		if (s->flags[1] == '0')
			ft_putnchar('0', (s->min_size - ft_strlen(str)));
		else
			ft_putnchar(' ', (s->min_size - ft_strlen(str)));
		ft_ret(s, (s->min_size - ft_strlen(str)));
	}
	print_s_ii(s, str);
	free(str);
}

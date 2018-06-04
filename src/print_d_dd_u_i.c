/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_each_style.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:15:18 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 16:05:57 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		print_d(t_pm *s, void *elem)
{
	char	*str;

	str = get_size_modified(s, elem, 'd');
	str = apply_precision_d(s, str);
	str = apply_flags_d(s, str);
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		print_i(t_pm *s, void *elem)
{
	char	*str;

	str = get_size_modified(s, elem, 'i');
	str = apply_precision(s, str);
	str = apply_flags_d(s, str);
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		print_u(t_pm *s, void *elem)
{
	char	*str;

	str = get_size_modified(s, elem, 'u');
	str = apply_precision(s, str);
	if (s->flags[4] == ' ')
		s->flags[4] = '.';
	if (s->flags[3] == '+')
		s->flags[3] = '.';
	str = apply_flags(s, str);
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		print_dd(t_pm *s, void *elem)
{
	char	*str;

	str = get_size_modified(s, elem, 'D');
	str = apply_precision(s, str);
	str = apply_flags(s, str);
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

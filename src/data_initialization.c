/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:17:48 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/23 13:09:10 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			init_s(t_pm **s)
{
	if (!(*s = (t_pm *)malloc(sizeof(t_pm))))
	{
		ft_putstr("\nMalloc Error\n");
		exit(0);
	}
	if (!((*s)->flags = ft_memalloc_c(4, '.')))
	{
		ft_putstr("\nMalloc Error\n");
		exit(0);
	}
	(*s)->spec_lst = "sSpdDioOuUxXcC%";
	(*s)->precision = -1;
	(*s)->min_size = 0;
	(*s)->size_modif = 0;
	(*s)->ret = 0;
	(*s)->isneg = 0;
	(*s)->i = 0;
	(*s)->exception = 0;
	(*s)->letter = 0;
}

void			init_f(void (*f[14])(t_pm *, void *))
{
	f[0] = print_s;
	f[1] = nada;
	f[2] = print_p;
	f[3] = nada;
	f[4] = print_dd;
	f[5] = print_i;
	f[6] = print_o;
	f[7] = print_o;
	f[8] = print_u;
	f[9] = print_u;
	f[10] = print_x;
	f[11] = print_xx;
	f[12] = print_c;
	f[13] = nada;
	f[14] = print_modulo;
}

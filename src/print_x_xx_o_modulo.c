/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_xx_o_modulo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:20:22 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 17:07:35 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

char		*add_ox(char *str, char c)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3))))
	{
		ft_putstr("\nMalloc Error\n");
		exit(0);
	}
	while (j != i)
		ret[j++] = ' ';
	ret[j] = '0';
	ret[j + 1] = c;
	ft_strcpy(ret + j + 2, str + i);
	free(str);
	return (ret);
}

int			test(t_pm *s, void *elem)
{
	int	bouh;

	if (s->size_modif == 'H')
		bouh = (unsigned char)elem == 0 ? 0 : 1;
	else if (s->size_modif == 'h')
		bouh = (unsigned short)elem == 0 ? 0 : 1;
	else if (s->size_modif == 'L')
		bouh = (unsigned long long)elem == 0 ? 0 : 1;
	else if (s->size_modif == 'l')
		bouh = (unsigned long)elem == 0 ? 0 : 1;
	else if (s->size_modif == 'j')
		bouh = (uintmax_t)elem == 0 ? 0 : 1;
	else if (s->size_modif == 'z')
		bouh = (size_t)elem == 0 ? 0 : 1;
	else
		bouh = (int)elem == 0 ? 0 : 1;
	return (bouh);
}

void		print_x(t_pm *s, void *elem)
{
	char	*str;
	int		i;

	i = test(s, elem);
	str = get_size_modified(s, elem, 'x');
	str = apply_precision(s, str);
	str = apply_flags(s, str);
	if (s->precision < 0)
	{
		s->exception = 1;
		str = apply_min_size_x(s, str);
	}
	if (s->flags[0] == '#' && i
			&& ft_strcmp(str, "") != 0)
		str = add_ox(str, 'x');
	else if (ft_strcmp(str, "") == 0 && s->precision > 0)
		str = ft_strdup_f("0", str);
	str = apply_min_size_x(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		print_xx(t_pm *s, void *elem)
{
	char	*str;
	int		i;

	i = test(s, elem);
	str = get_size_modified(s, elem, 'X');
	str = apply_precision(s, str);
	str = apply_flags(s, str);
	if (s->precision < 0)
	{
		s->exception = 1;
		str = apply_min_size_x(s, str);
	}
	if (s->flags[0] == '#' && i
			&& ft_strcmp(str, "") != 0)
		str = add_ox(str, 'X');
	else if (ft_strcmp(str, "") == 0 && s->precision > 0)
		str = ft_strdup_f("0", str);
	str = apply_min_size_x(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		print_o(t_pm *s, void *elem)
{
	char	*str;

	if (!elem && s->precision > 0)
		str = ft_strdup("0");
	else if (!elem && s->precision <= 0)
		str = ft_strdup("");
	else
		str = get_size_modified(s, elem, 'o');
	if (s->flags[0] == '#' && ft_strcmp(str, "0") != 0)
	{
		str = ft_strjoin_f("0", str, 2);
	}
	str = apply_precision(s, str);
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		print_modulo(t_pm *s, void *elem)
{
	char	*str;

	if (elem)
		;
	str = ft_strdup("%");
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

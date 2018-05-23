/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:15:37 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/22 21:18:34 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				get_precision(t_pm *s, char *str, int i)
{
	if (ft_isdigit(str[i + 1]))
	{
		s->precision = (ft_isdigit(str[i + 1])) ?
			(ft_atoi(str + i + 1)) : 0;
		i += intlen(s->precision) + 1;
	}
	else
	{
		s->precision = 0;
		i++;
	}
	return (i);
}

int				get_modifier(t_pm *s, char *str, int i)
{
	s->size_modif = (str[i + 1] == str[i] || str[i - 1] == str[i]) ?
		(str[i] - 32) : str[i];
	(s->size_modif >= 'a') ? i++ : (i += 2);
	return (i);
}

int				get_bad_specifier(t_pm *s, char *str, int *xpt, int i)
{
	s->letter = str[i];
	*xpt = i;
	return (-1);
}

int				get_min_size(t_pm *s, char *str, int i)
{
	s->min_size = ft_atoi(str + i);
	i += intlen(s->min_size);
	return (i);
}

char			get_spec(t_pm *s, char *str, int i, int *xpt)
{
	static char	flaglist[5] = {'#', '0', '-', '+', ' '};
	static char	sizem_list[4] = {'h', 'l', 'j', 'z'};
	int			n;

	n = 0;
	*xpt = 0;
	while ((pos_in_str(str[i], s->spec_lst) < 0) && str[i])
	{
		if ((n = pos_in_str(str[i], sizem_list)) >= 0)
			i = get_modifier(s, str, i);
		else if ((n = pos_in_str(str[i], flaglist)) >= 0)
			s->flags[n] = str[i++];
		else if (str[i] == '.')
			i = get_precision(s, str, i);
		else if (ft_isdigit(str[i]) && str[i] > '0')
			i = get_min_size(s, str, i);
		else if (ft_isalpha(str[i]))
			return (get_bad_specifier(s, str, xpt, i));
		else
			i++;
	}
	if (str[i] == '\0')
		return (-2);
	return (str[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:29:58 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 12:52:45 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			*modif_u(t_pm *s, void *elem)
{
	if (s->size_modif == 'h' && s->i != 9)
		return (ft_uitoa((unsigned short)elem));
	else if (s->size_modif == 'H' && s->i != 9)
		return (ft_uitoa((unsigned char)elem));
	else if (s->size_modif == 'l' || s->size_modif == 'L'
			|| s->size_modif == 'j' || s->i == 9)
		return (ft_uitoa((unsigned long long)elem));
	else if (s->size_modif == 'z')
		return (ft_uitoa((size_t)elem));
	else if (s->i == 8)
		return (ft_uitoa((unsigned int)(elem)));
	return (0);
}

void			*modif_int(t_pm *s, void *elem, char c)
{
	if ((s->size_modif == 'H' || s->size_modif == 'h') && (c == 'D'))
		return (ft_litoa((long long)elem));
	if (s->size_modif == 'h')
		return (ft_itoa((short)elem));
	else if (s->size_modif == 'H')
		return (ft_itoa((signed char)elem));
	else if (s->size_modif == 'l' || s->size_modif == 'L'
			|| s->size_modif == 'j')
		return (ft_litoa((long long)elem));
	else if (s->size_modif == 'z')
		return (ft_litoa((size_t)elem));
	else if (c == 'D')
		return (ft_litoa((long)(elem)));
	else
		return (ft_itoa((int)(elem)));
	return (0);
}

void			*modif_x(t_pm *s, void *elem, char c)
{
	if (s->size_modif == 'h')
		return (ft_uitoa_base((unsigned short)elem, 16, c == 'X'));
	else if (s->size_modif == 'H')
		return (ft_uitoa_base((unsigned char)elem, 16, c == 'X'));
	else if (s->size_modif == 'l' || s->size_modif == 'L'
			|| s->size_modif == 'j')
		return (ft_ulitoa_base((unsigned long long)elem, 16, c == 'X'));
	else if (s->size_modif == 'z')
		return (ft_ulitoa_base((size_t)elem, 16, c == 'X'));
	else
		return (ft_uitoa_base((int)(elem), 16, c == 'X'));
	return (0);
}

void			*modif_o(t_pm *s, void *elem, char c)
{
	if (s->size_modif == 'h' && s->i != 7)
		return (ft_uitoa_base((unsigned short)elem, 8, c == 'X'));
	else if (s->size_modif == 'H' && s->i != 7)
		return (ft_uitoa_base((unsigned char)elem, 8, c == 'X'));
	else if (s->size_modif == 'l' || s->size_modif == 'L'
			|| s->size_modif == 'j' || s->i == 7)
		return (ft_ulitoa_base((unsigned long long)elem, 8, c == 'X'));
	else if (s->size_modif == 'z')
		return (ft_ulitoa_base((size_t)elem, 8, c == 'X'));
	else
		return (ft_uitoa_base((int)(elem), 8, c == 'X'));
	return (0);
}

char			*get_size_modified(t_pm *s, void *elem, char c)
{
	char		*str;

	str = NULL;
	if (!elem)
		return (ft_strdup("\0"));
	else if (c == 'd' || c == 'i' || c == 'D')
		str = modif_int(s, elem, c);
	else if (c == 'u')
		str = modif_u(s, elem);
	else if (c == 'x' || c == 'X')
		str = modif_x(s, elem, c);
	else if (c == 'o' || c == 'O')
		str = modif_o(s, elem, c);
	else
		return (str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:25:06 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/17 19:26:03 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strnotchr(const char *s, int c)
{
	char	*cs;

	cs = (char *)s;
	while (*cs == c && *cs)
		cs++;
	if (*cs != c)
		return (cs);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:11:02 by adhondt           #+#    #+#             */
/*   Updated: 2017/11/28 20:44:51 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	*ft_memalloc_c(size_t size, int c)
{
	void	*dest;

	if ((dest = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_memset(dest, c, size);
	return (dest);
}

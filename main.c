/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:19:25 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/23 13:26:37 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int main()
{

	printf("%d\n", 2445);
	ft_printf("%d\n", 2445);
	printf("%lld\n", 2445);
	ft_printf("%lld\n", 2445);
	printf("%hd\n", 2445);
	ft_printf("%hd\n", 2445);
	printf("%zd\n", 2445);
	ft_printf("%zd\n", 2445);
	printf("%zd|%d|\n", 2445, 45);
	ft_printf("%zd|%d|\n", 2445, 45);
}

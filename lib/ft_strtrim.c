/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:55:38 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 13:19:22 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_count(char const *s, int i, int len)
{
	int	len2;

	len2 = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		len2++;
	}
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s++;
		len2++;
	}
	if (*s == '\0')
		len2 = len;
	return (len2);
}

char			*ft_strtrim(char const *s)
{
	int		len2;
	char	*str;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = len - 1;
	len2 = ft_count(s, i, len);
	str = (char*)malloc(sizeof(char) * (len - len2 + 1));
	if (str == NULL)
		return (str);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	i = 0;
	while (s[i] != '\0' && i < len - len2)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

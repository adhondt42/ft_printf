/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:15:41 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 20:55:19 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		error_bad_flag(t_pm *s)
{
	char *str;

	str = ft_chardup((char)s->letter);
	str = apply_min_size(s, str);
	s->ret += ft_strlen(str);
	ft_putstr(str);
}

int			check_flag(char *str, char *flg)
{
	int		i;

	i = 0;
	while (pos_in_str(str[i], flg) < 0 && str[i] &&
			(pos_in_str(str[i], "hljz") >= 0 || !ft_isalpha(str[i])))
		i++;
	if (str[i] == '\0' && str[i] != '%')
		return (-1);
	else if (pos_in_str(str[i], flg) >= 0 && str[i] != '%')
		return (1);
	return (0);
}

int			ft_run(const char *str, void *elem, int *ret)
{
	t_pm	*s;
	int		xpt;
	void	(*f[14])(t_pm *, void *);

	init_s(&s);
	init_f(f);
	s->i = pos_in_str((get_spec(s, (char *)(str + 1), 0, &xpt)), s->spec_lst);
	if (s->i >= 0)
		f[s->i](s, elem);
	else if (s->letter)
		error_bad_flag(s);
	*ret += s->ret;
	free(s->flags);
	free(s);
	return (xpt);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	va;
	int		ret;

	ret = 0;
	va_start(va, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			j = check_flag((char *)str + i + 1, "sSpdDioOuUxXcC%");
			if (j == 1)
				ft_run((str + i++), va_arg(va, void *), &ret);
			else if (j == 0)
				ft_run((str + i++), NULL, &ret);
			while ((!ft_isalpha(str[i]) || pos_in_str(str[i], "hljz") >= 0)
					&& str[i] && str[i] != '%')
				i++;
		}
		else
			(ret++) ? ft_putchar(str[i]) : ft_putchar(str[i]);
	}
	return (ret);
}

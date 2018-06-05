/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:15:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/05 20:55:17 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>



#include <stdio.h>

typedef struct	s_pm
{
	char		*spec_lst;
	char		*flags;
	int			precision;
	int			min_size;
	int			size_modif;
	int			ret;
	int			isneg;
	int			i;
	int			exception;
	int			letter;
	int			star;
}				t_pm;

int				ft_printf(const char *str, ...);
char			*apply_flags(t_pm *s, char *str);
char			*apply_flags_d(t_pm *s, char *str);
char			*apply_flags_u(t_pm *s, char *str);
char			*apply_min_size(t_pm *s, char *str);
char			*apply_min_size_x(t_pm *s, char *str);
char			*apply_precision(t_pm *s, char *str);
char			*apply_precision_d(t_pm *s, char *str);
char			*get_size_modified(t_pm *s, void *elem, char c);
int				test(t_pm *s, void *elem);
void			init_s(t_pm **s);
void			init_f(void (*f[14])(t_pm *, void *));
char			get_spec(t_pm *s, char *str, int i, int *xpt);
void			nada();
void			print_s(t_pm *s, void *elem);
void			print_p(t_pm *s, void *elem);
void			print_d(t_pm *s, void *elem);
void			print_dd(t_pm *s, void *elem);
void			print_i(t_pm *s, void *elem);
void			print_o(t_pm *s, void *elem);
void			print_u(t_pm *s, void *elem);
void			print_x(t_pm *s, void *elem);
void			print_xx(t_pm *s, void *elem);
void			print_c(t_pm *s, void *elem);
void			print_modulo(t_pm *s, void *elem);

char			*ft_itoa(int n);
int				ft_isalpha(int c);
void			ft_putchar(char c);
char			*ft_uitoa(uintmax_t n);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *s);
char			*ft_strtrim(char const *s);
void			*ft_memalloc(size_t size);
int				ft_strlen(const char *src);
void			pf_putstr(t_pm *s, char *str);
int				pos_in_str(char c, char *str);
int				ft_isalpha_but(int c, char *str);
char			*ft_strnotchr(const char *s, int c);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strdup_f(const char *s, char *str);
int				inteq(int a, int b, int c, int ref);
char			*ft_strcpy(char *dest, const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*add_nfrontchar(char *str, char c, size_t n);
char			*ft_uitoa_base(unsigned int value, int base, int up);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_ulitoa_base(unsigned long value, int base, int up);
char			*ft_strjoin_f(char const *s1, char const *s2, int j);
char			*ft_litoa_base(long long value, int base, int upper);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_itoa_base(int value, int base, int upper);
int				ft_strcmp(const char *tab, const char *tab2);
char			*add_nendchar(char *str, char c, size_t n);
char			*ft_strcat(char *dest, const char *src);
void			pf_putnchar(t_pm *s, char c, int n);
void			*ft_memalloc_c(size_t size, int c);
char			*add_frontchar(char *str, char c);
char			*ft_strcnew(size_t n, char c);
void			pf_putchar(t_pm *s, char c);
void			ft_putnchar(char c, int n);
int				ft_atoi(const char *str);
char			*ft_litoa(long long n);
char			*ft_chardup(char c);
int				ft_isdigit(int c);
void			ft_putnbr(int n);
int				intlen(int nb);

#endif

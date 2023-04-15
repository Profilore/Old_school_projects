/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 07:12:52 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 12:37:06 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define HEXA "0123456789abcdef"
# define HEXAUP "0123456789ABCDEF"
# define DECI "0123456789"
# define FLAGS "# +-"
# define CONVER "cspdiuxX%"
# define ALL "0123456789cspdiuxX%# +-"

typedef struct s_all
{
	int		hash;
	int		space;
	int		plus;
	int		cnt;
	int		pls_bool;
	int		width;
	int		dash;
	int		spaces;
	int		digits;
	int		fr_bool;
	int		bk_bool;
}			t_all;

t_all	*init_all(void);
size_t	parse_flags(const char *str, t_all *all, int i);
void	parse_str(const char *str, t_all *all, va_list *arg, int i);
void	retreave_flag(char c, va_list *arg, t_all *all);
void	pf_sruct_clean(t_all *all);
int		ft_printf(const char *str, ...);
int		pf_putstr(char *str, t_all *all);
int		pf_putnbr(int n, t_all *all);
int		pf_putnbr_pls_sp(t_all *all);
int		pf_nbr(int n, t_all *all);
int		pf_putchar(char c);
int		pf_putchar_pf(char c, t_all *all);
size_t	pf_strlen(char *s);
int		pf_putu(unsigned int nb, t_all *all);
char	*pf_strchr(const char *s, int c);
int		pf_puthexa(unsigned int nb, const char *b, t_all *all);
int		pf_hex(unsigned int nb, const char *b, t_all *all);
int		pf_puthexaup(unsigned int nb, const char *b, t_all *all);
int		pf_hexup(unsigned int nb, const char *b, t_all *all);
int		pf_putpointer(void *p, t_all *all);
int		pf_hexapoint(unsigned long long int nb, const char *b);
void	error_handle(t_all *all);
void	cnt_digits(t_all *all, size_t len);
int		cnt_nb_len_u(long long unsigned nb, t_all *all, int base);
int		cnt_nb_len_s(long long int nb, t_all *all, int base);
int		parse_nums(const char *str, t_all *all);

#endif

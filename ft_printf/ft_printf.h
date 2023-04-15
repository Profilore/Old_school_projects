/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 07:12:52 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 12:37:59 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXA "0123456789abcdef"

int		ft_printf(const char *str, ...);
int		pf_putchar(char c);
int		pf_putnbr(int nb);
int		pf_puthexa(unsigned int nb, const char *b);
int		pf_puthexaup(unsigned int nb, const char *b);
int		pf_hexapoint(unsigned long long int nb, const char *b);
int		retreave_flag(char c, va_list *arg);
int		pf_putstr(char *str);
int		pf_putpointer(void *p);
int		pf_putu(unsigned int nb);
char	*pf_strchr(const char *s, int c);
size_t	pf_strlen(char *s);

#endif

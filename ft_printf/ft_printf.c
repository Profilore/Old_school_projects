/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:47:30 by nlavinia          #+#    #+#             */
/*   Updated: 2021/12/04 21:56:55 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	retreave_flag(char c, va_list *arg)
{
	if (c == 's')
		return (pf_putstr(va_arg(*arg, char *)));
	if (c == 'c')
		return (pf_putchar(va_arg(*arg, int)));
	if (c == 'i' || c == 'd')
		return (pf_putnbr(va_arg(*arg, int)));
	if (c == 'u')
		return (pf_putu(va_arg(*arg, int)));
	if (c == 'x')
		return (pf_puthexa(va_arg(*arg, unsigned int), HEXA));
	if (c == 'X')
		return (pf_puthexaup(va_arg(*arg, unsigned int), HEXA));
	if (c == 'p')
		return (pf_putpointer(va_arg(*arg, void *)));
	if (c == '%')
		return (pf_putchar(c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		cnt;

	cnt = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && pf_strchr("cspdiuxX%", str[i + 1]))
		{
			cnt += retreave_flag(str[++i], &arg);
			i++;
		}
		else
		{
			cnt += pf_putchar(str[i]);
			i++;
		}
	}
	va_end (arg);
	return (cnt);
}

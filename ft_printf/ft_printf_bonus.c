/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:34:37 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 09:44:32 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

t_all	*init_all(void)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->hash = 0;
	all->space = 0;
	all->cnt = 0;
	all->plus = 0;
	all->pls_bool = 0;
	all->width = 0;
	all->dash = 0;
	all->spaces = 0;
	all->digits = 0;
	all->fr_bool = 0;
	all->bk_bool = 0;
	return (all);
}

size_t	parse_flags(const char *str, t_all *all, int i)
{
	while (pf_strchr(FLAGS, str[i]))
	{
		if (str[i] == '#')
		{
			all->hash = 1;
			i++;
		}
		else if (str[i] == ' ')
		{
			all->space = 1;
			i++;
		}
		else if (str[i] == '+')
		{
			all->plus = 1;
			i++;
		}
		else if (str[i] == '-')
		{
			all->dash = 1;
			i++;
		}
	}
	return (i);
}

void	retreave_flag(char c, va_list *arg, t_all *all)
{
	if (pf_strchr("%", c))
		pf_sruct_clean(all);
	if (c == 's')
		all->cnt += pf_putstr(va_arg(*arg, char *), all);
	if (c == 'c')
		all->cnt += pf_putchar_pf(va_arg(*arg, int), all);
	if (c == 'i' || c == 'd')
		all->cnt += pf_putnbr(va_arg(*arg, int), all);
	if (c == 'u')
		all->cnt += pf_putu(va_arg(*arg, int), all);
	if (c == 'x')
		all->cnt += pf_puthexa(va_arg(*arg, unsigned int), HEXA, all);
	if (c == 'X')
		all->cnt += pf_puthexaup(va_arg(*arg, unsigned int), HEXAUP, all);
	if (c == 'p')
		all->cnt += pf_putpointer(va_arg(*arg, void *), all);
	if (c == '%')
		all->cnt += pf_putchar(c);
}

void	pf_sruct_clean(t_all *all)
{
	all->hash = 0;
	all->space = 0;
	all->plus = 0;
	all->pls_bool = 0;
	all->width = 0;
	all->dash = 0;
	all->spaces = 0;
	all->digits = 0;
	all->fr_bool = 0;
	all->bk_bool = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_all	*all;
	int		cnt;
	int		i;

	i = 0;
	all = init_all();
	if (!all)
		return (0);
	cnt = 0;
	va_start(arg, str);
	parse_str(str, all, &arg, i);
	va_end(arg);
	cnt = all->cnt;
	free(all);
	return (cnt);
}

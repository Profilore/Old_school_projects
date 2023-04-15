/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:33:30 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 12:27:22 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	parse_str(const char *str, t_all *all, va_list *arg, int i)
{
	while (str[i])
	{
		if (str[i] == '%' && pf_strchr(ALL, str[i + 1]))
		{
			i += parse_flags(&(str[i + 1]), all, 0);
			i += parse_nums(&(str[i + 1]), all);
			if (pf_strchr(CONVER, str[i + 1]))
			{
				retreave_flag(str[++i], &(*arg), all);
				i++;
			}
		}
		else
			all->cnt += pf_putchar(str[i++]);
		pf_sruct_clean(all);
	}
}

int	parse_nums(const char *str, t_all *all)
{
	int		i;
	char	*start;

	i = 0;
	while (pf_strchr(DECI, str[i]))
		i++;
	start = malloc(i + 1);
	if (!start)
		error_handle(all);
	i = -1;
	while (pf_strchr(DECI, str[++i]))
		start[i] = str[i];
	start[i] = '\0';
	all->width = atoi(start);
	free(start);
	return (i);
}

int	pf_putnbr_pls_sp(t_all *all)
{
	int	cnt;

	cnt = 0;
	if (all->plus == 1 && all->pls_bool == 0)
	{
		cnt += pf_putchar('+');
		all->plus = 0;
		all->pls_bool = 1;
	}
	else if (all->space == 1 && all->pls_bool == 0)
	{
		cnt += pf_putchar(' ');
		all->space = 0;
	}
	return (cnt);
}

void	error_handle(t_all *all)
{
	free(all);
	write(1, "Error\n", 7);
	exit(1);
}

//spaces = ho many spaces to print
void	cnt_digits(t_all *all, size_t len)
{
	if (all->width != 0 && all->width > (int)len)
		all->spaces = all->width - (int)len;
	all->digits = len;
}

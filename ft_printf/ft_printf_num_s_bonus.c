/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_s_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:53:00 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 12:24:37 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	pf_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	pf_strlen(char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	pf_putnbr(int n, t_all *all)
{
	int				cnt;
	long long int	nb;

	cnt = 0;
	nb = n;
	cnt_digits(all, cnt_nb_len_s(nb, all, 10));
	if (all->dash == 0)
		while (all->spaces-- > 0)
			cnt += write(1, " ", 1);
	cnt += pf_nbr(nb, all);
	while (all->dash != 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	return (cnt);
}

int	pf_putstr(char *str, t_all *all)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		cnt += write(1, "(null)", 6);
		return (cnt);
	}
	cnt_digits(all, pf_strlen(str));
	while (all->dash == 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	while (*str)
		cnt += pf_putchar(*(str++));
	while (all->dash != 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	return (cnt);
}

int	pf_putpointer(void *p, t_all *all)
{
	int	cnt;

	cnt = 0;
	cnt_digits(all, cnt_nb_len_u((unsigned long long int)p, all, 16));
	while (all->dash == 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	cnt += write(1, "0x", 2);
	all->spaces -= 2;
	cnt += pf_hexapoint((unsigned long long int)p, HEXA);
	while (all->dash != 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	return (cnt);
}

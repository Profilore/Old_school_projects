/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:34:37 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 12:25:14 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	pf_hexup(unsigned int nb, const char *b, t_all *all)
{
	int		cnt;
	char	c;

	cnt = 0;
	c = 0;
	if (nb >= 16)
		cnt += pf_hexup(nb / 16, b, all);
	c = (char)(b[nb % 16]);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	cnt += pf_putchar(c);
	return (cnt);
}

int	pf_hex(unsigned int nb, const char *b, t_all *all)
{
	int		cnt;

	cnt = 0;
	if (nb >= 16)
		cnt += pf_hex(nb / 16, b, all);
	cnt += pf_putchar((char)(b[nb % 16]));
	return (cnt);
}

int	pf_nbr(int n, t_all *all)
{
	int				cnt;
	long long int	nb;

	cnt = 0;
	nb = n;
	if (nb < 0)
	{
		cnt += pf_putchar('-');
		nb = (unsigned int)(nb * -1);
		all->pls_bool = 1;
	}
	else
	{
		cnt += pf_putnbr_pls_sp(all);
		nb = (unsigned int)nb;
	}
	if (nb >= 10)
		cnt += pf_nbr(nb / 10, all);
	cnt += pf_putchar((char)(nb % 10 + '0'));
	return (cnt);
}

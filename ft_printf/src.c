/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:46 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/06 13:47:23 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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

int	pf_putnbr(int n)
{
	int				cnt;
	long long int	nb;

	cnt = 0;
	nb = n;
	if (nb < 0)
	{
		cnt += pf_putchar('-');
		nb = (unsigned int)(nb * -1);
	}
	else
		nb = (unsigned int)nb;
	if (nb >= 10)
		cnt += pf_putnbr(nb / 10);
	cnt += pf_putchar((char)(nb % 10 + '0'));
	return (cnt);
}

int	pf_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		cnt += write(1, "(null)", 6);
		return (cnt);
	}
	while (str[cnt])
		pf_putchar(str[cnt++]);
	return (cnt);
}

int	pf_putpointer(void *p)
{
	int	cnt;

	cnt = 0;
	cnt += write(1, "0x", 2);
	cnt += pf_hexapoint((unsigned long long int)p, HEXA);
	return (cnt);
}

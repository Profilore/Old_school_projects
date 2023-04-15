/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:42:31 by nlavinia          #+#    #+#             */
/*   Updated: 2021/12/04 21:56:47 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pf_putu(unsigned int nb)
{
	int	cnt;

	cnt = 0;
	if (nb >= 10)
		cnt += pf_putnbr(nb / 10);
	cnt += pf_putchar((char)(nb % 10 + '0'));
	return (cnt);
}

char	*pf_strchr(const char *s, int c)
{
	while ((unsigned char)c != *s && *s != '\0')
	{
		s++;
	}
	if ((unsigned char)c == *s)
		return ((char *) s);
	else
		return (NULL);
}

int	pf_puthexa(unsigned int nb, const char *b)
{
	int		cnt;

	cnt = 0;
	if (nb >= 16)
		cnt += pf_puthexa(nb / 16, b);
	cnt += pf_putchar((char)(b[nb % 16]));
	return (cnt);
}

int	pf_puthexaup(unsigned int nb, const char *b)
{
	int		cnt;
	char	c;

	cnt = 0;
	c = 0;
	if (nb >= 16)
		cnt += pf_puthexaup(nb / 16, b);
	c = (char)(b[nb % 16]);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	cnt += pf_putchar(c);
	return (cnt);
}

int	pf_hexapoint(unsigned long long int nb, const char *b)
{
	int		cnt;

	cnt = 0;
	if (nb >= 16)
		cnt += pf_hexapoint(nb / 16, b);
	cnt += pf_putchar((char)(b[nb % 16]));
	return (cnt);
}

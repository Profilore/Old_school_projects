/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_p_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:14:22 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 12:25:58 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	pf_putu(unsigned int nb, t_all *all)
{
	int	cnt;

	cnt = 0;
	cnt_digits(all, cnt_nb_len_u(nb, all, 10));
	while (all->dash == 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	if (nb >= 10)
		cnt += pf_nbr(nb / 10, all);
	cnt += pf_putchar((char)(nb % 10 + '0'));
	while (all->dash != 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
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

int	pf_puthexa(unsigned int nb, const char *b, t_all *all)
{
	int		cnt;

	cnt = 0;
	cnt_digits(all, cnt_nb_len_u(nb, all, 16));
	if (all->hash == 1 && nb != 0)
		all->spaces -= 2;
	if (all->dash == 0 && all->spaces > 0)
		while (all->spaces-- > 0)
			cnt += write(1, " ", 1);
	if (all->hash == 1 && nb != 0)
		cnt += write(1, "0x", 2);
	cnt += pf_hex(nb, b, all);
	while (all->dash == 1 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	return (cnt);
}

int	pf_puthexaup(unsigned int nb, const char *b, t_all *all)
{
	int		cnt;

	cnt = 0;
	cnt_digits(all, cnt_nb_len_u(nb, all, 16));
	if (all->hash == 1 && nb != 0)
		all->spaces -= 2;
	if (all->dash == 0 && all->spaces > 0)
		while (all->spaces-- > 0)
			cnt += write(1, " ", 1);
	if (all->hash == 1 && nb != 0)
		cnt += write(1, "0X", 2);
	cnt += pf_hexup(nb, b, all);
	while (all->dash == 1 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
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

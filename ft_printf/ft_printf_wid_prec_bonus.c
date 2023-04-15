/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wid_prec_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:33:30 by nlavinia          #+#    #+#             */
/*   Updated: 2022/07/07 11:28:46 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	cnt_nb_len_u(long long unsigned nb, t_all *all, int base)
{
	int	cnt;

	cnt = 0;
	if (all->plus == 1 || all->space == 1)
		cnt++;
	while (nb >= (unsigned)base)
	{
		nb /= base;
		cnt++;
	}
	cnt++;
	return (cnt);
}

int	cnt_nb_len_s(long long int nb, t_all *all, int base)
{
	int	cnt;

	cnt = 0;
	if (all->plus == 1 || all->space == 1 || nb < 0)
		cnt++;
	if (nb < 0)
		nb *= -1;
	while (nb >= base)
	{
		nb /= base;
		cnt++;
	}
	cnt++;
	return (cnt);
}

int	pf_putchar_pf(char c, t_all *all)
{
	int	cnt;

	cnt = 0;
	cnt_digits(all, 1);
	while (all->dash == 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	cnt += write(1, &c, 1);
	while (all->dash != 0 && all->spaces-- > 0)
		cnt += write(1, " ", 1);
	return (cnt);
}

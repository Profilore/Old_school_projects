/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <wbungo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:54:18 by wbungo            #+#    #+#             */
/*   Updated: 2022/10/14 14:55:21 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	check_sign(const char *str, int *i)
{
	if (*str == '-')
		*i = -1;
}

long long	ft_atoll(const char *str, long *nbr)
{
	int					i[2];
	unsigned long long	out;
	unsigned long long	max;

	i[0] = 0;
	i[1] = 1;
	out = 0;
	max = 9223372036854775807;
	while (ft_isspace(*str))
		str++;
	check_sign(str, &i[1]);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (str && ft_isdigit(*str))
	{
		out = out * 10 + (*str - '0');
		if ((i[1] > 0 && out <= max) || (i[1] < 0 && out <= (max + 1)))
			str++;
		else
			return (-1);
	}
	*nbr = (long)(i[1] * out);
	return (0);
}

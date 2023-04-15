/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:56:12 by nlavinia          #+#    #+#             */
/*   Updated: 2022/10/17 16:03:55 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				last;
	unsigned char	c_unsigned;

	c_unsigned = (unsigned char)c;
	if (c_unsigned == '\0')
		return ((char *)&s[ft_strlen(s)]);
	last = ft_strlen(s) - 1;
	if (last < 0)
		return (NULL);
	while (last >= 0)
	{
		if (s[last] == c_unsigned)
			return ((char *)&s[last]);
		last--;
	}
	return (NULL);
}

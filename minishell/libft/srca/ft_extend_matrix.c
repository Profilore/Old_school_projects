/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:56:09 by nlavinia          #+#    #+#             */
/*   Updated: 2022/10/17 16:05:18 by nlavinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_extend_matrix(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = ft_matrixlen(in);
	out = malloc(sizeof(char *) * (len + 2));
	out[len + 1] = NULL;
	if (!out)
		return (in);
	while (++i < len)
	{
		out[i] = ft_strdup(in[i]);
		if (!out[i])
		{
			ft_free_matrix(&in);
			ft_free_matrix(&out);
		}
	}
	out[i] = ft_strdup(newstr);
	ft_free_matrix(&in);
	return (out);
}

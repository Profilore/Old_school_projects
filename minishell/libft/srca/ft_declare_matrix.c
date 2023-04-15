/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:56:09 by nlavinia          #+#    #+#             */
/*   Updated: 2022/10/18 15:42:39 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	sort_init(char **tmp)
{
	int		strncmp;
	int		i;
	int		j;
	char	*tmp_2;

	tmp_2 = NULL;
	i = -1;
	while ((tmp)[++i])
	{
		j = i;
		while ((tmp)[++j])
		{
			strncmp = ft_strncmp((tmp)[i], (tmp)[j], ft_strlen((tmp)[j]));
			if (strncmp > 0)
			{
				tmp_2 = (tmp)[i];
				(tmp)[i] = (tmp)[j];
				(tmp)[j] = tmp_2;
			}
		}
	}
	return (0);
}

static void	free_tmp(char ***tmp)
{
	int		i;
	char	**p;

	p = *tmp;
	i = 0;
	if (p)
	{
		if (p[i])
		{
			while (p[i])
			{
				free(p[i]);
				i++;
			}
		}
		free(p);
	}
	tmp = NULL;
}

char	*add_declare_init(char *str2)
{
	char	**tmp;
	char	*full;
	char	*str1;
	char	*out;

	if (!str2)
		return (NULL);
	tmp = ft_split(str2, '=');
	str1 = malloc(strlen(tmp[1]) + 4);
	ft_strlcpy(str1, "=\"", 3);
	ft_strlcat(str1, tmp[1], (ft_strlen(tmp[1]) + ft_strlen(str1) + 2));
	ft_strlcat(str1, "\"", (ft_strlen(str1) + 3));
	full = ft_strjoin(tmp[0], str1);
	out = ft_strjoin("declare -x ", full);
	free (str1);
	free (str2);
	free (full);
	free_tmp(&tmp);
	return (out);
}

char	**ft_declare_matrix(char **m)
{
	char	**out;
	int		i;

	i = 0;
	out = malloc(sizeof(char *) * (ft_matrixlen(m) + 1));
	if (!out)
		return (NULL);
	while (m && m[i])
	{
		out[i] = ft_strdup(m[i]);
		if (!out[i])
		{
			ft_free_matrix(&out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	sort_init(out);
	i = -1;
	while (m && m[++i])
		out[i] = add_declare_init(out[i]);
	out[i] = NULL;
	return (out);
}

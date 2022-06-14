/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:32:50 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/02/18 17:16:37 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free_res(char **res, int len)
{
	while (len--)
		free(res[len]);
	free(res);
}

static int	new_word(char **res, int w, int size)
{
	res[w] = (char *)malloc(size + 1);
	if (!res[w])
	{
		ft_free_res(res, w);
		return (0);
	}
	res[w][size] = '\0';
	return (1);
}

static int	ft_skip_sep(const char *s, char **res, const char *set)
{
	int	w;
	int	i;
	int	j;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (!ft_strchr(set, s[i]))
		{
			j = i;
			i++;
			while (!ft_strchr(set, s[i]) && s[i])
				i++;
			if (!new_word(res, w, i - j))
				return (0);
			ft_memmove(res[w], s + j, i - j);
			w++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char const *set)
{
	char	**res;
	int		i;
	int		size_res;

	i = 0;
	size_res = 1;
	while (s[i])
	{
		if (!ft_strchr(set, s[i]))
		{
			size_res++;
			i++;
			while (!ft_strchr(set, s[i]) && s[i])
				i++;
		}
		else
			i++;
	}
	res = (char **)malloc(size_res * sizeof(char *));
	if (!res)
		return (NULL);
	res[size_res - 1] = NULL;
	if (!ft_skip_sep(s, res, set))
		return (NULL);
	return (res);
}

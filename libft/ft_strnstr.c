/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:06:12 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/11/26 21:38:16 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = ft_strlen(little);
	i = 0;
	if (!n)
		return ((char *)big);
	while (len-- && big[i])
	{
		j = 0;
		while (j < len + 1 && big[i + j] && little[j] == big[i + j])
			j++;
		if (j == n)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

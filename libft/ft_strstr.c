/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:32:53 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/03/05 14:37:20 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	n2;

	n = ft_strlen(little);
	n2 = ft_strlen(big);
	i = 0;
	if (n > n2)
		return (NULL);
	if (!n)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (j < n && i + j < n2 && little[j] == big[i + j])
			j++;
		if (j == n)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

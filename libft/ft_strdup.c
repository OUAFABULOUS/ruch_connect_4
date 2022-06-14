/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:53:28 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/03/05 14:36:25 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s) + 1;
	str = (char *)malloc(n);
	if (!str)
		return (NULL);
	return ((char *)ft_memcpy(str, s, n));
}

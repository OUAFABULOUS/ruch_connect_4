/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:28:31 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/11/23 10:13:26 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n_dest;
	size_t	n_src;

	n_src = ft_strlen(src);
	n_dest = ft_strlen(dest);
	if (size <= n_dest)
		return (n_src + size);
	while (*dest)
		dest++;
	ft_strlcpy(dest, src, size - n_dest);
	return (n_src + n_dest);
}

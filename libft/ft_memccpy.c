/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:59:30 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/11/26 21:35:27 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = dest;
	while (n--)
	{
		*tmp++ = *((char *)src++);
		if (*(tmp - 1) == (unsigned char)c)
			return (tmp);
	}
	return (NULL);
}

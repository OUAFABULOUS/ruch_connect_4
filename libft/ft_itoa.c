/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:05:01 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/11/19 13:56:28 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		res_size;
	int		x;

	res_size = 1;
	x = n;
	while (x / 10)
	{
		res_size++;
		x /= 10;
	}
	res = (char *)malloc(res_size + 1 + (n < 0));
	if (!res)
		return (NULL);
	res[res_size + (n < 0)] = '\0';
	if (n < 0)
		*res = '-';
	while (res_size--)
	{
		res[res_size + (n < 0)] = '0' - (n % 10 * (n < 0))
			+ n % 10 * (n >= 0);
		n /= 10;
	}
	return (res);
}

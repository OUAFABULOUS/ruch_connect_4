/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieu <ldrieu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:41:13 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/03/08 14:56:58 by ldrieu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strcmp_lower(const char *s1, const char *s2)
{
	unsigned char	n1;
	unsigned char	n2;

	while (*s1 || *s2)
	{
		if (*s1 && *s2 && !*(s1 + 1) && !*(s2 + 1)
			&& *s1 != *s2 && *s1 == ft_toupper(*s1) && *s1 == ft_toupper(*s2))
			return (*s2 - *s1);
		n1 = ft_tolower(*s1);
		n2 = ft_tolower(*s2);
		if (n1 != n2)
			return (n1 - n2);
		s1++;
		s2++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:36:10 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/11/29 11:31:07 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) - start;
	if (s_len >= len)
		s_len = len;
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (NULL);
	while (*s && start--)
		s++;
	ft_memcpy(str, s, s_len * sizeof(char));
	str[s_len] = '\0';
	return (str);
}

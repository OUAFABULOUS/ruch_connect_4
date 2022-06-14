/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:09:52 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/03/05 14:35:59 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	num_len(char *num)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(*num))
	{
		len++;
		num++;
	}
	return (len);
}

static inline int	do_str_neg_case(char *str,
	const char *min, const char *max, int ret)
{
	size_t	len;
	size_t	len_min;
	size_t	len_max;

	len_min = ft_strlen(min) - 1;
	str++;
	if (!*str)
		return (0);
	while (*str == '0' && *(str + 1))
		str++;
	len = num_len(str);
	if (len > len_min)
		ret = 0;
	else if (len == len_min)
		ret &= (ft_strncmp(str, min + 1, len) <= 0);
	if (*max == '-')
	{
		len_max = ft_strlen(max) - 1;
		if (len < len_max)
			ret = 0;
		else if (len == len_max)
			ret &= (ft_strncmp(str, max + 1, len) >= 0);
		return (ret);
	}
	return (ret);
}

static inline int	do_str_pos_case(char *str,
	const char *min, const char *max, int ret)
{
	size_t	len;
	size_t	len_min;
	size_t	len_max;

	if (*str == '+')
		str++;
	while (*str == '0' && *(str + 1))
		str++;
	len = num_len(str);
	len_max = ft_strlen(max);
	if (len > len_max)
		ret = 0;
	else if (len == len_max)
		ret &= (ft_strncmp(str, max, len) <= 0);
	if (*min != '-')
	{
		len_min = ft_strlen(min);
		if (len < len_min)
			ret = 0;
		else if (len == len_min)
			ret &= (ft_strncmp(str, min, len) >= 0);
	}
	return (ret);
}

int	str_is_numeric(char *str, const char *min, const char *max)
{
	int	i;

	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	if (*str == '-' && *min == '-')
		return (do_str_neg_case(str, min, max, 1));
	else if (*str != '-' && *max != '-')
		return (do_str_pos_case(str, min, max, 1));
	return (0);
}

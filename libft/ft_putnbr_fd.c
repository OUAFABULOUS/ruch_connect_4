/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:46:46 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/11/19 16:41:48 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_bis(int n, int fd)
{
	if (n == 0)
		return ;
	ft_putnbr_bis(n / 10, fd);
	if (n >= 0)
		ft_putchar_fd(n % 10 + '0', fd);
	else
		ft_putchar_fd('0' - n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_bis(n, fd);
}

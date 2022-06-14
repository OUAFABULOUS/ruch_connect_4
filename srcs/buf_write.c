/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:49:36 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/06/11 11:51:35 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

int	buf_write(t_buf *buf, int fd, const void *src, int n)
{
	if (buf->len + n >= BUFFER_SIZE)
	{
		if (write(fd, buf->buf, buf->len) == -1)
		{
			buf->len = 0;
			return (1);
		}
		buf->len = 0;
		if (write(fd, src, n) == -1)
			return (1);
	}
	else
	{
		ft_memcpy(buf->buf + buf->len, src, n);
		buf->len += n;
	}
	return (0);
}
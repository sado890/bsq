/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:16:49 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 15:18:50 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*apd_buff_ret(char *buf)
{
	free(buf);
	return (NULL);
}

char	*append_buf(char *buf, size_t blen, char *chunk, ssize_t clen)
{
	size_t	total;
	char	*newbuf;
	size_t	i;

	i = 0;
	total = blen + (ssize_t)clen + 1;
	newbuf = (char *)malloc(total);
	if (!newbuf)
		return (apd_buff_ret(buf));
	while (i < blen && buf != NULL)
	{
		newbuf[i] = buf[i];
		i++;
	}
	i = 0;
	while (i < (size_t)clen)
	{
		newbuf[i + blen] = chunk[i];
		i++;
	}
	newbuf[blen + (size_t)clen] = '\0';
	free(buf);
	return (newbuf);
}

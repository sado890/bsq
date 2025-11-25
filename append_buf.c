/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:16:49 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/25 23:29:43 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *append_buf(char *buf, size_t buf_len, char *chunk, ssize_t chunk_len)
{
	size_t total;
	char *newbuf;
	size_t	i;

	i = 0;
	total = buf_len + (ssize_t)chunk_len + 1;
	newbuf = malloc(total);
	if (!newbuf)
	{
		free(buf);
		return NULL;
	}
	while (i < buf_len && buf != NULL)
	{
		newbuf[i] = buf[i];
		i++;
	}
	i = 0;
	while (i < (size_t)chunk_len)
	{
		newbuf[i + buf_len] = chunk[i];
		i++;
	}
	newbuf[buf_len + (size_t)chunk_len] = '\0';
	free(buf);
	return (newbuf);
}

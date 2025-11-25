/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:39:39 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 01:46:37 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char	*read_file(char *filename)
{
	int	fd;
	char *buf;

	if (filename == NULL)
	{
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = read_fd_to_buffer(fd);
	close(fd);
	return (buf);
}
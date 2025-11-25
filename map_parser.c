/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:46:31 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 00:52:44 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *skip_first_line(char *content)
{
	int i;

	i = 0;
	while (content[i] && content[i] != '\n')
	{
		i++;
	}
	if (content[i] == '\0')
	{
		return (NULL);
	}
	return (content + i + 1);
}

int get_line_length(char *map_start)
{
    int i;

    i = 0;
    while (map_start[i] && map_start[i] != '\n')
    {
        i++;
    }
    return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:46:31 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 15:33:06 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*skip_first_line(char *content)
{
	int	i;

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

int	get_line_length(char *map_start)
{
	int	i;

	i = 0;
	while (map_start[i] && map_start[i] != '\n')
		i++;
	return (i);
}

char	**allocate_map_data(int rows, int cols)
{
	char	**map_data;
	int		i;

	map_data = (char **)malloc(sizeof(char *) * rows);
	if (!map_data)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_data[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map_data[i])
		{
			free_map_data(map_data, i);
			return (NULL);
		}
		i++;
	}
	return (map_data);
}

void	free_map_data(char **map_data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:14:15 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 08:37:47 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int parse_map_body(char *content, t_map *map)
{
	int		i;
	int		j;
	char	*ptr;
	int 	len;
	
	ptr = skip_first_line(content);
	if (!ptr)
		return (0);
	map->cols = get_line_length(ptr);
	if (map->cols == 0)
		return (0);
	map->map_data = allocate_map_data(map->rows, map->cols);
	if (!map->map_data)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		len = get_line_length(ptr);
		if (len != map->cols)
			return (0);
		j = 0;
		while (j < map->cols)
		{
			map->map_data[i][j] = *ptr;
			j++;
			ptr++;
		}
		map->map_data[i][j] = '\0';
		if (*ptr != '\n')
			return (0);
		ptr++;
		i++;
	}
	return (1);
}
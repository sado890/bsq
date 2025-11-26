/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:14:15 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 16:20:58 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_map_body(char *content, t_map *map)
{
	int		i;
	int		j;
	char	*ptr;
	int		len;

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
			if (ptr[j] != map->empty && ptr[j] != map->obs)
				return (0);
			map->map_data[i][j] = ptr[j];
			j++;
		}
		map->map_data[i][j] = '\0';
		ptr += map->cols;
		if (*ptr == '\n')
			ptr++;
		else if (i < map->rows - 1)
			return (0);
		i++;
	}
	return (1);
}

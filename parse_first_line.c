/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:06:50 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 16:50:43 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_first_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	parse_first_line(char *line, t_map *map)
{
	char	obs;
	char	empty;
	char	full;
	int		len;

	len = get_first_line_len(line);
	if (len < 4)
	{
		return (0);
	}
	empty = line[len - 3];
	obs = line[len - 2];
	full = line[len - 1];
	if (!are_chars_valid(empty, obs, full))
	{
		return (0);
	}
	return (fl_compleate(map, line));
}

int	fl_compleate(t_map *map, char *line)
{
	int		len;
	char	obs;
	char	empty;
	char	full;
	int		rows;

	len = get_first_line_len(line);
	empty = line[len - 3];
	obs = line[len - 2];
	full = line[len - 1];
	rows = str_to_positive_int(line, len - 3);
	if (rows == -1 || rows == 0)
	{
		return (0);
	}
	map->empty = empty;
	map->full = full;
	map->obs = obs;
	map->rows = rows;
	return (1);
}

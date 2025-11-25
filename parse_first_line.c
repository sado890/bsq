/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:06:50 by muarici           #+#    #+#             */
/*   Updated: 2025/11/25 21:18:16 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

 int parse_first_line(char *line, t_map *map)
 {
	int rows;
	char obs;
	char empty;
	char full;
	int len;
	
	len = get_clean_len(line);
	if (len < 4)
	{
		return 0;
	}
	empty = line[len - 3];
	obs = line[len - 2];
	full = line[len - 1];
	if (!are_chars_valid(empty,obs,full))
	{
		return 0;
	}
	rows = str_to_positive_int(line, len - 3);
	if (rows == -1)
	{
		return 0;
	}
	map->empty = empty;
	map->full = full;
	map->obs = obs;
	map->rows = rows;
	return (1);
 }
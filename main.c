/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:11:39 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 15:35:48 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void	mark_square(t_map *map)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	start_row = map->square.row - map->square.size + 1;
	start_col = map->square.col - map->square.size + 1;
	i = 0;
	while (i < map->square.size)
	{
		j = 0;
		while (j < map->square.size)
		{
			map->map_data[start_row + i][start_col + j] = map->full;
			j++;
		}
		i++;
	}
}

void	free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

int	solve_map(t_map *map)
{
	int	**dp;

	dp = allocate_dp(map->rows, map->cols);
	if (!dp)
		return (0);
	init_dp_borders(dp, map);
	fill_dp_table(dp, map);
	map->square = find_max_square(dp, map);
	free_dp(dp, map->rows);
	if (map->square.size > 0)
		mark_square(map);
	return (1);
}

int	process_map(char *content)
{
	t_map	map;

	if (!parse_first_line(content, &map))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	if (!parse_map_body(content, &map))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	if (!solve_map(&map))
	{
		free_map_data(map.map_data, map.rows);
		write(2, "map error\n", 10);
		return (0);
	}
	print_map(&map);
	free_map_data(map.map_data, map.rows);
	return (1);
}

int	process_file(char *filename)
{
	char	*content;
	int		result;

	content = read_file(filename);
	if (!content)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	result = process_map(content);
	free(content);
	return (result);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*content;

	if (argc == 1)
	{
		content = read_stdin();
		if (!content)
		{
			write(2, "map error\n", 10);
			return (1);
		}
		process_map(content);
		free(content);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			process_file(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
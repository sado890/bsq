/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:17:18 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 16:20:22 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

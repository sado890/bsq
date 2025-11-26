/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dp_borders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:55 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 11:32:17 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_dp_borders(int **dp, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->cols)
	{
		if (map->map_data[0][i] == map->empty)
			dp[0][i] = 1;
		else
			dp[0][i] = 0;
		i++;
	}
	j = 0;
	while (j < map->rows)
	{
		if (map->map_data[j][0] == map->empty)
			dp[j][0] = 1;
		else
			dp[j][0] = 0;
		j++;
	}
}

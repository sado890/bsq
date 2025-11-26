/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:44:58 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 14:14:43 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_square	find_max_square(int **dp, t_map *map)
{
	t_square	result;
	int			i;
	int			j;

	result.size = 0;
	result.row = 0;
	result.col = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (dp[i][j] > result.size)
			{
				result.size = dp[i][j];
				result.row = i;
				result.col = j;
			}
			j++;
		}
		i++;
	}
	return (result);
}

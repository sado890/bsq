/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_dp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:50 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 03:42:17 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**allocate_dp(int rows, int cols)
{
	int	**dp;
	int	i;
	int j;

	i = 0;
	dp = (int **)malloc(rows * sizeof(int *));
	if (!dp)
		return (NULL);
	while (i < rows)
	{
		dp[i] = (int *)malloc(cols * sizeof(int));
		if (!dp[i])
		{
			j = 0;
			while (j < i)
			{
				free(dp[i]);
				i++;
			}
			free(dp);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

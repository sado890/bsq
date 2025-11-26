/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:48:53 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 09:55:49 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void print_map(t_map *map)
{
	int i;

	i = 0;
	while(map->map_data[i] && map->map_data[i] != '\0')
	{
		write(1,map->map_data[i],map->cols);
		write(1, "\n", 1);
		i++;
	}
	write(1,"\n",1);
}
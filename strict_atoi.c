/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:52:37 by muarici           #+#    #+#             */
/*   Updated: 2025/11/25 20:53:31 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int str_to_positive_int(char *str, int len)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < len)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
		{
			return (-1);
		}
		else
		{
			nb = nb * 10 + (str[i] - '0');
		}
		i++;
	}
	return (nb);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:53:55 by muarici           #+#    #+#             */
/*   Updated: 2025/11/25 21:02:04 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int are_chars_valid(char empty, char obs, char full)
{
	if (!(ft_is_printable(empty) && ft_is_printable(obs) && ft_is_printable(full)))
		return 0;
	else if (empty == obs || empty == full || obs == full)
		return 0;
		
	return 1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:53:55 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 15:40:06 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	are_chars_valid(char empty, char obs, char full)
{
	if (!(ft_is_printable(empty)
			&& ft_is_printable(obs)
			&& ft_is_printable(full)))
		return (0);
	else if (empty == obs || empty == full || obs == full)
		return (0);
	return (1);
}

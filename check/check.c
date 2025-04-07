/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:10:04 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 16:21:43 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(mlx_game *var)
{
	if (shape_check(var))
		return (ft_putstr("Eroor in shape\n"), 0);
	else if (wall_check(var))
		return (ft_putstr("Eroor in  walls\n"), 0);
	else if (elements_check(var) || valid_characters(var))
		return (ft_putstr("Eroor in  elements\n"), 0);
	else if (player_pass(var))
		return (ft_putstr("Eroor in  Game\n"), 0);
	else 
	{
		var->width = ft_strlen_newline(var->map[0]);
		var->height = var->count;
		if(var->width > WIDTH || var->height > HEIGHT)
			return (ft_putstr("Size mape to long\n"), 0);
		return (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:10:04 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/04 14:16:58 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(mlx_game *var)
{
	if (shape_check(var))
	{
		printf("Eroor in shape\n");
		return (0);
	}
	if (wall_check(var))
	{
		printf("Eroor in  walls\n");
		return (0);
	}
	if (elements_check(var) || valid_characters(var))
	{
		printf("Eroor in  elements\n");
		return (0);
	}
	if (player_pass(var))
	{
		printf("Eroor in  Game\n");
		return (0);
	}
	return (1);
}

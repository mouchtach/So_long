/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:45:47 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 21:07:59 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	push_to_window(mlx_game *var)
{
	int i;
	int j;

	i = 0;
	while(var->map[i])
	{
		j = 0;
		while(var->map[i][j])
		{
			if (mlx_image_to_window(var->mlx_init, var->imgs.load_background, j * TILE_SIZE, i * TILE_SIZE) == -1)
				return (false);
			if (var->map[i][j] == '1')
				if (mlx_image_to_window(var->mlx_init, var->imgs.load_wall, j * TILE_SIZE, i * TILE_SIZE) == -1)
					return (false);
			if (var->map[i][j] == 'C')
				if (mlx_image_to_window(var->mlx_init, var->imgs.load_coin, j * TILE_SIZE, i * TILE_SIZE) == -1)
					return (false);
			if (var->map[i][j] == 'E')
				if (mlx_image_to_window(var->mlx_init, var->imgs.load_exit_0, j * TILE_SIZE, i * TILE_SIZE) == -1)
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	so_long(mlx_game *var)
{
	if(!check_texture_loading(var))
		return (ft_putstr("Error in loading png\n"), false);
	var->mlx_init = mlx_init(var->width * TILE_SIZE, var->height * TILE_SIZE, "so_long", false);
	imgs_loading(var);
	clear_load_png(var);
	if(!push_to_window(var))
		return (ft_putstr("Error in push imgs\n"), false);
	if (mlx_image_to_window(var->mlx_init, var->imgs.load_player, var->p_y * TILE_SIZE, var->p_x * TILE_SIZE) == -1)
		return (ft_putstr("Error in push imgs\n"), false);
	// printf("x y = %c\n", var->map[var->p_y / TILE_SIZE][var->p_x / TILE_SIZE]);
	// printf("py = %d \n px = %d\n", var->p_y, var->p_x);
	// printf("x + 1 = %c\n", var->map[var->p_x][var->p_y + 1]);
	// printf("x - 1 = %c\n", var->map[var->p_x][var->p_y - 1]);
	// printf("y - 1 = %c\n", var->map[var->p_x - 1][var->p_y]);
	// printf("y + 1 = %c\n", var->map[var->p_x + 1][var->p_y]);
	moves(var);
	mlx_loop(var->mlx_init);
	return(true);
	
}
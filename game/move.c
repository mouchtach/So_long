/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:16:20 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 21:53:55 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_1(mlx_game *var)
{
	int	i;
    int j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'E')
			{
				var->load.load_exit_1 = mlx_load_png(PATH_EXIT_1);
				var->imgs.load_exit_1 = mlx_texture_to_image(var->mlx_init , var->load.load_exit_1);
				mlx_image_to_window(var->mlx_init, var->imgs.load_exit_1, j * TILE_SIZE, i * TILE_SIZE);
				mlx_delete_texture(var->load.load_exit_1);
				return ;
			}
			j++;
		}
		i++;
	}
}

// py = 32 
//  px = 1
// x + 1 = 1
// x - 1 = 0
// y - 1 = 1
// y + 1 = 1

void	func(mlx_key_data_t keydata, void *param)
{

    mlx_game *var = (mlx_game *)param;
    mlx_image_t *player = (mlx_image_t *)(var->imgs.load_player);
	printf("A = %c\n", var->map[var->p_x ][var->p_y - 1]);

	if(keydata.key == MLX_KEY_A  && keydata.action && var->map[var->p_x][var->p_y - 1] != '1')
		right(var, player);
	else if(keydata.key == MLX_KEY_D  && keydata.action && var->map[var->p_x][var->p_y + 1] != '1')
		left(var, player);
	else if(keydata.key == MLX_KEY_W  && keydata.action && var->map[var->p_x - 1][var->p_y] != '1')
		up(var, player);
	else if(keydata.key == MLX_KEY_S  && keydata.action && var->map[var->p_x + 1][var->p_y] != '1')
		down(var, player);
	else 
}

void    moves(mlx_game *var)
{
	

    // mlx_key_hook(game.mlx, &my_keyhook, &game);

    mlx_key_hook(var->mlx_init, &func, var);

    // mlx_loop_hook(var->mlx_init, &function, var);
}
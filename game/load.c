/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:29:10 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 17:03:53 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void clear_texture(mlx_game *var)
{
	if (var->load.load_background)
		mlx_delete_texture(var->load.load_background); 
	if (var->load.load_player)
		mlx_delete_texture(var->load.load_player); 
	if (var->load.load_wall)
		mlx_delete_texture(var->load.load_wall); 
	if (var->load.load_coin)
		mlx_delete_texture(var->load.load_coin); 
	if (var->load.load_exit_0)
		mlx_delete_texture(var->load.load_exit_0); 
	if (var->load.load_exit_1)
		mlx_delete_texture(var->load.load_exit_1); 
}

void	set_texture(mlx_game *var)
{
	var->png.background = PATH_BACKGROUND ;
	var->png.player = PATH_PLAYER ;
	var->png.wall = PATH_WALL ;
	var->png.coin = PATH_COIN ;
	var->png.exit_0 = PATH_EXIT_0 ;
	var->png.exit_1 = PATH_EXIT_1 ;
}

void	png_loading(mlx_game *var)
{
	var->load.load_background = mlx_load_png(PATH_BACKGROUND);
	var->load.load_player = mlx_load_png(PATH_PLAYER);
	var->load.load_wall = mlx_load_png(PATH_WALL);
	var->load.load_coin = mlx_load_png(PATH_COIN);
	var->load.load_exit_0 = mlx_load_png(PATH_EXIT_0);
	var->load.load_exit_1 = mlx_load_png(PATH_EXIT_1);
}

void	imgs_loading(mlx_game *var)
{
	var->imgs.load_background = mlx_texture_to_image(var->mlx_init, var->load.load_background);
	var->imgs.load_player = mlx_texture_to_image(var->mlx_init, var->load.load_player);
	var->imgs.load_wall = mlx_texture_to_image(var->mlx_init, var->load.load_wall);
	var->imgs.load_coin = mlx_texture_to_image(var->mlx_init, var->load.load_coin);
	var->imgs.load_exit_0 = mlx_texture_to_image(var->mlx_init, var->load.load_exit_0);
	var->imgs.load_exit_1 = mlx_texture_to_image(var->mlx_init, var->load.load_exit_1);
}

bool check_texture_loading(mlx_game *var)
{
	set_texture(var);
	png_loading(var);
	if (!(var->load.load_background) || !(var->load.load_coin) || !(var->load.load_exit_0) 
		|| !(var->load.load_exit_1) || !(var->load.load_player) || !(var->load.load_wall))
	{
		clear_texture(var);
		return(false);
	}
	else
		return(true);
}

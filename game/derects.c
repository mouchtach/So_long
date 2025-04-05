/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:41:46 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 21:52:32 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void up(mlx_game *var, mlx_image_t *player)
{

    if (var->map[var->p_x - 1][var->p_y] == 'C')
    {
        var->element.c -= 1;
        mlx_image_to_window(var->mlx_init, var->imgs.load_background, (var->p_x - 1) * TILE_SIZE, var->p_y * TILE_SIZE);
        mlx_image_to_window(var->mlx_init, var->imgs.load_player , (var->p_x - 1) * TILE_SIZE, var->p_y * TILE_SIZE);
    }

    player->instances[0].y -= TILE_SIZE;
	var->p_x -= 1;
    if (var->element.c == 0)
        exit_1(var);
    
}
void down(mlx_game *var, mlx_image_t *player)
{
    if (var->map[var->p_x + 1][var->p_y] == 'C')
    {
        var->element.c -= 1;
        mlx_image_to_window(var->mlx_init, var->imgs.load_background, (var->p_x ) * TILE_SIZE, var->p_y * TILE_SIZE);
        mlx_image_to_window(var->mlx_init, var->imgs.load_player , (var->p_x ) * TILE_SIZE, var->p_y * TILE_SIZE);
    }

    player->instances[0].y += TILE_SIZE;
	var->p_x += 1;
    if (var->element.c == 0)
        exit_1(var);

}
void left(mlx_game *var, mlx_image_t *player)
{
    if (var->map[var->p_x][var->p_y + 1] == 'C')
    {
        var->element.c -= 1;
        mlx_image_to_window(var->mlx_init, var->imgs.load_background, var->p_x * TILE_SIZE, (var->p_y + 1) * TILE_SIZE);
        mlx_image_to_window(var->mlx_init, var->imgs.load_player , var->p_x * TILE_SIZE, (var->p_y + 1) * TILE_SIZE);
    }   
    player->instances[0].x += TILE_SIZE;
	var->p_y += 1;
	if (var->element.c == 0)
        exit_1(var);
}
void right(mlx_game *var, mlx_image_t *player)
{
    if (var->map[var->p_x][var->p_y - 1] == 'C')
    {
        var->element.c -= 1;
        mlx_image_to_window(var->mlx_init, var->imgs.load_background, var->p_x * TILE_SIZE, (var->p_y - 1) * TILE_SIZE);
        mlx_image_to_window(var->mlx_init, var->imgs.load_player , var->p_x * TILE_SIZE, (var->p_y - 1) * TILE_SIZE);
    }
    player->instances[0].x -= TILE_SIZE;
	var->p_y -= 1;
    if (var->element.c == 0)
        exit_1(var);
}
// void esc(mlx_game *var, mlx_image_t *player)
// {

// }
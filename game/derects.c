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

bool  take_coin(mlx_game *var, int x, int y)
{

    mlx_image_to_window(var->mlx_init, var->imgs.load_background, x * TILE_SIZE, y * TILE_SIZE);
    var->map[y][x] = '0';
    mlx_delete_image(var->mlx_init, var->imgs.load_player);
    var->load.load_player = mlx_load_png(PATH_PLAYER);
    
	var->imgs.load_player = mlx_texture_to_image(var->mlx_init, var->load.load_player);
    mlx_image_to_window(var->mlx_init, var->imgs.load_player, x * TILE_SIZE, y * TILE_SIZE);
    if(var->element.c > 0)
        var->element.c -= 1;
    if(var->element.c == 0)
        exit_1(var);
    return (true); 
}

bool up(mlx_game *var, mlx_image_t *player)
{

    if (var->map[var->p_y - 1][var->p_x] == 'C')
    {
        if(!take_coin(var, var->p_x , var->p_y - 1))
            return (false);
    }
    else
        player->instances[0].y -= TILE_SIZE;
    var->p_y -= 1;
    if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
        mlx_close_window(var->mlx_init);
    return (true);
    
}
bool down(mlx_game *var, mlx_image_t *player)
{
    if (var->map[var->p_y + 1][var->p_x] == 'C')
    {
        if(!take_coin(var, var->p_x , var->p_y + 1))
            return (false);
    }
    else
        player->instances[0].y += TILE_SIZE;
    var->p_y += 1;
    if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
        mlx_close_window(var->mlx_init);
    return (true);
}

bool left(mlx_game *var, mlx_image_t *player)
{
    if (var->map[var->p_y][var->p_x + 1] == 'C')
    {
        if(!take_coin(var, var->p_x + 1 , var->p_y))
           return (false);
    }
    else
        player->instances[0].x += TILE_SIZE;
    var->p_x += 1;
    if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
        mlx_close_window(var->mlx_init);
    return (true);
}

bool  right(mlx_game *var, mlx_image_t *player)
{
    if (var->map[var->p_y][var->p_x - 1] == 'C')
    {
        if(!take_coin(var, var->p_x - 1 , var->p_y))
            return (false);
    }
    else
        player->instances[0].x -= TILE_SIZE;
    var->p_x -= 1;
    if (var->map[var->p_y][var->p_x]  == 'E' && var->element.c == 0)
        mlx_close_window(var->mlx_init);
    return (true);
}
// void esc(mlx_game *var, mlx_image_t *player)
// {

// }
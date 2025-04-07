/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:41:46 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 20:08:59 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	take_coin(t_mlx_game *var, int x, int y)
{
	mlx_image_to_window(var->mlx_init, var->imgs.load_background, x * P, y * P);
	var->map[y][x] = '0';
	mlx_delete_image(var->mlx_init, var->imgs.load_player);
	var->load.load_player = mlx_load_png(PATH_PLAYER);
	var->imgs.load_player = mlx_texture_to_image(var->mlx_init,
			var->load.load_player);
	mlx_image_to_window(var->mlx_init, var->imgs.load_player, x * P, y * P);
	if (var->element.c > 0)
		var->element.c -= 1;
	if (var->element.c == 0)
		exit_1(var);
	return (true);
}

bool	up(t_mlx_game *var, mlx_image_t *player)
{
	if (var->map[var->p_y - 1][var->p_x] == 'C')
	{
		if (!take_coin(var, var->p_x, var->p_y - 1))
			return (false);
	}
	else
		player->instances[0].y -= P;
	var->p_y -= 1;
	ft_putnbr(var->moves++);
	write(1, "\n", 1);
	if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
		end_game(var);
	return (true);
}

bool	down(t_mlx_game *var, mlx_image_t *player)
{
	if (var->map[var->p_y + 1][var->p_x] == 'C')
	{
		if (!take_coin(var, var->p_x, var->p_y + 1))
			return (false);
	}
	else
		player->instances[0].y += P;
	var->p_y += 1;
	ft_putnbr(var->moves++);
	write(1, "\n", 1);
	if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
		end_game(var);
	return (true);
}

bool	left(t_mlx_game *var, mlx_image_t *player)
{
	if (var->map[var->p_y][var->p_x + 1] == 'C')
	{
		if (!take_coin(var, var->p_x + 1, var->p_y))
			return (false);
	}
	else
		player->instances[0].x += P;
	var->p_x += 1;
	ft_putnbr(var->moves++);
	write(1, "\n", 1);
	if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
		end_game(var);
	return (true);
}

bool	right(t_mlx_game *var, mlx_image_t *player)
{
	if (var->map[var->p_y][var->p_x - 1] == 'C')
	{
		if (!take_coin(var, var->p_x - 1, var->p_y))
			return (false);
	}
	else
		player->instances[0].x -= P;
	ft_putnbr(var->moves++);
	write(1, "\n", 1);
	var->p_x -= 1;
	if (var->map[var->p_y][var->p_x] == 'E' && var->element.c == 0)
		end_game(var);
	return (true);
}

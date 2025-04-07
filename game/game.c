/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:45:47 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 21:35:56 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	my_image_to_window(t_mlx_game *var, int i, int j)
{
	if (mlx_image_to_window(var->mlx_init, var->imgs.load_background, j * P, i
			* P) == -1)
		return (false);
	if (var->map[i][j] == '1')
		if (mlx_image_to_window(var->mlx_init, var->imgs.load_wall, j * P, i
				* P) == -1)
			return (false);
	if (var->map[i][j] == 'C')
		if (mlx_image_to_window(var->mlx_init, var->imgs.load_coin, j * P, i
				* P) == -1)
			return (false);
	if (var->map[i][j] == 'E')
		if (mlx_image_to_window(var->mlx_init, var->imgs.load_exit_0, j * P, i
				* P) == -1)
			return (false);
	return (true);
}

void	end_game(t_mlx_game *var)
{
	free_map(var);
	if (var->win)
		ft_putstr("You win !\n");
	else
		ft_putstr("End Game !\n");
	mlx_close_window(var->mlx_init);
}

bool	push_to_window(t_mlx_game *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (!my_image_to_window(var, i, j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	so_long(t_mlx_game *var)
{
	if (!check_texture_loading(var))
		return (ft_putstr("Error in loading png\n"), false);
	var->mlx_init = mlx_init(var->width * P, var->height * P, "so_long", false);
	imgs_loading(var);
	clear_texture(var);
	if (!push_to_window(var))
		return (ft_putstr("Error in push imgs\n"), false);
	if (mlx_image_to_window(var->mlx_init, var->imgs.load_player, var->p_x * P,
			var->p_y * P) == -1)
		return (ft_putstr("Error in push imgs\n"), false);
	ft_putstr("Start Game !\n");
	var->moves = 1;
	var->win = false;
	moves(var);
	mlx_loop(var->mlx_init);
	return (true);
}

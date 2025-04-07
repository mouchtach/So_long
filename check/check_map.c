/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:54:31 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 20:06:39 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	shape_check(t_mlx_game *var)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen_newline(var->map[i]);
	while (var->map[i])
	{
		if (size != ft_strlen_newline(var->map[i]))
			return (1);
		size = ft_strlen_newline(var->map[i]);
		i++;
	}
	return (0);
}

int	wall_check(t_mlx_game *var)
{
	int	i;

	i = 0;
	while (var->map[0][i] == '1' && var->map[0][i] && var->map[0][i] != '\n')
		i++;
	if (!(var->map[0][i] == 0 || var->map[0][i] == '\n'))
		return (1);
	i = 0;
	while (var->map[var->count - 1][i] == '1' && var->map[0][i]
		&& var->map[0][i] != '\n')
		i++;
	if (!(var->map[0][i] == 0 || var->map[0][i] == '\n'))
		return (1);
	i = 0;
	while (i < var->count && var->map[i][0] == '1')
		i++;
	if (i != var->count)
		return (1);
	i = 0;
	while (i < var->count && var->map[i][ft_strlen_newline(var->map[i])
		- 1] == '1')
		i++;
	if (i != var->count)
		return (1);
	return (0);
}

int	valid_characters(t_mlx_game *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'C' || var->map[i][j] == 'P'
				|| var->map[i][j] == 'E')
				j++;
			else if (var->map[i][j] == '0' || var->map[i][j] == '1'
				|| var->map[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	elements_check(t_mlx_game *var)
{
	var->element.c = 0;
	var->element.p = 0;
	var->element.e = 0;
	var->element.i = 0;
	while (var->map[var->element.i])
	{
		var->element.j = 0;
		while (var->map[var->element.i][var->element.j])
		{
			if (var->map[var->element.i][var->element.j] == 'C')
				var->element.c++;
			if (var->map[var->element.i][var->element.j] == 'P')
				var->element.p++;
			if (var->map[var->element.i][var->element.j] == 'E')
				var->element.e++;
			var->element.j++;
		}
		var->element.i++;
	}
	if (check_val(var))
		return (1);
	else
		return (0);
}

int	player_pass(t_mlx_game *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'P')
			{
				var->p_x = j;
				var->p_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	if (!check_cpy(var))
		return (1);
	return (0);
}

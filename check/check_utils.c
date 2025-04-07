/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:55:32 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 20:06:39 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_val(t_mlx_game *var)
{
	if (var->element.c < 1)
		return (1);
	else if (var->element.e != 1)
		return (1);
	else if (var->element.p != 1)
		return (1);
	else
		return (0);
}

int	ft_strlen_newline(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	flood_fill(t_mlx_game *var, int x, int y)
{
	if (var->map_cpy[x][y + 1] == '0' || var->map_cpy[x][y + 1] == 'P'
		|| var->map_cpy[x][y + 1] == 'E' || var->map_cpy[x][y + 1] == 'C')
	{
		var->map_cpy[x][y + 1] = '1';
		flood_fill(var, x, y + 1);
	}
	if (var->map_cpy[x][y - 1] == '0' || var->map_cpy[x][y - 1] == 'P'
		|| var->map_cpy[x][y - 1] == 'E' || var->map_cpy[x][y - 1] == 'C')
	{
		var->map_cpy[x][y - 1] = '1';
		flood_fill(var, x, y - 1);
	}
	if (var->map_cpy[x + 1][y] == '0' || var->map_cpy[x + 1][y] == 'P'
		|| var->map_cpy[x + 1][y] == 'E' || var->map_cpy[x + 1][y] == 'C')
	{
		var->map_cpy[x + 1][y] = '1';
		flood_fill(var, x + 1, y);
	}
	if (var->map_cpy[x - 1][y] == '0' || var->map_cpy[x - 1][y] == 'P'
		|| var->map_cpy[x - 1][y] == 'E' || var->map_cpy[x - 1][y] == 'C')
	{
		var->map_cpy[x - 1][y] = '1';
		flood_fill(var, x - 1, y);
	}
}

int	check_cpy(t_mlx_game *var)
{
	int	i;
	int	j;

	i = 0;
	var->map_cpy = map_copy(var);
	flood_fill(var, var->p_y, var->p_x);
	while (var->map_cpy[i])
	{
		j = 0;
		while (var->map_cpy[i][j])
		{
			if (var->map_cpy[i][j] == 'C' || var->map_cpy[i][j] == 'E')
			{
				free_map_cpy(var);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map_cpy(var);
	return (1);
}

char	**map_copy(t_mlx_game *var)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (var->count + 1));
	if (!cpy)
		return (NULL);
	while (var->map[i])
	{
		cpy[i] = ft_strdup(var->map[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

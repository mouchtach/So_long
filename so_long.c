/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 22:20:14 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *argv, t_mlx_game *var)
{
	int	map;

	if (!check_name(argv))
	{
		ft_putstr("name error\n");
		exit(1);
	}
	map = open(argv, O_RDONLY, 0777);
	if (map == -1)
	{
		ft_putstr("file not exist \n");
		exit(1);
	}
	var->count = count_lines(map);
	close(map);
	map = open(argv, O_RDONLY, 0777);
	return (map);
}

int	main(int argc, char **argv)
{
	t_mlx_game	var;
	int			fd_map;

	if (argc == 2)
	{
		fd_map = open_file(argv[1], &var);
		var.map = read_map(fd_map, &var);
		if (!check_map(&var))
			return (free_map(&var), 1);
		if (!so_long(&var))
			return (free_map(&var), 1);
	}
	return (0);
}

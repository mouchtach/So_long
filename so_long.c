/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/04 14:10:16 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *argv, mlx_game *var)
{
	int	map;

	if (!check_name(argv))
	{
		printf("name error\n");
		exit(1);
	}
	map = open(argv, O_RDONLY, 0777);
	if (map == -1)
	{
		printf("file not exist \n");
		exit(1);
	}
	var->count = count_lines(map);
	close(map);
	map = open(argv, O_RDONLY, 0777);
	return (map);
}

int	main(int argc, char **argv)
{
	mlx_game var;
	int fd_map;

	if (argc == 2)
	{
		fd_map = open_file(argv[1], &var);
		var.map = read_map(fd_map, &var);
		if (!check_map(&var))
		{
			free_map(&var);
			exit(1);
		}
	}
	// if(!parsing_arry(var.map, count))
	// {
	//     multy_free(var.map, NULL);
	//     exit(1);
	// }
	// copy = map_copy(var.map, count);
	// player_pass(&var, copy);
	// if(!check_map(copy))
	// {
	//     multy_free(var.map, copy);
	//     exit(1);
	// }
	// multy_free(copy, NULL);
	// so_long(var);
}
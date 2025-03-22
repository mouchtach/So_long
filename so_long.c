/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/22 01:30:17 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    int map;
    int count;
    char **map_array;

    map = open("map.ber", O_RDONLY, 0777);
    if (!map)
        printf("map not exist \n");
    count = count_lines(map);
    close (map);
    map = open("map.ber", O_RDONLY, 0777);
    map_array = read_map(map, count);
    // int i = 0;
    // while(map_array[i])
    // {
    //     printf("%s", (map_array[i]));
    //     i++;
    // }
    parsing_arry(map_array, count);

}
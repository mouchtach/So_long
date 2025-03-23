/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:36:47 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/23 00:48:21 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


    
void    set_player_coord(char **map, coord *val)
{
    int i = 0;
    int j;

    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
            {
                val->x = i;
                val->y = j;
                break;
            }
            j++;
        }
        i++;
    }
}
void    print_map(char **map)
{
    int i = 0;
    while(map[i])
    {
        printf("%s", map[i]);
        i++;
    }
}

void    flood_fill(char **map, int x, int y)
{
    if (map[x][y + 1] == '0' || map[x][y + 1] == 'P' || map[x][y + 1] == 'E' || map[x][y + 1] == 'C') 
    {
        map[x][y + 1] = '1';
        flood_fill(map, x, y + 1);
    }
    if (map[x][y - 1] == '0' || map[x][y - 1] == 'P' || map[x][y - 1] == 'E' || map[x][y - 1] == 'C')
    {
        map[x][y - 1] = '1';
        flood_fill(map, x, y - 1);
    }
    if (map[x + 1][y] == '0' || map[x + 1][y] == 'P' || map[x + 1][y] == 'E' || map[x + 1][y] == 'C')
    {
        map[x + 1][y] = '1';
        flood_fill(map, x + 1, y);
    }
    if (map[x - 1][y] == '0' || map[x - 1][y] == 'P' || map[x - 1][y] == 'E' || map[x - 1][y] == 'C')
    {
        map[x - 1][y] = '1';
        flood_fill(map, x - 1, y);
    }
}

 
int player_pass(char **map)
{
    coord val;

    set_player_coord(map, &val);
    flood_fill(map, val.x, val.y);
    print_map(map);
    return(0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/23 00:58:38 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_file(char *argv, int *count)
{
    int map;
    
    if(!check_name(argv))
    {
        printf("name error\n");
        exit(1);
    }
    map = open(argv, O_RDONLY, 0777);
    if (map ==  -1)
    {
        printf("file not exist \n");
        exit(1);
    }
    *count = count_lines(map);
    close (map);
    map = open(argv, O_RDONLY, 0777);
    return(map);
}

char ** 
int main(int argc, char **argv)
{
    int map;
    int count;
    char **map_array;
    char **copy;

    if (argc != 2)
        return (0);
    map = open_file(argv[1], &count);
    map_array = read_map(map, count);
    parsing_arry(map_array, count);
    copy = map_copy(map_array);
    // print_map(map_array);
    // printf("\n");
    player_pass(map_array);
    printf("\n");
    print_map(map_array);
}
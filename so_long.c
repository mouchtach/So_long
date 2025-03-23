/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/23 21:41:10 by ymouchta         ###   ########.fr       */
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

char **map_copy(char **map_array, int count)
{
    char **cpy;
    int i;
    i = 0;

    cpy = malloc(sizeof(char *) * (count + 1));
    if (!cpy)
        return (NULL);
    
    while (map_array[i])
    {
        cpy[i] = ft_strdup(map_array[i]);
        i++;
    }
    cpy[i] = NULL;
    return(cpy);
}
int check_map(char **map_copy)
{
    int i;
    int j;

    i = 0;
    while(map_copy[i])
    {
        j = 0;
        while(map_copy[i][j])
        {
            if(map_copy[i][j] == 'C')
            {
                printf("Eroor in  Map\n");
                return(0);
            }
            j++;
        }
        i++;
    }
    return(1);
}
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
    if(!parsing_arry(map_array, count))
    {
        multy_free(map_array, NULL);
        exit(1);   
    }
    copy = map_copy(map_array, count);
    player_pass(copy);
    if(!check_map(copy))
    {
        multy_free(map_array, copy);
        exit(1);
    }
    // printf("\n");
    // player_pass(copy);
    // printf("\n");
    // print_map(map_array);
    // printf("\n");
    // print_map(copy);
}
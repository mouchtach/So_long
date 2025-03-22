/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:07:54 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/21 22:27:28 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_lines(int map)
{
    char *line;
    int i = 0;
    while (1)
    {
        // return(NULL);
        line = get_next_line(map);
        if(!line)
            break;
        free(line);
        i++;
    }
    return (i); 
}

char **read_map(int map, int count)
{
    char **arry;
    char *line;
    int i = 0;

    arry = malloc(sizeof(char *) * (count + 1));
    while (i < count)
    {
        line = get_next_line(map);
        if(!line)
            break;
        arry[i] = ft_strdup(line);
        free(line);
        i++;
    }
    arry[i] = NULL;
    return(arry);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:42:12 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/22 01:28:02 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_val(t_elements val)
{
    if (val.c < 1)
        return(1);
    else if (val.e != 1)
        return(1);
    else if (val.p != 1)
        return(1);
    else
        return(0);
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


int shape_check(char **map)
{
    int size;
    int i;

    i = 0;
    size = ft_strlen_newline(map[i]);
    while(map[i])
    {
        if (size != ft_strlen_newline(map[i]))
            return(1);
        size = ft_strlen_newline(map[i]);
        // printf("size line %d  = %d \n", i + 1, size);
        i++;
    }
    return(0);
}
int wal_check(char **map,int  count)
{
    int i;
    i = 0;
    while(map[0][i] == '1' && map[0][i] && map[0][i] != '\n')
        i++;
    if(!(map[0][i] == 0 || map[0][i] == '\n'))
        return(1);
    i = 0;
    while(map[count - 1][i] == '1' && map[0][i] && map[0][i] != '\n')
        i++;
    if(!(map[0][i] == 0 || map[0][i] == '\n'))
        return(1);
    i = 0;
    while(i < count && map[i][0] == '1')
        i++;
    if(i != count)
        return(1);
    i = 0;
    while(i < count)
        i++;
    if(i != count)
        return(1);
    return(0);
}

int valid_characters(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
                j++;
            else if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == '\n')
                j++;
            else
                return(1);
        }
        i++;
    }
    return(0);
}

int elements_check(char **map)
{
    t_elements val;

    val.c = 0;
    val.p = 0;
    val.e = 0;
    val.i = 0;
    while (map[val.i])
    {
        val.j = 0;
        while (map[val.i][val.j])
        {
            if (map[val.i][val.j] == 'C')
                val.c ++;
            if (map[val.i][val.j] == 'P')
                val.p ++;
            if (map[val.i][val.j] == 'E')
                val.e ++;
            val.j++;
        }
        val.i++;
    }
    if (check_val(val))
        return(1);
    else 
        return(0);
}

void parsing_arry(char **map,int  count)
{
    if (shape_check(map))
    {
        printf("Eroor in shape\n");
        exit(1);
    }
    if (wal_check(map, count))
    {
        printf("Eroor in  walls\n");
        exit(1);
    }
    if (elements_check(map)|| valid_characters(map))
    {
        printf("Eroor in  elements\n");
        exit(1);
    }    
}

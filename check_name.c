/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:05:25 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/22 19:13:18 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_name(char *name)
{
    int i;

    i = 0;
    while(name[i])
    {
        if(name[i] == '/' && name[i + 1] == '/')
            return(0);
        if (name[i] == ';')
            return(0);
        if(name[i] == '.' && ft_strcmp(name + i, ".ber"))
            return(0);    
        i++;
    }
    i = 0;
    while(name[i] && name[i] != '.')
        i++;
    if(name[i] != '.')
        return(0);
    else 
        return(1);
}
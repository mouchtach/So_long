/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:05:25 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 19:45:00 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (i < 5)
		return (0);
	if (name[i - 1] != 'r' || name[i - 2] != 'e' || name[i - 3] != 'b' 
		|| name[i - 4] != '.' || name[i - 5] == '/')
		return (0);
	return (1);
}

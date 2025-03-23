/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:10:20 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/23 21:41:36 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


char    **read_map(int map, int count);


int     count_lines(int map);

typedef struct t_elements
{
    int i;
    int j;
    int c;
    int p;
    int e;
    
}t_elements;

typedef struct coord
{
    int x;
    int y;
}coord;
// free
void     multy_free(char **f1, char **f2);

// parsing
int     check_val(t_elements val);
int     ft_strlen_newline(const char *s);
int     shape_check(char **map);
int     wal_check(char **map,int  count);
int     valid_characters(char **map);
int     elements_check(char **map);
int     parsing_arry(char **map,int  count);


// libft 
int  ft_strcmp(char *s1, char *s2);

// name check
int   check_name(char *name);

//get_next_line 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1100
# endif
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int     ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

//player pass
int player_pass(char **map);

// print
void    print_map(char **map);

#endif

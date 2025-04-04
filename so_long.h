/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:10:20 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/04 14:18:21 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100
# define TILE_SIZE 64

typedef struct t_elements
{
	int				i;
	int				j;
	int				c;
	int				p;
	int				e;

}					t_elements;

typedef struct mlx_game
{
	mlx_image_t		*mlx_img;
	mlx_image_t		*player_img;
	mlx_texture_t	*texture;
	t_elements		element;
	char			**map_cpy;
	char			**map;
	void			*mlx;
	int				count;
	int				width;
	int				height;
	int				coin;
	int				p_y;
	int				p_x;

}					mlx_game;

typedef struct texture
{
	char			*background;
	char			*player_left;
	char			*player_right;
	char			*player_up;
	char			*player_down;
	char			*wall;
	char			*coin;
	char			*exit_0;
	char			*exit_1;

}					texture;

//---------|  CHECK  |----------//
// check_map
int					shape_check(mlx_game *var);
int					wall_check(mlx_game *var);
int					valid_characters(mlx_game *var);
int					elements_check(mlx_game *var);
int					player_pass(mlx_game *var);
// check_name
int					check_name(char *name);
// check_utils
int					check_val(mlx_game *var);
int					ft_strlen_newline(const char *s);
void				flood_fill(mlx_game *var, int x, int y);
int					check_cpy(mlx_game *var);
char				**map_copy(mlx_game *var);
// check
int					check_map(mlx_game *var);

//----------|   READ   |-----------//
// get_next_Line_utils
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
int					ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
// get_next_Line
char				*get_next_line(int fd);
// libft
int					ft_strcmp(char *s1, char *s2);
// read
int					count_lines(int map);
char				**read_map(int fd_map, mlx_game *var);

// free
void				free_map(mlx_game *var);
void				free_map_cpy(mlx_game *var);
void				multy_free(mlx_game *var);

#endif

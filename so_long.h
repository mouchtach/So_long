/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:10:20 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/07 20:25:12 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100
# define P 64
# define WIDTH 40
# define HEIGHT 21

# define PATH_BACKGROUND "textures/backround.png"
# define PATH_PLAYER "textures/player.png"
# define PATH_WALL "textures/wall.png"
# define PATH_COIN "textures/coin.png"
# define PATH_EXIT_1 "textures/open.png"
# define PATH_EXIT_0 "textures/close.png"

typedef struct t_elements
{
	int				i;
	int				j;
	int				c;
	int				p;
	int				e;

}					t_elements;

typedef struct load_png
{
	void			*load_background;
	void			*load_player;
	void			*load_wall;
	void			*load_coin;
	void			*load_exit_0;
	void			*load_exit_1;

}					t_load_png;

typedef struct texture
{
	char			*background;
	char			*player;
	char			*wall;
	char			*coin;
	char			*exit_0;
	char			*exit_1;

}					t_texture;

typedef struct mlx_game
{
	mlx_image_t		*mlx_img;
	mlx_image_t		*player_img;
	mlx_texture_t	*texture;
	t_texture		png;
	t_load_png		load;
	t_load_png		imgs;
	t_elements		element;
	char			**map_cpy;
	char			**map;
	void			*mlx_init;
	int				moves;
	int				count;
	int				width;
	int				height;
	int				coin;
	int				p_y;
	int				p_x;

}					t_mlx_game;

//---------|  CHECK  |----------//
// check_map
int					shape_check(t_mlx_game *var);
int					wall_check(t_mlx_game *var);
int					valid_characters(t_mlx_game *var);
int					elements_check(t_mlx_game *var);
int					player_pass(t_mlx_game *var);
// check_name
int					check_name(char *name);
// check_utils
int					check_val(t_mlx_game *var);
int					ft_strlen_newline(const char *s);
void				flood_fill(t_mlx_game *var, int x, int y);
int					check_cpy(t_mlx_game *var);
char				**map_copy(t_mlx_game *var);
// check
int					check_map(t_mlx_game *var);

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
void				ft_putstr(char *s);
void				ft_putnbr(int n);
// read
int					count_lines(int map);
char				**read_map(int fd_map, t_mlx_game *var);

//----------|   GAME   |-----------//

// move
void				moves(t_mlx_game *var);
void				exit_1(t_mlx_game *var);

// derects
bool				up(t_mlx_game *var, mlx_image_t *player);
bool				down(t_mlx_game *var, mlx_image_t *player);
bool				left(t_mlx_game *var, mlx_image_t *player);
bool				right(t_mlx_game *var, mlx_image_t *player);
bool				esc(t_mlx_game *var, mlx_image_t *player);

// game
void				end_game(t_mlx_game *var);
bool				so_long(t_mlx_game *var);

// load
void				clear_texture(t_mlx_game *var);
void				set_texture(t_mlx_game *var);
void				imgs_loading(t_mlx_game *var);
void				png_loading(t_mlx_game *var);
bool				check_texture_loading(t_mlx_game *var);

// free
void				free_map(t_mlx_game *var);
void				free_map_cpy(t_mlx_game *var);
void				multy_free(t_mlx_game *var);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:10:20 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 21:47:56 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>


# define BUFFER_SIZE 100
# define TILE_SIZE 64

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
	void		*load_background;
	void		*load_player;
	void		*load_wall;
	void		*load_coin;
	void		*load_exit_0;
	void		*load_exit_1;

}	load_png;

typedef struct texture
{
	char			*background;
	char			*player;
	char			*wall;
	char			*coin;
	char			*exit_0;
	char			*exit_1;

}	texture;

typedef struct mlx_game
{
	mlx_image_t		*mlx_img;
	mlx_image_t		*player_img;
	mlx_texture_t	*texture;
	texture			png;
	load_png		load;
	load_png		imgs;
	t_elements		element;
	char			**map_cpy;
	char			**map;
	void			*mlx_init;
	int				count;
	int				width;
	int				height;
	int				coin;
	int				p_y;
	int				p_x;

}					mlx_game;



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
void				ft_putstr(char *s);
// read
int					count_lines(int map);
char				**read_map(int fd_map, mlx_game *var);


//----------|   GAME   |-----------//

// move
void    moves(mlx_game *var);
void	exit_1(mlx_game *var);

// derects
bool	 up(mlx_game *var, mlx_image_t *player);
bool	 down(mlx_game *var, mlx_image_t *player);
bool	 left(mlx_game *var, mlx_image_t *player);
bool	 right(mlx_game *var, mlx_image_t *player);
bool	 esc(mlx_game *var, mlx_image_t *player);



// game
bool	so_long(mlx_game *var);

// load
void	clear_texture(mlx_game *var);
void	set_texture(mlx_game *var);
void	imgs_loading(mlx_game *var);
void	png_loading(mlx_game *var);
bool	check_texture_loading(mlx_game *var);


// free
void				free_map(mlx_game *var);
void				free_map_cpy(mlx_game *var);
void				multy_free(mlx_game *var);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 15:31:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>

# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define ESC_KEY 65307

# define TILE_SIZE 64

# define TRANSPARENT 0xFF000000

typedef struct s_algo
{
	char	**tab;
	int		exit_reached;
	int		nbr_collecti;
	int		x;
	int		y;
}			t_algo;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**tab;
	int		width;
	int		height;
	int		has_start;
	int		has_exit;
	int		nbr_collecti;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
}			t_map;

typedef struct s_player
{
	t_img	down;
	t_img	up;
	t_img	left;
	t_img	right;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			x_player;
	int			y_player;
	int			player_moves;
	int			collected;
	int			nbr_enemy;
	t_map		map;
	t_player	player;
	t_algo		flood_fill;
	t_img		player_sprite;
	t_img		enemy;
	t_img		buffer;
}			t_game;

/***************RENDERING_GAME***************/
int				rendering(t_game *game);
void			init_buffer(t_game *game);
void			draw_map_to_buffer(t_game *game);
void			draw_tile_to_buffer(t_game *game, char tile, int x, int y);
void			draw_sprite(t_img *dst, t_img *sprite, int pos_x, int pos_y);

/***************SPRITE***************/
int				load_textures(t_game *game);
void			load_xpm(void *mlx, t_img *img, char *path);
void			put_pixel(t_img *img, int x, int y, unsigned int color);
unsigned int	get_pixel(t_img *img, int x, int y);

/***************CHECKER***************/
int				is_wall(char c);
int				checker_map(t_game *game, char *filename);
int				check_walls_width(t_game *game);
int				check_walls_height(t_game *game);
int				is_ber(char *str);
void			parsing_map(t_game *game);
void			init_flood_fill(t_game *game);
void			flood_fill(t_game *game, int x, int y);

/***************GAME***************/
int				close_game(t_game *game);
int				handle_key(int keycode, t_game *game);
void			init_game(t_game *game, char *filename);
void			move_player(t_game *game, int dir_x, int dir_y);

/***************UTILS***************/
void			find_player_position(t_game *game);
void			free_tab(char **tab);
void			get_map_size(t_game *game, char *filename);
char			**fill_tab_map(t_game *game, char *filename);

/***************ERRORS***************/
void			error_exit(char *msg);
void			error_check(char *msg, t_game *game);
void			error_window(char *msg, t_game *game);
void			error_textures(char *msg, t_game *game);

/***************BONUS***************/
void			destroy_textures(t_game *game);
void			draw_text_on_window(t_game *game);
void			move_player1(t_game *game, int dir_x, int dir_y);
void			move_player2(t_game *game, int new_x, int new_y);
int				load_animations(t_game *game);
int				is_wall_or_enemy(char c);

#endif

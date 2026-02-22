/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 17:10:42 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	if (game->buffer.img)
		mlx_destroy_image(game->mlx, game->buffer.img);
	if (game->player_sprite.img)
		mlx_destroy_image(game->mlx, game->player_sprite.img);
	if (game->map.wall.img)
		mlx_destroy_image(game->mlx, game->map.wall.img);
	if (game->map.floor.img)
		mlx_destroy_image(game->mlx, game->map.floor.img);
	if (game->map.collectible.img)
		mlx_destroy_image(game->mlx, game->map.collectible.img);
	if (game->map.exit.img)
		mlx_destroy_image(game->mlx, game->map.exit.img);
	if (game->map.tab)
		free_tab(game->map.tab);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(1);
}

void	move_player(t_game *game, int dir_x, int dir_y)
{
	int	new_x;
	int	new_y;

	new_x = (game->x_player / TILE_SIZE) + dir_x;
	new_y = (game->y_player / TILE_SIZE) + dir_y;
	if (game->map.tab[new_y][new_x] == '1')
		return ;
	game->x_player = new_x * TILE_SIZE;
	game->y_player = new_y * TILE_SIZE;
	game->player_moves++;
	ft_printf("number of movements = %d\n", game->player_moves);
	if (game->map.tab[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map.tab[new_y][new_x] = '0';
	}
	else if (game->map.tab[new_y][new_x] == 'E'
		&& game->collected == game->map.nbr_collecti)
	{
		ft_printf("CONGRATULATIONS : You success the game !\n");
		close_game(game);
	}
	else if (game->map.tab[new_y][new_x] == 'E'
		&& game->collected != game->map.nbr_collecti)
		ft_printf("You need to have all collectibles before !\n");
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_game(game);
	else if (keycode == W_KEY)
		move_player(game, 0, -1);
	else if (keycode == S_KEY)
		move_player(game, 0, 1);
	else if (keycode == D_KEY)
		move_player(game, 1, 0);
	else if (keycode == A_KEY)
		move_player(game, -1, 0);
	return (0);
}

void	init_game(t_game *game, char *filename)
{
	get_map_size(game, filename);
	game->map.tab = fill_tab_map(game, filename);
	if (!checker_map(game, filename))
		error_check("map invalide", game);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_check("mlx_init failed", game);
	game->window = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->window)
		error_window("mlx_new_window failed", game);
	if (!load_textures(game))
		error_textures("problem loading textures", game);
	init_buffer(game);
	game->player_moves = 0;
	game->collected = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long file.ber");
	init_game(&game, argv[1]);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, rendering, &game);
	mlx_loop(game.mlx);
	return (0);
}

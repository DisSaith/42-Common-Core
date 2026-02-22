/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 15:26:25 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	destroy_textures(game);
	if (game->buffer.img)
		mlx_destroy_image(game->mlx, game->buffer.img);
	if (game->map.tab)
		free_tab(game->map.tab);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	destroy_textures(t_game *game)
{
	if (game->map.wall.img)
		mlx_destroy_image(game->mlx, game->map.wall.img);
	if (game->map.floor.img)
		mlx_destroy_image(game->mlx, game->map.floor.img);
	if (game->map.collectible.img)
		mlx_destroy_image(game->mlx, game->map.collectible.img);
	if (game->map.exit.img)
		mlx_destroy_image(game->mlx, game->map.exit.img);
	if (game->enemy.img)
		mlx_destroy_image(game->mlx, game->enemy.img);
	if (game->player.down.img)
		mlx_destroy_image(game->mlx, game->player.down.img);
	if (game->player.up.img)
		mlx_destroy_image(game->mlx, game->player.up.img);
	if (game->player.left.img)
		mlx_destroy_image(game->mlx, game->player.left.img);
	if (game->player.right.img)
		mlx_destroy_image(game->mlx, game->player.right.img);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_game(game);
	else if (keycode == W_KEY)
		move_player1(game, 0, -1);
	else if (keycode == S_KEY)
		move_player1(game, 0, 1);
	else if (keycode == D_KEY)
		move_player1(game, 1, 0);
	else if (keycode == A_KEY)
		move_player1(game, -1, 0);
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
	if (!load_textures(game) || !load_animations(game))
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

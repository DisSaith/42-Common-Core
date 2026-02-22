/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 13:44:01 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile_to_buffer(t_game *game, char tile, int x, int y)
{
	t_img	*sprite;

	draw_sprite(&game->buffer, &game->map.floor,
		x * TILE_SIZE, y * TILE_SIZE);
	sprite = NULL;
	if (tile == '1')
		sprite = &game->map.wall;
	else if (tile == 'C')
		sprite = &game->map.collectible;
	else if (tile == 'E')
		sprite = &game->map.exit;
	if (sprite)
		draw_sprite(&game->buffer, sprite,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	init_buffer(t_game *game)
{
	game->buffer.img = mlx_new_image(game->mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE);
	if (!game->buffer.img)
		error_textures("problem to create the buffer", game);
	game->buffer.addr = mlx_get_data_addr(game->buffer.img,
			&game->buffer.bpp,
			&game->buffer.line_len,
			&game->buffer.endian);
	game->buffer.width = game->map.width * TILE_SIZE;
	game->buffer.height = game->map.height * TILE_SIZE;
}

void	draw_map_to_buffer(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width && game->map.tab[y][x] != '\0')
		{
			if (game->map.tab[y][x] != '\n')
				draw_tile_to_buffer(game,
					game->map.tab[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	rendering(t_game *game)
{
	draw_map_to_buffer(game);
	draw_sprite(&game->buffer, &game->player_sprite,
		game->x_player, game->y_player);
	mlx_put_image_to_window(game->mlx, game->window,
		game->buffer.img, 0, 0);
	return (0);
}

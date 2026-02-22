/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:15:11 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 17:10:18 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player1(t_game *game, int dir_x, int dir_y)
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
	move_player2(game, new_x, new_y);
	if (dir_y == 1)
		game->player_sprite = game->player.down;
	if (dir_y == -1)
		game->player_sprite = game->player.up;
	if (dir_x == -1)
		game->player_sprite = game->player.left;
	if (dir_x == 1)
		game->player_sprite = game->player.right;
}

void	move_player2(t_game *game, int new_x, int new_y)
{
	if (game->map.tab[new_y][new_x] == 'D')
	{
		ft_printf("FAIL : You lost !\n");
		close_game(game);
	}
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

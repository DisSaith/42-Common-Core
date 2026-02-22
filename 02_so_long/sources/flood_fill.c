/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/07 11:37:48 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_flood_fill(t_game *game)
{
	int	i;

	game->flood_fill.tab = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->flood_fill.tab)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		game->flood_fill.tab[i] = ft_strdup(game->map.tab[i]);
		i++;
	}
	game->flood_fill.tab[i] = NULL;
	game->flood_fill.exit_reached = 0;
	game->flood_fill.nbr_collecti = 0;
	game->flood_fill.x = game->x_player / TILE_SIZE;
	game->flood_fill.y = game->y_player / TILE_SIZE;
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	if (is_wall(game->flood_fill.tab[y][x])
		|| game->flood_fill.tab[y][x] == '2')
		return ;
	if (game->flood_fill.tab[y][x] == 'E')
		game->flood_fill.exit_reached = 1;
	else if (game->flood_fill.tab[y][x] == 'C')
		game->flood_fill.nbr_collecti++;
	game->flood_fill.tab[y][x] = '2';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

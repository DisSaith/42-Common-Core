/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 13:37:59 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	checker_map(t_game *game, char *filename)
{
	game->map.has_exit = 0;
	game->map.has_start = 0;
	game->map.nbr_collecti = 0;
	parsing_map(game);
	find_player_position(game);
	init_flood_fill(game);
	flood_fill(game, game->flood_fill.x, game->flood_fill.y);
	free_tab(game->flood_fill.tab);
	if (!game->flood_fill.exit_reached
		|| game->flood_fill.nbr_collecti != game->map.nbr_collecti)
		return (0);
	if (!game->map.has_exit || !game->map.nbr_collecti
		|| !game->map.has_start)
		return (0);
	if (game->map.has_exit > 1 || game->map.has_start > 1)
		error_check("the map need only 1 start and 1 exit", game);
	if (game->map.width <= game->map.height)
		error_check("the map need to be rectangular", game);
	if (!is_ber(filename))
		error_check("the map nead to be a .ber", game);
	if (!check_walls_width(game) || !check_walls_height(game))
		return (0);
	return (1);
}

void	parsing_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.tab[i] != NULL)
	{
		j = 0;
		while (game->map.tab[i][j] != '\0')
		{
			if (game->map.tab[i][j] == 'E')
				game->map.has_exit++;
			if (game->map.tab[i][j] == 'P')
				game->map.has_start++;
			if (game->map.tab[i][j] == 'C')
				game->map.nbr_collecti++;
			j++;
		}
		i++;
	}
}

int	check_walls_width(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.width - 1)
	{
		if (game->map.tab[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (x < game->map.width - 1)
	{
		if (game->map.tab[game->map.height - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_walls_height(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height - 1)
	{
		if (game->map.tab[y][0] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (y < game->map.height - 1)
	{
		if (game->map.tab[y][game->map.width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	is_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i + 1] == 'b')
				if (str[i + 2] == 'e')
					if (str[i + 3] == 'r')
						return (1);
		i++;
	}
	return (0);
}

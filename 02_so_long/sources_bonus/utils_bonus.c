/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:25:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 15:23:55 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_animations(t_game *game)
{
	game->player.down = game->player_sprite;
	load_xpm(game->mlx, &game->player.up, "textures_bonus/up.xpm");
	if (!game->player.up.img)
		return (0);
	load_xpm(game->mlx, &game->player.right, "textures_bonus/right.xpm");
	if (!game->player.right.img)
		return (0);
	load_xpm(game->mlx, &game->player.left, "textures_bonus/left.xpm");
	if (!game->player.left.img)
		return (0);
	return (1);
}

void	get_map_size(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	game->map.height = 0;
	game->map.width = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("can't open file");
	line = get_next_line(fd);
	while (line[i] != '\0')
	{
		i++;
		game->map.width++;
	}
	while (line != NULL)
	{
		game->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

char	**fill_tab_map(t_game *game, char *filename)
{
	char	**tab;
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("can't open file");
	tab = malloc(sizeof(char *) * (game->map.height + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (1)
	{	
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width && game->map.tab[y][x] != '\0')
		{
			if (game->map.tab[y][x] == 'P')
			{
				game->x_player = x * TILE_SIZE;
				game->y_player = y * TILE_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}

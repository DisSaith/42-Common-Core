/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:35:32 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/08 13:46:22 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit (0);
}

void	error_check(char *msg, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (game->map.tab)
		free_tab(game->map.tab);
	exit (0);
}

void	error_window(char *msg, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (game->map.tab)
		free_tab(game->map.tab);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (0);
}

void	error_textures(char *msg, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
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
	exit (0);
}

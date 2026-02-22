/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:11:58 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/07 11:37:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_textures(t_game *game)
{
	load_xpm(game->mlx, &game->map.wall, "textures/wall.xpm");
	if (!game->map.wall.img)
		return (0);
	load_xpm(game->mlx, &game->map.floor, "textures/floor.xpm");
	if (!game->map.floor.img)
		return (0);
	load_xpm(game->mlx, &game->map.collectible, "textures/collectible.xpm");
	if (!game->map.collectible.img)
		return (0);
	load_xpm(game->mlx, &game->map.exit, "textures/exit.xpm");
	if (!game->map.exit.img)
		return (0);
	load_xpm(game->mlx, &game->player_sprite, "textures/player.xpm");
	if (!game->player_sprite.img)
		return (0);
	return (1);
}

void	load_xpm(void *mlx, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path,
			&img->width, &img->height);
	if (!img->img)
		return ;
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x *(img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_sprite(t_img *dst, t_img *sprite, int pos_x, int pos_y)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			color = get_pixel(sprite, x, y);
			if (color != TRANSPARENT)
				put_pixel(dst, pos_x + x, pos_y + y, color);
			x++;
		}
		y++;
	}
}

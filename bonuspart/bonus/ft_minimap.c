/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:01 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/20 15:11:16 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_print_square(double x, double y, mlx_image_t *minimap,
	uint32_t color)
{
	double	i;
	double	j;
	double	square_size;
	int		scale;

	scale = SCREEN_X;
	if (SCREEN_X > SCREEN_Y)
		scale = SCREEN_Y;
	square_size = (double)(scale / 9 / 4);
	i = square_size * x;
	while (i < (square_size * x) + square_size)
	{
		j = square_size * y;
		while (j < (square_size * y) + square_size)
		{
			if (i >= 0 && j >= 0 && j <= scale / 4 - square_size && i <= \
				scale / 4 - square_size)
				mlx_put_pixel(minimap, i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_mini_init(mlx_image_t *minimap)
{
	int	i;
	int	j;
	int	scale;

	scale = SCREEN_X;
	if (SCREEN_X > SCREEN_Y)
		scale = SCREEN_Y;
	i = 0;
	while (i < scale / 4 - (scale / 4 / 9))
	{
		j = 0;
		while (j < scale / 4 - (scale / 4 / 9))
		{
			mlx_put_pixel(minimap, i, j, 0x0000ff);
			j++;
		}
		i++;
	}
}

void	ft_print_player(double x, double y, mlx_image_t *minimap,
	uint32_t color)
{
	double	i;
	double	j;
	double	square_size;
	int		scale;

	scale = SCREEN_X;
	if (SCREEN_X > SCREEN_Y)
		scale = SCREEN_Y;
	square_size = (double)(scale / 9 / 4);
	i = (square_size * x);
	while (i < (square_size * x) + (square_size * 0.10))
	{
		j = (square_size * y);
		while (j < (square_size * y) + (square_size * 0.10))
		{
			if (i >= 0 && j >= 0)
				mlx_put_pixel(minimap, i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_minimap_next(t_game *g, t_minipoint p)
{
	if (p.x >= 0 && p.y >= 0 && p.x < g->map->size_x && p.y < g->map->size_y \
		&& (g->map->map[p.y][p.x] == '1' || g->map->map[p.y][p.x] == 'T'))
		ft_print_square(p.i - 1 + ((int)g->player->x - g->player->x), p.j - \
		1 + ((int)g->player->y - g->player->y), g->img, 0x737373ff);
	else if (p.x >= 0 && p.y >= 0 && p.x < g->map->size_x && p.y < \
		g->map->size_y && g->map->map[p.y][p.x] == 'D')
		ft_print_square(p.i - 1 + ((int)g->player->x - g->player->x), p.j - \
		1 + ((int)g->player->y - g->player->y), g->img, 0x00ffddff);
	else if (p.x >= 0 && p.y >= 0 && p.x < g->map->size_x && p.y < \
		g->map->size_y && g->map->map[p.y][p.x] == 'S')
		ft_print_square(p.i - 1 + ((int)g->player->x - g->player->x), p.j - \
		1 + ((int)g->player->y - g->player->y), g->img, 0xFFFF00FF);
}

void	ft_minimap(t_game *g)
{
	int			x;
	int			y;
	double		i;
	double		j;

	ft_mini_init(g->img);
	x = g->player->x - 5;
	i = 0;
	while (++x < g->player->x + 5 && ++i)
	{
		y = g->player->y - 5;
		j = 0;
		while (++y < g->player->y + 5 && ++j)
			ft_minimap_next(g, (t_minipoint){x, y, i, j});
	}
	ft_print_player(i - 6, j - 6, g->img, 0xff00b7);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:01 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/19 18:40:09 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_print_square(double x, double y, mlx_image_t *minimap, uint32_t color)
{
	double	i;
	double	j;
	double	square_size;
	int	scale;

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
			if (i >= 0 && j >= 0 && j <= scale / 4 - square_size && i <= scale / 4 - square_size)
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

void	ft_print_player(double x, double y, mlx_image_t *minimap, uint32_t color)
{
	double	i;
	double	j;
	double	square_size;
	int	scale;

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

void	ft_minimap(t_game *g)
{
	int			x;
	int			y;
	double		i;
	double		j;

	ft_mini_init(g->img);
	x = g->player->x - 4;
	i = 0;
	while (x < g->player->x + 5)
	{
		y = g->player->y - 4;
		j = 0;
		while (y < g->player->y + 5)
		{
			if (x >= 0 && y >= 0 && x < g->map->size_x && y < g->map->size_y && g->map->map[y][x] != 'D' && g->map->map[y][x] != 'S' && g->map->map[y][x] != '0')
				ft_print_square(i + ((int)g->player->x - g->player->x), j + ((int)g->player->y - g->player->y), g->img, 0x737373ff);
			else if (x >= 0 && y >= 0 && x < g->map->size_x && y < g->map->size_y && g->map->map[y][x] == 'D')
				ft_print_square(i + ((int)g->player->x - g->player->x), j + ((int)g->player->y - g->player->y), g->img, 0x00ffddff);
			else if (x >= 0 && y >= 0 && x < g->map->size_x && y < g->map->size_y && g->map->map[y][x] == 'S')
				ft_print_square(i + ((int)g->player->x - g->player->x), j + ((int)g->player->y - g->player->y), g->img, 0xFFFF00FF);
			y++;
			j++;
		}
		x++;
		i++;
	}
	ft_print_player(i - 6, j - 6, g->img, 0xff00b7);
}

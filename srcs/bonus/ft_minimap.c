/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:01 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/19 14:32:46 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_print_square(double x, double y, mlx_image_t *minimap, uint32_t color)
{
	double	i;
	double	j;
	double	square_size[2];
	int	scale;

	scale = SCREEN_X;
	if (SCREEN_X > SCREEN_Y)
		scale = SCREEN_Y;
	square_size[0] = (double)(scale / 9 / 4);
	square_size[1] = (double)(scale / 9 / 4);
	i = square_size[0] * x;
	while (i < (square_size[0] * x) + square_size[0])
	{
		j = square_size[1] * y;
		while (j < (square_size[1] * y) + square_size[1])
		{
			if (i >= 0 && j >= 0)
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
	while (i < scale / 4)
	{
		j = 0;
		while (j < scale / 4)
		{
			mlx_put_pixel(minimap, i, j, 0x0000ff);
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_game *g)
{
	mlx_image_t	*minimap;
	int			x;
	int			y;
	double		i;
	double		j;

	minimap = g->img;
	ft_mini_init(minimap);
	x = g->player->x - 4;
	i = 0;
	while (x < g->player->x + 4)
	{
		y = g->player->y - 4;
		j = 0;
		while (y < g->player->y + 4)
		{
			if (x >= 0 && y >= 0 && x < g->map->size_x && y < g->map->size_y && g->map->map[y][x] != '0' && g->map->map[y][x] != 'D' && g->map->map[y][x] != 'O')
				ft_print_square(i + ((int)g->player->x - g->player->x), j + ((int)g->player->y - g->player->y), minimap, 0x2f00ff);
			else if (x >= 0 && y >= 0 && x < g->map->size_x && y < g->map->size_y && (g->map->map[y][x] == 'D' || g->map->map[y][x] == 'O'))
				ft_print_square(i + ((int)g->player->x - g->player->x), j + ((int)g->player->y - g->player->y), minimap, 0xffffff);
			y++;
			j++;
		}
		x++;
		i++;
	}
	ft_print_square(i - 5, j - 5, minimap, 0xff00b7);//mettre joueur plus petit (croix?)
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:01 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/16 15:34:29 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_square(int x, int y, mlx_image_t *minimap, uint32_t color)
{
	int	i;
	int	j;
	int	square_size[2];

	square_size[0] = SCREEN_X / 5 / 9;
	square_size[1] = SCREEN_Y / 5 / 9;
	i = square_size[0] * x;
	while (i < (square_size[0] * x) + square_size[0])
	{
		j = square_size[1] * y;
		while (j < (square_size[1] * y) + square_size[1])
		{
			mlx_put_pixel(minimap, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_mini_init(mlx_image_t *minimap)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_X / 5)
	{
		j = 0;
		while (j < SCREEN_X / 5)
		{
			mlx_put_pixel(minimap, i, j, 0x0000ff);
			j++;
		}
		i++;
	}
}

//plante quand approche bord tableau 9 * 9
void	ft_minimap(t_game *g)
{
	mlx_image_t	*minimap;
	//coordonnees des points de la map a convertir en minimap
	int			x;
	int			y;
	//coordonnees minimap
	int			i;
	int			j;

	minimap = g->img;//minimap 1/5e ecran
	ft_mini_init(minimap);//met le fond
	x = g->player->x - 4;//4 cases avant joueur
	i = 0;
	while (x < g->player->x + 4)// jusqua 4 cases apres 
	{
		y = g->player->y - 4;
		j = 0;
		while (y < g->player->y + 4)
		{
			if (x >= 0 && y >= 0 && x < g->map->size_x && y < g->map->size_y && g->map->map[y][x] == '1')
				ft_print_square(i, j, minimap, 0x2f00ff);
			y++;
			j++;
		}
		x++;
		i++;
	}
	ft_print_square(i - 5, j - 5, minimap, 0xff00b7);
}

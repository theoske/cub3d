/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:01 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/13 17:21:55 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_square(int x, int y, mlx_image_t *minimap, uint32_t color)
{
	int	i;
	int	j;
	int	square_size[2];

	square_size[0] = SCREEN_X / 100;
	square_size[1] = SCREEN_Y / 100;
	i = square_size[0] * x - 10;
	while (i < (square_size[0] * x))
	{
		j = square_size[1] * y - 10;
		while (j < (square_size[1] * y))
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

//prendre position joueur et mettre 10 cases
void	ft_minimap(t_game *g)// pixel noir rend transparent
{
	mlx_image_t	*minimap;
	int			i;
	int			j;

	minimap = g->img;//minimap 1/5e ecran
	ft_mini_init(minimap);
	i = g->player->x - (SCREEN_X / 200);
	printf("x : %f, %d\n", g->player->x, SCREEN_X / 200);
	if (i < 0)
		i = 0;
	while (i < g->player->x + (SCREEN_X / 200) && g->map->map[0][i])
	{
		j = g->player->y - (SCREEN_Y / 200);
		if (j < 0)
			j = 0;
		while (j < g->player->y + (SCREEN_Y / 200) && g->map->map[j][0])
		{
			if (g->map->map[j][i] == '1')//mur
				ft_print_square(i, j, minimap, 0x2f00ff);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:01 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/14 16:37:02 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_square(int x, int y, mlx_image_t *minimap, uint32_t color)
{
	int	i;
	int	j;
	int	square_size[2];

	square_size[0] = SCREEN_X / 50;
	square_size[1] = SCREEN_Y / 50;
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
	while (i < SCREEN_X / 50 * 9)
	{
		j = 0;
		while (j < SCREEN_X / 50 * 9)
		{
			mlx_put_pixel(minimap, i, j, 0x0000ff);
			j++;
		}
		i++;
	}
}

//plante quand approche bord tableau 9 * 9
void	ft_minimap(t_game *g)// pixel noir rend transparent
{
	mlx_image_t	*minimap;
	int			x;
	int			y;
	int			i;
	int			j;

	minimap = g->img;//minimap 1/5e ecran
	ft_mini_init(minimap);//met le fond
	
	x = /*player - 5*/ g->player->x - 4;
	i = 0;
	while (i < /*10 cases / taille minimap*/ 9)
	{
		y = /*player + 5*/ g->player->y - 4;
		j = 0;
		while (j < /*10 cases / taille minimap*/ 9) 
		{
			printf("x : %d, y : %d\n", x, y);
			if (x < 0 || y < 0 || !g->map->map[y][x])
			{
				i++;
				j++;
				x++;
				y++;
				continue;
			}
			if (g->map->map[y][x] == '1')
				ft_print_square(i + 1, j + 1, minimap, 0x2f00ff);
			y++;
			j++;
		}
		x++;
		i++;
	}
	ft_print_square(5, 5, minimap, 0xff00b7);
	// i = g->player->x - (SCREEN_X / 200);
	// printf("x : %f, %d\n", g->player->x, SCREEN_X / 200);
	// if (i < 0)
	// 	i = 0;
	// while (i < g->player->x + (SCREEN_X / 200) && g->map->map[0][i])
	// {
	// 	j = g->player->y - (SCREEN_Y / 200);
	// 	if (j < 0)
	// 		j = 0;
	// 	while (j < g->player->y + (SCREEN_Y / 200) && g->map->map[j][0])
	// 	{
	// 		if (g->map->map[j][i] == '1')//mur
	// 			ft_print_square(i, j, minimap, 0x2f00ff);
	// 		j++;
	// 	}
	// 	i++;
	// }
}

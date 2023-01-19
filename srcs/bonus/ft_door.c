/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:39:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/19 14:30:59 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_door(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_F))
	{
		if (g->map->map[(int)g->player->y + 1][(int)g->player->x] == 'D' && (int)g->player->y + 1 != g->map->size_y - 1)
			g->map->map[(int)g->player->y + 1][(int)g->player->x] = 'O';
		else if (g->map->map[(int)g->player->y + 1][(int)g->player->x] == 'O' && (int)g->player->y + 1 != g->map->size_y - 1)
			g->map->map[(int)g->player->y + 1][(int)g->player->x] = 'D';
		if (g->map->map[(int)g->player->y - 1][(int)g->player->x] == 'D' && (int)g->player->y - 1 != 0)
			g->map->map[(int)g->player->y - 1][(int)g->player->x] = 'O';
		else if (g->map->map[(int)g->player->y - 1][(int)g->player->x] == 'O' && (int)g->player->y - 1 != 0)
			g->map->map[(int)g->player->y - 1][(int)g->player->x] = 'D';
		if (g->map->map[(int)g->player->y][(int)g->player->x + 1] == 'D' && (int)g->player->x + 1 != g->map->size_x - 1)
			g->map->map[(int)g->player->y][(int)g->player->x + 1] = 'O';
		else if (g->map->map[(int)g->player->y][(int)g->player->x + 1] == 'O' && (int)g->player->x + 1 != g->map->size_x - 1)
			g->map->map[(int)g->player->y][(int)g->player->x + 1] = 'D';
		if (g->map->map[(int)g->player->y][(int)g->player->x - 1] == 'D' && (int)g->player->x - 1 != 0)
			g->map->map[(int)g->player->y][(int)g->player->x - 1] = 'O';
		else if (g->map->map[(int)g->player->y][(int)g->player->x - 1] == 'O' && (int)g->player->x - 1 != 0)
			g->map->map[(int)g->player->y][(int)g->player->x - 1] = 'D';
		usleep(100000);
	}
}

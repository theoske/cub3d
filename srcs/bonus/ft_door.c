/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:39:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/18 20:36:51 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//ajouter texture porte

//quand D est dans map -> mur invisble => lui donner une texture speciale

//la manipuler avec :
void	ft_door(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_F))
	{
		if (g->map->map[(int)g->player->y + 1][(int)g->player->x] == 'D' && (int)g->player->y + 1 != g->map->size_y - 1)
			g->map->map[(int)g->player->y + 1][(int)g->player->x] = '0';
		if (g->map->map[(int)g->player->y - 1][(int)g->player->x] == 'D' && (int)g->player->y - 1 != 0)
			g->map->map[(int)g->player->y - 1][(int)g->player->x] = '0';
		if (g->map->map[(int)g->player->y][(int)g->player->x + 1] == 'D' && (int)g->player->x + 1 != g->map->size_x - 1)
			g->map->map[(int)g->player->y][(int)g->player->x + 1] = '0';
		if (g->map->map[(int)g->player->y][(int)g->player->x - 1] == 'D' && (int)g->player->x - 1 != 0)
			g->map->map[(int)g->player->y][(int)g->player->x - 1] = '0';
	}
}

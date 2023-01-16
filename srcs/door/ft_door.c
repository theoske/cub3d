/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:39:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/16 17:46:17 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ajouter texture porte

//quand D est dans map -> mur invisble => lui donner une texture speciale

//la manipuler avec :
void	ft_door(t_game *g)
{
	//si il y a une porte a 1 de distqnce et si 'f' est appuye alors ouvrir porte
	if (g->map->map[(int)g->player->y + 1][(int)g->player->x] == 'D' || g->map->map[(int)g->player->y][(int)g->player->x + 1] == 'D' && mlx_is_key_down(g->mlx, MLX_KEY_F))
	{ 
		//faire animation de disparition en reduisant la taille sprite jusqua 0
		//changer map 'D' door qui fonctionne comme un mur en '0' qui fonctionne comme sol
	}
}
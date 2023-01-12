/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:54:59 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/12 14:53:46 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse_aiming(t_game *g)
{
	int		posx;
	int		posy;

	mlx_set_cursor_mode(g->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(g->mlx, &posx, &posy);
	if (posx < SCREEN_X / 2 - 10)
		g->player->angle -= g->pt_speed / 2;
	else if (posx > SCREEN_X / 2 + 10)
		g->player->angle += g->pt_speed / 2;
	g->player->angle = ft_fixangle(g->player->angle);

	mlx_set_mouse_pos(g->mlx, SCREEN_X / 2, g->img->height / 2);
}

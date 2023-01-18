/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:54:59 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/16 16:26:52 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse_aiming(t_game *g)
{
	static int	oldx = SCREEN_X / 2;
	int			posx;
	int			posy;

	mlx_set_cursor_mode(g->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(g->mlx, &posx, &posy);
	g->player->angle += (((double)posx / 1000) - ((double)oldx / 1000));
	mlx_set_mouse_pos(g->mlx, SCREEN_X / 2, g->img->height / 2);
	posx = SCREEN_X / 2;
	g->player->angle = ft_fixangle(g->player->angle);
	oldx = posx;
}

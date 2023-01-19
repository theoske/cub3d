/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:54:59 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/19 19:28:45 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_focus(t_game *g)
{
	static int	ret = 0;
	int			x;
	int			y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(g->mlx, &x, &y);
	if (mlx_is_mouse_down(g->mlx, MLX_MOUSE_BUTTON_LEFT) && x > 0 && \
		(unsigned int)x < g->img->width && y > 0 && \
		(unsigned int)y < g->img->height)
		ret = 1;
	else if (mlx_is_mouse_down(g->mlx, MLX_MOUSE_BUTTON_RIGHT))
		ret = 0;
	return (ret);
}

void	mouse_aiming(t_game *g)
{
	static int	oldx = SCREEN_X / 2;
	int			posx;
	int			posy;

	if (is_focus(g))
	{
		mlx_set_cursor_mode(g->mlx, MLX_MOUSE_HIDDEN);
		mlx_get_mouse_pos(g->mlx, &posx, &posy);
		g->player->angle += (((double)posx / 1000) - ((double)oldx / 1000));
		mlx_set_mouse_pos(g->mlx, SCREEN_X / 2, g->img->height / 2);
		posx = SCREEN_X / 2;
		g->player->angle = ft_fixangle(g->player->angle);
		oldx = posx;
	}
}

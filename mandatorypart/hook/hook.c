/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:38 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:41:59 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/includes/cub3d.h"

void	hook(void *base)
{
	t_game	*g;

	g = (t_game *)base;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S)
		|| mlx_is_key_down(g->mlx, MLX_KEY_W))
		ft_player_move_fb(g->mlx, g->player, g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A)
		|| mlx_is_key_down(g->mlx, MLX_KEY_D))
		ft_player_turn(g->mlx, g->player, g);
	g->player->dx = cos(g->player->angle);
	g->player->dy = sin(g->player->angle);
	ft_sum_ray(g);
	ft_draw(g);
}

void	ft_player_move_fb(mlx_t *mlx, t_pos *player, t_game *g)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S) && !mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (player->y > 0 && (player->x + (0.5 * player->dx)) > 0.1)
			player->x -= player->dx * g->p_speed;
		if (player->x > 0 && (player->y + (0.5 * player->dx)) > 0.1)
			player->y -= player->dy * g->p_speed;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_S)
		&& mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (player->y > 0 && (player->x + (0.5 * player->dx)) > 0.1)
			player->x += player->dx * g->p_speed;
		if (player->x > 0 && (player->y + (0.5 * player->dx)) > 0.1)
			player->y += player->dy * g->p_speed;
	}
}

void	ft_player_turn(mlx_t *mlx, t_pos *player, t_game *g)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle -= g->pt_speed / 4;
	else if (!mlx_is_key_down(mlx, MLX_KEY_A)
		&& mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle += g->pt_speed / 4;
	player->angle = ft_fixangle(player->angle);
}

double	ft_fixangle(double angle)
{
	if (angle < 0)
		angle += (M_PI * 2);
	else if (angle > M_PI * 2)
		angle -= (M_PI * 2);
	return (angle);
}

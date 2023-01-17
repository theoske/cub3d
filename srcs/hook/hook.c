/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:38 by stissera          #+#    #+#             */
/*   Updated: 2023/01/17 16:12:55 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hook(void *base)
{
	t_game	*g;

	g = (t_game *)base;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
	{
		g->pt_speed = 0.15;
		g->p_speed = 0.2;
	}
	if (!mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
	{
		g->pt_speed = 0.1;
		g->p_speed = 0.1;
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_S)
		|| mlx_is_key_down(g->mlx, MLX_KEY_W))
		ft_player_move_fb(g->mlx, g->player, g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A)
		|| mlx_is_key_down(g->mlx, MLX_KEY_D))
		ft_player_turn(g->mlx, g->player, g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(g->mlx, MLX_KEY_E))
		ft_player_strafe(g->mlx, g->player, g);
//	if (mlx_is_key_down(g->mlx, MLX_KEY_B))
//		ft_debug(base);
//	if (mlx_is_key_down(g->mlx, MLX_KEY_TAB))
//		base->window->minimap_o = 1;
//	else
//		base->window->minimap_o = 0;
	mouse_aiming(g);
	ft_door(g);
	g->player->dx = cos(g->player->angle);
	g->player->dy = sin(g->player->angle);
	ft_sum_ray(g);
	ft_draw(g);
	ft_minimap(g);
}

void	ft_player_move_fb(mlx_t *mlx, t_pos *player, t_game *g)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S) && !mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (g->map->map[(int)player->y] \
			[(int)(player->x - (0.5 * player->dx))] == 48)
			player->x -= player->dx * g->p_speed;
		if (g->map->map[(int)(player->y - (0.5 * player->dy))] \
			[(int)player->x] == 48)
			player->y -= player->dy * g->p_speed;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_S)
		&& mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (g->map->map[(int)player->y] \
			[(int)(player->x + (0.5 * player->dx))] == 48)
			player->x += player->dx * g->p_speed;
		if (g->map->map[(int)(player->y + (0.5 * player->dy))] \
			[(int)player->x] == 48)
			player->y += player->dy * g->p_speed;
	}
}

void	ft_player_strafe(mlx_t *mlx, t_pos *player, t_game *g)
{
	if (mlx_is_key_down(mlx, MLX_KEY_Q) && !mlx_is_key_down(mlx, MLX_KEY_E))
	{
		if (g->map->map[(int)player->y] \
			[(int)(player->x + (0.5 * player->dy))] == 48)
			player->x += player->dy * g->p_speed;
		if (g->map->map[(int)(player->y - (0.5 * player->dx))] \
		[(int)player->x] == 48)
			player->y -= player->dx * g->p_speed;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_Q)
		&& mlx_is_key_down(mlx, MLX_KEY_E))
	{
		if (g->map->map[(int)player->y] \
			[(int)(player->x - (0.5 * player->dy))] == 48)
			player->x -= player->dy * g->p_speed;
		if (g->map->map[(int)(player->y + (0.5 * player->dx))] \
			[(int)player->x] == 48)
			player->y += player->dx * g->p_speed;
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

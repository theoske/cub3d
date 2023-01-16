/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:40:56 by stissera          #+#    #+#             */
/*   Updated: 2023/01/16 17:40:14 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_pos	ray_inter_x(t_game *g, double x, double y)
{
	t_pos	inter;

	inter.x = (int)g->player->x + (x > 0) - (x < 0);
	if (x > 0)
		inter.y = g->player->y + y * (1 - (g->player->x - (int)g->player->x));
	else
		inter.y = g->player->y + y * (g->player->x - (int)g->player->x);
	while ((unsigned)inter.y < (unsigned)g->map->size_y && \
			(unsigned)inter.x < (unsigned)g->map->size_x && \
			g->map->map[(unsigned)inter.y][(unsigned)inter.x] != '1')// D
			inter = (t_pos){inter.x + x, inter.y + y, 0, 0, 0, 0};
	inter.x += (x < 0);
	return (inter);
}

static t_pos	ray_inter_y(t_game *g, double x, double y)
{
	t_pos	inter;

	inter.y = (int)g->player->y + (y > 0) - (y < 0);
	if (y > 0)
		inter.x = g->player->x + x * (1 - (g->player->y - (int)g->player->y));
	else
		inter.x = g->player->x + x * (g->player->y - (int)g->player->y);
	while ((unsigned)inter.y < (unsigned)g->map->size_y && \
			(unsigned)inter.x < (unsigned)g->map->size_x && \
			g->map->map[(unsigned)inter.y][(unsigned)inter.x] != '1')// D
		inter = (t_pos){inter.x + x, inter.y + y, 0, 0, 0, 0};
	inter.y += (y < 0);
	return (inter);
}

static void	ray_sum(t_game *g, double angle, unsigned int ray)
{
	t_pos	x;
	t_pos	y;
	t_pos	dist;
	int		stx;
	int		sty;

	stx = 1 - 2 * !(angle <= M_PI_2 || angle > 3 * M_PI_2);
	sty = 1 - 2 * (angle > M_PI);
	x = ray_inter_x(g, stx, stx * tan(angle));
	y = ray_inter_y(g, (float)sty / tan(angle), (float)sty);
	dist = (t_pos){g->player->dx * (x.x - g->player->x)
		+ g->player->dy * (x.y - g->player->y),
		g->player->dx * (y.x - g->player->x)
		+ g->player->dy * (y.y - g->player->y), 0, 0, 0, 0};
	if (dist.x < dist.y)
		g->ray[ray] = (t_ray){(unsigned int)(g->scale / dist.x) & ~1,
			x.y - (int)x.y, "EW"[x.x < g->player->x]};
	else
		g->ray[ray] = (t_ray){(unsigned int)(g->scale / dist.y) & ~1,
			y.x - (int)y.x, "SN"[y.y < g->player->y]};
	if (g->ray[ray].dir == 'W' || g->ray[ray].dir == 'S')
		g->ray[ray].texture_pos = 1. - g->ray[ray].texture_pos;
}

void	ft_sum_ray(t_game *g)
{
	unsigned int	ray;
	double			angle;

	ray = 0;
	while (ray < SCREEN_X)
	{
		angle = g->player->angle
			+ atan(g->step * (ray - ((float)SCREEN_X / 2)));
		angle = ft_fixangle(angle);
		ray_sum(g, angle, ray);
		ray++;
	}
}

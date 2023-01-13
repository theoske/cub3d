/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:42:07 by stissera          #+#    #+#             */
/*   Updated: 2023/01/12 19:11:00 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_draw_col(mlx_texture_t *texture, int col, int dst_y, t_point point)
{
	unsigned int	x;
	unsigned int	y;
	t_game			*g;

	x = point.x;
	y = point.y;
	g = (t_game *)ft_get_struct(NULL);
	g->img->pixels[(col * 4) + (g->img->width * dst_y * 4)]
		= texture->pixels[(y * texture->width) * 4 + x * 4];
	g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 1]
		= texture->pixels[(y * texture->width) * 4 + x * 4 + 1];
	g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 2]
		= texture->pixels[(y * texture->width) * 4 + x * 4 + 2];
	g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 3]
		= texture->pixels[(y * texture->width) * 4 + x * 4 + 3];
}

static void	ft_draw_scaled(t_ray *ray, mlx_texture_t *texture,
	unsigned int col)
{
	const unsigned int	x = ray->texture_pos * texture->width;
	unsigned int		y;
	unsigned int		dst_y;
	unsigned int		max_y;
	unsigned int		error;

	y = 0;
	dst_y = ft_max(0, ((int)SCREEN_Y - (int)ray->height) / 2);
	max_y = dst_y + ray->height;
	error = texture->height / 2;
	if (ray->height > SCREEN_Y)
	{
		error = (ray->height - SCREEN_Y) * texture->height / 2;
		y = error / ray->height;
		error = error % ray->height;
		max_y = SCREEN_Y;
	}
	while (dst_y < max_y)
	{
		while (error >= ray->height && ++y)
			error -= ray->height;
		ft_draw_col(texture, col, dst_y, (t_point){x,y});
		dst_y++;
		error += texture->width;
	}
}

void	ft_draw(t_game *g)
{
	unsigned int	ray;
	unsigned int	textures;

	ray = 0;
	ft_fill_img(g->img->pixels, g->map->texture[5]->pixels, 0,
		g->img->width * g->img->height / 2);
	ft_fill_img(g->img->pixels, g->map->texture[4]->pixels,
		g->img->width * g->img->height / 2,
		g->img->width * g->img->height);
	while (ray < SCREEN_X)
	{
		textures = ft_strchr("NSWE", g->ray[ray].dir) - "NSWE";
		ft_draw_scaled(&g->ray[ray], g->map->texture[textures], ray);
		ray++;
	}
}

void	ft_fill_img(void *pixels, void *fill, size_t s, size_t e)
{
	unsigned int	*array;
	unsigned int	*tofill;
	size_t			t;

	array = pixels;
	tofill = fill;
	if (s > e)
	{
		t = e;
		e = s;
		s = t;
	}
	while (s < e)
		array[s++] = *tofill;
}

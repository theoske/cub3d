/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:34:36 by stissera          #+#    #+#             */
/*   Updated: 2023/01/16 15:41:48 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

mlx_texture_t	*ft_atexture(t_atexture *texture, mlx_texture_t *t)
{
	static bool		active = 0;
	mlx_texture_t	*ret;

	texture->timer = time(NULL);
	if (texture->timer % texture->n_time == 0 && active == 0)
	{
		ret = texture->frame[texture->nframe++];
		if (texture->nframe == texture->nbr_frame)
			texture->nframe = 0;
		active = 1;
		return (ret);
	}
	if (texture->timer % texture->n_time != 0)
		active = 0;
	return (t);
}

void	ft_atexture_init(t_game	*g)
{
	g->map->animed = (t_atexture *)malloc(sizeof(t_atexture) * NBR_TEXTURE);
	if (!g->map->animed)
		exit (0 * ft_error(INIT_ALLOC));
	g->map->animed->nbr_frame = 4;
	g->map->animed->n_time = 2;
	g->map->animed->nframe = 0;
	g->map->animed->frame = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *)
			* g->map->animed->nbr_frame);
	if (!g->map->animed[0].frame)
		exit (0 * ft_error(INIT_ALLOC));
	g->map->animed->frame[0] = mlx_load_png("./textures/LAVA1.png");
	g->map->animed->frame[1] = mlx_load_png("./textures/LAVA2.png");
	g->map->animed->frame[2] = mlx_load_png("./textures/LAVA3.png");
	g->map->animed->frame[3] = mlx_load_png("./textures/LAVA4.png");
}

int	ft_free_atexture(t_map *map)
{
	int	i;

	i = 0;
	if (!map->animed)
		return (0);
	free(map->animed->frame);
	free(map->animed);
	return (0);
}

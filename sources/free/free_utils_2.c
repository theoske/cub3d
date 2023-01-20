/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:26:40 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:36:18 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_delete_texture(mlx_texture_t *texture)
{
	if (texture && texture->height > 1)
	{
		mlx_delete_texture(texture);
	}
	else if (texture)
	{
		free(texture->pixels);
		free(texture);
	}
	return (0);
}

void	ft_free_texture(t_map *m)
{
	int	id;

	id = -1;
	while (++id < 18)
	{
		if (m->color[id])
		{
			free(m->texture[id]->pixels);
			free(m->texture[id]);
			m->color[id] = NULL;
			m->texture[id] = NULL;
		}
		if (m->texture[id])
		{
			mlx_delete_texture(m->texture[id]);
			m->texture[id] = NULL;
		}
	}
}

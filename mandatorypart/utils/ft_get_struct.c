/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:17:25 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:43:22 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/includes/cub3d.h"

void	*ft_get_struct(void *data)
{
	static int			reload;
	static t_game		*g;

	if (reload != 1)
	{
		g = (t_game *)data;
		reload = 1;
	}
	if (data == NULL)
		return (g);
	if (!ft_strncmp(data, "player", 7))
		return ((t_pos *)g->player);
	if (!ft_strncmp(data, "window", 7))
		return ((mlx_image_t *)g->img);
	if (!ft_strncmp(data, "map", 4))
		return ((t_map *)g->map);
	return (NULL);
}

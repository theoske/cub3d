/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:39:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/20 15:03:33 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_door2(t_game *g, t_door **door, t_door *bak)
{
	if (door[0]->next == NULL && door[0]->prev == NULL)
	{
		g->door = NULL;
		free(door[0]);
		door[0] = NULL;
	}
	else if (door[0]->prev == NULL && door[0]->next != NULL)
	{
		g->door = door[0]->next;
		g->door->prev = NULL;
		free(door[0]);
		door[0] = g->door;
	}
	else if (door[0]->prev != NULL && door[0]->next != NULL)
	{
		bak = door[0];
		door[0]->prev->next = door[0]->next;
		door[0]->next->prev = door[0]->prev;
		door[0] = door[0]->next;
		free(bak);
		bak = NULL;
	}
}

void	ft_check_door(t_game *g)
{
	t_door	*door;
	t_door	*bak;

	door = g->door;
	bak = NULL;
	while (door)
	{
		if (((g->time.tv_sec * 1000) + (g->time.tv_usec / 1000)) - \
			((door->start_at.tv_sec * 1000) + (door->start_at.tv_usec / 1000)) \
			> door->close_time && ((int)g->player->x != door->x || \
			(int)g->player->y != door->y))
		{
			g->map->map[door->y][g->door->x] = 'D';
			ft_check_door2(g, &door, bak);
			if (door->prev != NULL && door->next == NULL)
			{
				door->prev->next = NULL;
				free(door);
				return ;
			}
			continue ;
		}
		door = door->next;
	}
}

static void	ft_open_door(int y, int x, t_map *map)
{
	t_game	*g;
	t_door	*new;
	t_door	*exist;

	g = (t_game *)ft_get_struct(NULL);
	map->map[y][x] = 'S';
	new = (t_door *)malloc(sizeof(t_door));
	if (!new)
		exit(ft_error(INIT_ALLOC));
	*new = (t_door){NULL, x, y, {0, 0}, 5000, NULL};
	gettimeofday(&new->start_at, NULL);
	if (!g->door)
	{
		g->door = new;
		return ;
	}
	exist = g->door;
	while (exist->next)
		exist = exist->next;
	new->prev = exist;
	exist->next = new;
	return ;
}

void	ft_door(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_F))
	{
		if (g->map->map[(int)g->player->y + 1][(int)g->player->x] == 'D' && \
			(int)g->player->y + 1 != g->map->size_y - 1 && \
			(g->player->angle > M_PI_4 && g->player->angle < M_PI_4 * 3))
			ft_open_door((int)g->player->y + 1, (int)g->player->x, g->map);
		if (g->map->map[(int)g->player->y - 1][(int)g->player->x] == 'D' && \
			(int)g->player->y - 1 != 0 && \
			(g->player->angle > M_PI_4 * 5 && g->player->angle < M_PI_4 * 7))
			ft_open_door((int)g->player->y - 1, (int)g->player->x, g->map);
		if (g->map->map[(int)g->player->y][(int)g->player->x + 1] == 'D' && \
			(int)g->player->x + 1 != g->map->size_x - 1 &&
			(g->player->angle > M_PI_4 * 7 || g->player->angle < M_PI_4))
			ft_open_door((int)g->player->y, (int)g->player->x + 1, g->map);
		if (g->map->map[(int)g->player->y][(int)g->player->x - 1] == 'D' && \
			(int)g->player->x - 1 != 0 && \
			(g->player->angle > M_PI_4 * 3 && g->player->angle < M_PI_4 * 5))
			ft_open_door((int)g->player->y, (int)g->player->x - 1, g->map);
	}
}

void	ft_free_door(t_door *d)
{
	if (!d)
		return ;
	if (d->next)
		ft_free_door(d->next);
	free(d);
}

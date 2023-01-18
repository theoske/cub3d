/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:39:23 by stissera          #+#    #+#             */
/*   Updated: 2023/01/18 22:27:48 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	g;
	t_map	map;
	t_pos	player;

	g = (t_game){0};
	ft_init_struct(&g, &map, &player);
	ft_get_struct(&g);
	if (ac != 2)
		return (1 + (0 * ft_error(ARG)));
	if (ft_file_name(av[1]))
		return (1 + (0 * write(1, "Error file name! Need .cub\n", 27)));
	window_init(&g);
	if (ft_import_map (av[1], &g))
		return (1 + (0 * ft_error(MAP_ERROR)));
	ft_atexture_init(&g);
	mlx_loop_hook(g.mlx, &hook, &g);
	mlx_loop(g.mlx);
	ft_free_texture(g.map);
	mlx_delete_image(g.mlx, g.img);
	mlx_close_window(g.mlx);
	mlx_terminate(g.mlx);
	ft_free_tab(g.map->map);
	ft_free_atexture(g.map);
	return (0);
}

int	ft_init_struct(t_game *g, t_map *map, t_pos *player)
{
	*player = (t_pos){0};
	*map = (t_map){0};
	g->player = player;
	g->map = map;
	g->p_speed = 0.1;
	g->pt_speed = 0.1;
	return (0);
}

void	window_init(t_game *g)
{
	g->mlx = mlx_init(SCREEN_X, SCREEN_Y, NAME, false);
	g->aspect = (float)SCREEN_X / (float)SCREEN_Y;
	if (!g->mlx)
		exit (1);
	g->img = mlx_new_image(g->mlx, SCREEN_X, SCREEN_Y);
	mlx_image_to_window(g->mlx, g->img, 0, 0);
	g->fov = ((g->aspect >= 1.77) - (g->aspect < 1.77)) * \
			sqrt(fabs(M_PI_4 * (g->aspect - 1.77) / 2)) + M_PI_2;
	g->step = tan(g->fov / (SCREEN_X - 1));
	g->scale = 1 / g->step;
}

double	ft_fixangle(double angle)
{
	if (angle < 0)
		angle += (M_PI * 2);
	else if (angle > M_PI * 2)
		angle -= (M_PI * 2);
	return (angle);
}

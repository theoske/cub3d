/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:58:09 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 14:37:03 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_add_color_texture(unsigned char *rgba,
	t_map *map, int id)
{
	ft_delete_texture(map->texture[id]);
	map->texture[id] = (mlx_texture_t *) malloc(sizeof(mlx_texture_t));
	map->texture[id]->bytes_per_pixel = 4;
	map->texture[id]->height = 1;
	map->texture[id]->width = 1;
	map->texture[id]->pixels = (uint8_t *) malloc(sizeof(uint8_t) * 4);
	map->texture[id]->pixels[0] = (uint8_t)rgba[0];
	map->texture[id]->pixels[1] = (uint8_t)rgba[1];
	map->texture[id]->pixels[2] = (uint8_t)rgba[2];
	map->texture[id]->pixels[3] = (uint8_t)rgba[3];
	map->color[id] = map->texture[id];
	return ;
}

static int	ft_putarg_rgb(char *line, t_map *map, int id)
{
	unsigned char	rgba[4];
	int				i;
	int				nbr;

	i = 0;
	ft_bzero(rgba, 4);
	while (*line && i <= 3)
	{
		nbr = ft_atoi(line);
		if (nbr < 0 || nbr > 255)
			exit(1 + (0 * ft_error(BAD_COLOR)));
		rgba[i] = nbr + 0;
		while (*line && ft_isdigit(*(line++)))
			;
		while (*line && !ft_isdigit(*(line)))
			line++;
		if (*line)
			i++;
	}
	if (i < 2 || i > 3)
		exit(1 + (0 * ft_error(BAD_COLOR)));
	if (!rgba[3])
		rgba[3] = 255;
	ft_add_color_texture(rgba, map, id);
	return (0);
}

static int	ft_putarg_in(char *line, t_map *map, int id)
{
	int		i;
	char	*file;

	i = 0;
	file = NULL;
	if (!strncmp(line, "./", 2) || !strncmp(line, "../", 3))
	{
		while (line[i] && line[i] != ' ')
			i++;
		file = (char *)malloc((sizeof(char) * i) + 1);
		if (!file)
			exit(1 + (0 * ft_error(INIT_ALLOC)));
		file[i] = 0;
		while (--i >= 0)
			file[i] = line[i];
		if ((!ft_strcmp(&file[ft_strlen(file) - 4], ".png") || !ft_strcmp(\
&file[ft_strlen(file) - 4], ".PNG")) && !ft_delete_texture(map->texture[id]))
				map->texture[id] = mlx_load_png(file);
		ft_free_str(file);
		if (map->texture[id] == NULL)
			exit(1 + (0 * ft_error(NEX_FILE)));
	}
	else if (ft_putarg_rgb(line, map, id))
		exit(1 + (0 * ft_error(BAD_COLOR)));
	return (0);
}

static int	ft_map_param_wf(char *line, t_game *g, int i)
{
	if (i == 4 || i == 5)
		line += 2;
	else
		line += 3;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, g->map, i);
	return (0);
}

int	ft_map_insert_param(char *line, t_game *g)
{
	if (!ft_strncmp(line, "NO ", 3))
		ft_map_param_wf(line, g, 0);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_map_param_wf(line, g, 1);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_map_param_wf(line, g, 2);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_map_param_wf(line, g, 3);
	else if (!ft_strncmp(line, "F ", 2))
		ft_map_param_wf(line, g, 4);
	else if (!ft_strncmp(line, "C ", 2))
		ft_map_param_wf(line, g, 5);
	else
		return (-1 + (0 * write(1, "Invalid argurment in map file!\n", 31)));
	return (0);
}

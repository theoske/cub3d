/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:25:43 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:42:07 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/includes/cub3d.h"

static void	ft_input_line_map(char **line, char **create, int *l, int *c)
{
	t_pos	*g;

	g = ft_get_struct("player");
	*c = *c + 1;
	if (**line == 'N' || **line == 'S' || **line == 'E' || **line == 'W')
	{
		create[*l][*c] = '0';
		if (g->positioned != 0 && !ft_error(BAD_START))
			exit(1);
		if (**line == 'N')
			g->angle = M_PI_2 * 3;
		if (**line == 'S')
			g->angle = M_PI_2;
		if (**line == 'W')
			g->angle = M_PI;
		g->positioned = *line[0]++;
		g->x = *c + 0.5;
		g->y = *l + 0.5;
	}
	else if (**line == ' ' || **line == '1' || **line == '0')
		create[*l][*c] = *line[0]++;
	else
		exit(1 + (0 * ft_error(MAP_ERROR)));
	return ;
}

static int	ft_realloc_map(t_map *map, char *line, char **create)
{
	int		l;
	int		c;

	create = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!create && ft_error(INIT_ALLOC))
		exit(1);
	ft_bzero(create, sizeof(char *) * (map->size_y + 1));
	l = -1;
	while (++l < map->size_y)
	{
		create[l] = (char *)malloc(sizeof(char) * (map->size_x) + 1);
		if (!create[l] && ft_error(INIT_ALLOC))
			exit(1);
		ft_bzero(create[l], map->size_x + 1);
		if (l < map->size_y - 1)
			ft_memset(create[l], '1', map->size_x);
		c = -1;
		while (l < map->size_y - 1 && map->map[l][++c])
			create[l][c] = map->map[l][c];
	}
	ft_memset(create[--l], '1', map->size_x);
	while (*line)
		ft_input_line_map(&line, create, &l, &c);
	map->map = ft_free_tab(map->map) + create;
	return (0);
}

static int	ft_map_first(t_map *map, char *line, char **create)
{
	int		c;

	create = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!create && ft_error(INIT_ALLOC))
		exit(1);
	ft_bzero(create, sizeof(char *) * (map->size_y + 1));
	create[0] = (char *)malloc(sizeof(char) * (map->size_x + 1));
	if (!create[0] && ft_error(INIT_ALLOC))
		exit(1);
	ft_bzero(create[0], map->size_x + 1);
	ft_memset(create[0], '0', map->size_x);
	c = -1;
	while (*line)
	{
		if ((*line == 'N' || *line == 'S' \
			|| *line == 'E' || *line == 'W') && line++)
			create[0][++c] = '0';
		else if (*line == ' ' && line++)
			create[0][++c] = '1';
		else
			create[0][++c] = *line++;
	}
	map->map = create;
	return (0);
}

int	ft_map_create(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i > 0)
	{
		if (i > map->size_x)
			map->size_x = i;
		map->size_y++;
		if (map->map || ft_map_first(map, line, NULL))
		{
			if (line[0] == '\n')
				exit(1 + (0 * ft_error(MAP_ERROR)));
			if (ft_realloc_map(map, line, NULL))
				exit(1 + (0 * ft_error(INIT_ALLOC)));
		}
		return (1);
	}
	return (0);
}

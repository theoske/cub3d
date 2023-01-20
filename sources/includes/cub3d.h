/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:45:48 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 18:04:37 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BONUS
#else	#include "../../bonuspart/includes/cub3d_bonus.h"
#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <math.h>

# define SCREEN_X 1024
# define SCREEN_Y 768
# define SCALE 32
# define NAME "CUB3D - stissera"
# define P_SPEED 0.1
# define FPS 50

enum e_type_err
{
	ZERO,
	ARG,
	INIT_BASE,
	MAP_ERROR = 0x04,
	INIT_WINDOW = 0x08,
	INIT_ALLOC = 0x10,
	NEX_FILE = 0x20,
	BAD_COLOR = 0x40,
	BAD_START = 0x80,
	UNK_CARMAP = 0xFF,
	MISS_TEXTURE = 0xA0
};

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}	t_point;

typedef struct s_pos
{
	double			x;
	double			y;
	double			angle;
	char			positioned;
	double			dx;
	double			dy;
}	t_pos;

typedef struct s_map
{
	int				size_x;
	int				size_y;
	char			**map;
	mlx_texture_t	*texture[6];
	mlx_texture_t	*color[6];
}	t_map;

typedef struct s_ray
{
	unsigned int	height;
	double			texture_pos;
	char			dir;
}	t_ray;

typedef struct s_game
{
	void			*mlx;
	double			step;
	double			scale;
	float			fov;
	float			aspect;
	mlx_image_t		*img;
	t_pos			*player;
	t_map			*map;
	t_ray			ray[SCREEN_X];
	double			p_speed;
	double			pt_speed;
}	t_game;

void	ft_sum_ray(t_game *g);
void	ft_draw(t_game *g);
void	ft_fill_img(void *pixels, void *fill, size_t s, size_t e);

int		ft_init_struct(t_game *g, t_map *map, t_pos *player);
void	window_init(t_game *g);
int		ft_file_name(char *file);

int		ft_free_map(t_map *map);
int		ft_free_str(char *str);
int		ft_free_int(int *nbr);
int		ft_free_tab(char **tab);
int		ft_free_tab_int(int **tab);
void	ft_free_texture(t_map *m);
int		ft_delete_texture(mlx_texture_t *texture);

void	hook(void *g);
int		ft_import_map(char *file, t_game *base);
int		ft_map_create(char *line, t_map *map);
int		ft_map_insert_param(char *line, t_game *g);
int		ft_file_exist(char *file);
void	*ft_get_struct(void *data);

int		ft_error(int value);

void	ft_player_move_fb(mlx_t *mlx, t_pos *player, t_game *g);
void	ft_player_turn(mlx_t *mlx, t_pos *player, t_game *g);
void	ft_player_strafe(mlx_t *mlx, t_pos *player, t_game *g);

double	ft_fixangle(double angle);
int		ft_max(int i, int j);
#endif

#endif
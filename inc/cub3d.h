/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:35 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/07 19:17:02 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <string.h>
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"

# define NB_PARAMS_PARSE 7
# define PI 3.14159265
# define PI2
# define MAX_X 1920
# define MAX_Y 1080

# define ESC 65307
# define R_LEFT 65361
# define R_RIGHT 65363
# define W 119
# define S 115
# define D 100
# define Q 97
# define TRUE 0
# define FALSE 1

enum e_err {
	e_gnl,
	e_malloc,
	e_wrong_param,
	e_qt_param,
	e_cub_file,
	e_wrong_map,
	e_param_qt,
	e_param_type,
	e_param_path,
	e_param_color,
	e_map_char,
	e_map_hole,
	e_map_multi_pl
};

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		init;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_data;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

typedef struct	s_vector
{
	float	x;
	float	y;
}				t_vector;

typedef struct s_player
{
	float			pos_x;
	float			pos_y;
	int				going_up;
	int				going_down;
	int				going_left;
	int				going_right;
	int				rotate_left;
	int				rotate_right;
	size_t			is_moving;
	char			orientation;
	float			angle;
	float			pos_delta_x;
	float			pos_delta_y;
	t_vector		dir_v;
	t_vector		cam_v;
}					t_player;

typedef struct s_ray
{
	int				map_x;
	int				map_y;
	float			length_x;
	float			length_y;
	float			delta_length_x;
	float			delta_length_y;
	float			wall_dist;
	int				step_x;
	int				step_y;
	int				side;
}					t_ray;


typedef struct s_parser_valid
{
	int				resolution;
	int				floor;
	int				ceiling;
	int				texture_no;
	int				texture_so;
	int				texture_we;
	int				texture_ea;
	int				texture_sp;
}					t_parser_valid;

typedef struct s_params
{
	unsigned int	res_x;
	unsigned int	res_y;
	char			*path_texture_no;
	char			*path_texture_so;
	char			*path_texture_we;
	char			*path_texture_ea;
	int				ceiling_color[3];
	int				floor_color[3];
	unsigned int	nb_valid_param;
	t_parser_valid	unique;
}					t_params;

typedef struct s_map
{
	char			**map;
	size_t			width;
	size_t			height;
}					t_map;

typedef struct s_base {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_params	*params;
	t_color		*colors;
	t_data		*img;
	t_data		*north;
	t_data		*east;
	t_data		*south;
	t_data		*west;
	t_data		*minime;
	t_player	*player;
}		t_base;

/*
**	Errors
*/
void				error_init(char *context);
void				ft_exit(char *context);
/*
**	RayCasting
*/
void	draw_ray(t_base *base);
/*
**	MLX and images
*/
void    destroy_base(t_base *base, char *err);
void	put_img(t_base *base);
void	init_tiles(t_base *base);
int		close_win(t_base *base);
int		draw_line(t_base *base, int startX, int startY, int endX, int endY, int color);
void	update(t_base *base);

void	to_wall(t_base *base);
/*
**	Moves
*/
int		key_press(int keycode, t_base *base);
int		key_release(int keycode, t_base *base);
void	look_right(t_base *base);
void	look_left(t_base *base);
void	move_up(t_base *base);
void	move_down(t_base *base);
void	move_right(t_base *base);
void	move_left(t_base *base);
void	move_chased_step(t_base *base, char left_or_right);
void	rotations(t_base *base, float angle);
/*
**	Initialisations and parsing
*/
t_base				*init_base(t_params *params, t_map *map, t_player *player);
// initialise.c
int					init_param(t_params *pa, int *fd);
int					init_map(t_params *pa, t_map *map, t_player *pl, int *fd);
// parse_parameters.c
int					parse_root(char *av, t_params *params, t_map *map,
						t_player *player);
int					parse_res(t_params *params, char *line);
int					parse_color(t_params *params, char *line, int *color);
int					split_parse_text_path(t_params *params, char *line);
// parse_param_utils.c
char				**check_number_param(size_t nb_par, char *line, char split);
int					ft_str_is_digitspace(char *str);
// parse_map.c
char				**reallocmap(char **map, size_t map_size, size_t new_size);
int					parse_map(t_map *map, t_player *player);
// check_parameters.c
int					check_params_integrity(t_params *params);
// check_map.c
int					map_ok_or_quit(t_map *map);
// check_map_pivoted.c
int					empty_pivoted_map(t_map *map, t_map *new);
void				pi_by_two_pivote_map(t_map *map, t_map *new);
// check_map_utils.c
int					check_char(t_map *map);
int					hole_finder(t_map *map);

/*
**	Errors
*/
void				print_error(int err_nb);
void				ft_exit(char *context);

/*
**	Clean quit
*/
void				free_params(t_params *params);
void				free_map(t_map *map);

#endif

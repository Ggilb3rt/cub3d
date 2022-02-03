/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:35 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/03 18:35:13 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <string.h>
# include "../lib/libft/libft.h"

# define ERR_MALLOCCRASH "Crash of malloc"
# define ERR_GNL "Can't read next line"
# define ERR_MAP_HOLE "Hole in the map"
# define ERR_PARAMS_RES "Resolution must have 2 values"
# define NB_PARAMS_PARSE 7
# define PI 3.14159265
# define MAX_X 1920
# define MAX_Y 1080

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
	e_map_hole
};

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

typedef struct s_player
{
	float			pos_x;
	float			pos_y;
	char			orientation;
	float			angle;
	float			pos_delta_x;
	float			pos_delta_y;
}					t_player;

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

/*
**	Initialisations and parsing
*/
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
void				parse_map(t_map *map, t_player *player);
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

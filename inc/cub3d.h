/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:35 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 18:01:21 by ggilbert         ###   ########.fr       */
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
# define NB_PARAMS_PARSE 8
# define PI 3.14159265
# define MAX_X 1920
# define MAX_Y 1080

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
	char			*path_texture_sp;
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
**	Errors
*/
void				print_error(char *context);
void				error_init(char *context);
void				ft_exit(char *context);
/*
**	Initialisations and parsing
*/
int					init_param(t_params *pa, int *fd);
int					init_map(t_params *pa, t_map *map, t_player *pl, int *fd);
void				parse_res(t_params *params, char *line);
void				parse_color(t_params *params, char *line, int *color);
void				split_parse_text_path(t_params *params, char *line);
char				**reallocmap(char **map, size_t map_size, size_t new_size);
void				parse_map(t_map *map, t_player *player);
void				check_map_integrity(t_map *map);
void				empty_pivoted_map(t_map *map, t_map *new);
void				pi_by_two_pivote_map(t_map *map, t_map *new);
void				check_params_integrity(t_params *params);
/*
**	Clean quit
*/
void				free_params(t_params *params);
void				free_map(t_map *map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:35 by ggilbert          #+#    #+#             */
/*   Updated: 2021/02/23 10:14:31 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <string.h>
# include "../lib/libft/libft.h"

typedef struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

typedef struct 		s_player
{
	float			pos_x;
	float			pos_y;
	char			orientation;
}					t_player;


typedef struct		s_params
{
	unsigned int	res_x;
	unsigned int	res_y;
	char			*path_texture_no;
	char			*path_texture_so;
	char			*path_texture_we;
	char			*path_texture_ea;
	char			*path_texture_sp;
	t_color			c_floor;
	t_color			c_ceiling;
}					t_params;

typedef struct		s_map
{
	char			**map;
	size_t			width;
	size_t			height;
}					t_map;

/*	Errors	*/
void				error_init(char *context);
/*	Initialisations and parsing	*/
int					init_param(t_params *pa, t_map *m, t_player *pl, char *f);
void				parse_res(t_params *params, char *line);
void				parse_color(t_params *params, char *line);
void				parse_text_path(t_params *params, char *line);
/*	Clean quit	*/
#endif

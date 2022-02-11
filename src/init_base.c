/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:37:20 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/11 13:05:25 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_initial_camera(t_base *base)
{
	if (base->player->orientation == 'N')
	{
		base->player->cam_v.x = 0.66;
		base->player->cam_v.y = 0;
	}
	else if (base->player->orientation == 'S')
	{
		base->player->cam_v.x = -0.66;
		base->player->cam_v.y = 0;
	}
	else if (base->player->orientation == 'E')
	{
		base->player->cam_v.x = 0;
		base->player->cam_v.y = 0.66;
	}
	else if (base->player->orientation == 'W')
	{
		base->player->cam_v.x = 0;
		base->player->cam_v.y = -0.66;
	}
}

void	get_initial_direction(t_base *base)
{
	if (base->player->orientation == 'N')
	{
		base->player->dir_v.x = 0;
		base->player->dir_v.y = -1;
	}
	else if (base->player->orientation == 'S')
	{
		base->player->dir_v.x = 0;
		base->player->dir_v.y = 1;
	}
	else if (base->player->orientation == 'E')
	{
		base->player->dir_v.x = 1;
		base->player->dir_v.y = 0;
	}
	else if (base->player->orientation == 'W')
	{
		base->player->dir_v.x = -1;
		base->player->dir_v.y = 0;
	}
	printf("starting x %f\t y %f\n\n", base->player->pos_x, base->player->pos_y);
}

void	init_vars(t_base *base)
{
	int	tmp;

	tmp = base->map->height;
	base->map->height = base->map->width;
	base->map->width = tmp;
	base->map->rotated = TRUE;
	base->player->going_up = 0;
	base->player->going_down = 0;
	base->player->going_left = 0;
	base->player->going_right = 0;
	base->player->is_moving = 0;
	base->player->rotate_left = 0;
	base->player->rotate_right = 0;
	base->can_move = TRUE;
	get_initial_direction(base);
	get_initial_camera(base);
}

t_data	*initialise_data(t_base *base, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->init = 0;
	if (i == 0)
	{
		data->img = mlx_new_image(base->mlx, (int)base->params->res_x,
				(int)base->params->res_y);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		data->init = 1;
	}
	return (data);
}

t_base	*init_base(t_params *params, t_map *map, t_player *player)
{
	t_base	*base;

	base = (struct s_base *)malloc(sizeof(t_base));
	ft_bzero(base, sizeof(t_base));
	base->player = player;
	base->params = params;
	base->map = map;
	base->north = initialise_data(base, 1);
	base->east = initialise_data(base, 1);
	base->west = initialise_data(base, 1);
	base->south = initialise_data(base, 1);
	base->img = 0;
	init_vars(base);
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, params->res_x,
			params->res_y, "cube3d");
	base->img = initialise_data(base, 0);
	init_tiles(base);
	return (base);
}

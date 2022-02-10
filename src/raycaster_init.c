/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:59:17 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 12:28:18 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_step_length(t_base *base, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->length_x = (base->player->pos_x - ray->map_x)
			* ray->delta_length_x;
	}
	else
	{
		ray->step_x = 1;
		ray->length_x = (ray->map_x + 1.0 - base->player->pos_x)
			* ray->delta_length_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->length_y = (base->player->pos_y - ray->map_y)
			* ray->delta_length_y;
	}
	else
	{
		ray->step_y = 1;
		ray->length_y = (ray->map_y + 1.0 - base->player->pos_y)
			* ray->delta_length_y;
	}
}

void	init_ray(t_base *base, t_ray *ray, float pixx)
{
	float	camera_x;

	camera_x = 2 * pixx / (float)base->params->res_x - 1;
	ray->ray_dir_x = base->player->dir_v.x + base->player->cam_v.x * camera_x;
	ray->ray_dir_y = base->player->dir_v.y + base->player->cam_v.y * camera_x;
	ray->map_x = (int)base->player->pos_x;
	ray->map_y = (int)base->player->pos_y;
	if (ray->ray_dir_x != 0)
		ray->delta_length_x = fabs(1 / ray->ray_dir_x);
	else
		ray->delta_length_x = 1e30;
	if (ray->ray_dir_y != 0)
		ray->delta_length_y = fabs(1 / ray->ray_dir_y);
	else
		ray->delta_length_y = 1e30;
	init_ray_step_length(base, ray);
}

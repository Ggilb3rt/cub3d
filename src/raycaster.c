/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:24:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/07 19:24:49 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	to_wall(t_base *base)
{
	t_ray	ray;
	int		hit;

	// get ray pos and dir
	float	cameraX = 0;
	float	ray_dir_x = base->player->dir_v.x + base->player->cam_v.x * cameraX;
	float	ray_dir_y = base->player->dir_v.y + base->player->cam_v.y * cameraX;
	
	// init ray
	ray.map_x = (int)base->player->pos_x;
	ray.map_y = (int)base->player->pos_y;
	if (ray_dir_x != 0)
		ray.delta_length_x = fabs(1 / ray_dir_x);
		//ray.delta_length_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
	else
		ray.delta_length_x = 1e30;
	if (ray_dir_y != 0)
		ray.delta_length_y = fabs(1 / ray_dir_y);
		//ray.delta_length_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
	else
		ray.delta_length_y = 1e30;
	printf("raydeltaDir x %f, y %f\n", ray.delta_length_x, ray.delta_length_y);
	
	// init step and initial ray.length
	if (ray_dir_x < 0)
	{
		ray.step_x = -1;
		ray.length_x = (base->player->pos_x - ray.map_x) * ray.delta_length_x;
	}
	else
	{
		ray.step_x = 1;
		ray.length_x = (ray.map_x + 1.0 - base->player->pos_x) * ray.delta_length_x;
	}
	if (ray_dir_y < 0)
	{
		ray.step_y = -1;
		ray.length_y = (base->player->pos_y - ray.map_y) * ray.delta_length_y;
	}
	else
	{
		ray.step_y = 1;
		ray.length_y = (ray.map_y + 1.0 - base->player->pos_y) * ray.delta_length_y;
	}
	
	// DDA
	hit = 0;
	while (hit == 0)
	{
		printf("colision point x %f, y %f\n", ray.length_x, ray.length_y);
		if (ray.length_x < ray.length_y)
		{
			ray.length_x += ray.delta_length_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.length_y += ray.delta_length_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (base->map->map[ray.map_x][ray.map_y] == '1')
			hit = 1;
	}
	printf("hit wall at %d, %d\n", ray.map_x, ray.map_y);
	draw_line(base,
		base->player->pos_x * 64, base->player->pos_y * 64,
		ray.map_x * 64,
		ray.map_y * 64,
		0x0000FF);
}

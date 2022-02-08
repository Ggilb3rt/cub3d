/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:24:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/08 12:38:26 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster(t_base *base)
{
	t_ray	ray;
	int		hit;

	for (int pixx = 0; pixx < (int)base->params->res_x; pixx++)
	{
	// get ray pos and dir
	//float	cameraX = base->player->pos_x + base->player->dir_v.x;
	float	cameraX = 2 * pixx / (float)base->params->res_x - 1;
	float	ray_dir_x = base->player->dir_v.x + base->player->cam_v.x * cameraX;
	float	ray_dir_y = base->player->dir_v.y + base->player->cam_v.y * cameraX;
	// float	ray_dir_x = 1 + 0 * cameraX;
	// float	ray_dir_y = 0 + 0.66 * cameraX;
	
	// init ray
	ray.map_x = (int)base->player->pos_x;
	ray.map_y = (int)base->player->pos_y;
	if (ray_dir_x != 0)
		ray.delta_length_x = fabs(1 / ray_dir_x);
	else
		ray.delta_length_x = 1e30;
	if (ray_dir_y != 0)
		ray.delta_length_y = fabs(1 / ray_dir_y);
	else
		ray.delta_length_y = 1e30;
	//printf("raydeltaDir x %f, y %f\n", ray.delta_length_x, ray.delta_length_y);
	
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
		//printf("ray length x %f, y %f\n", ray.length_x, ray.length_y);
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
		if (base->map->map[ray.map_y][ray.map_x] == '1')
			hit = 1;
	}
	
	// wallDist
	if (ray.side == 0)
		ray.perp_wall_dist = ray.length_x - ray.delta_length_x;
	else
		ray.perp_wall_dist = ray.length_y - ray.delta_length_y;
	int	line_height = (int)((int)base->params->res_y / ray.perp_wall_dist);
	int	draw_start = (int)base->params->res_y / 2 - line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = (int)base->params->res_y / 2 + line_height / 2;
	if (draw_end >= (int)base->params->res_y)
		draw_end = (int)base->params->res_y - 1;
	//printf("hit wall at %d, %d\n\n\n", ray.map_x, ray.map_y);
	if (ray.side == 0)
		draw_line(base, pixx, draw_start, pixx, draw_end, 0x9830d9);
	else
		draw_line(base, pixx, draw_start, pixx, draw_end, 0xFF0000);
	// draw_line(base,
	// 	base->player->pos_x * 64, base->player->pos_y * 64,
	// 	ray.map_x * 64,
	// 	ray.map_y * 64,
	// 	0x0000FF);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:24:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/09 19:41:22 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster(t_base *base)
{
	t_ray	ray;
	int		hit;
	// int		pixx;
printf("\npouet\n");

	// pixx = 0;
	// while (pixx < (int)base->params->res_x)
	for (int pixx = 0; pixx < (int)base->params->res_x; pixx++)
	{
		// get ray pos and dir
		//float	cameraX = base->player->pos_x + base->player->dir_v.x;
		float	cameraX = 2 * pixx / (float)base->params->res_x - 1;
		float	ray_dir_x = base->player->dir_v.x + base->player->cam_v.x * cameraX;
		float	ray_dir_y = base->player->dir_v.y + base->player->cam_v.y * cameraX;
		// float	ray_dir_x = 1 + 0 * cameraX;
		// float	ray_dir_y = 0 + 0.66 * cameraX;	
printf("[%f][%f]\n", ray_dir_x, ray_dir_y);
if (ray_dir_y == 0)
	ray_dir_y += 0.000001;
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
	
printf("2[%f][%f]\n", ray_dir_x, ray_dir_y);
		// DDA
		hit = 0;
		while (hit == 0)
		{
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
				ray.side = 1 ;
			}
			if (base->map->map[ray.map_y][ray.map_x] == '1')
			{
				hit = 1;
				// get_wall_orientation
				if (ray.side == 0)
				{
					if (base->player->pos_x > ray.map_x)
						ray.wall_side = 'E';
					else
						ray.wall_side = 'W';
				}
				else
				{
					if (base->player->pos_y > ray.map_y)
						ray.wall_side = 'S';
					else
						ray.wall_side = 'N';
				}
			}
		}
// printf("pouet3 %d\n", pixx);
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
			draw_end = (int)base->params->res_y;
			
		// textures 1: get X
		t_data	*tex;
		double	wallX;
		int		texX;
		
		if (ray.wall_side == 'N')
			tex = base->north;
		if (ray.wall_side == 'S')
			tex = base->south;
		if (ray.wall_side == 'E')
			tex = base->east;
		if (ray.wall_side == 'W')
			tex = base->west;
		if (ray.side == 0)
		{
			wallX = base->player->pos_y + ray.perp_wall_dist * ray_dir_y;
		}
		else
			wallX = base->player->pos_x + ray.perp_wall_dist * ray_dir_x;
		wallX -= floor(wallX);
		wallX = fabs(wallX - 1);
		texX = wallX * (double)TEX_SIZE;
		if (ray.side == 0 && ray_dir_x > 0)
			texX = TEX_SIZE - texX - 1;
		if (ray.side == 1 && ray_dir_y <= 0)
			texX = TEX_SIZE - texX - 1;
// printf("pouet4 %d\n", pixx);
		// textures 2: get Y
		double	step = 1.0 * TEX_SIZE / line_height;
		double	texPos = (draw_start - base->params->res_y / 2 + line_height / 2) * step;
		int		y = draw_start;
		int		texY;
		unsigned int	color;
// printf("pouet5 %d\n", pixx);
		while (y < draw_end)
		{
			texY = (int)texPos & (TEX_SIZE -1);
			texPos += step;
			color = get_pixel(tex, texX, texY);
			// printf("lol %d, %d\n", pixx, y);
			my_mlx_pixel_put(base->img, pixx, y, color);
			// printf("lol2 %d %d\n", pixx, y);
			y++;
		}
	printf("pouet fin\n");
	}
}

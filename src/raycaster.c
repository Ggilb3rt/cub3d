/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:24:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 13:58:43 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_height_screen(int res_y, t_ray *ray, t_ray_screen *line)
{
	line->line_height = res_y / ray->perp_wall_dist;
	line->draw_start = res_y / 2 - line->line_height / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = res_y / 2 + line->line_height / 2;
	if (line->draw_end >= res_y)
		line->draw_end = res_y;
}

void	set_wall_x_hit(t_player *player, t_ray *ray, t_ray_screen *line)
{
	if (ray->side == 0)
		line->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		line->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	line->wall_x -= floor(line->wall_x);
	if (line->wall_x != 0)
		line->wall_x = fabs(line->wall_x - 1);
}

void	draw_wall_line(t_base *base, t_ray *ray, t_ray_screen *line, int pixx)
{
	while (line->draw_start < line->draw_end)
	{
		line->tex_y = (int)line->tex_pos & (TEX_SIZE - 1);
		line->tex_pos += line->step;
		line->color = get_pixel(find_texture_side(base, ray),
				line->tex_x, line->tex_y);
		my_mlx_pixel_put(base->img, pixx, line->draw_start, line->color);
		line->draw_start++;
	}
}

void	raycaster(t_base *base)
{
	t_ray			ray;
	t_ray_screen	line;
	int				pixx;

	pixx = 0;
	ft_bzero(&ray, sizeof(t_ray));
	ft_bzero(&line, sizeof(t_ray_screen));
	while (pixx < (int)base->params->res_x)
	{
		init_ray(base, &ray, pixx);
		find_closest_wall(base, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = ray.length_x - ray.delta_length_x;
		else
			ray.perp_wall_dist = ray.length_y - ray.delta_length_y;
		set_wall_height_screen((int)base->params->res_y, &ray, &line);
		set_wall_x_hit(base->player, &ray, &line);
		set_texture_pos(&ray, &line, base->params->res_y);
		draw_wall_line(base, &ray, &line, pixx);
		pixx++;
	}
}

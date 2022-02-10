/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:57:56 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 13:58:52 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*find_texture_side(t_base *base, t_ray *ray)
{
	if (ray->wall_side == 'N')
		return (base->north);
	if (ray->wall_side == 'S')
		return (base->south);
	if (ray->wall_side == 'E')
		return (base->east);
	if (ray->wall_side == 'W')
		return (base->west);
	return (base->west);
}

void	set_texture_pos(t_ray *ray, t_ray_screen *line, int res_y)
{
	line->tex_x = line->wall_x * (float)TEX_SIZE;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		line->tex_x = TEX_SIZE - line->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		line->tex_x = TEX_SIZE - line->tex_x - 1;
	line->step = 1.0 * TEX_SIZE / line->line_height;
	line->tex_pos = (line->draw_start - res_y / 2 + line->line_height / 2)
		* line->step;
}

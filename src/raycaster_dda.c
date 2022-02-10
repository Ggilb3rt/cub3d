/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_dda.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:05:00 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 12:05:17 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_wall_orientation(t_base *base, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (base->player->pos_x > ray->map_x)
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (base->player->pos_y > ray->map_y)
			return ('S');
		else
			return ('N');
	}
}

void	find_closest_wall(t_base *base, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->length_x < ray->length_y)
		{
			ray->length_x += ray->delta_length_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->length_y += ray->delta_length_y;
			ray->map_y += ray->step_y;
			ray->side = 1 ;
		}
		if (base->map->map[ray->map_y][ray->map_x] == '1')
		{
			ray->wall_side = get_wall_orientation(base, ray);
			hit = 1;
		}
	}
}

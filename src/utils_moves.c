/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:36:53 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/10 11:36:55 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_wall(t_base *base, float x, float y)
{
	int	rx;
	int	ry;

	rx = x;
	ry = y;
	if (x - rx < MOVE_SPEED && base->map->map[ry][rx - 1] == '1')
		return (FALSE);
	if (x - rx >= 1 - MOVE_SPEED && base->map->map[ry][rx + 1] == '1')
		return (FALSE);
	if (y - ry < MOVE_SPEED && base->map->map[ry - 1][rx] == '1')
		return (FALSE);
	if (y - ry >= 1 - MOVE_SPEED && base->map->map[ry + 1][rx] == '1')
		return (FALSE);
	return (TRUE);
}

void	stay_in_two_pi(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	else if (*angle > 2 * PI)
		*angle -= 2 * PI;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:35:56 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/10 11:35:59 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	look_left(t_base *base)
{
	base->player->angle -= MOVE_SPEED;
	stay_in_two_pi(&base->player->angle);
	rotations(base, -MOVE_SPEED);
}

void	look_right(t_base *base)
{
	base->player->angle += MOVE_SPEED;
	stay_in_two_pi(&base->player->angle);
	rotations(base, MOVE_SPEED);
}

void	move_down(t_base *base)
{
	float	x;
	float	y;

	x = base->player->pos_x - base->player->dir_v.x * MOVE_SPEED;
	y = base->player->pos_y - base->player->dir_v.y * MOVE_SPEED;
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x = x;
		base->player->pos_y = y;
	}
	else
		base->can_move = FALSE;
}

void	move_up(t_base *base)
{
	float	x;
	float	y;

	x = base->player->pos_x + base->player->dir_v.x * MOVE_SPEED;
	y = base->player->pos_y + base->player->dir_v.y * MOVE_SPEED;
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x = x;
		base->player->pos_y = y;
	}
	else
		base->can_move = FALSE;
}

void	move_chased_step(t_base *base, char lr)
{
	t_vector	vec;
	float		x;
	float		y;

	if (lr == 'r')
		vec = rot_quarter(base->player->dir_v);
	else
		vec = rot_rev(base->player->dir_v);
	x = base->player->pos_x + vec.x * MOVE_SPEED;
	y = base->player->pos_y + vec.y * MOVE_SPEED;
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x = x;
		base->player->pos_y = y;
	}
	else
		base->can_move = FALSE;
}

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

void	look_left(t_base *base)
{
	base->player->angle -= MOVE_SPEED;
	stay_in_two_pi(&base->player->angle);
	//base->player->pos_delta_x = cos(base->player->angle) / 16;
	//base->player->pos_delta_y = sin(base->player->angle) / 16;
	rotations(base, -MOVE_SPEED);
}

void	look_right(t_base *base)
{
	base->player->angle += MOVE_SPEED;
	stay_in_two_pi(&base->player->angle);
	//base->player->pos_delta_x = cos(base->player->angle) / 16;
	//base->player->pos_delta_y = sin(base->player->angle) / 16;
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







// void	move_up(t_base *base)
// {
// 	float	x;
// 	float	y;

// 	x = base->player->pos_x + base->player->pos_delta_x;
// 	y = base->player->pos_y + base->player->pos_delta_y;
// 	if (check_wall(base, x, y) == TRUE)
// 	{
// 		base->player->pos_x = x;
// 		base->player->pos_y = y;
// 	}
// }

// void	move_down(t_base *base)
// {
// 	float	x;
// 	float	y;

// 	x = base->player->pos_x - base->player->pos_delta_x;
// 	y = base->player->pos_y - base->player->pos_delta_y;
// 	if (check_wall(base, x, y) == TRUE)
// 	{
// 		base->player->pos_x = x;
// 		base->player->pos_y = y;
// 	}
// }

// void	move_chased_step(t_base *base, char left_or_right)
// {
// 	float	dx;
// 	float	dy;
// 	float	new_angle;

// 	if (left_or_right == 'r')
// 		new_angle = base->player->angle + M_PI_2;
// 	else if (left_or_right == 'l')
// 		new_angle = base->player->angle - M_PI_2;
// 	else
// 		new_angle = 0;
// 	stay_in_two_pi(&new_angle);
// 	dx = cos(new_angle) / 16;
// 	dy = sin(new_angle) / 16;
// 	if (check_wall(base, base->player->pos_x + dx,
// 			base->player->pos_y + dy) == TRUE)
// 	{
// 		base->player->pos_x += dx;
// 		base->player->pos_y += dy;
// 		base->player->dir_v.x += dx;
// 		base->player->dir_v.y += dy;
// 	}
// }

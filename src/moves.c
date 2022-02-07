#include "../inc/cub3d.h"

int	check_wall(t_base *base, float x, float y)
{
	int	rx;
	int	ry;

	rx = x;
	ry = y;
	if (x - rx < 0.125 && base->map->map[ry][rx - 1] == '1')
		return (FALSE);
	if (x - rx >= 0.875 && base->map->map[ry][rx + 1] == '1')
		return (FALSE);
	if (y - ry < 0.125 && base->map->map[ry - 1][rx] == '1')
		return (FALSE);
	if (y - ry >= 0.875 && base->map->map[ry + 1][rx] == '1')
		return (FALSE);
	return (TRUE);
}

void	look_left(t_base *base)
{
	base->player->angle -= 0.125;
	if (base->player->angle < 0)
		base->player->angle += 2 * PI;
	base->player->pos_delta_x = cos(base->player->angle) / 16;
	base->player->pos_delta_y = sin(base->player->angle) / 16;
}

void	look_right(t_base *base)
{
	base->player->angle += 0.125;
	if (base->player->angle > 2 * PI)
		base->player->angle -= 2 * PI;
	base->player->pos_delta_x = cos(base->player->angle) / 8;
	base->player->pos_delta_y = sin(base->player->angle) / 8;
}

void	move_up(t_base *base)
{
	float	x;
	float	y;

	x = base->player->pos_x + base->player->pos_delta_x;
	y = base->player->pos_y + base->player->pos_delta_y;
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x += base->player->pos_delta_x;
		base->player->pos_y += base->player->pos_delta_y;
	}
}

void	move_down(t_base *base)
{
	float	x;
	float	y;

	x = base->player->pos_x - base->player->pos_delta_x;
	y = base->player->pos_y - base->player->pos_delta_y;
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x -= base->player->pos_delta_x;
		base->player->pos_y -= base->player->pos_delta_y;
	}
}

void	move_right(t_base *base)
{
	float	x;
	float	y;

	x = base->player->pos_x + (cos(base->player->angle + PI / 2) / 16);
	y = base->player->pos_y + (sin(base->player->angle + PI / 2) / 16);
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x += cos(base->player->angle + PI / 2) / 16;
		base->player->pos_y += sin(base->player->angle + PI / 2) / 16;
	}
}

void	move_left(t_base *base)
{
	float	x;
	float	y;

	x = base->player->pos_x + (cos(base->player->angle - PI / 2) / 16);
	y = base->player->pos_y + (sin(base->player->angle - PI / 2) / 16);
	if (check_wall(base, x, y) == TRUE)
	{
		base->player->pos_x += cos(base->player->angle - (PI / 2)) / 16;
		base->player->pos_y += sin(base->player->angle - (PI / 2)) / 16;
	}
}

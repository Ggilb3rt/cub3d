#include "cub3d.h"

t_vector	rot_quarter(t_vector dir)
{
	t_vector	vec;
	float		temp;

	vec = dir;
	temp = vec.x;
	vec.x = vec.y * -1;
	vec.y = temp;
	return (vec);
}

t_vector	rot_rev(t_vector dir)
{
	t_vector	vec;
	float		temp;

	vec = dir;
	temp = vec.y;
	vec.y = vec.x * -1;
	vec.x = temp;
	return (vec);
}

void	rotations(t_base *base, float angle)
{
	t_vector	vec;
	float		x;
	float		y;

	vec = base->player->dir_v;
	x = vec.x * cos(angle) - vec.y * sin(angle);
	y = vec.x * sin(angle) + vec.y * cos(angle);
	//printf("\n--------------\n");
	//	printf("playX %f\t playY %f\n", base->player->pos_x, base->player->pos_y);
	//printf("dirX %f\t dirY%f\n\n", base->player->dir_v.x, base->player->dir_v.y);

	base->player->dir_v.x = x;
	base->player->dir_v.y = y;
	vec = base->player->cam_v;
	x = vec.x * cos(angle) - vec.y * sin(angle);
	y = vec.x * sin(angle) + vec.y * cos(angle);
	base->player->cam_v.x = x;
	base->player->cam_v.y = y;
}

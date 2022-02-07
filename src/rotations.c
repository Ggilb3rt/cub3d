#include "cub3d.h"

void	rotations(t_base *base, float angle)
{
	t_vector	vec;
	float		x;
	float		y;
	
	vec = base->player->dir_v;
	x = vec.x * cos(angle) - vec.y * sin(angle);
	y = vec.x * sin(angle) + vec.y * cos(angle);
	printf("\n--------------\n");
		printf("playX %f\t playY %f\n", base->player->pos_x, base->player->pos_y);
	printf("dirX %f\t dirY%f\n\n", base->player->dir_v.x, base->player->dir_v.y);

	base->player->dir_v.x = x; 
	base->player->dir_v.y = y; 
}
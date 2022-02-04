#include "../inc/cub3d.h"

void	look_right(t_base *base)
{
	base->player->angle += 0.125;
	if (base->player->angle < 0)
		base->player->angle += 2 * PI;
	base->player->pos_delta_x = cos(base->player->angle) / 8;
	base->player->pos_delta_y = sin(base->player->angle) / 8;
}

void	look_left(t_base *base)
{
	base->player->angle -= 0.125;
	if (base->player->angle > 2 * PI)
		base->player->angle -= 2 * PI;
	base->player->pos_delta_x = cos(base->player->angle) / 8;
	base->player->pos_delta_y = sin(base->player->angle) / 8;
}

void	move_up(t_base *base)
{
	// int  	x;
	// int  	y;
	
	// x = base->player->pos_x;
	// y = base->player->pos_y;
	// if (/* CHECK COLLISION */)
	// {
	// 	printf("jesuisla\n");
	// 	if (base->map->map[y - 1][x] == '0')
	// 	{
	// 		base->player->pos_x -= base->player->pos_delta_x;
	// 		base->player->pos_y -= base->player->pos_delta_y;
	// 	}
	// }
	// else
	{
		base->player->pos_x -= base->player->pos_delta_x;
		base->player->pos_y -= base->player->pos_delta_y;
	}
}

void	move_down(t_base *base)
{
	// int  	x;
	// int  	y;
	
	// x = base->player->pos_x;
	// y = base->player->pos_y;
	// if (/* CHECK COLLISION */)
	// {
	// 	printf("jesuisla\n");
	// 	if (base->map->map[y - 1][x] == '0')
	// 	{	
	// 		base->player->pos_x -= base->player->pos_delta_x;
	// 		base->player->pos_y -= base->player->pos_delta_y;
	// 	}
	// }
	// else
	{
		base->player->pos_x += base->player->pos_delta_x;
		base->player->pos_y += base->player->pos_delta_y;
	}
}

void	move_left(t_base *base)
{
	// 	int  	x;
	// int  	y;
	
	// x = base->player->pos_x;
	// y = base->player->pos_y;
	// if (/* CHECK COLLISION */)
	// {
	// 	printf("jesuisla\n");
	// 	if (base->map->map[y - 1][x] == '0')
	// 	{	
	// 		base->player->pos_x -= base->player->pos_delta_x;
	// 		base->player->pos_y -= base->player->pos_delta_y;
	// 	}
	// }
	// else
	{
		base->player->pos_x += base->player->pos_delta_x - (PI / 2) / 8;
		base->player->pos_y += base->player->pos_delta_y - (PI / 2) / 8;
	}
}

void	move_right(t_base *base)
{
	// int  	x;
	// int  	y;
	
	// x = base->player->pos_x;
	// y = base->player->pos_y;
	// if (/* CHECK COLLISION */)
	// {
	// 	printf("jesuisla\n");
	// 	if (base->map->map[y - 1][x] == '0')
	// 	{	
	// 		base->player->pos_x -= base->player->pos_delta_x;
	// 		base->player->pos_y -= base->player->pos_delta_y;
	// 	}
	// }
	// else
	{
		base->player->pos_x += (base->player->pos_delta_x * 8 + PI / 2) / 8;
		base->player->pos_y += (base->player->pos_delta_y * 8 + PI / 2) / 8;
	}
}
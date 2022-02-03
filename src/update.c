#include "../inc/cub3d.h"

void	move_player(t_base *base)
{
	if (base->player->going_up == 1)
		move_up(base);
	else if (base->player->going_down == 1)
		move_down(base);
	else if (base->player->going_right == 1)
		move_right(base);
	else if (base->player->going_left == 1)
		move_left(base);
}

void	update(t_base *base)
{
	move_player(base);
	base->player->is_moving = 0;
	put_img(base);
}

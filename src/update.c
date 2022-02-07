#include "../inc/cub3d.h"

void	move_player(t_base *base)
{
	if (base->player->going_up == 1)
		move_up(base);
	else if (base->player->going_down == 1)
		move_down(base);
	else if (base->player->going_right == 1)
		move_chased_step(base, 'r');
	else if (base->player->going_left == 1)
		move_chased_step(base, 'l');
	else if (base->player->rotate_left == 1)
		look_left(base);
	else if (base->player->rotate_right == 1)
		look_right(base);
}

void	update(t_base *base)
{
	move_player(base);
	base->player->is_moving = 0;
	put_img(base);
}

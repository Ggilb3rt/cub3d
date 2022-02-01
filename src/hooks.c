#include "../inc/cub3d.h"

int	close_win(t_base *base)
{
	(void)base;
	//destroy_base(base, "finished");
	return (0);
}

int	key_press(int keycode, t_base *base)
{
	if (keycode == 65307 || keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
	{
		if (keycode == 65307)
			close_win(base);
		if (keycode == 119)
			base->player->going_up = 1;
		if (keycode == 115)
			base->player->going_down = 1;
		if (keycode == 97)
			base->player->going_left = 1;
		if (keycode == 100)
			base->player->going_right = 1;
		//update(base);
	}
	return (0);
}

int	key_release(int keycode, t_base *base)
{
	if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
	{
		if (keycode == 119)
			base->player->going_up = 0;
		else if (keycode == 115)
			base->player->going_down = 0;
		else if (keycode == 97)
			base->player->going_left = 0;
		else
			base->player->going_right = 0;
	}
	return (0);
}

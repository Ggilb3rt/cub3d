#include "../inc/cub3d.h"

void	move_up(t_base *base)
{
	int	x;
	int	y;

	x = base->player->pos_x;
	y = base->player->pos_y;
	if (base->map->map[x][y - 1] == '0')
	{
		base->player->pos_y -= 1;
	}
}

void	move_down(t_base *base)
{
	int	x;
	int	y;

	x = base->player->pos_x;
	y = base->player->pos_y;
	if (base->map->map[x][y + 1] == '0')
		base->player->pos_y += 1;
}

void	move_left(t_base *base)
{
	int	x;
	int	y;

	x = base->player->pos_x;
	y = base->player->pos_y;
	if (base->map->map[x - 1][y] == '0')
		base->player->pos_x -= 1;
}

void	move_right(t_base *base)
{
	int	x;
	int	y;

	x = base->player->pos_x;
	y = base->player->pos_y;
	if (base->map->map[x + 1][y] == '0')
		base->player->pos_x += 1;
}
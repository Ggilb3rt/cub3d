#include "../inc/cub3d.h"

void	init_vars(t_base *base)
{
	base->player->going_up = 0;
	base->player->going_down = 0;
	base->player->going_left = 0;
	base->player->going_right = 0;
	base->player->is_moving = 0;
}

t_data	*initialise_data(t_base *base, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->init = 0;
	if (i == 0)
	{
		data->img = mlx_new_image(base->mlx, base->map->width * 64,
				base->map->height * 64);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		data->init = 1;
	}
	return (data);
}

t_base	*init_base(t_params *params, t_map *map, t_player *player)
{
	t_base	*base;

	base = (struct s_base *)malloc(sizeof(t_base));
	base->player = player;
	base->params = params;
	base->mlx = 0;
	base->win = 0;
	base->map = map;
	base->north = initialise_data(base, 1);
	base->east = initialise_data(base, 1);
	base->west = initialise_data(base, 1);
	base->south = initialise_data(base, 1);
	base->minime = initialise_data(base, 1);
	base->img = 0;
	init_vars(base);
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, params->res_x, params->res_x, "cube3d");
	base->img = initialise_data(base, 0);
	init_tiles(base);
	return (base);
}
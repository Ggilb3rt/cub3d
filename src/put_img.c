#include "../inc/cub3d.h"

unsigned int	get_pixel(t_data *tile, int x, int y)
{
	return (*(unsigned int *)(tile->addr + (y
			* tile->line_length + x * (tile->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_tiles(t_base *base, char *path, t_data *tile)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(base->mlx, path, &width, &height);
	tile->img = img;
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
			&tile->line_length, &tile->endian);
	// if (tile->img == 0)
	// 	destroy_base(base, "mlx failed");
	{
		tile->width = width;
		tile->height = height;
		tile->init = 1;
	}
}

void	init_tiles(t_base *base)
{
	put_tiles(base, base->params->path_texture_no, base->north);
	put_tiles(base, base->params->path_texture_so, base->south);
	put_tiles(base, base->params->path_texture_ea, base->east);
	put_tiles(base, base->params->path_texture_we, base->west);
	put_tiles(base, "./assets/textures/antouine.xpm", base->minime);
}

void	draw_tile(t_base *base, t_point start, t_data *tile)
{
	int				x;
	int				y;
	unsigned int	color;

	x = -1;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			color = get_pixel(tile, x, y);
			if (color != 0x000000)
				my_mlx_pixel_put(base->img, (start.x) + x,
					(start.y) + y, color);
		}
	}
}

void	put_map(t_base *base)
{
	unsigned int	i;
	unsigned int	j;
	t_point			start;

	j = -1;
	while (++j < base->map->height && base->map->map[j])
	{
		i = -1;
		while (++i < base->map->width && base->map->map[j][i])
		{
			start.y = j * 64;
			start.x = i * 64;
			printf("\n\n--- j[%d]i[%d] == |%c| ---\n\n", j, i, base->map->map[j][i]);
			if (base->map->map[j][i] == '1')
				draw_tile(base, start, base->north);
			else if (j == base->player->pos_x && i == base->player->pos_y == j)
			{
				draw_tile(base, start, base->north);
				draw_tile(base, start, base->minime);
			}
		}
	}
}

void	put_img(t_base *base)
{
	put_map(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img->img, 0, 0);
}
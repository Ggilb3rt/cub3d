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

int	trgb_to_hex(int t, int r, int g, int b)
{
	int	trgb[4];
	int	i;

	trgb[0] = t;
	trgb[1] = r;
	trgb[2] = g;
	trgb[3] = b;
	i = 0;
	while (i < 4)
	{
		if (trgb[i] < 0)
			trgb[i] = 0;
		if (trgb[i] > 255)
			trgb[i] = 255;
		i++;
	}
	return (trgb[0] << 24 | trgb[1] << 16 | trgb[2] << 8 | trgb[3]);
}

int	put_tiles(t_base *base, char *path, t_data *tile)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(base->mlx, path, &width, &height);
	if (img == NULL)
		return (0);
	tile->img = img;
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
			&tile->line_length, &tile->endian);
	{
		tile->width = width;
		tile->height = height;
		tile->init = 1;
	}
	return (1);
}

int	init_tiles(t_base *base)
{
	if (!put_tiles(base, base->params->path_texture_no, base->north))
		return (0);
	if (!put_tiles(base, base->params->path_texture_so, base->south))
		return (0);
	if (!put_tiles(base, base->params->path_texture_ea, base->east))
		return (0);
	if (!put_tiles(base, base->params->path_texture_we, base->west))
		return (0);
	// if (!put_tiles(base, "./assets/textures/antouine.xpm", base->minime))
	// 	return (0);
	return (1);
}

int	draw_line(t_base *base, int startX, int startY, int endX, int endY, int color)
{
	// raydir[0]
	// float x = base->player->dir_v.x - base->player->cam_v.x;
	// float y = base->player->dir_v.y - base->player->cam_v.y;
	// //raydir[799]
	// float x = base->player->dir_v.x + base->player->cam_v.x;
	// float y = base->player->dir_v.y + base->player->cam_v.y;
	double dX = endX - startX;
	double dY = endY - startY;
	int pixels = sqrt((dX * dX) + (dY * dY));

	dX /= pixels;
	dY /= pixels;

	double pixelX = startX;
	double pixelY = startY;
	while (pixels)
	{
		my_mlx_pixel_put(base->img, pixelX, pixelY, color);
		pixelX += dX;
		pixelY += dY;
		pixels--;
	}
	return (1);
}

void put_ceiling(t_base *base)
{
	unsigned int	y;

	y = 0;
	while (y < base->params->res_y / 2)
	{
		draw_line(base, 0, y, base->params->res_x, y,
			trgb_to_hex(0,
				base->params->ceiling_color[0],
				base->params->ceiling_color[1],
				base->params->ceiling_color[2]));
		y++;
	}
}


void put_floor(t_base *base)
{
	unsigned int	y;

	y = base->params->res_y / 2;
	while (y < base->params->res_y)
	{
		draw_line(base, 0, y, base->params->res_x, y,
			trgb_to_hex(0,
				base->params->floor_color[0],
				base->params->floor_color[1],
				base->params->floor_color[2]));
		y++;
	}
}

void	put_img(t_base *base)
{
	//printf("playX %f\t playY %f\n", base->player->pos_x, base->player->pos_y);
	//printf("dirX %f\t dirY%f\n\n", base->player->dir_v.x, base->player->dir_v.y);
	//put_map(base);
	put_ceiling(base);
	put_floor(base);
	raycaster(base);
	dprintf(2, "sortie ray\n");
	mlx_put_image_to_window(base->mlx, base->win, base->img->img, 0, 0);
}

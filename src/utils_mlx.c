/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:36:15 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/10 11:36:17 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (tile->img == 0)
		destroy_base(base, "mlx failed");
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
}

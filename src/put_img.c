/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:41:12 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/10 11:41:14 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	draw_line(t_base *base, t_point start, t_point end, int color)
{
	t_vector	d;
	t_vector	pixel;
	int			pixels;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	pixels = sqrt((d.x * d.x) + (d.y * d.y));
	d.x /= pixels;
	d.y /= pixels;
	pixel.x = start.x;
	pixel.y = start.y;
	while (pixels)
	{
		my_mlx_pixel_put(base->img, pixel.x, pixel.y, color);
		pixel.x += d.x;
		pixel.y += d.y;
		pixels--;
	}
	return (1);
}

void	put_ceiling(t_base *base)
{
	t_point	start;
	t_point	end;

	start.y = 0;
	start.x = 0;
	end.x = base->params->res_x;
	while ((unsigned int)start.y < base->params->res_y / 2)
	{
		end.y = start.y;
		draw_line(base, start, end,
			trgb_to_hex(0,
				base->params->ceiling_color[0],
				base->params->ceiling_color[1],
				base->params->ceiling_color[2]));
		start.y++;
	}
}

void	put_floor(t_base *base)
{
	t_point	start;
	t_point	end;

	start.y = base->params->res_y / 2;
	start.x = 0;
	end.x = base->params->res_x;
	while ((unsigned int)start.y < base->params->res_y)
	{
		end.y = start.y;
		draw_line(base, start, end,
			trgb_to_hex(0,
				base->params->floor_color[0],
				base->params->floor_color[1],
				base->params->floor_color[2]));
		start.y++;
	}
}

void	put_img(t_base *base)
{
	put_ceiling(base);
	put_floor(base);
	raycaster(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img->img, 0, 0);
}

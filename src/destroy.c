/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:36:25 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/10 11:36:26 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
}

void	destroy_image(void *mlx, t_data *data, char *err)
{
	(void)err;
	if (data->init == 1)
		mlx_destroy_image(mlx, data->img);
	free(data);
}

void	destroy_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

void	destroy_base(t_base *base, char *err)
{
	if (base != 0)
	{
		if (base->north != 0)
			destroy_image(base->mlx, base->north, err);
		if (base->south != 0)
			destroy_image(base->mlx, base->south, err);
		if (base->east != 0)
			destroy_image(base->mlx, base->east, err);
		if (base->west != 0)
			destroy_image(base->mlx, base->west, err);
		if (base->img != 0)
			destroy_image(base->mlx, base->img, err);
		if (base->win != 0)
			mlx_destroy_window(base->mlx, base->win);
		if (base->mlx != 0)
			destroy_mlx(base->mlx);
		free(base);
	}
	if (ft_strncmp(err, "finished", 8))
		error(err);
	exit(0);
}

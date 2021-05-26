/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:39:55 by ggilbert          #+#    #+#             */
/*   Updated: 2021/05/26 11:43:01 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_color(int color[3])
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (!(color[i] >= 0 && color[i] <= 255))
			return (0);
		i++;
	}
	return (1);
}

void	check_params_integrity(t_params *params)
{
	// CHECK RESOLUTION
	if (params->res_x > MAX_X)
		params->res_x = MAX_X;
	if (params->res_y > MAX_Y)
		params->res_y = MAX_Y;
	// check COLOR
	if (!valid_color(params->ceiling_color))
		ft_exit("Invalid ceiling color value");
	if (!valid_color(params->floor_color))
		ft_exit("Invalid floor color value");
	// check PATHS
}
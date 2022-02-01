/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:39:55 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 16:07:24 by ggilbert         ###   ########.fr       */
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

int	valid_path(char *path)
{
	int		i;

	i = 0;
	while (path[i] != '\0')
	{
		if (!ft_isprint(path[i]) || path[i] == ' ')
			return (0);
		i++;
	}
	if (!ft_check_file_extention(path, ".xpm"))
		return (0);
	return (1);
}

void	check_params_integrity(t_params *params)
{
	if (params->res_x > MAX_X)
		params->res_x = MAX_X;
	if (params->res_y > MAX_Y)
		params->res_y = MAX_Y;
	if (!valid_color(params->ceiling_color))
		ft_exit("Invalid ceiling color value");
	if (!valid_color(params->floor_color))
		ft_exit("Invalid floor color value");
	if (!valid_path(params->path_texture_ea))
		ft_exit("Invalid east texture path");
	if (!valid_path(params->path_texture_no))
		ft_exit("Invalid north texture path");
	if (!valid_path(params->path_texture_we))
		ft_exit("Invalid west texture path");
	if (!valid_path(params->path_texture_so))
		ft_exit("Invalid south texture path");
	if (!valid_path(params->path_texture_sp))
		ft_exit("Invalid sprite texture path");
}

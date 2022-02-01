/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:04:52 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 17:27:58 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_params(t_params *params)
{
	if (params->unique.texture_ea)
		free(params->path_texture_ea);
	if (params->unique.texture_we)
		free(params->path_texture_we);
	if (params->unique.texture_so)
		free(params->path_texture_so);
	if (params->unique.texture_no)
		free(params->path_texture_no);
	if (params->unique.texture_sp)
		free(params->path_texture_sp);
}

void	free_map(t_map *map)
{
	size_t	x;

	x = 0;
	while (x < map->height)
	{
		free(map->map[x]);
		x++;
	}
	free(map->map);
	map->map = NULL;
}

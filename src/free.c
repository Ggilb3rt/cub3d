/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:04:52 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 18:30:27 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_params(t_params *params)
{
	if (params->unique.texture_ea == 1)
		free(params->path_texture_ea);
	if (params->unique.texture_we)
		free(params->path_texture_we);
	if (params->unique.texture_so)
		free(params->path_texture_so);
	if (params->unique.texture_no)
		free(params->path_texture_no);
}

void	free_map(t_map *map)
{
	size_t	x;

	x = 0;
	if (map->map == NULL)
		return ;
	while (x < map->height)
	{
		free(map->map[x]);
		x++;
	}
	free(map->map);
	map->map = NULL;
}

void	free_map_rotated(t_map *map)
{
	size_t	x;

	x = 0;
	if (map->map == NULL)
		return ;
	while (x < map->width)
	{
		free(map->map[x]);
		x++;
	}
	free(map->map);
	map->map = NULL;
}

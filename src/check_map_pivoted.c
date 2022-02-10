/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pivoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:01:50 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/04 13:11:19 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_pivoted_map(t_map *map, t_map *new)
{
	int		x;

	x = -1;
	new->width = map->width;
	new->height = map->height;
	new->map = malloc(sizeof(new->map) * map->width);
	if (new->map == NULL)
		return (e_malloc);
	while (++x < (int)map->width)
	{
		new->map[x] = malloc(sizeof(*new->map) * map->height + 1);
		if (new->map[x] == NULL)
			return (e_malloc);
		ft_memset(new->map[x], ' ', map->height);
	}
	return (-1);
}

void	pi_by_two_pivote_map(t_map *map, t_map *new)
{
	size_t		x;
	size_t		y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (map->map[x][y] != '\0')
		{
			ft_memcpy(&new->map[(-y + map->width) - 1][x], &map->map[x][y], 1);
			y++;
		}
		new->map[x][new->height] = '\0';
		x++;
	}
}

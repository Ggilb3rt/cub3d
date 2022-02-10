/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pivoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:01:50 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 18:28:23 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_pivoted_map(t_map *map, t_map *new)
{
	int	y;

	y = 0;
	new->width = map->height;
	new->height = map->width;
	new->map = malloc(sizeof(new->map) * new->height + 1);
	if (new->map == NULL)
		return (e_malloc);
	while (y < (int)new->height)
	{
		new->map[y] = malloc(sizeof(*new->map) * new->width + 1);
		if (new->map[y] == NULL)
			return (e_malloc);
		ft_memset(new->map[y], ' ', new->width);
		y++;
	}
	return (-1);
}

void	pi_by_two_pivote_map(t_map *map, t_map *new)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			ft_memcpy(&new->map[-x + map->width - 1][y], &map->map[y][x], 1);
			x++;
		}
		y++;
	}
	y = -1;
	while (++y < new->height)
		new->map[y][new->width] = '\0';
}

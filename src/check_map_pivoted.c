/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pivoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:01:50 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 12:42:16 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	empty_pivoted_map(t_map *map, t_map *new)
{
	int		x;

	x = -1;
	new->width = map->height;
	new->height = map->width;
	new->map = malloc(sizeof(new->map) * new->height);
	if (new->map == NULL)
		ft_exit(ERR_MALLOCCRASH);
	while (++x < (int)new->height)
	{
		new->map[x] = malloc(sizeof(*new->map) * new->width + 1);
		if (new->map[x] == NULL)
			ft_exit(ERR_MALLOCCRASH);
		ft_memset(new->map[x], ' ', new->width);
	}
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
		new->map[x][new->width + 0] = '\0';
		x++;
	}
	// for (size_t z = 0; z < new->height; z++)
	// {
	// 	printf("%ld\t|%s|\n", z, new->map[z]);
	// }
}

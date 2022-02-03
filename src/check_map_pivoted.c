/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pivoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:01:50 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/03 18:02:01 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_pivoted_map(t_map *map, t_map *new)
{
	int		x;

	x = -1;
	new->width = map->height;
	new->height = map->width;
	new->map = malloc(sizeof(new->map) * new->height);
	if (new->map == NULL)
		return (e_malloc);
	while (++x < (int)new->height)
	{
		new->map[x] = malloc(sizeof(*new->map) * new->width + 1);
		if (new->map[x] == NULL)
			return (e_malloc);
		ft_memset(new->map[x], ' ', new->width);
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
			// printf("copy %c in map[%ld][%ld] ==to==> [%ld][%ld]\n",
			// 	map->map[x][y], x, y, (-y + map->width) - 1, x);
			ft_memcpy(&new->map[(-y + map->width) - 1][x], &map->map[x][y], 1);
			y++;
		}
		new->map[x][new->width] = '\0';
		x++;
	}
	// for (size_t z = 0; z < new->height; z++)
	// {
	// 	//printf("%s\n", new->map[z]);
	// 	for(size_t a = 0; new->map[z][a] != '\0'; a++)
	// 	{
	// 		printf("%c", new->map[z][a]);
	// 	}
	// 	printf("\n");
	// }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:56:17 by ggilbert          #+#    #+#             */
/*   Updated: 2021/04/08 09:46:50 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ERR_MAP_HOLE "Hole in the map"

void		check_char(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (map->map[x][y] != '\0')
		{
			if (map->map[x][y] != '0'
					&& map->map[x][y] != '1'
					&& map->map[x][y] != '2'
					&& map->map[x][y] != ' ')
				ft_exit("Unknow char in map");
			y++;
		}
		x++;
	}
}

int			find_first(t_map *map, size_t *x, size_t *y)
{
	while (map->map[*x][*y] != '1')
	{
		if (map->map[*x][*y] == ' ')
			*y += 1;
		else
			ft_exit(ERR_MAP_HOLE);
	}
	return (1);
}

int			open_or_not(t_map *map, size_t *x, size_t *y)
{
	char	starter_open;

	starter_open = map->map[*x][*y];
	if (starter_open == ' ')
	{
		while (map->map[*x][*y] != '\0' && map->map[*x][*y] == ' ')
			*y += 1;
		if (map->map[*x][*y] == '\0')
			return (0);
		if (map->map[*x][*y] != '1')
			return (1);
	}
	else if (starter_open != ' ')
	{
		while (map->map[*x][*y] != '\0' && map->map[*x][*y] != ' '
				&& map->map[*x][*y] != '1')
			*y += 1;
		if (map->map[*x][*y] == '1')
			return (0);
		if (map->map[*x][*y] == ' ' || map->map[*x][*y] == '\0')
			return (1);
	}
	return (0);
}

void		hole_finder(t_map *map)
{
	size_t	x;
	size_t	y;
	int		first_one;

	x = 0;
	y = 0;
	while (x < map->height)
	{
		first_one = 0;
		while (map->map[x][y] != '\0')
		{
			if (!first_one)
				first_one = find_first(map, &x, &y);
			if (map->map[x][y] != '1')
			{
				if (open_or_not(map, &x, &y))
					ft_exit(ERR_MAP_HOLE);
			}
			if (map->map[x][y] != '\0')
				y++;
		}
		y = 0;
		x++;
	}
}

void		pi_by_two_pivote_map(t_map *map, t_map *new)
{
	int		x;
	int		y;

	x = -1;
	new->width = map->height;
	new->height = map->width;
	if (!(new->map = malloc(sizeof(new->map) * new->height)))
		ft_exit(ERR_MALLOCCRASH);
	while (++x < (int)new->height)
	{
		if (!(new->map[x] = malloc(sizeof(*new->map) * new->width + 1)))
			ft_exit(ERR_MALLOCCRASH);
		ft_memset(new->map[x], ' ', new->width);
	}
	x = -1;
	while (++x < (int)map->height)
	{
		y = 0;
		while (map->map[x][y] != '\0')
		{
			ft_memcpy(&new->map[(-y + map->width) - 1][x], &map->map[x][y], 1);
			y++;
		}
		new->map[x][new->width + 1] = '\0';
	}
}

void		check_map_integrity(t_map *map)
{
	size_t	x;
	size_t	y;
	t_map	rotated_map;

	x = 0;
	y = 0;
	check_char(map);
	hole_finder(map);
	pi_by_two_pivote_map(map, &rotated_map);
	hole_finder(&rotated_map);
	while (x < rotated_map.height)
	{
		free(rotated_map.map[x]);
		x++;
	}
	free(rotated_map.map);
}

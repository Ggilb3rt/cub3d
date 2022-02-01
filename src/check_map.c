/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:56:17 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 12:47:07 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_char(t_map *map)
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

int	find_first(t_map *map, size_t *x, size_t *y)
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

int	open_or_not(t_map *map, size_t *x, size_t *y)
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

void	hole_finder(t_map *map)
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

void	check_map_integrity(t_map *map)
{
	size_t	x;
	size_t	y;
	t_map	rotated_map;

	x = 0;
	y = 0;
	(void)y;
	check_char(map);
	hole_finder(map);
	empty_pivoted_map(map, &rotated_map);
	pi_by_two_pivote_map(map, &rotated_map);
	hole_finder(&rotated_map);
	while (x < rotated_map.height)
	{
		free(rotated_map.map[x]);
		x++;
	}
	free(rotated_map.map);
}

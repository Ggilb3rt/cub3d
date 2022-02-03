/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:56:17 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/03 18:00:46 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(t_map *map)
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
					&& map->map[x][y] != ' ')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	find_first(t_map *map, size_t *x, size_t *y)
{
	while (map->map[*x][*y] != '1')
	{
		if (map->map[*x][*y] == ' ')
			*y += 1;
		else
			return (0);
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

int	hole_finder(t_map *map)
{
	size_t	x;
	size_t	y;
	int		first_one;

	x = -1;
	y = 0;
	while (++x < map->height)
	{
		first_one = 0;
		while (map->map[x][y] != '\0')
		{
			if (!first_one)
				first_one = find_first(map, &x, &y);
			if (!first_one)
				return (e_map_hole);
			if (map->map[x][y] != '1')
			{
				if (open_or_not(map, &x, &y))
					return (e_map_hole);
			}
			if (map->map[x][y] != '\0')
				y++;
		}
		y = 0;
	}
	return (-1);
}

int	check_map_integrity(t_map *map)
{
	size_t	x;
	t_map	rotated_map;
	int		hole_in_rotated;

	x = 0;
	hole_in_rotated = -1;
	if (check_char(map))
		return (e_map_char);
	if (hole_finder(map) != -1)
		return (e_map_hole);
	if (empty_pivoted_map(map, &rotated_map) != -1)
		return (e_malloc);
	pi_by_two_pivote_map(map, &rotated_map);
	hole_in_rotated = hole_finder(&rotated_map);
	while (x < rotated_map.height)
	{
		free(rotated_map.map[x]);
		x++;
	}
	free(rotated_map.map);
	if (hole_in_rotated != -1)
		return (e_map_hole);
	return (-1);
}

int	map_ok_or_quit(t_map *map)
{
	int	quit;

	quit = check_map_integrity(map);
	if (quit != -1)
	{
		print_error(quit);
		return (quit);
	}
	return (-1);
}

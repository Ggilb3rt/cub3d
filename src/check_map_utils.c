/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:38 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/03 18:32:58 by ggilbert         ###   ########.fr       */
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

int	first_but_hole(int *first_one, t_map *map, size_t *x, size_t *y)
{
	if (!*first_one)
		*first_one = find_first(map, x, y);
	if (!*first_one)
		return (e_map_hole);
	return (-1);
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
			if (first_but_hole(&first_one, map, &x, &y) != -1)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:56:17 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 18:29:38 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

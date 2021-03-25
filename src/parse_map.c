/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:03 by ggilbert          #+#    #+#             */
/*   Updated: 2021/03/25 12:26:29 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_map(t_map *map, t_player *player)
{
	char	*find_orientation;
	size_t	line_length;

	line_length = ft_strlen(map->map[map->height]);
	map->width < line_length ? map->width = line_length : map->width;
	find_orientation = ft_strchr(map->map[map->height], 'N');
	if (find_orientation && player->orientation == '0')
	{
		player->orientation = find_orientation[0];
		player->pos_y = map->height;
		player->pos_x = line_length - ft_strlen(find_orientation);
		find_orientation[0] = '0';
	}
	else if (find_orientation && player->orientation != '0')
		ft_exit("Find multiple players");
	map->height++;
}
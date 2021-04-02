/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:03 by ggilbert          #+#    #+#             */
/*   Updated: 2021/03/30 18:29:33 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*find_player_orientation(t_map *map, t_player *player)
{
	char	valid_orientation[4];
	char	*orientation;
	int		i;
	(void)player;

	valid_orientation[0] = 'N';
	valid_orientation[1] = 'S';
	valid_orientation[2] = 'E';
	valid_orientation[3] = 'W';
	i = 0;

	while (i < 4)
	{
		orientation = ft_strchr(map->map[map->height], valid_orientation[i]);
		if (orientation)
			return (orientation);
		i++;
	}
	return (0);
}

void		find_pos(t_map *map, t_player *player, size_t line_l, char *or)
{
	if (or && player->orientation == '0')
	{
		player->orientation = or[0];
		player->pos_y = map->height;
		player->pos_x = line_l - ft_strlen(or);
		or[0] = '0';
	}
	else if (or && player->orientation != '0')
		ft_exit("Find multiple players");
}

void		parse_map(t_map *map, t_player *player)
{
	char	*find_orientation;
	size_t	line_length;

	line_length = ft_strlen(map->map[map->height]);
	map->width < line_length ? map->width = line_length : map->width;
	find_orientation = find_player_orientation(map, player);
	find_pos(map, player, line_length, find_orientation);
	map->height++;
}
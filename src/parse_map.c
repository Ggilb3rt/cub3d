/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:03 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 18:55:58 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**reallocmap(char **map, size_t map_size, size_t new_size)
{
	char	**nmap;
	size_t	i;

	i = 0;
	if (new_size < map_size || new_size == 0)
		return (map);
	nmap = malloc(sizeof(nmap) * new_size);
	if (nmap == NULL)
		ft_exit(ERR_MALLOCCRASH);
	while (i < map_size)
	{
		*(nmap + i) = ft_strdup(*(map + i));
		free(*(map + i));
		i++;
	}
	if (map_size > 0)
		free(map);
	return (nmap);
}

char	*find_player_orientation(t_map *map)
{
	char	valid_orientation[4];
	char	*orientation;
	int		i;

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

void	find_pos(t_map *map, t_player *player, size_t line_l, char *or)
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

void	convert_orientation(t_player *player)
{
	if (player->orientation == 'N')
		player->angle = PI / 2;
	else if (player->orientation == 'S')
		player->angle = 3 * PI / 2;
	else if (player->orientation == 'E')
		player->angle = 0.00;
	else if (player->orientation == 'W')
		player->angle = PI;
	else
		ft_exit("How can you be here ?");
	player->pos_delta_x = cos(player->angle);
	player->pos_delta_y = sin(player->angle);
}

void	parse_map(t_map *map, t_player *player)
{
	char	*find_orientation;
	size_t	line_length;

	line_length = ft_strlen(map->map[map->height]);
	if (map->width < line_length)
		map->width = line_length;
	find_orientation = find_player_orientation(map);
	if (find_orientation)
	{
		find_pos(map, player, line_length, find_orientation);
		convert_orientation(player);
	}
	map->height++;
}

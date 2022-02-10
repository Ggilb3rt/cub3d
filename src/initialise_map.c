/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:04:03 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 11:27:06 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_line_map(t_map *map, char *line, t_player *pl)
{
	map->map = reallocmap(map->map, map->height, (map->height) + 1);
	if (map->map == NULL)
		return (e_malloc);
	map->map[map->height] = ft_strdup(line);
	if (parse_map(map, pl) != -1)
	{
		free(map->map[map->height]);
		return (e_map_multi_pl);
	}
	return (-1);
}

int	basic_check_map_line(t_params *par, t_map *map, t_player *pl, char *line)
{
	int	is_add;

	if (line[0] == '\0' && map->map == NULL)
		;
	else if (par->nb_valid_param == NB_PARAMS_PARSE
		&& (line[0] == ' ' || line[0] == '1'))
	{
		is_add = add_line_map(map, line, pl);
		if (is_add != -1)
		{
			free(line);
			return (is_add);
		}
	}
	else
	{
		free(line);
		return (e_wrong_map);
	}
	return (-1);
}

int	init_map(t_params *par, t_map *map, t_player *pl, int *fd)
{
	char	*line;
	int		ret;
	int		is_add;

	line = NULL;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(*fd, &line, 0);
		if (!line)
			return (e_gnl);
		is_add = basic_check_map_line(par, map, pl, line);
		if (is_add != -1)
		{
			get_next_line(*fd, &line, 1);
			return (is_add);
		}
		free(line);
	}
	if (pl->orientation == '0')
		return (e_map_multi_pl);
	return (-1);
}

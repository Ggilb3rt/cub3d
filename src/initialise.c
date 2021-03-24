/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:13:34 by ggilbert          #+#    #+#             */
/*   Updated: 2021/03/10 11:32:17 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_parameters(t_params *params, char *line)
{
	if (line[0] == 'R')
		parse_res(params, line);
	else if (line[0] == 'F' || line[0] == 'C')
		parse_color(params, line);
	else if (line[0] == 'S' || (line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A'))
		parse_text_path(params, line);
	else if (!(line[0] == ' ' || line[0] == '\n' || line[0] == '\0'))
		error_init("Find parameters with wrong ID");
	return (1);
}

char		**realocmap(char **map, size_t mapSize, size_t newSize)
{
	char	**nmap;
	size_t	i;

	i = 0;
	if (newSize == 0)
		return (map);
	else if (newSize < mapSize)
		return (map);
	if (!(nmap = malloc(sizeof(nmap)* newSize)))
		ft_exit(ERR_MALLOCCRASH);
	while (i < mapSize)
	{
		*(nmap + i) = ft_strdup(*(map + i));
		free(*(map + i));
		i++;
	}
	if (mapSize > 0)
		free(map);
	return (nmap); 
}


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

int			is_id_valid(char *line)
{
	if (line[0] == 'R' || line[0] == 'F' || line[0] == 'C'
		|| line[0] == 'S'
		|| (line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A'))
		return (1);
	else
		return (0);
}

int			init_map(t_params *par, t_map *map, t_player *pl, int *fd)
{
	int		res;
	char	*line;
	int		i;

	line = NULL;
	res = 1;
	i = 0;
	while (res != 0)
	{
		res = get_next_line(*fd, &line);
		printf("Line map : %s\n", line);
		if (line[0] == '\0' && map->map == NULL)
			;
		else if (par->nb_valid_param == 8 && (line[0] == ' ' || line[0] == '1'))
		{
			map->map = realocmap(map->map, i, i + 1);
			map->map[i] = ft_strdup(line);
			parse_map(map, pl);
			i++;
		}
		else
		{
			if (line)
				free(line);
			ft_exit("find somthing wrong in the map");
		}
		if (line)
			free(line);
	}
	return (1);
}

int			init_param(t_params *params, int *fd)
{
	int		res;
	char	*line;

	line = NULL;
	res = 1;
	while (res != 0 && params->nb_valid_param < 8)
	{
		res = get_next_line(*fd, &line);
		printf("Line param : %s\n", line);
		if (is_id_valid(line) && params->nb_valid_param < 8)
		{
			parse_parameters(params, line);
			free(line);
			continue;
		}
		else if (line[0] == '\0')
			;
		else
		{
			if (line)
				free(line);
			ft_exit("1. Impossible to parse parameters");
		}
		if (line)
			free(line);
	}
	if (params->nb_valid_param != 8)
		error_init("Invalid quantity of parameters in .cub file");
	return (1);
}

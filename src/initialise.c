/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:13:34 by ggilbert          #+#    #+#             */
/*   Updated: 2021/04/02 11:45:36 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_parameters(t_params *params, char *line)
{
	//? ajouter un système qui vérifie que le parametre n'est pas passer plusieurs fois ??
	if (line[0] == 'R')
		parse_res(params, line);
	else if (line[0] == 'F' || line[0] == 'C')
	{
		if (line[0] == 'F')
			parse_color(params, line, params->floor_color);
		else
			parse_color(params, line, params->ceiling_color);
	}
	else if ((line[0] == 'S' && line[1] == ' ')
			|| (line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A'))
		split_parse_text_path(params, line);
	else if (!(line[0] == ' ' || line[0] == '\n' || line[0] == '\0'))
		error_init("Find parameters with wrong ID");
	return (1);
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

char		**reallocmap(char **map, size_t map_size, size_t new_size)
{
	char	**nmap;
	size_t	i;

	i = 0;
	if (new_size == 0)
		return (map);
	else if (new_size < map_size)
		return (map);
	if (!(nmap = malloc(sizeof(nmap) * new_size)))
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
		//printf("Line map : %s\n", line);
		if (!line)
			ft_exit(ERR_GNL);
		if (line[0] == '\0' && map->map == NULL)
			;
		else if (par->nb_valid_param == 8 && (line[0] == ' ' || line[0] == '1'))
		{
			map->map = reallocmap(map->map, i, i + 1);
			map->map[i] = ft_strdup(line);
			parse_map(map, pl);
			i++;
		}
		else
		{
			free(line);
			ft_exit("Find somthing wrong in the map.");
		}
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
		//printf("Line param : %s\n", line);
		if (!line)
			ft_exit(ERR_GNL);
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
			free(line);
			ft_exit("1. Impossible to parse parameters");
		}
		free(line);
	}
	if (params->nb_valid_param != 8)
		error_init("Invalid quantity of parameters in .cub file");
	return (1);
}

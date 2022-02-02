/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:13:34 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/02 19:24:22 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_parameters(t_params *params, char *line)
{
	if (line[0] == 'R' && params->unique.resolution++ == 0)
		return (parse_res(params, line));
	else if (line[0] == 'F' || (line[0] == 'C' && params->unique.ceiling == 0))
	{
		if (line[0] == 'F' && params->unique.floor == 0)
			return (parse_color(params, line, params->floor_color));
		else if (line[0] == 'C' && params->unique.ceiling == 0)
			return (parse_color(params, line, params->ceiling_color));
		else
			return (e_qt_param);
	}
	else if ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A'))
		return (split_parse_text_path(params, line));
	else if (!(line[0] == ' ' || line[0] == '\n' || line[0] == '\0'))
		return (e_wrong_param);
	return (-1);
}

int	is_id_valid(char *line)
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

void	add_line_map(t_map *map, char *line, t_player *pl)
{
	map->map = reallocmap(map->map, map->height, (map->height) + 1);
	map->map[map->height] = ft_strdup(line);
	parse_map(map, pl);
}

int	init_map(t_params *par, t_map *map, t_player *pl, int *fd)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(*fd, &line);
		if (!line)
			return(e_gnl);
		if (line[0] == '\0' && map->map == NULL)
			;
		else if (par->nb_valid_param == NB_PARAMS_PARSE
			&& (line[0] == ' ' || line[0] == '1'))
			add_line_map(map, line, pl);
		else
		{
			free(line);
			return(e_wrong_map); 
		}
		free(line);
	}
	return (-1);
}

int	init_param(t_params *params, int *fd)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret != 0 && params->nb_valid_param < NB_PARAMS_PARSE)
	{
		ret = get_next_line(*fd, &line);
		if (!line)
			return(e_gnl);
		if (is_id_valid(line) || line[0] == '\0')
		{
			int pret = parse_parameters(params, line);
			free(line);
			if (pret != -1)
				return (pret);
			continue ;
		}
		else
		{
			free(line);
			return(e_wrong_param);
		}
	}
	if (params->nb_valid_param != NB_PARAMS_PARSE)
		return(e_qt_param);
	return (-1);
}

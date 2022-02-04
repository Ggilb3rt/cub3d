/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_parameters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:13:34 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/04 16:31:09 by ggilbert         ###   ########.fr       */
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
		|| (line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A'))
		return (1);
	else
		return (0);
}

int	basic_check_param_line(t_params *params, char *line)
{
	int	parse_ret;

	if (is_id_valid(line) || line[0] == '\0')
	{
		parse_ret = parse_parameters(params, line);
		free(line);
		if (parse_ret != -1)
			return (parse_ret);
		return (-1);
	}
	else
	{
		free(line);
		return (e_wrong_param);
	}
}

int	init_param(t_params *params, int *fd)
{
	char	*line;
	int		ret;
	int		parse_ret;

	ret = 1;
	line = NULL;
	while (ret != 0 && params->nb_valid_param < NB_PARAMS_PARSE)
	{
		ret = get_next_line(*fd, &line, 0);
		if (!line)
			return (e_gnl);
		parse_ret = basic_check_param_line(params, line);
		if (parse_ret != -1)
		{
			get_next_line(*fd, &line, 1);
			return (parse_ret);
		}
		else
			continue ;
		free(line);
	}
	if (params->nb_valid_param != NB_PARAMS_PARSE)
		return (e_qt_param);
	return (-1);
}

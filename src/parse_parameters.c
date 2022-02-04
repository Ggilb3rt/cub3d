/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:36:52 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/04 12:42:25 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_res(t_params *params, char *line)
{
	char	**splitted;

	splitted = check_number_param(2, line, ' ');
	if (splitted == NULL)
		return (e_param_qt);
	if (ft_str_is_digitspace(splitted[0]) && ft_str_is_digitspace(splitted[1]))
	{
		params->res_x = ft_atoi(splitted[0]);
		params->res_y = ft_atoi(splitted[1]);
		if (params->res_x > MAX_X)
			params->res_x = MAX_X;
		if (params->res_y > MAX_Y)
			params->res_y = MAX_Y;
	}
	else
	{
		ft_split_free((void **)splitted);
		return (e_param_type);
	}
	ft_split_free((void **)splitted);
	params->nb_valid_param++;
	return (-1);
}

int	parse_color(t_params *params, char *line, int *color)
{
	char			**splitted;
	size_t			splitted_l;

	splitted = check_number_param(3, line, ',');
	if (splitted == NULL)
		return (e_param_qt);
	splitted_l = ft_splitted_length(splitted);
	while (splitted_l-- > 0)
	{
		if (ft_str_is_digitspace(splitted[splitted_l]))
			color[splitted_l] = ft_atoi(splitted[splitted_l]);
		else
		{
			ft_split_free((void **)splitted);
			return (e_param_type);
		}
	}
	ft_split_free((void **)splitted);
	params->nb_valid_param++;
	if (&(params->floor_color[0]) != color)
		params->unique.ceiling = 1;
	else
		params->unique.floor = 1;
	return (-1);
}

int	parse_text_path(char **dest, char *line, int remove_id)
{
	size_t			line_len;

	while (remove_id-- > 0)
		line++;
	while (*line == ' ' && *line != '\0')
		line++;
	if (line[0] == '.' && line[1] == '/')
	{
		line_len = ft_strlen(line);
		*dest = malloc(sizeof(*dest) * line_len + 1);
		if (*dest == NULL)
			return (e_malloc);
		ft_strlcpy(*dest, line, line_len + 1);
		return (-1);
	}
	else
		return (e_param_path);
}

int	split_parse_text_path(t_params *params, char *line)
{
	params->nb_valid_param++;
	if (line[0] == 'N' && line[1] == 'O' && params->unique.texture_no++ == 0)
		return (parse_text_path(&(params->path_texture_no), line, 2));
	else if (line[0] == 'S' && line[1] == 'O'
		&& params->unique.texture_so++ == 0)
		return (parse_text_path(&(params->path_texture_so), line, 2));
	else if (line[0] == 'W' && line[1] == 'E'
		&& params->unique.texture_we++ == 0)
		return (parse_text_path(&(params->path_texture_we), line, 2));
	else if (line[0] == 'E' && line[1] == 'A'
		&& params->unique.texture_ea++ == 0)
		return (parse_text_path(&(params->path_texture_ea), line, 2));
	else
		return (e_wrong_param);
}

int	parse_root(char *av, t_params *params, t_map *map, t_player *player)
{
	int		fd;
	int		ret;

	fd = open(av, O_RDONLY);
	ret = init_param(params, &fd);
	if (ret != -1)
	{
		print_error(ret);
		close(fd);
		free_params(params);
		return (0);
	}
	ret = init_map(params, map, player, &fd);
	if (ret != -1)
	{
		print_error(ret);
		close(fd);
		free_params(params);
		free_map(map);
		return (0);
	}
	close(fd);
	return (1);
}

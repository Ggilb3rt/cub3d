/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:36:52 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/02 19:29:40 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_str_is_digitspace(char *str)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

// need to check with valgrind before removing legacy code
char	**check_number_param(size_t nb_par, char *line, char split, char *print)
{
	size_t			splitted_l;
	char			**splitted;

	splitted_l = 0;
	splitted = ft_split(++line, split);
	splitted_l = ft_splitted_length(splitted);
	if (splitted_l != nb_par)
	{
		(void)print;
		//print_error(print, 7);
		ft_split_free((void **)splitted);
		//free(--line);
		//line = NULL;
		return (NULL);
	}
	return (splitted);
}

int	parse_res(t_params *params, char *line)
{
	char	**splitted;

	splitted = check_number_param(2, line, ' ', ERR_PARAMS_RES);
	if (splitted == NULL)
	{
		//free_params(params);
		return (e_param_qt);
	}
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
		return(e_param_type);
	ft_split_free((void **)splitted);
	params->nb_valid_param++;
	return (-1);
}

int	parse_color(t_params *params, char *line, int *color)
{
	// put checking in check sould be better
	char			**splitted;
	size_t			splitted_l;

	line++;
	while (*line == ' ')
		line++;
	splitted = check_number_param(3, line, ',', "+color must be 3 values");
	if (splitted == NULL)
		return (e_param_qt);
	splitted_l = ft_splitted_length(splitted);
	while (splitted_l-- > 0)
	{
		if (ft_str_is_digitspace(splitted[splitted_l]))
			color[splitted_l] = ft_atoi(splitted[splitted_l]);
		else
			return(e_param_type);
			// return without free is bad
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
		return (e_param_multi_times);
}

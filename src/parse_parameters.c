/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:36:52 by ggilbert          #+#    #+#             */
/*   Updated: 2021/05/26 11:08:53 by ggilbert         ###   ########.fr       */
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

void	parse_res(t_params *params, char *line)
{
	size_t			i;
	char			**splitted;

	i = 0;
	splitted = ft_split(++line, ' ');
	i = ft_splitted_length(splitted);
	if (i != 2)
		error_init("Resolution must have 2 values");
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
		ft_exit("Resolution must be numbers");
	ft_split_free((void **)splitted);
	params->nb_valid_param++;
}

void	parse_color(t_params *params, char *line, int *color)
{
	char			**s;
	size_t			splitted_l;

	line++;
	while (*line == ' ')
		line++;
	s = ft_split(line, ',');
	splitted_l = ft_splitted_length(s);
	if (splitted_l != 3)
		ft_exit("Color must have 3 values");
	while (splitted_l-- > 0)
	{
		if (ft_str_is_digitspace(s[splitted_l]))
			color[splitted_l] = ft_atoi(s[splitted_l]);
		else
			ft_exit("Colors must be numbers");
		printf("%d\n", color[splitted_l]);
	}
	ft_split_free((void **)s);
	params->nb_valid_param++;
	if (&(params->floor_color[0]) != color)
		params->unique.ceiling = 1;
	else
		params->unique.floor = 1;
}

void	parse_text_path(char **dest, char *line, int remove_id)
{
	size_t			line_len;

	while (remove_id-- > 0)
	{
		line++;
	}
	while (*line == ' ' && *line != '\0')
		line++;
	if (line[0] == '.' && line[1] == '/')
	{
		line_len = ft_strlen(line);
		if (!(*dest = malloc(sizeof(*dest) * line_len + 1)))
			ft_exit(ERR_MALLOCCRASH);
		ft_strlcpy(*dest, line, line_len + 1);
	}
	else
		ft_exit("Le chemin d'une texture doit commencer par \"./\"");
}

void	split_parse_text_path(t_params *params, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && params->unique.texture_no++ == 0)
		parse_text_path(&(params->path_texture_no), line, 2);
	else if (line[0] == 'S' && line[1] == 'O'
		&& params->unique.texture_so++ == 0)
		parse_text_path(&(params->path_texture_so), line, 2);
	else if (line[0] == 'W' && line[1] == 'E'
		&& params->unique.texture_we++ == 0)
		parse_text_path(&(params->path_texture_we), line, 2);
	else if (line[0] == 'E' && line[1] == 'A'
		&& params->unique.texture_ea++ == 0)
		parse_text_path(&(params->path_texture_ea), line, 2);
	else if (line[0] == 'S' && line[1] == ' '
		&& params->unique.texture_sp++ == 0)
		parse_text_path(&(params->path_texture_sp), line, 1);
	else
		ft_exit("Texture path find but already set");
	params->nb_valid_param++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:13:34 by ggilbert          #+#    #+#             */
/*   Updated: 2021/02/20 19:01:58 by ggilbert         ###   ########.fr       */
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
	else if (line[0] == ' ')
		;
	else
	{
		error_init("Find parameters with wrong ID");
		return (-1);
	}
	
	/*char	**splited;
	int		i;
	int		max_split;

	params->res_x = 100;
	i = 0;
		if (line[0] == 'R')
		max_split = 3;
	else
		max_split = 2;
	splited = ft_split(line, ' ');
	while (i < max_split)
	{
		ft_putstr_fd(splited[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	i = 0;
	while (i < max_split)
	{
		ft_putstr_fd(splited[i], 1);
		ft_putstr_fd("\n", 1);
		free(splited[i]);
		i++;
	}
	free(splited);*/
	return (1);
}

int			parse_map(t_map *map, t_player *player, char *line)
{
	char	*find_orientation;
	size_t	line_length;

	line_length = ft_strlen(line);
	find_orientation = ft_strchr(line, 'N');
	map->width < line_length ? map->width = line_length : map->width;
	map->height++;
	if (find_orientation)
		player->orientation = find_orientation[0];
	return (1);
}

int			init_param(t_params *params, t_map *map, t_player *pl, char *file)
{
	int		fd;
	int		res;
	char	*line;

	fd = open(file, O_RDONLY);
	line = NULL;
	res = 1;
	while (res != 0)
	{
		res = get_next_line(fd, &line);
		if (line[0] == 'R' || line[0] == 'F' || line[0] == 'C' || line[0] == 'S'
			|| (line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A'))
			parse_parameters(params, line);
		else if (line[0] == '1' || line[0] == ' ')
			parse_map(map, pl, line);
		if (line)
			free(line);
	}
	ft_putchar_fd(pl->orientation, 1);
	ft_putstr_fd("\nMap Width ", 1);
	ft_putnbr_fd(map->width, 1);
	ft_putstr_fd("\nMap Height ", 1);
	ft_putnbr_fd(map->height, 1);
	return (1);
}

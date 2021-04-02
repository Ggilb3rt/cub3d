/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:56:17 by ggilbert          #+#    #+#             */
/*   Updated: 2021/04/02 12:27:05 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAP_HOLE "Hole in the map"

void		check_char(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (map->map[x][y] != '\0')
		{
			if (map->map[x][y] != '0'
					&& map->map[x][y] != '1'
					&& map->map[x][y] != '2'
					&& map->map[x][y] != ' ')
				ft_exit("Unknow char in map");
			y++;
		}
		x++;
	}
}

int			find_first(t_map *map, size_t *x, size_t *y)
{
	while (map->map[*x][*y] != '1')
	{
		if (map->map[*x][*y] == ' ')
			*y += 1;
		else
			ft_exit(MAP_HOLE);
	}
	return (1);
}

int			open_or_not_verti(t_map *map, size_t *x, size_t *y)
{
	char	starter_open;

	starter_open = map->map[*x][*y];
	if (starter_open == ' ')
	{
		while (map->map[*x][*y] != '\0' && map->map[*x][*y] == ' ')
			*y += 1;
		if (map->map[*x][*y] != '1')
			return (1);
	}
	else if (starter_open != ' ')
	{
		while (map->map[*x][*y] != '\0' && map->map[*x][*y] != ' '
				&& map->map[*x][*y] != '1')
			*y += 1;
		if (map->map[*x][*y] == '1')
			return (0);
		if (map->map[*x][*y] == ' ' || map->map[*x][*y] == '\0')
			return (1);
	}
	return (0);
}

void		verti(t_map *map)
{
	size_t		x;
	size_t		y;
	int		first_one;

	x = 0;
	y = 0;
	while (x < map->height)
	{
		first_one = 0;
		while (map->map[x][y] != '\0')
		{
			printf("%c", map->map[x][y]);
			if (!first_one)
				first_one = find_first(map, &x, &y);
			if (map->map[x][y] != '1')
			{
				if (open_or_not_verti(map, &x, &y))
				{
					printf("1stop in (%zu,%zu)\n%s\n", x, y, map->map[x]);
					ft_exit(MAP_HOLE);
				}
			}
			if (map->map[x][y] != '\0')
				y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
	printf("\n\n\n");
}

int			open_or_not_horiz(t_map *map, size_t *x, size_t *y)
{
	char	starter_open;

	starter_open = map->map[*x][*y];
	if (starter_open == ' ')
	{
		while (*x < map->height && map->map[*x][*y] == ' ')
			*x += 1;
		if (map->map[*x][*y] != '1')
			return (1);
	}
	else if (starter_open != ' ')
	{
		while (*x < map->height && map->map[*x][*y] != ' '
				&& map->map[*x][*y] != '1')
			*x += 1;
		if (map->map[*x][*y] == '1')
			return (0);
		if (map->map[*x][*y] == ' ')
			return (1);
	}
	return (0);
}

void			horiz(t_map *map)
{
	int			first_one;
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
printf("HORIZON\n");
	while (y < map->width)
	{
		first_one = 0;
		while (x < map->height)
		{
			printf("%c", map->map[x][y]);
			if (!first_one)
				first_one = find_first(map, &x, &y);
			if (map->map[x][y] != '1')
			{
				if (open_or_not_horiz(map, &x, &y))
				{
					printf("Hstop in (%zu,%zu)\n%s\n", x, y, map->map[x]);
					ft_exit(MAP_HOLE);
				}
			}
			if (map->map[x][y] != '\0')
				x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void		pi_by_two_pivote_map(t_map *map, t_map *new_map)
{
	char 	**new;
	size_t	new_h;
	size_t	new_w;

	new_h = map->width;
	new_w = map->height;
	new = malloc(sizeof(new) * new_h);
	for (size_t i = 0; i < new_h; i++)
	{
		new[i] = malloc(sizeof(*new) * new_w + 1);
		//strcpy(new[i], "bonojour");
		ft_memset(new[i], ' ', new_w);
		//new[i][new_w + 1] = '\0';
		//printf("full of : '%s'\n", new[i]);
	}
	for (size_t x = 0; x < map->height; x++)
	{
		for (size_t y = 0; map->map[x][y] != '\0'; y++)
		{
			//printf("(%zu, %zu) = (%zu, %zu)\n", x, y, -y+map->width-1, x);
			ft_memcpy(&new[(-y+map->width)-1][x], &map->map[x][y], 1);
			new[x][new_w + 1] = '\0';
		}
	}
	for (size_t i = 0; i < new_h; i++)
	{
		printf ("'%s'\n", new[i]);
	}
	new_map->map = new;
	new_map->width = new_w;
	new_map->height = new_h;
	// rotation puis translation
	// map[-y-map.width][x] = new[x][y];
}

void		check_map_integrity(t_map *map)
{
	size_t		x;
	size_t		y;
	t_map		rotated_map;
	//int			first_one;

	x = 0;
	y = 0;
	check_char(map);
	verti(map);
	pi_by_two_pivote_map(map, &rotated_map);
	verti(&rotated_map);
	//horiz(map);
	/*
	while (x < map->height)
	{
		first_one = 0;
		while (map->map[x][y] != '\0')
		{
			printf("%c", map->map[x][y]);
			if (!first_one)
				first_one = find_first(map, &x, &y);
			if (map->map[x][y] != '1')
			{
				if (open_or_not(map, &x, &y))
				{
					printf("1stop in (%zu,%zu)\n%s\n", x, y, map->map[x]);
					ft_exit(MAP_HOLE);
				}
			}
			if (map->map[x][y] != '\0')
				y++;
		}
		printf("\n");
		y = 0;
		x++;
	}*/
	//horiz(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_coordinates(t_map *map, char **r_file)
{
	int	range;
	int	i;
	int	j;

	range = find_coordinate_range(r_file);
	i = 0;
	map->flag = 0;
	while (r_file[i] && i < range)
	{
		j = 0;
		if (r_file[i][j] == ' ' && j == 0)
			while (r_file[i][j] && is_space(r_file[i][j]))
				j++;
		if (is_coordinate(r_file[i] + j) \
			&& !fill_coordinates(map, r_file, range, r_file[i] + j))
			map->flag += 3;
		else if (r_file[i][j] && !is_coordinate(r_file[i] + j) \
			&& (ft_isprint(r_file[i][j])))
			perror("Invalid map! Found a crazy string in the map!");
		i++;
	}
	if (map->flag != MAX_FLAG)
		perror("Invalid map! Check the documentation!");
	check_filled_coordinates(map);
	return (0);
}

static int	fill_coordinates(t_map *map, char **r_file, int range, char *str)
{
	if (!strncmp("NO ", str, 3))
		map->c_no = find_string("NO ", r_file, range);
	else if (!strncmp("SO ", str, 3))
		map->c_so = find_string("SO ", r_file, range);
	else if (!strncmp("EA ", str, 3))
		map->c_ea = find_string("EA ", r_file, range);
	else if (!strncmp("WE ", str, 3))
		map->c_we = find_string("WE ", r_file, range);
	else if (!strncmp("C ", str, 2))
		map->ceiling = find_string("C ", r_file, range);
	else if (!strncmp("F ", str, 2))
		map->floor = find_string("F ", r_file, range);
	else
		return (1);
	return (0);
}

static int	check_filled_coordinates(t_map *map)
{
	if (!map->c_no || !map->c_so || !map->c_ea || !map->c_we \
	|| !map->ceiling || !map->floor)
		perror("Invalid map! Read the rules!");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 20:05:20 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_valid(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else if (c == '1' || c == '0' || c == '*')
		return (2);
	else
		return (0);
}

// int	get_map(t_map *map, char **r_file)
// {
// 	int	size;
// 	int	i;
// 	int	j;

// 	size = matrix_size(r_file) - find_coordinate_range(r_file);
// 	i = find_coordinate_range(r_file);
// 	j = 0;
// 	map->r_map = malloc(sizeof(*map) * size + 1);
// 	if (!map)
// 		return (1);
// 	while (r_file[i])
// 	{
// 		map->r_map[j] = ft_strdup(r_file[i]);
// 		i++;
// 		j++;
// 	}
// 	map->r_map[j] = NULL;
// 	set_map_rows(matrix_size(map->r_map));
// 	ft_free_matrix(map->r_file);
// 	close_and_restart(map);
// 	return (0);
// }

int	check_valid_map(char **map, t_data *data, int flag, int i)
{
	int	j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] && !is_valid(map[i][j]))
				perror("Invalid character found in the map!");
			if (map[i][j] && (is_valid(map[i][j]) == 1))
			{
				flag = flag + 1;
				data->p_x = i;
				data->p_y = j;
			}
			j++;
		}
		i++;
	}
	if (flag != 1)
		perror("You need ONE player!");
	return (0);
}

int	find_directions(t_data *data, t_map *map, int i, int j)
{
	while (map->r_map[i])
	{
		j = 0;
		while (map->r_map[i][j])
		{
			if (map->r_map[i][j] && is_valid(map->r_map[i][j]) == 1)
			{
				if (map->r_map[i][j] == 'N')
					set_player_direction('N');
				else if (map->r_map[i][j] == 'S')
					set_player_direction('S');
				else if (map->r_map[i][j] == 'W')
					set_player_direction('W');
				else if (map->r_map[i][j] == 'E')
					set_player_direction('E');
				return (1);
			}
			j++;
		}
		i ++;
	}
	return (0);
}

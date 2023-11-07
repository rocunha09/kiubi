/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:52:27 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	validate_textures(char *str, t_map *map)
{
	char	**aux;

	aux = ft_split(str, ' ');
	if (!aux)
	{
		ft_free_matrix(aux);
		perror("Invalid textures!");
	}
	if (matrix_size(aux) > 2)
	{
		ft_free_matrix(aux);
		perror("parameters for texture: <direction> <path>");
	}
	else
	{
		check_valid_file(map, aux[1], ".xpm");
		ft_free_matrix(aux);
	}
	return (0);
}

static int	fill_data(t_map *map)
{
	char	**aux;

	aux = ft_split(map->c_no, ' ');
	//map->c_no = ft_strdup(aux[1]);
	set_map_n(ft_strdup(aux[1]));
	ft_free_matrix(aux);
	aux = ft_split(map->c_ea, ' ');
	//map->c_ea = ft_strdup(aux[1]);
	set_map_e(ft_strdup(aux[1]));
	ft_free_matrix(aux);
	aux = ft_split(map->c_so, ' ');
	//map->c_so = ft_strdup(aux[1]);
	set_map_s(ft_strdup(aux[1]));
	ft_free_matrix(aux);
	aux = ft_split(map->c_we, ' ');
	//map->c_we = ft_strdup(aux[1]);
	set_map_w(ft_strdup(aux[1]));
	ft_free_matrix(aux);
	return (0);
}

int	call_validate_textures(t_map *map)
{
	validate_textures(map->c_no, map);
	validate_textures(map->c_so, map);
	validate_textures(map->c_ea, map);
	validate_textures(map->c_we, map);
	fill_data(map);
	//printf("%s\n%s\n%s\n%s\n", map->c_ea, map->c_we, map->c_no, map->c_so);
	return (0);
}

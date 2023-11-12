/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 19:22:49 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_colors(char *color)
{
	char	**temp;
	int		i;
	int		aux;

	i = 1;
	temp = double_split(color, ' ', ',');
	aux = matrix_size(temp);
	if (aux != 4)
		perror("Wrong color parameters");
	while (temp[i] != NULL)
	{
		aux = 0;
		aux = ft_atoi(temp[i]);
		if (aux > 255 || aux < 0)
		{
			ft_free_matrix(temp);
			perror("Color range is from 0 to 255!");
		}
		i++;
	}
	ft_free_matrix(temp);
	return (0);
}

/*Mandar um array de int */
static int	fill_colors(t_map *map)
{
	char	**temp;

	temp = double_split(map->ceiling, ' ', ',');

	//[INICIO - rafael]	//roda ai
	/*
	int y = 0;
	while (temp[y])
	{
		printf("temp[%d] = %s\n", y, temp[y]);
		y++;
	}
	getchar();
	*/
	//[FIM - rafael]


	map->data->c_green = ft_atoi(temp[2]);
	map->data->c_blue = ft_atoi(temp[3]);
	set_ceiling_color_by_rgb(temp);
	ft_free_matrix(temp);
	temp = double_split(map->floor, ' ', ',');
	map->data->f_red = ft_atoi(temp[1]);
	map->data->f_green = ft_atoi(temp[2]);
	map->data->f_blue = ft_atoi(temp[3]);
	set_floor_color_by_rgb(temp);
	ft_free_matrix(temp);
	return (0);
}

int	validate_colors(t_map *map)
{
	get_colors(map->ceiling);
	get_colors(map->floor);
	fill_colors(map);
	//printf("c_r:%d\nc_g:%d\nc_b:%d\n", map->data->c_red, map->data->c_green, map->data->c_blue);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 17:08:46 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	read_file_map(t_map *map)
{
	char	*aux;
	char	*gnl;

	aux = ft_strdup("");
	while (42)
	{
		gnl = get_next_line(map->fd);
		if (!gnl)
			break ;
		aux = ft_strjoin2(aux, gnl);
		free(gnl);
	}
	map->r_file = ft_split(aux, '\n');
	clean_map(map);
	free(aux);
	free(gnl);
	close(map->fd);
	return (0);
}

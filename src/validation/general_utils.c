/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 20:36:25 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*return matriz size*/

int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

/*Search a string (str) inside an matrix (r_file) and return 
that string or NULL. If you don't have an specific range
to look for, the searching will ocur by the whole matrix lenght*/
char	*find_string(char *str, char **r_file, int range)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (range == 0)
		range = matrix_size(r_file);
	while (r_file[i] && i < range)
	{
		j = 0;
		if (r_file[i][0] == ' ' && j == 0)
			while (r_file[i][j] && is_space(r_file[i][j]))
				j++;
		if (!strncmp(str, (r_file[i] + j), ft_strlen(str)))
			return (r_file[i]);
		i++;
	}
	return (NULL);
}

int	close_and_restart(t_map *map)
{
	map->fd = close(map->fd);
	return (0);
}

int	biggest_string(char **str)
{
	int	i;
	int	big;

	i = 0;
	big = ft_strlen(str[i]);
	while (str[i])
	{
		if (((int)ft_strlen(str[i])) > big)
			big = ft_strlen(str[i]);
		i++;
	}
	return (big);
}

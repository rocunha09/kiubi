/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/11 23:31:25 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Checa se o arquivo existe e sua extensão é válida*/
int	check_valid_file(t_map *map, char *str, char *ext)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		perror("invalid file!");
	if (!check_extension(str, ext, ft_strlen(str)))
	{
		if (!ft_strncmp(ext, ".cub", 5))
		{
			set_fd(fd);
			map->fd = get_fd();
		}
		return (0);
	}
	else
	{
		free(str);
		perror("invalid extension!");
	}
	return (1);
}

int	check_extension(char *str, char *ext, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ext || !str)
		return (1);
	while (str[i] != '\0')
	{
		j = 0;
		if (ext[j] == str[i + j] && i + j < n)
			while (ext[j] == str[i + j] && ext[j] != '\0')
				j++;
		if (ext[j] == '\0')
		{
			if (str[i + j] == '\0')
				return (0);
			else
				break ;
		}
		i++;
	}
	return (1);
}

/*retira todos os caracteres indesejados do final da string*/
int	clean_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (map->r_file[i])
	{
		j = 0;
		len = ft_strlen(map->r_file[i]);
		while (map->r_file[i][j])
		{
			if (map->r_file[i][j] && (map->r_file[i][j] == 13 \
				|| map->r_file[i][j] == '\n') && len > 1)
			{
				map->r_file[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*OLD GETMAP OF PURPLE MINION*/
int	get_mapping(t_map *map, char **r_file)
{
	int	size;
	int	i;
	int	j;

	size = matrix_size(r_file) - find_coordinate_range(r_file);
	i = find_coordinate_range(r_file);
	j = 0;
	map->r_map = malloc(sizeof(*map) * size + 1);
	if (!map)
		return (1);
	while (r_file[i])
	{
		map->r_map[j] = ft_strdup(r_file[i]);
		i++;
		j++;
	}
	map->r_map[j] = NULL;
	set_map_rows(matrix_size(map->r_map));
	ft_free_matrix(map->r_file);
	close(map->fd);
	return (0);
}

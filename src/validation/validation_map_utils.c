/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 21:13:00 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**map_dup(char **map)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (matrix_size(map) + 1));
	if (!new)
		return (NULL);
	while (map[i])
	{
		new[i] = ft_strdup(map[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

/*modifica o mapa, colocando uma borda nele.*/
char	**close_map(t_map *map)
{
	char	**new;
	int		i;
	int		j;

	map->biggest_line = biggest_string(map->r_map) + 3;
	new = malloc(sizeof(char *) * (matrix_size(map->r_map) + 3));
	if (!new)
		return (NULL);
	i = 0;
	j = 1;
	new[0] = fill_char('*', map->biggest_line);
	while (map->r_map[i])
	{
		new[j] = ft_strjoin3("*", map->r_map[i]);
		j++;
		i++;
	}
	new[j] = fill_char('*', map->biggest_line);
	new[j + 1] = NULL;
	set_map(map_dup(map->r_map));
	ft_free_matrix(map->r_map);
	map->r_map = new;
	return (map->r_map);
}

/*devolve uma string de char c, de lenght = len*/
char	*fill_char(char c, int len)
{
	int		i;
	char	*aux;

	i = 0;
	aux = malloc(sizeof(char) * len);
	if (!aux)
		return (NULL);
	while (i < (len - 1))
	{
		aux[i] = c;
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

/*preenche os espaços em branco com um caractere * */
char	*clean_spaces(char *str, int len, char c)
{
	int		i;
	char	*new;

	i = -1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == ' ')
			new[i] = c;
		else
			new[i] = str[i];
	}
	if (i < len)
	{
		while (i < (len - 1))
		{
			new[i] = c;
			i++;
		}
	}
	new[i] = '\0';
	free(str);
	return (new);
}

/*percorre o mapa, chamando uma função que vai preencher 
todos os espaços em branco com um caractere*/
void	call_clean_spaces(t_map *map)
{
	int	i;

	i = 0;
	while (map->r_map[i] != NULL)
	{
		map->r_map[i] = clean_spaces(map->r_map[i], map->biggest_line, '*');
		//printf("[%d][%s]\n", i, map->r_map[i]);
		i++;
	}
	//printf("[%s]\n", map->r_map[i]);
}

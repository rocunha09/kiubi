/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:54:26 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**map(const char *action, int initialize, ...)
{
	static char	**the_map;
	va_list		args;

	if (initialize)
	{
		destroy_map();
		the_map = NULL;
	}
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (the_map);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		the_map = va_arg(args, char **);
	}
	return (0);
}

char	**get_map(void)
{
	return (map("get", 0));
}

void	set_map(char **new_map)
{
	map("set", 1, new_map);
}

char	**create_map(int rows, int columns)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc(rows, sizeof(char *));
	i = 0;
	while (i < rows)
	{
		map[i] = (char *)ft_calloc(columns, sizeof(char));
		i++;
	}
	return (map);
}

void	destroy_map(void)
{
	char	**map;
	int		i;

	map = get_map();
	if (map != NULL)
	{
		i = 0;
		while (i < get_map_rows())
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
	}
	free(map);
	map = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_closed_map(char **r_map)
{
	int	i;
	int	size;

	i = 0;
	size = matrix_size(r_map) - 1;
	while (i <= size)
	{
		if (check_front(r_map[i], '*'))
			return (1);
		if (check_back(r_map[i], '*'))
			return (1);
		if (i > 0 && check_up(r_map[i - 1], r_map[i], '*'))
			return (1);
		if (i < size && check_up(r_map[i + 1], r_map[i], '*'))
			return (1);
		i++;
	}
	return (0);
}

int	check_front(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] && str[i] == c)
		{
			if (str[i + 1] && (str[i + 1] != '1' \
				&& str[i + 1] != c && str[i + 1] != '\0'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_back(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0 && str[i] == c)
		{
			if (str[i - 1] && (str[i - 1] != '1' && str[i - 1] != c))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_up(char *up, char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && up[i] != '\0')
	{
		if (str[i] == c)
		{
			if (i >= 0 && (up[i] != '1' && up[i] != c))
				return (1);
			if (i >= 0 && (up[i + 1] != '1' \
				&& up[i + 1] != c && up[i + 1] != '\0'))
				return (1);
			if (i > 0 && (up[i - 1] != '1' && up[i - 1] != c))
				return (1);
		}
		i++;
	}
	return (0);
}

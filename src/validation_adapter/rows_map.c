/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	*rows_map(const char *action, int initialize, ...)
{
	static int	rows_map;
	va_list		args;

	if (initialize)
		rows_map = 0;
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (rows_map);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		rows_map = va_arg(args, int);
	}
	return (0);
}

int	get_map_rows(void)
{
	return (rows_map("get", 0));
}

void	set_map_rows(int new_numb_rows)
{
	rows_map("set", 1, new_numb_rows);
}

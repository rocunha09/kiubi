/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:55:00 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	player_direction(const char *action, int initialize, ...)
{
	static char	player_direction;
	va_list		args;

	if (initialize)
		player_direction = 0;
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (player_direction);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		player_direction = (char)va_arg(args, int);
	}
	return (0);
}

char	get_player_direction(void)
{
	return (player_direction("get", 0));
}

void	set_player_direction(char new_direction)
{
	player_direction("set", 1, new_direction);
}

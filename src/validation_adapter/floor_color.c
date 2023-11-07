/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:53:03 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	*floor_color(const char *action, int initialize, ...)
{
	static int	floor_color;
	va_list		args;

	if (initialize)
		floor_color = 0;
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (floor_color);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		floor_color = va_arg(args, int);
	}
	return (0);
}

int	get_floor_color(void)
{
	return (floor_color("get", 0));
}

void	set_floor_color(int new_floor_color)
{
	floor_color("set", 1, new_floor_color);
}

void	set_floor_color_by_rgb(char **new_rgb)
{
	int	rgb[3];

	rgb[0] = ft_atoi(new_rgb[0]);
	rgb[1] = ft_atoi(new_rgb[1]);
	rgb[2] = ft_atoi(new_rgb[2]);
	floor_color("set", 1, create_trgb(parser_mat_to_trgb(rgb)));
}

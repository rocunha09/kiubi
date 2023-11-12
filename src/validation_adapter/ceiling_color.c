/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 00:57:20 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	*ceiling_color(const char *action, int initialize, ...)
{
	static int	*ceiling_color;
	va_list		args;

	if (initialize)
		ceiling_color = 0;
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (ceiling_color);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		ceiling_color = va_arg(args, int);
	}
	return (0);
}

int	get_ceiling_color(void)
{
	return (ceiling_color("get", 0));
}

void	set_ceiling_color(int new_ceiling_color)
{
	ceiling_color("set", 1, new_ceiling_color);
}

void	set_ceiling_color_by_rgb(char **new_rgb)
{
	int	rgb[3];

	rgb[0] = ft_atoi(new_rgb[0]);
	rgb[1] = ft_atoi(new_rgb[1]);
	rgb[2] = ft_atoi(new_rgb[2]);
	ceiling_color("set", 1, create_trgb(parser_mat_to_trgb(rgb)));
}
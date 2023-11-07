/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_color_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	*ceiling_color_rgb(const char *action, int initialize, ...)
{
	static int	*ceiling_color_rgb;
	va_list		args;

	if (initialize)
	{
		destroy_color_rgb("ceiling");
		ceiling_color_rgb = 0;
	}
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (ceiling_color_rgb);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		ceiling_color_rgb = va_arg(args, int *);
	}
	return (0);
}

int	*get_ceiling_color_rgb(void)
{
	return (ceiling_color_rgb("get", 0));
}

void	set_ceiling_color_rgb(int *new_ceiling_color_rgb)
{
	ceiling_color_rgb("set", 1, new_ceiling_color_rgb);
}

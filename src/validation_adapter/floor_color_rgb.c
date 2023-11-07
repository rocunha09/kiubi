/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_color_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:52:56 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	*floor_color_rgb(const char *action, int initialize, ...)
{
	static int	*floor_color_rgb;
	va_list		args;

	if (initialize)
	{
		destroy_color_rgb("floor");
		floor_color_rgb = NULL;
	}
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (floor_color_rgb);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		floor_color_rgb = va_arg(args, int *);
	}
	return (0);
}

int	*create_color_rgb(int qnt_types)
{
	int	*colors_rgb;
	int	i;

	colors_rgb = (int *)malloc(qnt_types * sizeof(int));
	i = 0;
	while (i < qnt_types)
	{
		colors_rgb[i] = 0;
		i++;
	}
	return (colors_rgb);
}

void	destroy_color_rgb(const char *entity)
{
	int	*color;
	int	i;
	int	qnt_types;

	qnt_types = 3;
	if (strcmp(entity, "floor") == 0)
		color = get_floor_color_rgb();
	else if (strcmp(entity, "ceiling") == 0)
		color = get_ceiling_color_rgb();
	if (color != 0)
	{
		i = 0;
		while (i < qnt_types)
		{
			color[i] = 0;
			i++;
		}
		free(color);
		color = NULL;
	}
}

int	*get_floor_color_rgb(void)
{
	return (floor_color_rgb("get", 0));
}

void	set_floor_color_rgb(int *new_floor_color_rgb)
{
	floor_color_rgb("set", 1, new_floor_color_rgb);
}

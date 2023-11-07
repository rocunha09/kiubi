/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:51:57 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	my_mlx_pixel_put(t_img *cube, int x, int y, int color)
// {
// 	char	*pixel;

// 	pixel = cube->pix + (y * cube->line_len + x * (cube->bpp / 8));
// 	*(unsigned int *)pixel = color;
// }

void	floor_and_ceiling(t_img *cube, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < height / 2)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(cube, x, y, 0xF04482);
			x++;
		}
		y++;
	}
}

t_color	parser_mat_to_trgb(int *new_floor_color_rgb)
{
	t_color	new_floor_color;

	new_floor_color.r = new_floor_color_rgb[0];
	new_floor_color.g = new_floor_color_rgb[1];
	new_floor_color.b = new_floor_color_rgb[2];
	new_floor_color.t = 0;
	return (new_floor_color);
}

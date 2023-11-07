/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	*file_descriptor(const char *action, int initialize, ...)
{
	static int	fd;
	va_list		args;

	if (initialize)
		fd = 0;
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (fd);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		fd = va_arg(args, int);
	}
	return (0);
}

int	get_fd(void)
{
	return (file_descriptor("get", 0));
}

void	set_fd(int new_fd)
{
	file_descriptor("set", 1, new_fd);
}

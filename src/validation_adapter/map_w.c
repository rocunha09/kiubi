/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:53:58 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	destroy_map_w(void)
{
	t_list	*map_w;

	ft_lstclear(&map_w, free);
	map_w = NULL;
	set_map_w(NULL);
}

static t_list	*map_w(const char *action, int initialize, ...)
{
	t_list		*map_w;
	va_list		args;

	if (initialize)
	{
		destroy_map_w();
		map_w = NULL;
	}
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (map_w);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		map_w = ft_lstnew(va_arg(args, char *));
	}
	return (0);
}

t_list	*get_map_w(void)
{
	return (map_w("get", 0));
}

void	set_map_w(char *new_map_w)
{
	map_w("set", 1, new_map_w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:53:39 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	destroy_map_n(void)
{
	t_list	*map_n;

	ft_lstclear(&map_n, free);
	map_n = NULL;
	set_map_n(NULL);
}

static t_list	*map_n(const char *action, int initialize, ...)
{
	t_list		*map_n;
	va_list		args;

	if (initialize)
	{
		destroy_map_n();
		map_n = NULL;
	}
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (map_n);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		map_n = ft_lstnew(va_arg(args, char *));
	}
	return (0);
}

t_list	*get_map_n(void)
{
	return (map_n("get", 0));
}

void	set_map_n(char *new_map_n)
{
	map_n("set", 1, new_map_n);
}

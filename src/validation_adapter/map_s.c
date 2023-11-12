/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 20:21:26 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	destroy_map_s(t_list	*map_s)
{
	ft_lstclear(&map_s, free);
	map_s = NULL;
	set_map_s(NULL);
}


static t_list	*map_s(const char *action, int initialize, ...)
{
	t_list		*map_s;
	va_list		args;

	if (initialize)
		map_s = NULL;
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (map_s);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		map_s = ft_lstnew(va_arg(args, char *));
	}
	return (0);
}

t_list	*get_map_s(void)
{
	return (map_s("get", 0));
}

void	set_map_s(char *new_map_s)
{
	map_s("set", 1, new_map_s);
}

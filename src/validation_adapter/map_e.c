/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:53:31 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	destroy_map_e(void)
{
	t_list	*map_e;

	ft_lstclear(&map_e, free);
	map_e = NULL;
	set_map_e(NULL);
}

static t_list	*map_e(const char *action, int initialize, ...)
{
	t_list		*map_e;
	va_list		args;

	if (initialize)
	{
		destroy_map_e();
		map_e = NULL;
	}
	va_start(args, initialize);
	if (strcmp(action, "get") == 0)
	{
		va_end(args);
		return (map_e);
	}
	else if (strcmp(action, "set") == 0)
	{
		va_end(args);
		map_e = ft_lstnew(va_arg(args, char *));
	}
	return (0);
}

t_list	*get_map_e(void)
{
	return (map_e("get", 0));
}

void	set_map_e(char *new_map_e)
{
	map_e("set", 1, new_map_e);
}

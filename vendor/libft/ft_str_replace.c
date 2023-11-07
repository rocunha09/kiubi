/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *str, char *search, char *replace)
{
	int		i;
	int		total;
	char	*found;
	char	*new;

	if (!str || !search || !replace)
	{
		ft_free_ptr((void *) &str);
		return (NULL);
	}
	found = ft_strnstr(str, search, ft_strlen(str));
	if (!found)
		return (NULL);
	total = ft_strlen(str) - ft_strlen(search) + ft_strlen(replace) + 1;
	new = (char *)malloc(sizeof(char) * total);
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, (found - str) + 1);
	ft_strlcat(new, replace, total);
	i = (found - str) + ft_strlen(search);
	ft_strlcat(new, &str[i], total);
	ft_free_ptr((void *) &str);
	str = NULL;
	return (new);
}

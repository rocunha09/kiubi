/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace_all(char *str, char *search, char *replace)
{
	char	*tmp_str;

	while (ft_strnstr(str, search, ft_strlen(str)) != NULL)
	{
		tmp_str = ft_str_replace(str, search, replace);
		str = tmp_str;
	}
	return (str);
}

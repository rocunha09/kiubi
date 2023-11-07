/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	init;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		init = 0;
		end = ft_strlen(s1);
		while (s1[init] && ft_strchr(set, s1[init]))
			init++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > init)
			end--;
		str = (char *)malloc(sizeof(char) * (end - init + 1));
		if (str)
			ft_strlcpy(str, &s1[init], end - init + 1);
	}
	free(s1);
	return (str);
}

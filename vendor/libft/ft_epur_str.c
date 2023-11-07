/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_str(char *content)
{
	char	*new_content;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (content[i] == ' ' || content[i] == '\t')
		i++;
	new_content = ft_calloc(sizeof(char), (ft_strlen(content) + 1));
	while (content[i])
	{
		if (content[i] == ' ' || content[i] == '\t')
			flag = 1;
		if (!(content[i] == ' ' || content[i] == '\t'))
		{
			if (flag)
				new_content[j++] = ' ';
			flag = 0;
			new_content[j++] = content[i];
		}
		i++;
	}
	return (ft_strtrim(new_content, " "));
}

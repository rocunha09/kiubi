/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
} */

void	ft_strjoin_aux(char *s1, char *s2, char *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[j] = s2[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strjoin_aux(s1, s2, ptr);
	free(s1);
	return (ptr);
}

/* char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
	{
		len = ft_strlen(s);
		return ((char *)(s + len));
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
 */

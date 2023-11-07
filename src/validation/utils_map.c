/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:51:22 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	find_coordinate_range(char **r_file)
{
	int	range;
	int	i;

	range = 0;
	i = 0;
	while (r_file[range])
	{
		i = 0;
		if (r_file[range][0] == ' ' && i == 0)
		{
			while (is_space(r_file[range][i]))
				i++;
		}
		if (r_file[range][i] != '1' && r_file[range][i] != '0')
			range++;
		else
			break ;
	}
	return (range);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_coordinate(char *str)
{
	if (!ft_strncmp("NO ", str, 3) || !ft_strncmp("SO ", str, 3)
		|| !ft_strncmp("EA ", str, 3) || !ft_strncmp("WE ", str, 3)
		|| !ft_strncmp("F ", str, 2) || !ft_strncmp("C ", str, 2))
		return (1);
	else
		return (0);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*dest;
	char	*source;

	count = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (!dst || !src)
		return (NULL);
	while (count < n)
	{
		(dest[count] = source[count]);
		count++;
	}
	return (dest);
}

static char	*ft_strdup_gnl(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen_gnl(s) + 1;
	copy = malloc(sizeof(char) * len);
	if (!copy)
		return (NULL);
	ft_memcpy_gnl(copy, s, len);
	return (copy);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*join;
	size_t	maxlen;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup_gnl(s2));
	else if (!s2)
		return (ft_strdup_gnl(s1));
	s1_len = ft_strlen_gnl((char *)s1);
	s2_len = ft_strlen_gnl((char *)s2);
	maxlen = s1_len + s2_len;
	join = malloc(sizeof(char) * (maxlen + 1));
	if (!join)
		return (NULL);
	ft_memcpy_gnl((void *)join, (void *)s1, s1_len);
	ft_memcpy_gnl((void *)&join[s1_len], (void *)s2, s2_len);
	if (!join)
		return (NULL);
	join[maxlen] = '\0';
	free(s1);
	return (join);
}

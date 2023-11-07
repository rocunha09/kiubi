/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save(char *file)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(file) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (file[i])
		s[c++] = file[i++];
	s[c] = '\0';
	free(file);
	return (s);
}

char	*get_line(char *file)
{
	int		i;
	char	*s;

	i = 0;
	if (!file[i])
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		s[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		s[i] = file[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*read_file(int fd, char *file)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(file, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		file = ft_strjoin(file, buff);
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	file = read_file(fd, file);
	if (!file)
		return (NULL);
	line = get_line(file);
	file = save(file);
	return (line);
}

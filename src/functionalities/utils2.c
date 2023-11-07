/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:50:00 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}

static int	count_words_split(char *s, char c1, char c2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == c1 || s[i] == c2))
			i++;
		j = i;
		while (s[i] != '\0' && (s[i] != c1 && s[i] != c2))
			i++;
		if (j != i)
			k++;
	}
	return (k);
}

char	**double_split(char *s, char c1, char c2)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	if (!s || !c1 || !c2)
		return (NULL);
	i = 0;
	k = -1;
	temp = malloc((count_words_split(s, c1, c2) + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == c1 || s[i] == c2))
			i++;
		j = i;
		while (s[i] != '\0' && (s[i] != c1 && s[i] != c2))
			i++;
		if (j != i)
			temp[++k] = ft_substr(s, j, (i - j));
	}
	temp[k + 1] = NULL;
	return (temp);
}

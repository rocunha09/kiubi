/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_remove_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_char(char *s, char c)
{
	int	new;
	int	old;

	new = 0;
	old = 0;
	while (s[old])
	{
		if (s[old] != c)
			s[new++] = s[old];
		old++;
	}
	s[new] = '\0';
}

void	ft_chr_remove_all(char *s, char c)
{
	while (ft_strrchr(s, c) != NULL)
		ft_remove_char(s, c);
}

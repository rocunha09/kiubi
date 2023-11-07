/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	special_chars(char c)
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\r' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;
	int				signal;

	i = 0;
	result = 0;
	signal = 1;
	while (special_chars(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signal = -1;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(signal * result));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calc;
	size_t	i;

	if (!nmemb && !size)
	{
		nmemb = 1;
		size = 1;
	}
	calc = malloc (nmemb * size);
	if (!calc)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)calc)[i] = '\0';
		i++;
	}
	return (calc);
}

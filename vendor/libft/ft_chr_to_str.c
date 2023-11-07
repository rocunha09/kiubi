/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chr_to_str(int c, size_t qtd)
{
	char	*str;

	if (!c || !qtd)
		return (NULL);
	str = malloc((sizeof(char) * qtd) + 1);
	if (!str)
		return (NULL);
	ft_memset(str, c, qtd);
	str[qtd] = '\0';
	return (str);
}

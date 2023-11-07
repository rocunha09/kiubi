/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtx_free(void **matrix)
{
	int	i;

	i = -1;
	if (matrix)
	{
		while (matrix[++i])
			ft_free_ptr((void *) &matrix[i]);
		ft_free_ptr((void *) &matrix);
	}
}

void	ft_mtx_free_chr(char **matrix)
{
	free(matrix[0]);
	free(matrix[1]);
	free(matrix[2]);
	free(matrix[3]);
	free(matrix);
}

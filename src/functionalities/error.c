/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 20:03:54 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"




// O código é uma função em C chamada cub_exit que é responsável por encerrar o
// jogo em caso de erro. A função recebe um ponteiro param como argumento, que
// é um ponteiro para uma estrutura do tipo t_game. A função chama a função
// cub_perror com o erro end, que indica que o jogo deve ser encerrado, e o
// valor booleano 1, que indica que o jogo deve ser encerrado. A função 
// retorna 0.
int	cub_exit(void *param)
{
	cub_perror(end, param, NULL, 1);
	return (0);
}

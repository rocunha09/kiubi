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

// O código é uma função em C chamada cub_perror que é responsável por
// imprimir mensagens de erro na saída padrão de erro e encerrar o jogo em
// caso de erro. A função recebe quatro argumentos: err, que é um valor do tipo
// t_cub_err que indica o tipo de erro; g, que é um ponteiro para uma
// estrutura do tipo t_game; param, que é uma string que contém informações
// adicionais sobre o erro; e c, que é um valor booleano que indica se o jogo
// deve ser encerrado ou não. A função começa verificando se c é igual a 0 e, se
// for, retorna 0. Em seguida, a função chama a função cub_end para encerrar o
// jogo e liberar a memória alocada para as estruturas e imagens do jogo. A
// função escreve uma mensagem de erro na saída padrão de erro com base no valor
// de err e, em seguida, escreve a string param. A função verifica se err é
// igual a inv_argc e, se for, chama a função cub_usage para imprimir a mensagem
// de uso do jogo. Se err for igual a end, a função encerra o jogo com a função
// exit(0). Caso contrário, a função encerra o jogo com a função exit(1). A
// função retorna 1.

int	cub_perror(t_cub_err err, t_game *g, char *param, int c)
{
	if (!c)
		return (0);
	cub_end(g);
	write(2, "cub3d: ", 7 * (err != end));
	write(2, "invalid number of arguments\n", 28 * (err == inv_argc));
	write(2, "cub3D not run in root of the project\n", 37 * (err == inv_pwd));
	write(2, "file must be of .cub type\n", 26 * (err == inv_ext));
	write(2, "error opening file: ", 20 * (err == inv_file));
	write(2, "file is empty\n", 14 * (err == empty_file));
	write(2, "devide out of memory\n", 21 * (err == no_memory));
	write(2, "invalid color\n", 15 * (err == inv_color));
	write(2, "map not surrounded by walls\n", 28 * (err == inv_wall));
	write(2, "invalid map\n", 12 * (err == inv_map));
	write(2, "invalid character\n", 18 * (err == inv_charac));
	write(2, "invalid texture file\n", 21 * (err == inv_tex));
	write(2, "invalid number of players\n", 26 * (err == inv_player));
	if (param != NULL)
		ft_putendl_fd(param, 2);
	if (err == inv_argc && ft_putchar_fd('\n', 2))
		cub_usage(1);
	if (err == end)
		exit(0);
	exit(1);
	return (1);
}

// O código é uma função em C chamada cub_usage que é responsável por imprimir a
// mensagem de uso do jogo na saída padrão de erro e encerrar o jogo. A função
// recebe um inteiro errno como argumento, que é o código de erro a ser
// retornado.
// A função começa escrevendo uma mensagem de cabeçalho na saída padrão de erro
// com informações sobre o jogo. Em seguida, a função escreve a mensagem de uso
// do jogo na saída padrão de erro. Por fim, a função encerra o jogo com o
// código de erro errno usando a função exit.
void	cub_usage(int errno)
{
	ft_putstr_fd("Cub3D\nA simple raycaster with MinilibX\n\n", 2);
	ft_putstr_fd("usage: cub3d <map_file.cub>\n", 2);
	exit(errno);
}

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

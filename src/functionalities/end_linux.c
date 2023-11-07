/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 18:34:25 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada free_animation que recebe um ponteiro
// para uma estrutura do tipo t_game e um ponteiro para uma lista start como
// argumentos. A função é responsável por liberar a memória alocada para as
// imagens da animação do jogo. A função começa com um loop que percorre cada
// elemento da lista start. Para cada elemento, a função obtém o conteúdo do
// elemento, que é um ponteiro para uma estrutura t_img. A função verifica se a
// imagem da estrutura t_img é diferente de NULL e, se for, destrói a imagem com
// a função mlx_destroy_image. Em seguida, a função libera a memória alocada
// para a estrutura t_img e para o elemento da lista. No final, a função libera
// a memória alocada para a lista start.
void	free_animation(t_game *g, t_list *start)
{
	t_list	*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (g && ((t_img *)temp->content)->i)
			mlx_destroy_image(g->mlx_ptr, ((t_img *)temp->content)->i);
		free(temp->content);
		free(temp);
	}
}

// O código é uma função em C chamada destroy_images que recebe um ponteiro
// para uma estrutura do tipo t_game como argumento. A função é responsável por
// liberar a memória alocada para as imagens do jogo. A função começa chamando a
// função free_animation para liberar a memória alocada para as imagens da
// animação do jogo. Em seguida, a função verifica se as imagens da textura do
// chão e do teto existem e, se existirem, destrói as imagens com a função
// mlx_destroy_image. A função verifica se as imagens da janela do jogo existem
// e, se existirem, destrói as imagens com a função mlx_destroy_image. A função
// verifica se a imagem do escopo existe e, se existir, destrói a imagem com a
// função mlx_destroy_image. A função verifica se a janela do jogo existe e, se
// existir, destrói a janela com a função mlx_destroy_window. A função verifica
// se as imagens do minimapa e da miniatura da visão do jogador existem e, se
// existirem, destrói as imagens com a função mlx_destroy_image. Por fim, a
// função libera a memória alocada para as estruturas t_img da textura do chão e
// do teto e para a estrutura t_img do escopo.
void	destroy_images(t_game *g)
{
	free_animation(g, g->tex.n_bak);
	free_animation(g, g->tex.s_bak);
	free_animation(g, g->tex.e_bak);
	free_animation(g, g->tex.w_bak);
	if (g->tex.b && g->tex.b->i)
		mlx_destroy_image(g->mlx_ptr, g->tex.b->i);
	if (g->win_img.i)
		mlx_destroy_image(g->mlx_ptr, g->win_img.i);
	if (g->win_g.i)
		mlx_destroy_image(g->mlx_ptr, g->win_g.i);
	if (g->win_r.i)
		mlx_destroy_image(g->mlx_ptr, g->win_r.i);
	if (g->scope && g->scope->i)
		mlx_destroy_image(g->mlx_ptr, g->scope->i);
	if (g->win_ptr)
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	if (g->minimap.i)
		mlx_destroy_image(g->mlx_ptr, g->minimap.i);
	if (g->miniview.i)
		mlx_destroy_image(g->mlx_ptr, g->miniview.i);
	free(g->tex.b);
	free(g->scope);
}

// O código é uma função em C chamada cub_end que recebe um ponteiro para uma
// estrutura do tipo t_game como argumento. A função é responsável por encerrar
// o jogo e liberar a memória alocada para as estruturas e imagens do jogo. A
// função começa verificando se o ponteiro para a estrutura t_game é válido e,
// se não for, retorna. Em seguida, a função chama a função ft_free_matrix para
// liberar a memória alocada para a matriz do mapa do jogo. A função verifica se
// o descritor de arquivo do arquivo de configuração do jogo é maior que 0 e, se
// for, fecha o arquivo com a função close. A função chama a função
// destroy_images para liberar a memória alocada para as imagens do jogo. A
// função destrói a exibição do jogo com a função mlx_destroy_display e libera a
// memória alocada para o ponteiro da biblioteca gráfica mlx com a função free.

void	cub_end(t_game *g)
{
	if (!g)
		return ;
	ft_free_matrix(g->map);
	if (g->fd > 0)
		close(g->fd);
	destroy_images(g);
	mlx_destroy_display(g->mlx_ptr);
	free(g->mlx_ptr);
}

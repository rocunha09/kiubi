/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:41:02 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada redraw_elem que recebe quatro
// argumentos:
//   g, que é um ponteiro para uma estrutura do tipo t_game;
//   img, que é uma estrutura do tipo t_img que representa a imagem a ser
//   desenhada;
//   x, que é um inteiro que representa a coordenada x da posição da imagem
//   na janela;
//   y, que é um inteiro que representa a coordenada y da posição da imagem
//   na janela.
// A função é responsável por desenhar uma imagem na janela do jogo.
// A função começa definindo um array de inteiros p com as coordenadas x e y
// da posição da imagem na janela.
// A função define um array de estruturas images com as imagens a serem
// desenhadas.
// A função chama a função mlx_img_to_img para copiar a imagem img para a
// imagem g->win_img na posição p.
// A função usa a máscara 0xFF000000 para definir a transparência da
// imagem. Por fim, a função retorna.
void	redraw_elem(t_game *g, t_img img, int x, int y)
{
	int		p[2];
	t_img	images[2];

	p[0] = x;
	p[1] = y;
	images[0] = img;
	images[1] = g->win_img;
	mlx_img_to_img(p, images, 0xFF000000);
}

// O código é uma função em C chamada update_anim que recebe um ponteiro g para
// uma estrutura do tipo t_game. A função é responsável por atualizar as
// texturas das paredes do jogo para criar uma animação de movimento. A função
// começa atualizando a textura da parede norte para a próxima textura na lista
// encadeada. Se a próxima textura for nula, a função define a textura da
// parede norte como a textura de backup. A função atualiza a textura da parede
// sul, leste e oeste da mesma forma. Por fim, a função retorna.
void	update_anim(t_game *g)
{
	g->tex.n = g->tex.n->next;
	if (!g->tex.n)
		g->tex.n = g->tex.n_bak;
	g->tex.s = g->tex.s->next;
	if (!g->tex.s)
		g->tex.s = g->tex.s_bak;
	g->tex.e = g->tex.e->next;
	if (!g->tex.e)
		g->tex.e = g->tex.e_bak;
	g->tex.w = g->tex.w->next;
	if (!g->tex.w)
		g->tex.w = g->tex.w_bak;
}

// O código é uma função em C chamada check_move que recebe um ponteiro g
// para uma estrutura do tipo t_game. A função é responsável por verificar as
// teclas pressionadas pelo jogador e atualizar a posição do jogador no mapa.
// A função começa verificando se a tecla esquerda foi pressionada e, se for,
// diminui o ângulo do raio em 3 graus. A função verifica se a tecla direita
// foi pressionada e, se for, aumenta o ângulo do raio em 3 graus. A função
// verifica se a tecla W foi pressionada e, se for, chama a função move_pl com
// a tecla W, o ponteiro g e as coordenadas x e y como 0. A função verifica se
// a tecla A foi pressionada e, se for, chama a função move_pl com a tecla A,
// o ponteiro g e as coordenadas x e y como 0. A função verifica se a tecla S
// foi pressionada e, se for, chama a função move_pl com a tecla S, o ponteiro
// g e as coordenadas x e y como 0. A função verifica se a tecla D foi
// pressionada e, se for, chama a função move_pl com a tecla D, o ponteiro g e
// as coordenadas x e y como 0. Por fim, a função retorna.
void	check_move(t_game *g)
{
	if (g->pl.keys.left_pressed)
		g->ray.angle -= 3;
	if (g->pl.keys.right_pressed)
		g->ray.angle += 3;
	if (g->pl.keys.w_pressed)
		move_pl(KEY_W, g, 0, 0);
	if (g->pl.keys.a_pressed)
		move_pl(KEY_A, g, 0, 0);
	if (g->pl.keys.s_pressed)
		move_pl(KEY_S, g, 0, 0);
	if (g->pl.keys.d_pressed)
		move_pl(KEY_D, g, 0, 0);
}

// O código é uma função em C chamada cub_update que recebe um ponteiro
// param para um jogo t_game. A função é responsável por atualizar a cena do
// jogo e renderizá-la na janela.
// A função começa verificando se o número de frames é múltiplo da taxa de
// atualização do jogo. Se for, a função atualiza a animação das texturas das
// paredes, verifica o movimento do jogador, renderiza o minimapa, renderiza a
// cena do jogo com o algoritmo de raycasting, renderiza a visão em miniatura
// do jogo, renderiza o retículo de mira e a visão em miniatura na janela.
// A função verifica se a opção de inversão de cores está ativada e, se
// estiver, inverte as cores da cena do jogo. A função atualiza a janela com a
// função mlx_put_image_to_window. Por fim, a função incrementa o número de
// frames e retorna 0.
int	cub_update(void *param)
{
	t_game	*g;

	g = param;
	if (!(g->nframes % g->rate))
	{
		if (!(g->nframes % (2 * g->rate)))
			update_anim(g);
		if (!(g->nframes % (10 * g->rate)))
			g->pl.door_cooldown = 0;
		check_move(g);
		cub_minimap(g);
		cub_raycast(g);
		cub_miniview(g);
		redraw_elem(g, *g->scope, WIN_W / 2 - g->scope->width / 2, \
			WIN_H / 2 - g->scope->height / 2);
		redraw_elem(g, g->miniview, WIN_W - g->miniview.width - 20, \
			WIN_H - g->miniview.height - 20);
		if (g->neg == 1)
			cub_invert_color(g);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_img.i, 0, 0);
	}
	g->nframes++;
	return (0);
}

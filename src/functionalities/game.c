/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 20:02:50 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada cub_keyup que é chamada sempre que
// uma tecla é solta dentro da janela do jogo. A função recebe o código da
// tecla solta e um ponteiro para uma estrutura do tipo t_game como
// argumentos. A função verifica qual tecla foi solta e atualiza as
// variáveis relacionadas às teclas pressionadas pelo jogador na estrutura
// t_keys. Se a tecla R for solta, a variável neg da estrutura t_game é
// multiplicada por -1, invertendo a direção da rotação do jogador. Se a
// tecla E for solta, a função action_door é chamada para abrir ou fechar
// uma porta. Se a tecla LEFT for solta, a variável left_pressed da
// estrutura t_keys é atualizada para 0. O mesmo é feito para as outras
// teclas. A função retorna 0.

int	cub_keyup(int k, t_game *g)
{
	if (k == KEY_R)
		g->neg *= -1;
	else if (k == KEY_E)
		action_door(g);
	else if (k == KEY_LEFT)
		g->pl.keys.left_pressed = 0;
	else if (k == KEY_RIGHT)
		g->pl.keys.right_pressed = 0;
	else if (k == KEY_W)
		g->pl.keys.w_pressed = 0;
	else if (k == KEY_A)
		g->pl.keys.a_pressed = 0;
	else if (k == KEY_S)
		g->pl.keys.s_pressed = 0;
	else if (k == KEY_D)
		g->pl.keys.d_pressed = 0;
	return (0);
}

// O código é uma função em C chamada cub_keydown que é chamada sempre que
// uma tecla é pressionada dentro da janela do jogo. A função recebe o código
// da tecla pressionada e um ponteiro para uma estrutura do tipo t_game como
// argumentos. A função verifica qual tecla foi pressionada e atualiza as
// variáveis relacionadas às teclas pressionadas pelo jogador na estrutura
// t_keys. Se a tecla Q ou ESC for pressionada, a função cub_perror é chamada
// com o erro end, que indica que o jogo deve ser encerrado. A função retorna 0.

int	cub_keydown(int k, t_game *g)
{
	if (k == KEY_Q || k == KEY_ESC)
		cub_perror(end, g, NULL, 1);
	else if (k == KEY_LEFT)
		g->pl.keys.left_pressed = 1;
	else if (k == KEY_RIGHT)
		g->pl.keys.right_pressed = 1;
	else if (k == KEY_W)
		g->pl.keys.w_pressed = 1;
	else if (k == KEY_A)
		g->pl.keys.a_pressed = 1;
	else if (k == KEY_S)
		g->pl.keys.s_pressed = 1;
	else if (k == KEY_D)
		g->pl.keys.d_pressed = 1;
	return (0);
}

// O código é uma função em C chamada cub_mouse que é chamada sempre que
// o mouse é movido dentro da janela do jogo. A função recebe as coordenadas
// x e y do mouse e um ponteiro para uma estrutura do tipo t_game como
// argumentos. A função verifica se a coordenada y é diferente de -1, o que
// indica que o mouse não está fora da janela. Se a coordenada y for
// diferente de -1, a função atualiza o ângulo de visão do jogador com base
// no movimento horizontal do mouse. O ângulo de visão é atualizado
// adicionando a diferença entre a coordenada x atual do mouse e a
// coordenada x anterior do mouse dividida por 3. Em seguida, a coordenada x
// anterior do mouse é atualizada com a coordenada x atual do mouse. A
// função retorna 0.

int	cub_mouse(int x, int y, t_game *g)
{
	if (y != -1)
		g->ray.angle += (x - g->mouse_x) / 3;
	g->mouse_x = x;
	return (0);
}

// O código é uma função em C chamada init_attr que recebe um ponteiro para
// uma estrutura do tipo t_game como argumento. A função inicializa as
// variáveis relacionadas à renderização do jogo, como a janela, as imagens
// da janela, a imagem do minimapa e a imagem da miniatura da visão do
// jogador. A função começa criando a janela com a função mlx_new_window e as
// imagens da janela com a função mlx_new_image. Em seguida, a função obtém os
// endereços de memória das imagens com a função mlx_get_data_addr. A função
// my_mlx_area_put é chamada para preencher as imagens da janela com as cores
// verde e vermelha, que são usadas para debug. Depois, a função cria a imagem
// do minimapa com a função mlx_new_image e obtém o endereço de memória da
// imagem com a função mlx_get_data_addr. Por fim, a função cria a imagem da
// miniatura da visão do jogador com a função mlx_new_image e obtém o
// endereço de memória da imagem com a função mlx_get_data_addr. A largura e
// altura da miniatura da visão do jogador são definidas como 30 * SIZE e
// 15 * SIZE, respectivamente.

void	init_attr(t_game *g)
{
	g->win_ptr = mlx_new_window(g->mlx_ptr, WIN_W, WIN_H, "Cub3D");
	g->win_img.i = mlx_new_image(g->mlx_ptr, WIN_W, WIN_H);
	g->win_img.addr = mlx_get_data_addr(g->win_img.i, &g->win_img.bpp, \
		&g->win_img.line_len, &g->win_img.endian);
	g->win_g.i = mlx_new_image(g->mlx_ptr, WIN_W, WIN_H);
	g->win_g.addr = mlx_get_data_addr(g->win_g.i, &g->win_g.bpp, \
		&g->win_g.line_len, &g->win_g.endian);
	my_mlx_area_put(&g->win_g, ft_newvector(0, 0), \
		ft_newvector(WIN_W, WIN_H), 0x0000FF00);
	g->win_r.i = mlx_new_image(g->mlx_ptr, WIN_W, WIN_H);
	g->win_r.addr = mlx_get_data_addr(g->win_r.i, &g->win_r.bpp, \
		&g->win_r.line_len, &g->win_r.endian);
	my_mlx_area_put(&g->win_r, ft_newvector(0, 0), \
		ft_newvector(WIN_W, WIN_H), 0x00FF0000);
	g->minimap.i = mlx_new_image(g->mlx_ptr, g->width * SIZE, \
		g->height * SIZE);
	g->minimap.addr = mlx_get_data_addr(g->minimap.i, &g->minimap.bpp, \
		&g->minimap.line_len, &g->minimap.endian);
	g->miniview.i = mlx_new_image(g->mlx_ptr, 30 * SIZE, 15 * SIZE);
	g->miniview.addr = mlx_get_data_addr(g->miniview.i, &g->miniview.bpp, \
		&g->miniview.line_len, &g->miniview.endian);
	g->miniview.width = 30 * SIZE;
	g->miniview.height = 15 * SIZE;
}

// O código é uma função em C chamada game_init que recebe um ponteiro para uma
// estrutura do tipo t_game como argumento. A função inicializa o jogo e começa
// a rodá-lo. A função começa chamando as funções init_attr e init_ray para
// inicializar as variáveis relacionadas à renderização do jogo. Em seguida, a
// função define os callbacks para os eventos de teclado, mouse e saída da
// janela através das funções mlx_hook. A função mlx_loop_hook é chamada com a
// função cub_update para atualizar o jogo a cada frame. Por fim, a função
// mlx_loop é chamada para começar a rodar o jogo.

void	game_init(t_game *g)
{
	init_attr(g);
	init_ray(g);
	mlx_hook(g->win_ptr, 02, 1L << 0, cub_keydown, g);
	mlx_hook(g->win_ptr, 03, 1L << 1, cub_keyup, g);
	mlx_hook(g->win_ptr, 17, 0, cub_exit, g);
	mlx_hook(g->win_ptr, 06, 1L << 6, cub_mouse, g);
	mlx_loop_hook(g->mlx_ptr, cub_update, g);
	mlx_loop(g->mlx_ptr);
}

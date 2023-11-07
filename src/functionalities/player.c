/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:37:20 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada distance_to_door que recebe
// quatro argumentos: g, que é um ponteiro para uma estrutura do tipo
// t_game; ray_angle, que é um float que representa o ângulo do raio;
// x, que é um ponteiro para um float que representa a coordenada x da
// porta mais próxima; e y, que é um ponteiro para um float que
// representa a coordenada y da porta mais próxima. A função é responsável
// por calcular a distância até a porta mais próxima no mapa do jogo.
// A função começa definindo dois floats ray_cos e ray_sin com o cosseno
// e o seno do ângulo do raio, respectivamente. A função define as
// coordenadas x e y do jogador como as coordenadas atuais. A função
// percorre o mapa com um loop while até encontrar uma parede, uma coleta
// de item ou uma porta. A função atualiza as coordenadas x e y do
// jogador com base no cosseno e no seno do ângulo do raio e verifica se
// a nova posição do jogador colide com uma parede ou uma coleta de item
// no mapa. Se a nova posição do jogador colidir com uma parede ou uma
// coleta de item, a função retorna a distância até a porta mais próxima.
// Se a nova posição do jogador não colidir com uma parede ou uma coleta
// de item, a função continua atualizando as coordenadas x e y do jogador
// até encontrar uma porta. A função calcula a distância até a porta mais
// próxima com a função sqrt e retorna a distância. As coordenadas x e y
// da porta mais próxima são armazenadas nos ponteiros x e y.
float	distance_to_door(t_game *g, float ray_angle, float *x, float *y)
{
	float	d;
	float	ray_cos;
	float	ray_sin;

	ray_cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
	ray_sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
	*x = g->pl.x + 0.5;
	*y = g->pl.y + 0.5;
	while (!ft_strchr("1oc", g->map[(int)*y][(int)*x]) && \
		sqrt(powf(*x - g->pl.x - 0.5, 2.) + \
		powf(*y - g->pl.y - 0.5, 2.)) < g->ray.lim)
	{
		*x += ray_cos;
		*y += ray_sin;
	}
	d = sqrt(powf(*x - g->pl.x - 0.5, 2.) + powf(*y - g->pl.y - 0.5, 2.));
	d = d * cos(degree_to_radians(ray_angle - g->ray.angle));
	return (d);
}

// O código é uma função em C chamada move_pl que recebe quatro
// argumentos: k, que é um inteiro que representa a tecla pressionada
// pelo jogador; g, que é um ponteiro para uma estrutura do tipo t_game;
// ray_cos, que é um float que representa o cosseno do ângulo do raio; e
// ray_sin, que é um float que representa o seno do ângulo do raio. A
// função é responsável por mover o jogador no mapa com base na tecla
// pressionada. A função começa definindo um float angle com o ângulo
// do raio. A função verifica qual tecla foi pressionada e atualiza o
// ângulo do raio de acordo. A função calcula o cosseno e o seno do novo
// ângulo do raio e multiplica pelo valor da velocidade do jogador para
// obter as novas coordenadas x e y do jogador. A função verifica se a
// nova posição do jogador não colide com uma parede ou uma coleta de
// item no mapa. Se a nova posição não colidir com uma parede ou uma
// coleta de item, a função atualiza as coordenadas x e y do jogador. Por
// fim, a função retorna.
void	move_pl(int k, t_game *g, float ray_cos, float ray_sin)
{
	float	angle;

	angle = g->ray.angle;
	if (k == KEY_A)
		angle = g->ray.angle - 90;
	else if (k == KEY_S)
		angle = g->ray.angle - 180;
	else if (k == KEY_D)
		angle = g->ray.angle + 90;
	ray_cos = cos(degree_to_radians(angle)) * g->pl.speed;
	ray_sin = sin(degree_to_radians(angle)) * g->pl.speed;
	if (!ft_strchr("1c", g->map[(int)(g->pl.y + 0.5 + \
			(3 * ray_sin))][(int)(g->pl.x + 0.5)]))
		g->pl.y += ray_sin;
	if (!ft_strchr("1c", \
		g->map[(int)(g->pl.y + 0.5)][(int)(g->pl.x + 0.5 + (3 * ray_cos))]))
		g->pl.x += ray_cos;
}

// O código é uma função em C chamada action_door que recebe um
// ponteiro g para uma estrutura do tipo t_game. A função é responsável
// por abrir ou fechar portas no mapa do jogo. A função começa verificando
// se o cooldown da porta está ativo ou se a posição atual do jogador
// contém uma coleta de item ou um inimigo. Se a condição for verdadeira,
// a função retorna sem fazer nada. A função calcula a distância até a
// porta mais próxima com a função distance_to_door e obtém as coordenadas
// x e y da porta mais próxima. A função verifica se a distância até a
// porta mais próxima é menor que o limite de alcance do raio e se a
// porta mais próxima é uma coleta de item. Se a condição for verdadeira,
// a função define o cooldown da porta como ativo, atualiza a porta para
// um inimigo e atualiza a janela com a imagem da porta aberta. A função
// verifica se a distância até a porta mais próxima é menor que o limite
// de alcance do raio e se a porta mais próxima é um inimigo. Se a
// condição for verdadeira, a função define o cooldown da porta como
// ativo, atualiza a porta para uma coleta de item e atualiza a janela com
// a imagem da porta fechada. Por fim, a função retorna.
void	action_door(t_game *g)
{
	float	d;
	float	x;
	float	y;

	if (g->pl.door_cooldown || \
			ft_strchr("oc", g->map[(int)(g->pl.y + 0.5)][(int)(g->pl.x + 0.5)]))
		return ;
	d = distance_to_door(g, g->ray.angle, &x, &y);
	if (d < g->ray.lim && g->map[(int)y][(int)x] == 'c')
	{
		g->pl.door_cooldown = 1;
		g->map[(int)y][(int)x] = 'o';
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_g.i, 0, 0);
	}
	else if (d < g->ray.lim && g->map[(int)y][(int)x] == 'o')
	{
		g->pl.door_cooldown = 1;
		g->map[(int)y][(int)x] = 'c';
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_r.i, 0, 0);
	}
}

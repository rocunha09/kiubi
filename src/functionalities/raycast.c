/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:38:40 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada init_ray que recebe um ponteiro g para
// uma estrutura do tipo t_game. A função é responsável por inicializar as
// variáveis relacionadas ao raio no jogo. A função começa definindo o ângulo
// do raio como 0 e atualiza o ângulo do raio de acordo com a direção do
// jogador. A função define a largura do campo de visão horizontal como 30
// graus, a precisão do raio como 50 e o limite de alcance do raio como 11.
// A função calcula o incremento do ângulo do raio com base na largura do
// campo de visão horizontal e a largura da janela. Por fim, a função
// atualiza as variáveis relacionadas ao raio na estrutura do jogo.

void	init_ray(t_game *g)
{
	g->ray.angle = 0;
	if (g->pl.dir == 'S')
		g->ray.angle = 90;
	else if (g->pl.dir == 'W')
		g->ray.angle = 180;
	else if (g->pl.dir == 'N')
		g->ray.angle = 270;
	g->ray.hfov = 30;
	g->ray.incre_angle = 2 * g->ray.hfov / WIN_W;
	g->ray.precision = 50;
	g->ray.lim = 11;
}

// O código é uma função em C chamada distance_to_wall que recebe dois
// argumentos: g, que é um ponteiro para uma estrutura do tipo t_game; e
// ray_angle, que é um float que representa o ângulo do raio. A função é
// responsável por calcular a distância até a parede mais próxima no mapa
// do jogo. A função começa definindo dois floats ray_cos e ray_sin com o
// cosseno e o seno do ângulo do raio, respectivamente. A função define as
// coordenadas x e y do jogador como as coordenadas atuais. A função
// percorre o mapa com um loop while até encontrar uma parede ou uma coleta
// de item. A função atualiza as coordenadas x e y do jogador com base no
// cosseno e no seno do ângulo do raio e verifica se a nova posição do
// jogador colide com uma parede ou uma coleta de item no mapa. Se a nova
// posição do jogador colidir com uma parede ou uma coleta de item, a
// função calcula a distância até a parede mais próxima com a função sqrt e
// retorna a distância multiplicada pelo cosseno do ângulo do raio menos o
// ângulo do raio atual.
float	distance_to_wall(t_game *g, float ray_angle)
{
	float	d;

	g->ray.cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
	g->ray.sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
	g->x = g->pl.x + 0.5;
	g->y = g->pl.y + 0.5;
	while (!ft_strchr("1c", g->map[(int)g->y][(int)g->x]) && \
		sqrt(powf(g->x - g->pl.x - 0.5, 2.) + \
		powf(g->y - g->pl.y - 0.5, 2.)) < g->ray.lim)
	{
		g->x += g->ray.cos;
		g->y += g->ray.sin;
		if (ft_strchr("1c", g->map[(int)g->y][(int)g->x]))
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x00FF0000);
		else if (ray_angle - 1 < g->ray.angle && ray_angle + 1 > g->ray.angle)
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x0000FF00);
		else
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x00BDC1C6);
	}
	my_mlx_area_put(&g->minimap, ft_newvector((int)(g->pl.x + 0.5) * SIZE, \
		(int)(g->pl.y + 0.5) * SIZE), ft_newvector(SIZE, SIZE), 0x00FDD663);
	d = sqrt(powf(g->x - g->pl.x - 0.5, 2.) + powf(g->y - g->pl.y - 0.5, 2.));
	return (d * cos(degree_to_radians(ray_angle - g->ray.angle)));
}

// O código é uma função em C chamada cub_raycast que recebe um ponteiro g
// para uma estrutura do tipo t_game. A função é responsável por renderizar a
// cena do jogo com base no algoritmo de raycasting. A função começa definindo
// um inteiro x para percorrer as colunas da janela e um float ray_angle para
// representar o ângulo do raio. A função percorre as colunas da janela com um
// loop while. Para cada coluna, a função calcula o ângulo do raio com base na
// posição atual do jogador e a direção do raio. A função chama a função
// cast_ray para calcular a distância até a parede mais próxima e a cor da
// parede. A função define a altura da parede na janela com base na distância
// até a parede mais próxima e a altura da janela. A função define a posição y
// da parede na janela com base na altura da parede e a altura da janela. A
// função desenha a parede na janela com a função draw_wall e a cor da parede.
// A função desenha o chão e o teto na janela com a função draw_floor_ceiling.
// Por fim, a função atualiza a janela com a função mlx_put_image_to_window.
void	cub_raycast(t_game *g)
{
	float	ray_angle;
	int		ray_count;
	float	dist;

	ray_angle = g->ray.angle - g->ray.hfov;
	ray_count = -1;
	while (++ray_count < WIN_W)
	{
		dist = distance_to_wall(g, ray_angle);
		cub_draw(g, ray_count, dist);
		ray_angle += g->ray.incre_angle;
	}
}

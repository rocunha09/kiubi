/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:44:32 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada get_texture que recebe um
// ponteiro g para uma estrutura do tipo t_game. A função é responsável
// por obter a textura da parede mais próxima com base na direção do raio.
// A função começa definindo dois floats ray_cos e ray_sin com o cosseno
// e o seno do ângulo do raio, respectivamente.
// A função verifica se a parede ao norte da posição atual do jogador não é
// uma parede e, se não for, define a textura da parede norte como a textura do
// norte.
// A função verifica se a parede ao sul da posição atual do jogador não é
// uma parede e, se não for, define a textura da parede sul como a textura do
// sul.
// A função verifica se a parede ao leste da posição atual do jogador não é
// uma parede e, se não for, define a textura da parede leste como a textura do
// leste.
// A função verifica se a parede ao oeste da posição atual do jogador não é
// uma parede e, se não for, define a textura da parede oeste como a textura do
// oeste.
// A função retorna a textura da parede mais próxima.
t_img	*get_texture(t_game *g)
{
	t_img	*i;
	float	ray_cos;
	float	ray_sin;

	ray_cos = g->ray.cos;
	if (ray_cos < 0)
		ray_cos = -ray_cos;
	ray_sin = g->ray.sin;
	if (ray_sin < 0)
		ray_sin = -ray_sin;
	i = g->tex.b;
	if (g->map[(int)(g->y - ray_sin)][(int)g->x] != '1')
		i = g->tex.n->content;
	else if (g->map[(int)(g->y + ray_sin)][(int)g->x] != '1')
		i = g->tex.s->content;
	else if (g->map[(int)g->y][(int)(g->x + ray_cos)] != '1')
		i = g->tex.e->content;
	else if (g->map[(int)g->y][(int)(g->x - ray_cos)] != '1')
		i = g->tex.w->content;
	return (i);
}

// O código é uma função em C chamada get_tex_color que recebe três
// argumentos: g, que é um ponteiro para uma estrutura do tipo t_game; i,
// que é uma estrutura do tipo t_img que representa a imagem da textura; e
// z, que é um inteiro que representa a altura da parede na janela. A
// função é responsável por obter a cor da textura da parede mais próxima
// com base na posição atual do jogador e na altura da parede na janela. A
// função começa definindo a cor como preto.
// A função verifica se a posição atual do jogador no mapa é uma parede e, se
// for, define a cor como a cor da textura da parede na posição (int)(i->width *
// (g->x + g->y)) % i->width e altura z na imagem i.
// A função verifica se a posição atual do jogador no mapa é uma coleta de
// item e, se for, define a cor como vermelho. Por fim, a função retorna a cor.
int	get_tex_color(t_game *g, t_img *i, int z)
{
	int	color;

	color = 0x00000000;
	if (g->map[(int)g->y][(int)g->x] == '1')
		color = my_mlx_pixel_get(i, (int)(i->width * (g->x + g->y)) \
			% i->width, z);
	else if (g->map[(int)g->y][(int)g->x] == 'c')
		color = 0x00FF0000;
	return (color);
}

// O código é uma função em C chamada draw_texture que recebe quatro
// argumentos: g, que é um ponteiro para uma estrutura do tipo t_game; i,
// que é uma estrutura do tipo t_img que representa a imagem da textura
// da parede; ray_count, que é um inteiro que representa a coluna da
// janela onde a textura será desenhada; e wall_height, que é um inteiro
// que representa a altura da parede na janela.
// A função é responsável por desenhar a textura da parede na janela do
// jogo. A função começa definindo dois floats dy e ds com a altura da
// parede na janela e a distância da parede até o centro da janela,
// respectivamente.
// A função define um array de floats cy com as coordenadas y da parede
// na janela. A função percorre as linhas da textura com um loop while. Para
// cada linha, a função obtém a cor da textura da parede com a função
// get_tex_color e a distância da parede até o centro da janela com a
// função get_dist_color.
// A função define as coordenadas y da parede na janela com base na altura
// da parede na janela e a altura da textura da parede. A função desenha a
// linha da textura da parede na janela com a função my_mlx_pixel_put.
// Por fim, a função retorna.
void	draw_texture(t_game *g, t_img *i, int ray_count, int wall_height)
{
	float	dy;
	float	ds;
	float	cy[2];
	int		z;
	int		color;

	dy = ((float)wall_height * 2) / (float)i->height;
	ds = ((float)WIN_H / 2) - (float)wall_height;
	cy[1] = ds;
	z = -1;
	while (++z < i->height)
	{
		color = get_tex_color(g, i, z);
		color = get_dist_color(color, ds, 0);
		cy[0] = cy[1];
		while (cy[0] < cy[1] + dy)
		{
			if (cy[0] >= 0 && cy[0] < (float)WIN_H)
				my_mlx_pixel_put(&g->win_img, ray_count, cy[0], color);
			cy[0]++;
		}
		cy[1] += dy;
	}
}

// A função cub_draw em C recebe três argumentos: g, que é um ponteiro para
// uma estrutura do tipo t_game; ray_count, que é um inteiro representando a
// coluna da janela onde a textura será desenhada; e dis, que é um float que
// representa a distância da parede mais próxima. A função desenha a cena do
// jogo na janela usando o algoritmo de raycasting.
// A função começa definindo a altura da parede na janela com base na
// distância da parede mais próxima. Em seguida, define a distância da parede
// até o centro da janela com base na altura da parede na janela.
// A função percorre as linhas da janela com um loop while. Para cada linha,
// verifica se a linha está acima da parede e, se sim, desenha a cor do teto
// com a função get_dist_color. Se a linha estiver abaixo da parede, desenha
// a cor do chão com a função get_dist_color. A textura da parede é desenhada
// com a função draw_texture. Por fim, a função retorna.
void	cub_draw(t_game *g, int ray_count, float dis)
{
	int		wall_height;
	float	ds;
	int		j;

	wall_height = (int)(WIN_H / (1.5 * dis));
	ds = ((float)WIN_H / 2) - (float)wall_height;
	j = -1;
	while (++j < WIN_H)
	{
		if (j < ds)
			my_mlx_pixel_put(&g->win_img, ray_count, j, \
				get_dist_color(g->tex.ceiling, j, 0));
		else if (j >= (WIN_H / 2) + wall_height)
			my_mlx_pixel_put(&g->win_img, ray_count, j, \
				get_dist_color(g->tex.floor, WIN_H - j, 0));
	}
	draw_texture(g, get_texture(g), ray_count, wall_height);
}

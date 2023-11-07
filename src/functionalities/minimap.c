/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:02:17 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada cub_miniview que recebe um ponteiro
// g para uma estrutura do tipo t_game. A função é responsável por desenhar
// a visão em miniatura do jogo na janela. A função começa definindo dois
// vetores xy e aux com as coordenadas x e y da posição atual no minimapa e
// um contador auxiliar, respectivamente. A função define as coordenadas x e
// y do minimapa com base na posição do jogador e no tamanho da visão em
// miniatura. A função percorre as linhas da visão em miniatura com um loop
// while. Para cada linha, a função percorre as colunas da visão em miniatura
// com outro loop while. A função verifica se a posição atual está dentro dos
// limites do mapa e, se for, obtém a cor do minimapa para a posição atual com
// a função my_mlx_pixel_get. A função desenha um pixel na janela com a função
// my_mlx_pixel_put usando as coordenadas x e y da visão em miniatura e a cor
// obtida. Se a posição atual estiver fora dos limites do mapa, a função
// desenha um pixel preto opaco na janela. Por fim, a função retorna.
void	cub_miniview(t_game *g)
{
	int	xy[2];
	int	aux[2];

	aux[1] = -1;
	xy[1] = (g->pl.y + 0.5) * SIZE - (int)(g->miniview.height / 2);
	while (++aux[1] < (g->miniview.height))
	{
		aux[0] = -1;
		xy[0] = (g->pl.x + 0.5) * SIZE - (int)(g->miniview.width / 2);
		while (++aux[0] < g->miniview.width)
		{
			if (xy[1] >= 0 && xy[1] < (g->height * SIZE) && xy[0] >= 0 \
						&& xy[0] < (g->width * SIZE))
				my_mlx_pixel_put(&g->miniview, aux[0], aux[1], \
					my_mlx_pixel_get(&g->minimap, xy[0], xy[1]));
			else
				my_mlx_pixel_put(&g->miniview, aux[0], aux[1], 0xFF000000);
			xy[0]++;
		}
		xy[1]++;
	}
}

// O código é uma função em C chamada get_mini_color que recebe três
// argumentos: g, que é um ponteiro para uma estrutura do tipo t_game;
// len, que é o comprimento da linha atual do mapa; e xy, que é um vetor
// com as coordenadas x e y da posição atual no minimapa. A função é
// responsável por obter a cor do minimapa para a posição atual. A
// função começa definindo a cor padrão como preto opaco. A função
// verifica se a posição atual está dentro dos limites do mapa e se
// contém um espaço em branco. Se a condição for verdadeira, a função
// atualiza a cor para preto opaco. A função verifica se a posição atual
// contém uma coleta de item 'c' e, se for, atualiza a cor para vermelho.
// A função verifica se a posição atual contém um inimigo 'o' e, se for,
// atualiza a cor para verde. A função verifica se a posição atual não
// contém uma parede '1' e, se for, atualiza a cor para cinza claro. Se a
// posição atual contiver uma parede '1', a função atualiza a cor para
// azul claro. Por fim, a função retorna a cor obtida.

int	get_mini_color(t_game *g, int len, int xy[2])
{
	int	color;

	color = 0xFF000000;
	if (xy[0] < len && g->map[xy[1]][xy[0]] == ' ')
		color = 0xFF000000;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] == 'c')
		color = 0x00FF0000;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] == 'o')
		color = 0x0000FF00;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] != '1')
		color = 0x005E5C64;
	else if (xy[0] < len)
		color = 0x008BB5F8;
	return (color);
}

// O código é uma função em C chamada cub_minimap que recebe um ponteiro g
// para uma estrutura do tipo t_game. A função é responsável por desenhar o
// minimapa do jogo na janela. A função começa definindo um vetor xy com as
// coordenadas x e y do minimapa. A função percorre as linhas do mapa com um
// loop while. Para cada linha, a função percorre as colunas do mapa com outro
// loop while. A função calcula o comprimento da linha com a função ft_strlen.
// A função chama a função get_mini_color para obter a cor do minimapa para a
// posição atual. A função desenha um retângulo na janela com a função
// my_mlx_area_put usando as coordenadas x e y do minimapa, o tamanho do
// retângulo e a cor obtida. Por fim, a função retorna.

void	cub_minimap(t_game *g)
{
	int	xy[2];
	int	len;

	xy[1] = -1;
	while (++xy[1] < g->height)
	{
		xy[0] = -1;
		len = ft_strlen(g->map[xy[1]]);
		while (++xy[0] < g->width)
			my_mlx_area_put(&g->minimap, \
				ft_newvector(xy[0] * SIZE, xy[1] * SIZE), \
				ft_newvector(SIZE, SIZE), get_mini_color(g, len, xy));
	}
}

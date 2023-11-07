/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:34:31 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada my_mlx_pixel_put que recebe
// quatro argumentos: data, que é um ponteiro para uma estrutura do
// tipo t_img, que representa a imagem; x, que é a coordenada x do pixel;
// y, que é a coordenada y do pixel; e color, que é a cor do pixel. A
// função é responsável por desenhar um pixel na posição especificada na
// imagem com a cor especificada. A função começa definindo um ponteiro
// dst para apontar para o endereço de memória do pixel na posição
// especificada na imagem. A função armazena a cor do pixel no endereço
// apontado por dst como um valor inteiro sem sinal de 32 bits. Por fim,
// a função retorna.

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

// O código é uma função em C chamada my_mlx_pixel_get que recebe
// três argumentos: data, que é um ponteiro para uma estrutura do tipo
// t_img, que representa a imagem; x, que é a coordenada x do pixel; e y,
// que é a coordenada y do pixel. A função é responsável por obter a cor
// do pixel na posição especificada na imagem. A função começa definindo
// um ponteiro dst para apontar para o endereço de memória do pixel na
// posição especificada na imagem. A função retorna o valor inteiro sem
// sinal armazenado no endereço apontado por dst.

unsigned int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

// O código é uma função em C chamada my_mlx_area_put que recebe
// quatro argumentos: d, que é um ponteiro para uma estrutura do
// tipo t_img, que representa a imagem de destino; p, que é um vetor
// com as coordenadas x e y da posição inicial do retângulo na imagem
// de destino; dim, que é um vetor com as dimensões x e y do retângulo;
// e c, que é a cor do retângulo. A função é responsável por desenhar
// um retângulo na imagem de destino com a cor especificada. A função
// começa definindo dois inteiros x e y para percorrer as linhas e
// colunas do retângulo, respectivamente. A função percorre as linhas do
// retângulo com um loop while. Para cada linha, a função percorre as
// colunas do retângulo com outro loop while. A função chama a função
// my_mlx_pixel_put para desenhar um pixel na imagem de destino com as
// coordenadas x e y do pixel atual e a cor especificada. Por fim, a
// função retorna.
void	my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < dim.y)
	{
		x = -1;
		while (++x < dim.x)
			my_mlx_pixel_put(d, p.x + x, p.y + y, c);
	}
}

// O código é uma função em C chamada mlx_img_to_img que recebe
// três argumentos: p, que é um vetor com as coordenadas x e y da
// posição inicial da imagem de origem na imagem de destino; img, que
// é um vetor com duas estruturas do tipo t_img, onde a primeira
// estrutura é a imagem de origem e a segunda é a imagem de destino;
// e c1, que é a cor de transparência da imagem de origem. A função é
// responsável por copiar a imagem de origem para a imagem de destino,
// ignorando os pixels com a cor de transparência. A função começa
// definindo um vetor xy com as coordenadas x e y do pixel atual na
// imagem de origem e um inteiro color para armazenar a cor do pixel
// atual. A função percorre as linhas da imagem de origem com um loop
// while. Para cada linha, a função percorre as colunas da imagem de
// origem com outro loop while. A função verifica se a posição atual
// está dentro dos limites da imagem de destino e, se for, obtém a cor
// do pixel atual na imagem de origem com a função my_mlx_pixel_get. A
// função verifica se a cor do pixel atual é diferente da cor de
// transparência e, se for, desenha o pixel na imagem de destino com a
// função my_mlx_pixel_put. Por fim, a função retorna.

void	mlx_img_to_img(int p[2], t_img img[2], int c1)
{
	int	xy[2];
	int	color;

	xy[1] = -1;
	while (++xy[1] < img[0].height)
	{
		xy[0] = -1;
		while (++xy[0] < img[0].width)
		{
			if (xy[0] + p[0] >= 0 && xy[1] + p[1] >= 0)
			{
				color = my_mlx_pixel_get(&img[0], xy[0], xy[1]);
				if (color != c1)
					my_mlx_pixel_put(&img[1], xy[0] + p[0], \
						xy[1] + p[1], color);
			}
		}
	}
}

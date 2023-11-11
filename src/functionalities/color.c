/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/11 19:05:38 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// O código é uma função em C chamada create_trgb que recebe 
// uma estrutura t_color como argumento. 
// A função cria um inteiro no formato trgb a partir da 
// estrutura t_color. A função começa deslocando 
// o valor de transparência da cor para a esquerda em 24 
// bits com a operação c.t << 24. Em seguida, a 
// função desloca o valor de vermelho da cor para a esquerda 
// em 16 bits com a operação c.r << 16. Depois, 
// a função desloca o valor de verde da cor para a esquerda em 
// 8 bits com a operação c.g << 8. Por fim, a 
// função retorna o inteiro criado com a operação |, que combina 
// os valores deslocados com a cor no formato trgb. 
int	create_trgb(t_color c)
{
	return (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
}

// O código é uma função em C chamada create_rgbt que recebe um inteiro col como
// argumento. A função cria uma estrutura t_color a partir do inteiro col. A
// função começa definindo a variável c como uma estrutura t_color. Em seguida,
// a função obtém o valor de transparência da cor com a operação col >> 24 &
// 0xFF. A função obtém os valores de vermelho, verde e azul da cor com as
// operações col >> 16 & 0xFF, col >> 8 & 0xFF e col & 0xFF, respectivamente.
// Por fim, a função retorna a estrutura t_color criada com os valores obtidos.

t_color	create_rgbt(int col)
{
	t_color	c;

	c.t = (col >> 24) & 0xFF;
	c.r = (col >> 16) & 0xFF;
	c.g = (col >> 8) & 0xFF;
	c.b = col & 0xFF;
	return (c);
}

// O código é uma função em C chamada cub_invert_color que recebe um
// ponteiro para uma estrutura do tipo t_game como argumento. A função inverte
// as cores da imagem da janela do jogo. A função começa com dois loops
// aninhados que percorrem cada pixel da imagem da janela. Para cada pixel, a
// função obtém a cor atual com a função my_mlx_pixel_get e inverte a cor
// subtraindo a cor atual de 0xFFFFFF. Em seguida, a função preenche o pixel com
// a nova cor invertida usando a função my_mlx_pixel_put. No final, a função
// inverte todas as cores da imagem da janela, criando um efeito de negativo.

void	cub_invert_color(t_game *g)
{
	int		xy[2];

	xy[1] = -1;
	while (++xy[1] < WIN_H)
	{
		xy[0] = -1;
		while (++xy[0] < WIN_W)
		{
			my_mlx_pixel_put(&g->win_img, xy[0], xy[1], 0xFFFFFF - \
				my_mlx_pixel_get(&g->win_img, xy[0], xy[1]));
		}
	}
}

// O código é uma função em C chamada get_dist_color que recebe três
// argumentos: color, que é a cor original; ds, que é a distância entre o
// jogador e o objeto; e tr, que é um valor booleano que indica se o objeto é
// uma transparência ou não. A função calcula a nova cor do objeto com base na
// distância entre o jogador e o objeto. A função começa verificando se a
// distância é menor que 0 e, se for, define a distância como 0. Em seguida, a
// função calcula a diferença entre a distância e 7.5 elevado a 1.14. A função
// cria uma estrutura t_color a partir da cor original com a função create_rgbt.
// Se o objeto for uma transparência, a função subtrai a diferença do valor de
// transparência da cor. Caso contrário, a função define o valor de
// transparência como 256. A função subtrai a diferença dos valores de
// vermelho, verde e azul da cor. Se algum valor for menor que 0, a função
// define o valor como 0. Por fim, a função retorna a nova cor do objeto em
// formato trgb com a função create_trgb.

int	get_dist_color(int color, float ds, int tr)
{
	t_color	c;
	float	dif;

	if (ds < 0)
		ds = 0;
	dif = powf(1.14, ds / 7.5);
	c = create_rgbt(color);
	if (tr)
		c.t -= dif;
	else
		c.t = 256;
	c.r -= dif;
	c.g -= dif;
	c.b -= dif;
	if (c. t < 0)
		c.t = 0;
	if (c.r < 0)
		c.r = 0;
	if (c.g < 0)
		c.g = 0;
	if (c.b < 0)
		c.b = 0;
	return (create_trgb(c));
}

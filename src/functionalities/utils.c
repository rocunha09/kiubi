/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/11 19:07:55 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// A função mlx_load_img em C recebe dois argumentos: ptr, um ponteiro para a
// biblioteca gráfica mlx, e path, uma string que representa o caminho do
// arquivo de imagem. A função carrega uma imagem do arquivo especificado e
// retorna uma estrutura t_img com as informações da imagem.
// A função começa definindo uma estrutura t_img e um ponteiro para a
// estrutura. Em seguida, verifica se o caminho do arquivo é nulo ou não
// termina com a extensão ".xpm". Se for o caso, retorna a estrutura t_img
// vazia.
// A função tenta abrir o arquivo de imagem com a função open e, se não
// conseguir abrir o arquivo, retorna a estrutura t_img vazia. A função
// fecha o arquivo com a função close.
// Em seguida, a função carrega a imagem do arquivo com a função
// mlx_xpm_file_to_image e define a largura e a altura da imagem na estrutura
// t_img. Obtém o endereço da imagem com a função mlx_get_data_addr e define
// o endereço na estrutura t_img.
// Por fim, a função retorna a estrutura t_img.
t_img	*mlx_load_img(void *ptr, char *path)
{
	int		fd;
	t_img	*i;

	i = malloc(sizeof(t_img));
	i->i = NULL;
	if (!path || ft_strrncmp(path, ".xpm", 4))
		return (i);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (i);
	close(fd);
	i->i = mlx_xpm_file_to_image(ptr, path, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->i, &i->bpp, &i->line_len, &i->endian);
	return (i);
}

// A função degree_to_radians em C recebe um float "degree" que representa um
// ângulo em graus. Ela é responsável por converter o ângulo de graus para
// radianos.
// A função começa multiplicando o ângulo em graus por "M_PI / 180", que é a
// constante que representa a conversão de graus para radianos.
// Em seguida, a função retorna o resultado da multiplicação, que é o ângulo em
// radianos.
float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

void	ft_free_matrix(char **m)
{
	int	i;

	i = 0;
	while (m[i] != NULL)
	{
		free(m[i]);
		m[i] = NULL;
		i++;
	}
	free(m);
}


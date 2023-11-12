/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 19:31:22 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* O código é uma função em C chamada get_coordinates que recebe três argumentos: 
map, que é um ponteiro para uma estrutura do tipo t_map; r_file, que é um vetor 
de strings representando o arquivo lido.

A função está analisando um arquivo de mapa para um jogo. Aqui está uma explicação 
passo a passo do que a função faz:

A função começa definindo algumas variáveis: range, i e j.

A função então chama find_coordinate_range(r_file) para determinar o intervalo de 
coordenadas no arquivo e armazena o resultado em range.

A variável map->flag é inicializada como 0. Isso pode ser usado mais tarde para 
verificar se ocorreram erros durante a leitura do arquivo.

A função então entra em um loop while, que continua enquanto i for menor que range 
e r_file[i] não for nulo.

Dentro do loop, se o primeiro caractere da linha atual for um espaço, a função 
avança para o próximo caractere que não é um espaço.

A função então verifica se o restante da linha contém uma coordenada válida. 
Se for uma coordenada válida, a função tenta preencher as coordenadas no mapa. 
Se não conseguir preencher as coordenadas, incrementa map->flag por 3.

Se a linha contém caracteres, mas não é uma coordenada válida e o caractere é 
imprimível, a função gera um erro indicando que encontrou uma string inválida no mapa.

O loop continua com a próxima linha do arquivo (incrementando i).

Após o loop, a função verifica se map->flag é diferente de MAX_FLAG. Se for, gera 
um erro indicando que o mapa é inválido.

A função então chama check_filled_coordinates(map) para verificar se todas as 
coordenadas foram preenchidas corretamente.

Finalmente, a função retorna 0, indicando que terminou com sucesso.

Por favor, note que a explicação acima é baseada em suposições sobre o propósito do 
código, já que o contexto completo não foi fornecido. */
int	get_coordinates(t_map *map, char **r_file)
{
	int	range;
	int	i;
	int	j;

	range = find_coordinate_range(r_file);
	i = 0;
	map->flag = 0;
	while (r_file[i] && i < range)
	{
		j = 0;
		if (r_file[i][j] == ' ' && j == 0)
			while (r_file[i][j] && is_space(r_file[i][j]))
				j++;
		if (is_coordinate(r_file[i] + j) && fill_coordinates(map, r_file, range, r_file[i] + j)){
				map->flag += 3;
			}
			else if (r_file[i][j] && !is_coordinate(r_file[i] + j) && (ft_isprint(r_file[i][j])))
				perror("Invalid map! Found a crazy string in the map!");
		i++;
	}
	
	if (map->flag != MAX_FLAG)
		perror("Invalid map! Check the documentation!");
	check_filled_coordinates(map);
	return (0);
}

static int	fill_coordinates(t_map *map, char **r_file, int range, char *str)
{
	if (!ft_strncmp("NO ", str, 3))
		map->c_no = find_string("NO ", r_file, range);
	else if (!ft_strncmp("SO ", str, 3))
		map->c_so = find_string("SO ", r_file, range);
	else if (!ft_strncmp("EA ", str, 3))
		map->c_ea = find_string("EA ", r_file, range);
	else if (!ft_strncmp("WE ", str, 3))
		map->c_we = find_string("WE ", r_file, range);
	else if (!ft_strncmp("C ", str, 2))
		map->ceiling = find_string("C ", r_file, range);
	else if (!ft_strncmp("F ", str, 2))
		map->floor = find_string("F ", r_file, range);
	else
		return (0);
	return (1);
}

static int	check_filled_coordinates(t_map *map)
{
	if (!map->c_no || !map->c_so || !map->c_ea || !map->c_we \
	|| !map->ceiling || !map->floor)
		perror("Invalid map! Read the rules!");
	return (0);
}

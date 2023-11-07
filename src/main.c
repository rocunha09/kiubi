/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/05 19:57:44 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


// O código é uma função em C chamada `init_sprites` que recebe um
// ponteiro para uma estrutura do tipo `t_game` como argumento. A função
// inicializa as variáveis relacionadas às texturas do jogo, definindo-as
// como NULL. Em seguida, a função carrega as texturas do jogo através da
// função `mlx_load_img` da biblioteca gráfica `mlx`. A textura preta é
// carregada do arquivo "textures/black.xpm" e a textura da mira é
// carregada do arquivo "textures/scope.xpm". A função `cub_perror` é
// chamada para verificar se as texturas foram carregadas corretamente.
// Se alguma textura não foi carregada corretamente, a função `cub_perror`
// é chamada com o erro `inv_pwd`, que indica que o arquivo de configuração
// do jogo é inválido.

// A struct t_game é usada para armazenar as informações do jogo. A função
// init_sprites inicializa alguns dos atributos da struct. Abaixo está a
// descrição de cada atributo:

// win_img.i: ponteiro para a imagem da janela do jogo.
// win_g.i: ponteiro para a imagem do jogo.
// win_r.i: ponteiro para a imagem da visão em miniatura do jogo.
// minimap.i: ponteiro para a imagem do minimapa do jogo.
// miniview.i: ponteiro para a imagem da visão em miniatura do jogo.
// tex.n: ponteiro para a imagem da textura da parede norte.
// tex.n_bak: ponteiro para a imagem da textura da parede norte backup.
// tex.s: ponteiro para a imagem da textura da parede sul.
// tex.s_bak: ponteiro para a imagem da textura da parede sul backup.
// tex.e: ponteiro para a imagem da textura da parede leste.
// tex.e_bak: ponteiro para a imagem da textura da parede leste backup.
// tex.w: ponteiro para a imagem da textura da parede oeste.
// tex.w_bak: ponteiro para a imagem da textura da parede oeste backup.
// tex.b: ponteiro para a imagem da textura da parede preta.
// scope: ponteiro para a imagem do retículo de mira.

// Esses atributos são usados para armazenar as imagens que serão usadas no
// jogo, como as texturas das paredes, a imagem da janela do jogo, a imagem
// da visão em miniatura do jogo, a imagem do minimapa do jogo e a imagem
// do retículo de mira.

void	init_sprites(t_game *g)
{
	g->win_img.i = NULL;
	g->win_g.i = NULL;
	g->win_r.i = NULL;
	g->minimap.i = NULL;
	g->miniview.i = NULL;
	g->tex.n = get_map_n();
	g->tex.n_bak = NULL;
	g->tex.s = get_map_s();
	g->tex.s_bak = NULL;
	g->tex.e = get_map_e();
	g->tex.e_bak = NULL;
	g->tex.w = get_map_w();
	g->tex.w_bak = NULL;
	g->tex.b = mlx_load_img(g->mlx_ptr, "assets/textures/black.xpm");
	g->scope = mlx_load_img(g->mlx_ptr, "assets/textures/scope.xpm");
	if (!g->tex.b || !g->tex.b->i || !g->scope || !g->scope->i)
		cub_perror(inv_pwd, g, NULL, 1);
}

// O código é uma função em C chamada cub_init que retorna uma estrutura
// do tipo t_game. A função inicializa todas as variáveis necessárias para
// rodar o jogo, como a largura e altura da janela, o número de frames por
// segundo, o mapa do jogo, a posição do jogador, a velocidade do jogador,
// as teclas pressionadas pelo jogador, entre outras. A função também
// inicializa a biblioteca gráfica mlx e as texturas do jogo através da
// função init_sprites. Além disso, a função define valores padrão para
// algumas variáveis, como a posição do jogador e a taxa de atualização do
// jogo. No final, a função retorna a estrutura t_game inicializada.

static t_game	cub_init(void)
{
	t_game	g;

	g.width = get_map_cols();
	g.fd = get_fd();
	g.height = get_map_rows();
	g.nframes = 0;
	g.map = get_map();
	g.pl.dir = get_player_direction();
	g.mlx_ptr = NULL;
	g.win_ptr = NULL;
	g.mlx_ptr = mlx_init();
	init_sprites(&g);
	g.tex.floor = get_floor_color();
	g.tex.ceiling = get_ceiling_color();
	g.pl.x = -1;
	g.pl.y = -1;
	g.pl.speed = 0.12;
	g.pl.door_cooldown = 0;
	ft_bzero(&g.pl.keys, sizeof(t_key));
	g.mouse_x = 0;
	g.neg = -1;
	g.rate = 30;
	return (g);
}

static void	start_validation(t_map *map)
{
	read_file_map(map);
	get_coordinates(map, map->r_file);
	call_validate_textures(map);
	validate_colors(map);
	get_mapping(map, map->r_file);
	set_map_cols(biggest_string(map->r_map + 3));
	create_map(matrix_size(map->r_map), biggest_string(map->r_map + 3));
	//biggest_string(map->r_map);
	call_clean_spaces(map);
	if (check_closed_map(map->r_map))
		perror("O mapa não está fechado!");
	if (!check_valid_map(map->r_map, map->data, 0, 0))
		set_map(map->r_map);
	find_directions(map->data, map, 0, 0);
}

static void	exec_validation(int argc, char **argv)
{
	t_img	cube;
	t_map	map;
	t_data	data;

	map.mlx = &cube;
	map.data = &data;
	if (argc == 2 && !check_valid_file(&map, argv[1], ".cub"))
	{
		start_validation(&map);
	}
}

int	main(int argc, char **argv)
{
	t_game	g;

	exec_validation(argc, argv);
	g = cub_init();
	game_init(&g);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 21:07:58 by llima-da         ###   ########.fr       */
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
	//printf("win_img.i: %p\n", g->win_img.i);
	g->win_g.i = NULL;
	//printf("win_g.i: %p\n", g->win_g.i);
	g->win_r.i = NULL;
	//printf("win_r.i: %p\n", g->win_r.i);
	g->minimap.i = NULL;
	//printf("minimap.i: %p\n", g->minimap.i);
	g->miniview.i = NULL;
	//printf("miniview.i: %p\n", g->miniview.i);
	g->tex.n = get_map_n();
	//printf("tex.n: %p\n", g->tex.n);
	g->tex.n_bak = NULL;
	//printf("tex.n_bak: %p\n", g->tex.n_bak);
	g->tex.s = get_map_s();
	//printf("tex.s: %p\n", g->tex.s);
	g->tex.s_bak = NULL;
	//printf("tex.s_bak: %p\n", g->tex.s_bak);
	g->tex.e = get_map_e();
	//printf("tex.e: %p\n", g->tex.e);
	g->tex.e_bak = NULL;
	//printf("tex.e_bak: %p\n", g->tex.e_bak);
	g->tex.w = get_map_w();
	//printf("tex.w: %p\n", g->tex.w);
	g->tex.w_bak = NULL;
	//printf("tex.w_bak: %p\n", g->tex.w_bak);
	g->tex.b = mlx_load_img(g->mlx_ptr, "assets/textures/black.xpm");
	//printf("tex.b: %p\n", g->tex.b);
	//printf("tex.b->i: %p\n", g->tex.b->i);
	g->scope = mlx_load_img(g->mlx_ptr, "assets/textures/scope.xpm");
	//printf("scope: %p\n", g->scope);
	//printf("scope->i: %p\n", g->scope->i);
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
	//printf("width: %d\n", g.width);
	g.fd = get_fd();
	//printf("fd: %d\n", g.fd);
	g.height = get_map_rows();
	//printf("height: %d\n", g.height);
	g.nframes = 0;
	//printf("nframes: %ld\n", g.nframes);
	g.map = get_map();
	int i = 0;
	while (g.map[i] != NULL)
	{
		printf("%s\n", g.map[i]);
		i++;
	}
	
	//printf("map: %s\n", g.map);
	g.pl.dir = get_player_direction();
	//printf("pl.dir: %c\n", g.pl.dir);
	g.mlx_ptr = NULL;
	g.win_ptr = NULL;
	g.mlx_ptr = mlx_init();
	//printf("mlx_ptr: %p\n", g.mlx_ptr);
	init_sprites(&g);
	//printf("luciano2\n");
	g.tex.floor = get_floor_color();
	//printf("floor: %i\n", g.tex.floor);
	g.tex.ceiling = get_ceiling_color();
	//printf("ceiling: %i\n", g.tex.ceiling);
	g.pl.x = -1;
	//printf("pl.x: %f\n", g.pl.x);
	g.pl.y = -1;
	//printf("pl.y: %f\n", g.pl.y);
	g.pl.speed = 0.12;
	//printf("pl.speed: %f\n", g.pl.speed);
	g.pl.door_cooldown = 0;
	//printf("pl.door_cooldown: %d\n", g.pl.door_cooldown);
	ft_bzero(&g.pl.keys, sizeof(t_key));
	//printf("pl.keys: %d\n", g.pl.keys);
	g.mouse_x = 0;
	//printf("mouse_x: %d\n", g.mouse_x);
	g.neg = -1;
	//printf("neg: %d\n", g.neg);
	g.rate = 30;
	//printf("rate: %d\n", g.rate);
	return (g);
}

static void	init_map(t_map *map)
{
	map->r_file = NULL;
	map->c_ea = NULL;
	map->c_no = NULL;
	map->c_so = NULL;
	map->ceiling = NULL;
	map->floor = NULL;
	map->r_map = NULL;
	map->flag = 0;
	map->data->c_red = 0;
	map->data->c_green = 0;
	map->data->c_blue = 0;
	map->data->f_red = 0;
	map->data->f_green = 0;
	map->data->f_blue = 0;
}

static void	start_validation(t_map *map)
{
	init_map(map);
	read_file_map(map);
	get_coordinates(map, map->r_file);
	call_validate_textures(map);
	//printf("passou 1\n");
	validate_colors(map);
	//printf("passou 2\n");
	get_mapping(map, map->r_file);
	//printf("passou 3\n");
	set_map_cols(biggest_string(map->r_map + 3));
	//printf("passou 4\n");
	create_map(matrix_size(map->r_map), biggest_string(map->r_map + 3));
	//printf("passou 5\n");
	close_map(map);
	call_clean_spaces(map);
	//printf("passou 6\n");
	if (check_closed_map(map->r_map))
		perror("O mapa não está fechado!");
	//printf("passou 7\n");
	if (check_valid_map(map->r_map, map->data, 0, 0))
		perror("O mapa não é válido!");
		//set_map(map->r_map);
	//printf("passou 8\n");
	find_directions(map->data, map, 0, 0);
	//printf("passou 9\n");
}

static void	exec_validation(int argc, char **argv)
{
	t_img	cube;
	t_map	map;
	t_data	data;

	cube.map = &map;
	map.mlx = &cube;
	map.data = &data;
	if (argc == 2 && !check_valid_file(&map, argv[1], ".cub"))
	{
		start_validation(&map);
	}
}

static void end_reality_simulated()
{
	ft_print_str("[destroy map N]\n");
	destroy_map_n(get_map_n());
	ft_print_str("[destroy map S]\n");
	destroy_map_s(get_map_s());
	ft_print_str("[destroy map E]\n");
	destroy_map_e(get_map_e());
	ft_print_str("[destroy map W]\n");
	destroy_map_w(get_map_w());
}

int	main(int argc, char **argv)
{
	t_game	g;

	exec_validation(argc, argv);
	g = cub_init();
	game_init(&g);
	end_reality_simulated();
	return (0);
}
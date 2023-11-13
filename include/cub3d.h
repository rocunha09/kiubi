/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 20:59:52 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../vendor/get_next_line/get_next_line.h"
# include "../vendor/libft/libft.h"
# include "../vendor/miniLibX/mlx.h"
# include "../vendor/miniLibX/mlx_int.h"
# include "adapter.h"
# include "keycodes.h"
# include "my_mlx.h"
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef WIN_H
#  define WIN_H 480
# endif

# ifndef WIN_W
#  define WIN_W 640
# endif

# ifndef SIZE
#  define SIZE 7
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef MAX_FLAG
#  define MAX_FLAG 18
# endif

/* Enum to handle various exit/error messages */
typedef enum e_cub_err
{
	end,
	inv_argc,
	inv_ext,
	inv_file,
	empty_file,
	no_memory,
	inv_color,
	inv_wall,
	inv_map,
	inv_charac,
	inv_player,
	inv_tex,
	inv_pwd
}					t_cub_err;

/* Struct to handle rgb colors with transparency */
typedef struct s_color
{
	long			t;
	long			r;
	long			g;
	long			b;
}					t_color;

/* Every image corresponding to a wall texture, plus floor and ceiling */
typedef struct s_tex
{
	t_list			*n;
	t_list			*n_bak;
	t_list			*s;
	t_list			*s_bak;
	t_list			*w;
	t_list			*w_bak;
	t_list			*e;
	t_list			*e_bak;
	t_img			*b;
	int				floor;
	int				ceiling;
}					t_tex;

/* Struct to check when keys are pressed */
typedef struct s_key
{
	int				w_pressed;
	int				a_pressed;
	int				s_pressed;
	int				d_pressed;
	int				left_pressed;
	int				right_pressed;
}					t_key;

/* Struct to store various attributes of our player */
typedef struct s_player
{
	float			x;
	float			y;
	char			dir;
	float			speed;
	int				door_cooldown;
	t_key			keys;
}					t_player;

/* Struct to store all ray-casting-related data */
typedef struct s_ray
{
	float			incre_angle;
	float			angle;
	float			cos;
	float			sin;
	float			hfov;
	float			lim;
	int				precision;
}					t_ray;

/* Handles most game attributes */
typedef struct s_game
{
	int				fd;
	char			**entry_map;
	char			**map;
	int				height;
	int				width;
	int				mouse_x;
	int				rate;
	int				neg;
	long			nframes;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			win_img;
	t_img			win_g;
	t_img			win_r;
	t_img			minimap;
	t_img			miniview;
	t_img			*scope;
	t_tex			tex;
	t_ray			ray;
	t_player		pl;
	float			x;
	float			y;
}					t_game;

/*		| ESTRUTURA PARA VALIDAÇÃO DO MAPA |		*/
typedef struct s_map
{
	struct s_mlx	*mlx;
	struct s_data	*data;
	char			*file;
	int				fd;
	char			**r_file;
	char			**r_map;
	char			*ceiling;
	char			*floor;
	char			*c_no;
	char			*c_so;
	char			*c_we;
	char			*c_ea;
	int				flag;
	int				map_size;
	int				biggest_line;
}					t_map;

typedef struct s_data
{
	struct s_map	*map;
	int				c_red;
	int				c_green;
	int				c_blue;
	int				f_red;
	int				f_green;
	int				f_blue;
	int				p_x;
	int				p_y;
	int				d_x;
	int				d_y;
	int				plane_y;
	int				plane_x;
}					t_data;


/* Retrieves next line from a given fd */
/* char	*get_next_line(int fd); */

/* Prints appropriate error message and exits, freeing everything */
int					cub_perror(t_cub_err err, t_game *g, char *param, int c);


/* Function called by mlx when exiting */
int					cub_exit(void *param);

/* Drecreases RGB value of color as object gets further */
int					get_dist_color(int color, float ds, int tr);

/* Frees all necessary things before exiting */
void				cub_end(t_game *g);

/* Initializes game */
void				game_init(t_game *g);

/* Draws game */
void				draw_game(t_game *g);

/* Initialize raycast data */
void				init_ray(t_game *g);

/* Converts degrees to radians */
float				degree_to_radians(float degree);

/* Draws a 2D minimap */
void				cub_minimap(t_game *g);

/* Draws a section of the 2D minimap */
void				cub_miniview(t_game *g);

/* Function to shoot rays in a given direction to find walls */
void				cub_raycast(t_game *g);

/* Function called inside mlx loop */
int					cub_update(void *param);


/* Check every element of the map: spaces + characters */
void				check_elements(t_game *g);

/* Draws 3D view on window-sized image */
void				cub_draw(t_game *g, int ray_count, float dis);

/* Checks which wall has been hit to choose proper texture */
t_img				*get_texture(t_game *g);

/* Moves player depending on which key was pressed */
void				move_pl(int k, t_game *g, float ray_cos, float ray_sin);

/* Checks player surroundings to open/close doors */
void				action_door(t_game *g);

/* Inverts color of window-sized image */
void				cub_invert_color(t_game *g);

/* Adds spaces to end of all lines to ensure all lines have the same width */
char				**square_map(t_game *g);

void				ft_free_matrix(char **m);



t_vector			ft_newvector(int x, int y);

t_color				parser_mat_to_trgb(int *new_floor_color_rgb);

int					check_front(char *str, char c);

int					check_back(char *str, char c);

int					check_up(char *up, char *str, char c);

static int			fill_coordinates(t_map *map, char **r_file, int range,
						char *str);

static int			check_filled_coordinates(t_map *map);

int					check_extension(char *str, char *ext, int n);

int					get_mapping(t_map *map, char **r_file);

int					check_valid_file(t_map *map, char *str, char *ext);
int					read_file_map(t_map *map);
int					get_coordinates(t_map *map, char **r_file);
int					find_coordinate_range(char **r_file);
int					validate_textures(char *str, t_map *map);
int					call_validate_textures(t_map *map);
int					is_coordinate(char *str);
int					validate_colors(t_map *map);
int					get_colors(char *color);
char				**close_map(t_map *map);
char				*fill_char(char c, int len);
char				*clean_spaces(char *str, int len, char c);
void				call_clean_spaces(t_map *map);
int					check_closed_map(char **r_map);
int					check_valid_map(char **map, t_data *data, int flag, int i);
int					matrix_size(char **matrix);
int					is_space(char c);
int					biggest_string(char **str);
int					find_directions(t_data *data, t_map *map, int i, int j);
char				**double_split(char *s, char c1, char c2);
char				*ft_strjoin2(char *s1, char *s2);
char				*ft_strjoin3(char const *s1, char const *s2);
int					clean_map(t_map *map);
char				*find_string(char *str, char **r_file, int range);
int					create_trgb(t_color c);
#endif

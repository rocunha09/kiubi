/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/12 20:20:08 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADAPTER_H
# define ADAPTER_H

char	get_player_direction(void);
void	set_player_direction(char new_direction);

int		get_floor_color(void);
void	set_floor_color(int new_floor_color);
void	set_floor_color_by_rgb(char **new_rgb);

int		*get_floor_color_rgb(void);
void	set_floor_color_rgb(int *new_floor_color_rgb);

int		*create_color_rgb(int qnt_types);
void	destroy_color_rgb(const char *entity);

int		get_ceiling_color(void);
void	set_ceiling_color(int new_ceiling_color);
void	set_ceiling_color_by_rgb(char **new_rgb);
int		*get_ceiling_color_rgb(void);
void	set_ceiling_color_rgb(int *new_ceiling_color_rgb);

int		get_fd(void);
void	set_fd(int new_fd);

char	**get_map(void);
void	set_map(char **new_map);
int		get_map_rows(void);
void	set_map_rows(int new_map_rows);
int		get_map_cols(void);
void	set_map_cols(int new_map_cols);
char	**create_map(int rows, int columns);
void	destroy_map(void);

t_list	*get_map_n(void);
void	set_map_n(char *new_map_n);
void	destroy_map_n(t_list	*map_n);

t_list	*get_map_e(void);
void	set_map_e(char *new_map_e);
void	destroy_map_e(t_list	*map_e);

t_list	*get_map_s(void);
void	set_map_s(char *new_map_s);
void	destroy_map_s(t_list	*map_s);

t_list	*get_map_w(void);
void	set_map_w(char *new_map_w);
void	destroy_map_w(t_list	*map_w);

#endif
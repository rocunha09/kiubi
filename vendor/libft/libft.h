/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-da <llima-da @student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/03 17:33:31 by llima-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	int				content_type;
	int				position_on_input;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isdot(int c);
int		ft_is_signal(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		special_chars(char c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *havstack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strdup_space(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_epur_str(char *content);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newnode);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list *lst, void (*del)(void *));
char	sub_ft_ul_parse_to_hexa(unsigned long nbr);
char	*ft_ul_parse_to_hexa(unsigned long nbr);
char	*ft_ul_parse_to_str(unsigned long nbr);
int		ft_ul_number_len(unsigned long nb);
int		ft_put_pointer(long long unsigned int p);
int		ft_put_number(int nbr);
int		ft_put_u_number(unsigned int nbr);
int		ft_put_hex(unsigned int nbr);
int		ft_put_toupper_hex(unsigned long nbr);
int		ft_print_char(int ch);
int		ft_print_str(char *s);
int		print_arg(char c, va_list list);
int		ft_printf(const char *str, ...);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
int		ft_str_indexof(char *big, char *little, size_t n);
char	*ft_chr_to_str(int c, size_t qtd);
void	ft_free_ptr(void **ptr);
char	*ft_str_replace(char *str, char *search, char *replace);
char	*ft_str_replace_all(char *str, char *search, char *replace);
char	*ft_super_replace_all(char *str, int n, ...);
void	ft_mtx_free(void **matrix);
void	ft_chr_remove_all(char *s, char c);

#endif

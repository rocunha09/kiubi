#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        :::      ::::::::   */
#/*   Makefile                                           :+:      :+:    :+:   */
#/*                                                    +:+ +:+         +:+     */
#/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
#/*                                                +#+#+#+#+#+   +#+           */
#/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
#/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
#/*                                                                            */
#/* ************************************************************************** */

# Nome do arquivo de saída da biblioteca
NAME = libgnl.a

# Lista de arquivos fonte
SRCS = get_next_line.c get_next_line_utils.c

# Lista de arquivos de cabeçalho
HEADERS = get_next_line.h get_next_line_bonus.h

# Lista de objetos a serem gerados
OBJS = $(SRCS:.c=.o)

# Compilador e opções
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regras
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

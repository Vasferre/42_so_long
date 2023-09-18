# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 17:06:25 by vasferre          #+#    #+#              #
#    Updated: 2023/06/30 21:38:28 by vasferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -Wall -Wextra -Werror
RM = rm -rf
MLXFLAGS = -L ./libs/mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libs/libft/libft.a

SRCS = ./srcs/destroymlx.c ./srcs/map_checker.c ./srcs/mperror.c ./srcs/player.c \
       ./srcs/readmap.c ./srcs/so_long.c ./srcs/tileschecker.c ./srcs/hooks.c ./srcs/init_mlx.c \
	   ./srcs/path.c
	   
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) --no-print-directory -C ./libs/mlx
	$(MAKE) --no-print-directory -C ./libs/libft
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT:

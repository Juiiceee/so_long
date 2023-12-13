# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:57:01 by lbehr             #+#    #+#              #
#    Updated: 2023/12/13 13:41:30 by lbehr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= bin/so_long
SRC_DIR		:= src
OBJ_DIR		:= obj
SRCS		:= allprint.c main.c eventmouvement.c get_next_line.c graphique.c map.c mapcheckentity.c printhex.c printptr.c texture.c event.c ft_printf.c get_next_line_utils.c graphiqueutils.c mapcheck.c map_utils.c printint.c  printstr.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			:= cc
MINI		:= -lX11 -lXext Include/minilibx-linux/libmlx_Linux.a
CFLAGS		:= -Wall -Wextra -Werror
MLX_PATH	:= Include/minilibx-linux
RM			:= rm -rf
DIR_DUP     = mkdir -p $(@D)

all		:	$(MLX_PATH) $(NAME)

$(MLX_PATH):
	git clone git@github.com:42Paris/minilibx-linux.git Include/minilibx-linux; \

$(NAME)	:	$(OBJS)
	make -C $(MLX_PATH) --no-print-directory
	$(CC) $(OBJS) $(MINI) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) -c $< $(CFLAGS) -o $@

clean	:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(MLX_PATH)
	$(RM) $(NAME)

re		:	fclean $(MLX_PATH) all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:57:01 by lbehr             #+#    #+#              #
#    Updated: 2023/12/14 14:54:34 by lbehr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= bin/so_long
SRC_DIR		:= src
OBJ_DIR		:= obj
SRCS		:= allprint.c main.c checkpath.c eventmouvement.c get_next_line.c graphique.c map.c mapcheckentity.c printhex.c printptr.c texture.c event.c ft_printf.c get_next_line_utils.c graphiqueutils.c mapcheck.c map_utils.c printint.c  printstr.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			:= cc
NORM		:= norminette $(SRC_DIR)/*.c Include/*.h 
MINI		:= -lX11 -lXext Include/minilibx-linux/libmlx_Linux.a
CFLAGS		:= -Wall -Wextra -Werror
MLX_PATH	:= Include/minilibx-linux
RM			:= rm -rf
DIR_DUP     = mkdir -p $(@D)

all		:	norm $(MLX_PATH) $(NAME)

$(MLX_PATH):
	git clone git@github.com:42Paris/minilibx-linux.git Include/minilibx-linux;

norm	:
	$(NORM)
	@sleep 5

$(NAME)	:	$(OBJS)
	$(DIR_DUP)
	make -C $(MLX_PATH) --no-print-directory
	$(CC) $(OBJS) $(MINI) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) -c $< $(CFLAGS) -o $@

clean	:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)
	
ffclean	:	fclean
	$(RM) $(MLX_PATH)
	$(RM) bin

re		:	fclean all

rall	:	ffclean all

.PHONY: all clean fclean ffclean re rall
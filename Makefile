# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:57:01 by lbehr             #+#    #+#              #
#    Updated: 2023/12/12 16:38:19 by lbehr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
SRC_DIR		:= src
OBJ_DIR		:= obj
SRCS		:= allprint.c eventmouvement.c get_next_line.c graphique.c map.c mapcheckentity.c printhex.c printptr.c texture.cevent.c ft_printf.c get_next_line_utils.c graphiqueutils.c mapcheck.c map_utils.c printint.c  printstr.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			:= cc
MINI		:= Include/minilibx-linux/libmlx_Linux.a
CFLAGS		:= -lX11 -lXext -Wall -Wextra -Werror
RM			:= rm -f
DIR_DUP     = mkdir -p $(@D)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) -c $(MINI) $@ $(CFLAGS) -o $<

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY: all clean fclean re
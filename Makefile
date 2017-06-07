# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 11:36:26 by agrumbac          #+#    #+#              #
#    Updated: 2017/06/07 16:31:08 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c fractol_keys.c fractol_brush.c fractol_mouse.c \
	fractal_julia.c fractal_mandelbrot.c

OBJDIR = objs

CFLAGS = -Wall -Wextra -Werror -g

DEP = libft/includes/libft.h fractol.h

CC = clang #/Users/agrumbac/.brew/bin/gcc-7

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

LIB = -Llibft -lft -Lminilibx_macos/ -lmlx

INCL = -Ilibft/includes -I. -Iminilibx_macos/

FRAMEWORKS = -framework OpenGL -framework AppKit

BY = "\033[33;1m"
BR = "\033[31;1m"
BG = "\033[32;1m"
BB = "\033[34;1m"
BM = "\033[35;1m"
BC = "\033[36;1m"
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
W = "\033[34;5m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: libft ${NAME}
	@echo ${G}Success"   "[${NAME}]${X}

libft: art
	@make -C libft/
	@make -C minilibx_macos/

${NAME}: ${OBJ}
	@echo ${B}Compiling [${NAME}]...${X}
	@${CC} ${CFLAGS} ${LIB} ${INCL} ${FRAMEWORKS} -o $@ ${OBJ}

${OBJDIR}/%.o: ./srcs/%.c ${DEP}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} ${INCL} -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning"  "[mlx objs]...${X}
	@make -C minilibx_macos/ clean
	@echo ${R}Cleaning"  "[libft objs]...${X}
	@make -C libft/ clean
	@echo ${R}Cleaning"  "[objs]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@make -C libft/ fclean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}

test:
	@${CC} ${INCL} ${FRAMEWORKS} -g -fsanitize=address ${LIB} -o ${NAME} \
	$(addprefix srcs/, ${SRC})

debug: test
	lldb ./${NAME}

build: ${OBJ}

re: fclean all

art:
	@echo ${BG}"                       __/\\__"
	@echo "                       \\    /"
	@echo "                 __/\\__/    \\__/\\__"
	@echo "                 \\                /"
	@echo "                 /__            __\\"
	@echo "                    \\          /"
	@echo "      __/\\__      __/          \\__      __/\\__"
	@echo "      \\    /      \\              /      \\    /"
	@echo "__/\\__/    \\__/\\__/              \\__/\\__/    \\__/\\__"
	@echo ${W}"              ___             __       __"
	@echo "             / _/______ _____/ /____  / /"
	@echo "            / _/ __/ _ \`/ __/ __/ _ \\/ / "
	@echo "           /_//_/  \\_,_/\\__/\\__/\\___/_/"
	@echo ${X}${BG}""
	@echo "----------------------------------------------------"${X}

.PHONY: all clean fclean re test art build debug

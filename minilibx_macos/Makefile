#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

.SILENT:

all: $(NOM)
	@echo ${G}Success"   "[${NOM}]${X}

$(NOM):	$(OBJ)
	@echo ${B}Compiling [${NOM}]...${X}
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all

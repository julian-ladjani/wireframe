##
## Makefile for makefile in /home/julian-ladjani/delivery/PSU/my_printf
##
## Made by julian ladjani
## Login   <julian.ladjani@epitech.net>
##
## Started on  Mon Nov  7 16:31:28 2016 julian ladjani
## Last update Jun Dec 9 14:27:29 2016 Julian Ladjani
##

CC 		=	gcc -g

SRC		=	src/my_draw_line.c				\
			src/my_put_pixel.c				\
			src/window/windows.c				\
			src/my_parallel_projection.c			\
			src/parseur/parseur.c				\
			src/parseur/parseur2.c				\
			src/wireframe.c					\
			src/wireframe_foncs.c				\
			src/calc/calc.c					\

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS		=	-I./include/ -Werror

LIBDIR		=	./lib/

NAME 		=	wireframe

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -lc_graph_prog -lm -L$(LIBDIR) -lmy

clean:
			$(RM) $(OBJ)
			$(RM) *~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

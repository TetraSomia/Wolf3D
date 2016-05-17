##
## Makefile for wolf3d in /home/josso_a/rendu/info/gfx_wolf3d
## 
## Made by Tetra
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Thu Dec  3 18:17:06 2015 Tetra
## Last update Wed Dec  9 19:16:38 2015 Tetra
##

NAME    = 	wolf3d

CC	= 	gcc

INC     =       ./include/

CFLAGS 	=	-I/home/${USER}/.froot/include/ \
		-L/home/${USER}/.froot/lib/ \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
		-lsfml-system -lstdc++ -ldl -lm \
		-I$(INC) \
		-W -Wall -Werror -ansi -pedantic

SRC	= 	src/main.c \
		src/wolf.c \
		src/default_map.c \
		src/move.c \
		src/lib.c \
		src/get_data.c \
		src/wall_color.c \
		src/get_var.c \
		src/err.c \
		tcore/tekpixel.c \
		tcore/vecnorm.c \
		tcore/go.c

OBJ	= 	$(SRC:.c=.o)

RM	= 	rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) 

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

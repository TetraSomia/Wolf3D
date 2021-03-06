##
## Makefile for wolf3d in /home/josso_a/rendu/info/gfx_wolf3d
## 
## Made by Tetra
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Thu Dec  3 18:17:06 2015 Tetra
## Last update Sat Dec 12 20:46:57 2015 Tetra
##

NAME    = 	wolf3d

CC	= 	gcc

INC     =       -I./include/ -I./liblapin/include/

LDFLAGS	+=	-L./liblapin -llapin \
                -lsfml-audio -lsfml-graphics \
                -lsfml-window -lsfml-system \
                -lstdc++ -ldl -lm

CFLAGS	+=	$(INC) \
		-W -Wall -Wextra

SRC	= 	src/main.c \
		src/wolf.c \
		src/default_map.c \
		src/move.c \
		src/lib.c \
		src/get_data.c \
		src/wall_color.c \
		src/get_var.c \
		src/err.c \
		src/load_bmp.c \
		src/tekgetpixel.c \
		src/sprite.c \
		tcore/tekpixel.c \
		tcore/vecnorm.c \
		tcore/go.c

OBJ	= 	$(SRC:.c=.o)

RM	= 	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

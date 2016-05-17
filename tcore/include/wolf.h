/*
** wolf.h for wolf3d in /home/josso_a/rendu/info/gfx_wolf3d
** 
** Made by Tetra
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Dec  3 18:28:54 2015 Tetra
** Last update Fri Dec 11 18:34:14 2015 Tetra
*/

#ifndef WOLF_H_
# define WOLF_H_

#include <lapin.h>

#define W_Y (768)
#define W_Y2 (W_Y / 2)
#define W_X (1024)
#define SEG (0.5)
#define D (1)
#define MOVE (0.02)
#define ROT (1)
#define RAD(deg) (deg * M_PI / 180)

typedef struct s_cols
{
  t_color sky;
  t_color wall;
  t_color ground;
}t_cols;

typedef struct s_me
{
  float x;
  float y;
  int	a;
} t_me;

typedef struct s_map
{
  int height;
  int width;
  char **map;
} t_map;

typedef struct s_win
{
  t_bunny_window *win;
  t_bunny_pixelarray *array;
  struct s_me me;
  struct s_map map;
  struct s_cols cols;
} t_win;

/*
** wolf.c
*/

int	draw_wall(t_win *win);

/*
** tekpixel.c
*/

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *p,
		 t_color *c);

/*
** default_map.c
*/

int	set_def_map(t_win *win);
void	set_moves(t_me *me);
void    free_map(t_map *map);

/*
** move.c
*/

typedef enum	e_move
  {
    FORWARD	= 0,
    BACKWARD	= 1,
    LEFT	= 2,
    RIGHT	= 3
  }		t_move;

void    move(t_win *win, char move);
void	go_left(t_win *win);
void	go_right(t_win *win);

/*
** get_data.c
*/

int	set_data(const char *path,
		 const char *scope,
		 t_win *win);

/*
** lib.c
*/

void    my_putstr(char *s);
int     my_strlen(const char *str);
int     my_strcmp(const char *s1, const char *s2);
int     my_getnbr(const char *str);

/*
** get_var.c
*/

void    set_xy(t_win *win, float *x1, float *y1, float x);
float   get_k(float a, float a0, float va);
int     get_x(t_win *win, float k, float va, float a0);
int     get_y(t_win *win, float k, float va, float a0);

/*
** wall_color.c
*/

void    set_wall_color(t_win *win, float k);
void    set_cols(t_win *win);

/*
** err.c
*/

int     err(char *s);
int	check(t_win *win);

#endif

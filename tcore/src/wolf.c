/*
** wolf.c for wolf3d in /home/josso_a/rendu/info/gfx_wolf3d
** 
** Made by Tetra
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Dec  3 20:40:00 2015 Tetra
** Last update Wed Dec  9 19:33:19 2015 Tetra
*/

#include <math.h>
#include "wolf.h"

void	test_x(t_win *win, float vx, float vy, float *k_min)
{
  int	i;
  int   back;
  float k;
  int   y;

  i = 0;
  while (vx != 0 && i < win->map.width)
    {
      back = 0;
      k = get_k(i, win->me.x, vx);
      y = get_y(win, k, vy, win->me.y);
      if (win->me.x >= i)
	back = 1;
      if (y != -1 && i - back != -1 && win->map.map[(int)i - back][y] == '1'
	  && k >= 0 && k < *k_min)
	*k_min = k;
      i++;
    }
}

void    test_y(t_win *win, float vx, float vy, float *k_min)
{
  int   i;
  int   back;
  float k;
  int   x;

  i = 0;
  while (vy != 0 && i < win->map.height)
    {
      back = 0;
      k = get_k(i, win->me.y, vy);
      x = get_x(win, k, vx, win->me.x);
      if (win->me.y >= i)
	back = 1;
      if (x != -1 && i - back != -1 && win->map.map[x][(int)i - back] == '1'
	  && k >= 0 && k < *k_min)
	*k_min = k;
      i++;
    }
}

float	set_k(t_win *win, float vx, float vy)
{
  float k_min;

  k_min = win->map.height + win->map.width;
  test_x(win, vx, vy, &k_min);
  test_y(win, vx, vy, &k_min);
  return (k_min);
}

void	wall_gen(t_win *win, t_bunny_position *pos, float k)
{
  if (pos->y < (W_Y2) - k)
    tekpixel(win->array, pos, &win->cols.sky);
  else if ((W_Y2) - k <=  pos->y && pos->y <= (W_Y2) + k)
    tekpixel(win->array, pos, &win->cols.wall);
  else
    tekpixel(win->array, pos, &win->cols.ground);
  pos->y++;
}

int	draw_wall(t_win *win)
{
  t_bunny_position	pos;
  float	vx;
  float	vy;
  float	k;

  pos.x = 0;
  while (pos.x < W_X)
    {
      set_xy(win, &vx, &vy, pos.x);
      k = set_k(win, vx, vy);
      k *= sqrt(vx * vx + vy * vy);
      k = W_Y / k;
      set_wall_color(win, k);
      k /= 2;
      pos.y = 0;
      while (pos.y < W_Y)
	wall_gen(win, &pos, k);
      pos.x++;
    }
  return (0);
}

/*
** wall_color.c for wolf in /home/josso_a/rendu/info/gfx_wolf3d
** 
** Made by Tetra
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Dec  7 19:45:21 2015 Tetra
** Last update Fri Dec 11 18:33:29 2015 Tetra
*/

#include "wolf.h"

void    set_cols(t_win *win)
{
  win->cols.sky.argb[RED_CMP] = 0;
  win->cols.sky.argb[GREEN_CMP] = 191;
  win->cols.sky.argb[BLUE_CMP] = 255;
  win->cols.sky.argb[ALPHA_CMP] = 255;
  win->cols.ground.argb[RED_CMP] = 70;
  win->cols.ground.argb[GREEN_CMP] = 70;
  win->cols.ground.argb[BLUE_CMP] = 70;
  win->cols.ground.argb[ALPHA_CMP] = 255;
}

void    set_wall_color(t_win *win, float k)
{
  unsigned char col;

  if (k <= W_Y)
    col = (k * 200) / W_Y + 55;
  else
    col = 255;
  win->cols.wall.argb[RED_CMP] = col;
  win->cols.wall.argb[BLUE_CMP] = col;
  win->cols.wall.argb[GREEN_CMP] = col;
  win->cols.wall.argb[ALPHA_CMP] = 255;
}

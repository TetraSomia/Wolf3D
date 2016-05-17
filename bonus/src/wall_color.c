/*
** wall_color.c for wolf in /home/josso_a/rendu/info/gfx_wolf3d
** 
** Made by Tetra
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Dec  7 19:45:21 2015 Tetra
** Last update Fri Dec 25 17:49:17 2015 Tetra
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

void	put_in_black(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		col;

  pos.x = 0;
  col.full = BLACK;
  col.argb[ALPHA_CMP] = 0;
  while (pos.x < pix->clipable.clip_width)
    {
      pos.y = 0;
      while (pos.y < pix->clipable.clip_height)
	{
	  tekpixel(pix, &pos, &col);
	  pos.y++;
	}
      pos.x++;
    }
}

void	set_ground(t_win *win)
{
  t_bunny_position	pos;
  t_color		col;
  unsigned char		lvl;

  pos.y = W_Y2;
  col.argb[ALPHA_CMP] = 255;
  while (pos.y < W_Y)
    {
      pos.x = 0;
      while (pos.x < W_X)
	{
	  lvl = MAP((float)pos.y, W_Y2, W_Y, 0, 50);
	  col.argb[RED_CMP] = lvl;
	  col.argb[GREEN_CMP] = lvl;
	  col.argb[BLUE_CMP] = lvl;
	  tekpixel(win->array, &pos, &col);
	  pos.x++;
	}
      pos.y++;
    }
}

void	fill_wall(t_win *win,
		  t_bunny_pixelarray *wall,
		  t_bunny_position *pos,
		  float k)
{
  t_bunny_position      p;
  t_color               col;

  p.y = MAP((float)pos->y, (float)(W_Y2 - k), (float)(W_Y2 + k),
	    0.0, (float)wall->clipable.clip_height);
  p.x = win->me.ratio * (float)wall->clipable.clip_width - 0.5;
  k = k <= W_Y2 ? k : W_Y2;
  col.full = tekgetpixel(wall, &p);
  col.argb[RED_CMP] = MAP(k, 0, W_Y2, 20, col.argb[RED_CMP]);
  col.argb[BLUE_CMP] = MAP(k, 0, W_Y2, 20, col.argb[BLUE_CMP]);
  col.argb[GREEN_CMP] = MAP(k, 0, W_Y2, 20, col.argb[GREEN_CMP]);
  tekpixel(win->array, pos, &col);
}

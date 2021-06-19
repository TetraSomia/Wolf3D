/*
** torch.c for wolf in /home/josso_a/rendu/info/gfx_wolf3d/bonus
** 
** Made by Tetra
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Dec 12 15:00:37 2015 Tetra
** Last update Fri Dec 25 20:44:42 2015 Tetra
*/

#include "wolf.h"

void	sprite_loop(t_bunny_pixelarray *pix,
		    t_sprite *sprite,
		    int beg,
		    int end)
{
  t_bunny_position      pos;
  t_bunny_position      p;
  t_color               col;
  t_color               teal;

  teal.full = TEAL;
  teal.argb[ALPHA_CMP] = 0;
  pos.y = sprite->beg.y;
  while (pos.y < sprite->end.y)
    {
      pos.x = sprite->beg.x;
      while (pos.x < sprite->end.x)
	{
	  p.x = MAP((float)pos.x, sprite->beg.x, sprite->end.x, beg, end);
	  p.y = MAP((float)pos.y, sprite->beg.y, sprite->end.y, 0,
		    sprite->pix->clipable.clip_height);
	  if ((col.full = tekgetpixel(sprite->pix, &p)) != teal.full)
	    tekpixel(pix, &pos, &col);
	  pos.x++;
	}
      pos.y++;
    }
}

void    draw_sprite(t_bunny_pixelarray *pix, t_sprite *sprite)
{
  int                   beg;
  int                   end;

  beg = (int)sprite->act_frame * sprite->width;
  end = sprite->width * ((int)sprite->act_frame + 1);
  sprite_loop(pix, sprite, beg, end);
  sprite->act_frame += 0.25;
  if (sprite->act_frame >= sprite->nb_frame)
    sprite->act_frame = 0;
}

int     set_heart(t_sprite *heart)
{
  if ((heart->pix = load_bitmap("ressources/heart.bmp")) == NULL)
    return (1);
  heart->width = 112;
  heart->nb_frame = 6;
  heart->act_frame = 0;
  heart->beg.x = 7 * W_X / 10;
  heart->beg.y = 4 * W_Y / 6;
  heart->end.x = 9 * W_X / 10;
  heart->end.y = W_Y;
  return (0);
}

int	set_torch(t_sprite *torch)
{
  if ((torch->pix = load_bitmap("ressources/torch.bmp")) == NULL)
    return (1);
  torch->width = 200;
  torch->nb_frame = 7;
  torch->act_frame = 0;
  torch->beg.x = 0;
  torch->beg.y = W_Y2;
  torch->end.x = 2 * W_X / 5;
  torch->end.y = W_Y;
  return (0);
}

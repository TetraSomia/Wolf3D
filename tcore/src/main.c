/*
** main.c for fdf in /home/josso_a/rendu/info/gfx_fdf1/src
** 
** Made by josso_a
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Nov 10 14:16:13 2015 josso_a
** Last update Fri Dec 25 18:04:19 2015 Tetra
*/

#include "wolf.h"

t_bunny_response        press_key(t_bunny_event_state state,
				  t_bunny_keysym keysym,
				  void *data)
{
  (void)data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void		move_me(t_win *win)
{
  const bool	*key_pressed;

  key_pressed = bunny_get_keyboard();
  if (key_pressed[BKS_W])
    move(win, FORWARD);
  if (key_pressed[BKS_S])
    move(win, BACKWARD);
  if (key_pressed[BKS_A])
    move(win, LEFT);
  if (key_pressed[BKS_D])
    move(win, RIGHT);
  if (key_pressed[BKS_LEFT])
    go_left(win);
  if (key_pressed[BKS_RIGHT])
    go_right(win);
}

t_bunny_response        mainloop(void *data)
{
  t_win			*win;
  t_bunny_position	origin;

  origin.x = 0;
  origin.y = 0;
  win = data;
  move_me(win);
  draw_wall(win);
  bunny_blit(&win->win->buffer, &win->array->clipable, &origin);
  bunny_display(win->win);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_win	win;

  if ((win.win = bunny_start(W_X, W_Y, false, "wolfd3d")) == NULL)
    return (1);
  if ((win.array = bunny_new_pixelarray(W_X, W_Y)) == NULL)
    return (1);
  if (ac == 2 && set_data(av[1], "level1", &win) == -1)
    return (1);
  else if (ac != 2 && set_def_map(&win) == 1)
    return (1);
  set_cols(&win);
  bunny_set_key_response(&press_key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(win.win, 60, &win);
  free_map(&win.map);
  bunny_delete_clipable(&win.array->clipable);
  bunny_stop(win.win);
  return (0);
}

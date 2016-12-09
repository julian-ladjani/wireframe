/*
** wireframe.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 17:35:32 2016 Julian Ladjani
** Last update Jul Dec 10 00:18:42 2016 Julian Ladjani
*/

#include "my.h"

int		check_env(char **env)
{
  int		i;
  int		j;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strcmp("DISPLAY", env[i], 6) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		main(int ac, char **av, char **ae)
{
  t_int_tab	tab;
  int		i;

  i = 0;
  if (ac < 2)
    {
      my_printf("%s\n", "Invalid option : wireframe \"file.wf\"");
      return (84);
    }
  if (check_env(ae) < 1)
    {
      my_printf("%s\n", "Install X11 Server or check env var");
      return (84);
    }
  tab = read_it(av[1]);
  if (tab.tab == NULL)
    {
      my_printf("%s\n", "Invalid file");
      return (84);
    }
  windows(tab);
  while (++i < (tab.ylenght))
    free(tab.tab[i]);
  free(tab.buffer);
  free(tab.tab);
  return (0);
}

int			windows(t_int_tab tab)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  t_my_framebuffer	*buffer;
  sfSprite		*sprite;
  sfTexture		*texture;

  mode.width = SCREEN_WIDTH;
  mode.height = SCREEN_HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SFML window", sfClose, NULL);
  if (window == NULL)
    return (1);
  buffer = my_framebuffer_create(mode.width, mode.height);
  sprite = sfSprite_create();
  texture = sfTexture_create(mode.width, mode.height);
  tab.buffer = buffer;
  tab = calc_line_lenght(tab);
  draw_wireframe(tab);
  //my_draw_line(buffer, from, to2, sfRed);
  set_sprite(buffer, sprite, texture);
  my_window(window, sprite, tab);
  return (0);
}
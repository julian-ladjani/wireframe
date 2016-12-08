/*
** windows.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/window
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:42:42 2016 Julian Ladjani
** Last update Apr Dec 7 23:40:22 2016 Julian Ladjani
*/

#include "my.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  buffer->pixels = malloc(sizeof(sfUint8) * 4 * width * height);
  buffer->width = width;
  buffer->height = height;
  return (buffer);
}

void			set_sprite(t_my_framebuffer *buffer,
				   sfSprite *sprite, sfTexture *texture)
{
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfTexture_updateFromPixels(texture, buffer->pixels,
			     buffer->width, buffer->height, 0, 0);
}

void			my_window(sfRenderWindow *window, sfSprite *sprite)
{
  sfEvent		event;

  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
        {
          if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        }
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
}

int			main()
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  t_my_framebuffer	*buffer;
  sfSprite		*sprite;
  sfTexture		*texture;
  sfVector2i		from;
  sfVector3f		to;
  sfVector2i		to2;

  from.x = 600;
  from.y = 400;
  to.x = 800;
  to.y = 400;
  to.z = 0;
  to2 = my_parallel_projection(to, (2/3) * M_PI );
  mode.width = 1200;
  mode.height = 920;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SFML window", sfClose, NULL);
  if (window == NULL)
    return (1);
  buffer = my_framebuffer_create(mode.width, mode.height);
  sprite = sfSprite_create();
  texture = sfTexture_create(mode.width, mode.height);
  my_draw_line(buffer, from, to2, sfRed);
  set_sprite(buffer, sprite, texture);
  my_window(window, sprite);
  return (0);
}

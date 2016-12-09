/*
** windows.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/window
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:42:42 2016 Julian Ladjani
** Last update May Dec 8 23:19:48 2016 Julian Ladjani
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

void			my_window(sfRenderWindow *window, sfSprite *sprite,
				  t_int_tab tab)
{
  sfEvent		event;

  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
	    sfRenderWindow_close(window);
	}
      //if (draw_wireframe(tab) == 84)
	//sfRenderWindow_close(window);
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
}

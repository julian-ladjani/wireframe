/*
** my_put_pixel.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 18:08:35 2016 Julian Ladjani
** Last update May Dec 8 11:05:01 2016 Julian Ladjani
*/

#include "my.h"

void		my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color)
{
  if (x >= 0 && x <= buffer->width && y >= 0 && y <= buffer->width)
    {
      buffer->pixels[(buffer->width * y + x) * 4] = color.r;
      buffer->pixels[(buffer->width * y + x) * 4 + 1] = color.g;
      buffer->pixels[(buffer->width * y + x) * 4 + 2] = color.b;
      buffer->pixels[(buffer->width * y + x) * 4 + 3] = color.a;
    }
}

/*
** my_put_pixel.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 18:08:35 2016 Julian Ladjani
** Last update Mar Dec 6 18:09:07 2016 Julian Ladjani
*/

#include "my.h"

void		my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color)
{
  buffer->pixels[(buffer->width * y + x) * 4] = color.r;
  buffer->pixels[(buffer->width * y + x) * 4 + 1] = color.g;
  buffer->pixels[(buffer->width * y + x) * 4 + 2] = color.b;
  buffer->pixels[(buffer->width * y + x) * 4 + 3] = color.a;
}

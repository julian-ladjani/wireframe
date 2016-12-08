/*
** my_parallel_projection.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Apr Dec 7 21:25:05 2016 Julian Ladjani
** Last update May Dec 8 09:09:55 2016 Julian Ladjani
*/

#include "my.h"

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i	point;

  point.x = pos3d.x - pos3d.y * sinf(angle);
  point.y = pos3d.y * cosf(angle) - pos3d.z;
  printf("%d %d\n", point.x, point.y);
  return (point);
}

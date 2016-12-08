/*
** my_isometric_projection.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 18:05:28 2016 Julian Ladjani
** Last update Apr Dec 7 23:56:26 2016 Julian Ladjani
*/

#include "my.h"

sfVector2i 	my_isometric_projection(sfVector3f pos3d)
{
  sfVector2i	point;

  point.x = (pos3d.x - pos3d.z) / sqrt(2);
  point.y = (pos3d.x + 2 * pos3d.y + pos3d.z) / sqrt(6);
  return (point);
}

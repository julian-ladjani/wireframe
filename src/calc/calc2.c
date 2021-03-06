/*
** calc2.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/calc
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jul Dec 10 18:55:30 2016 Julian Ladjani
** Last update Feb Dec 12 01:26:52 2016 Julian Ladjani
*/

#include "my.h"

sfVector2i	center_wf(sfVector3f vec, t_int_tab tab)
{
  sfVector2i	point;

  if (vec.z > 0)
    vec.z += (tab.ztrans + tab.linelenght);
  else if (vec.z < 0)
    vec.z -= (tab.ztrans + tab.linelenght);
  vec.z += tab.linelenght;
  if (tab.proj == 0)
    point = my_parallel_projection(vec, ANGLE);
  else if (tab.proj == 1)
    point = my_julian_projection(vec);
  point.x += - (((tab.xlenght - 1) * sinf(ANGLE)) * tab.linelenght) / 2;
  point.x += (tab.buffer->width / 2);
  point.x += tab.xtrans;
  point.y += - (((tab.ylenght - 1) * cosf(ANGLE)) * tab.linelenght) / 2;
  point.y += (tab.buffer->height / 2);
  point.y += tab.ytrans;
  return (point);
}

t_int_tab	bonus_reset(t_int_tab tab)
{
  tab.affgrid = 1;
  tab.affzero = 1;
  tab.affline = 1;
  tab.aff3dgrid = 1;
  tab.xtrans = 0;
  tab.ytrans = 0;
  tab.ztrans = 0;
  tab.proj = 0;
  tab.incre = 1;
  tab.linelenght = tab.linelenghtbase;
  return (tab);
}

t_int_tab	action_affbonus2(t_int_tab tab, sfEvent event)
{
  if (event.key.code == sfKeyP)
    {
      if (tab.aff3dgrid == 1)
	tab.aff3dgrid = 0;
      else
	tab.aff3dgrid = 1;
    }
  else if (event.key.code == sfKeyK)
    {
      if (tab.proj == 1)
	tab.proj = 0;
      else
	tab.proj = 1;
    }
  else if (event.key.code == sfKeyQ && tab.incre < 10)
    tab.incre += 1;
  else if (event.key.code == sfKeyW && tab.incre > 1)
    tab.incre -= 1;
  return (tab);
}

t_int_tab	action_affbonus(t_int_tab tab, sfEvent event)
{
  if (event.key.code == sfKeyU)
    {
      if (tab.affgrid == 1)
	tab.affgrid = 0;
      else
	tab.affgrid = 1;
    }
  else if (event.key.code == sfKeyI)
    {
      if (tab.affline == 1)
	tab.affline = 0;
      else
	tab.affline = 1;
    }
  else if (event.key.code == sfKeyO)
    {
      if (tab.affzero == 1)
	tab.affzero = 0;
      else
	tab.affzero = 1;
    }
  else
    tab = action_affbonus2(tab, event);
  return (tab);
}

t_int_tab	action_bonus(t_int_tab tab, sfEvent event)
{
  if (event.key.code == sfKeySpace)
    tab = bonus_reset(tab);
  else if (event.key.code == sfKeyLeft)
    tab.xtrans -= tab.incre;
  else if (event.key.code == sfKeyRight)
    tab.xtrans += tab.incre;
  else if (event.key.code == sfKeyUp)
    tab.ytrans -= tab.incre;
  else if (event.key.code == sfKeyDown)
    tab.ytrans += tab.incre;
  else if (event.key.code == sfKeyPageUp)
    tab.ztrans += tab.incre;
  else if (event.key.code == sfKeyPageDown)
    tab.ztrans -= tab.incre;
  else if (event.key.code == sfKeyE)
    tab.linelenght += tab.incre;
  else if (event.key.code == sfKeyD)
    tab.linelenght -= tab.incre;
  else
    tab = action_affbonus(tab, event);
  tab = check_bonus(tab);
  return (tab);
}

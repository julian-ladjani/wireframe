/*
** calc.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/calc
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jun Dec 9 14:16:17 2016 Julian Ladjani
** Last update Jun Dec 9 22:43:59 2016 Julian Ladjani
*/

#include "my.h"

t_int_tab	calc_line_lenght(t_int_tab tab)
{
  if (tab.xlenght > tab.ylenght)
    tab.linelenght = 500 / tab.xlenght;
  else
    tab.linelenght = 500 / tab.ylenght;
  tab.xpos = tab.buffer->width;
  tab.ypos = tab.buffer->height;
  tab.xposbase = tab.xpos;
  tab.yposbase = tab.ypos;
  return (tab);
}

void		draw_grid(t_int_tab tab)
{
  sfVector3f	from;
  sfVector3f	to;

  from.z = 0;
  to.z = 0;
  from.x = tab.xpos;
  from.y = tab.ypos;
  to.x = tab.xpos;
  if ((tab.xpos) != (tab.xposbase))
    {
      to.x = tab.xpos - tab.linelenght;
    }
      to.y = tab.ypos;
  my_draw_line(tab.buffer, my_parallel_projection(from, ANGLE),
	       my_parallel_projection(to, ANGLE), sfRed);
  from.x = tab.xpos;
  to.x = tab.xpos;
  if ((tab.ypos) != (tab.yposbase))
    {
      to.y = tab.ypos - tab.linelenght;
      my_draw_line(tab.buffer, my_parallel_projection(from, ANGLE),
		   my_parallel_projection(to, ANGLE), sfRed);
    }
}

void		draw_line(t_int_tab tab)
{
  sfVector3f	from;
  sfVector3f	to;

  to.x = tab.xpos;
  from.x = tab.xpos;
  to.y = tab.ypos;
  from.y = tab.ypos;
  to.z = tab.zpos;
  from.z = 0;
  my_draw_line(tab.buffer, my_parallel_projection(from, ANGLE),
             my_parallel_projection(to, ANGLE), sfRed);
}

void		draw_grid3d(t_int_tab tab)
{
  sfVector3f	from;
  sfVector3f	to;

  from.x = tab.xpos;
  from.y = tab.ypos;
  to.x = tab.xpos;
  to.z = tab.tab[tab.ysee][tab.xsee - 1];
  from.z = tab.zpos;
  if ((tab.xpos) != (tab.xposbase))
    {
      to.x = tab.xpos - tab.linelenght;
    }
      to.y = tab.ypos;
  my_draw_line(tab.buffer, my_parallel_projection(from, ANGLE),
             my_parallel_projection(to, ANGLE), sfRed);
  from.x = tab.xpos;
  to.x = tab.xpos;
  if ((tab.ysee) >= (tab.ylenght - 1))
    to.z = tab.tab[tab.ysee - 1][tab.xsee];
  if ((tab.ypos) != (tab.yposbase))
    {
      to.y = tab.ypos - tab.linelenght;
      my_draw_line(tab.buffer, my_parallel_projection(from, ANGLE),
                 my_parallel_projection(to, ANGLE), sfRed);
    }
}

void		draw_it(t_int_tab tab)
{
  draw_grid(tab);
  draw_line(tab);
  draw_grid3d(tab);
}

/*
** calc.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/calc
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jun Dec 9 14:16:17 2016 Julian Ladjani
** Last update Jan Dec 11 18:54:04 2016 Julian Ladjani
*/

#include "my.h"

t_int_tab	calc_line_lenght(t_int_tab tab)
{
  if (tab.xlenght > tab.ylenght)
    tab.linelenght = 500 / tab.xlenght;
  else
    tab.linelenght = 500 / tab.ylenght;
  tab.xpos = 0;
  tab.ypos = 0;
  tab.xtrans = 0;
  tab.ytrans = 0;
  tab.ztrans = 0;
  tab.xposbase = tab.xpos;
  tab.yposbase = tab.ypos;
  tab.affgrid = 1;
  tab.aff3dgrid = 1;
  tab.affline = 1;
  tab.affzero = 1;
  tab.zoom = 0;
  tab.linelenghtbase = tab.linelenght;
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
  my_draw_line(tab.buffer, center_wf(from, tab),
	       center_wf(to, tab), sfBlue);
  from.x = tab.xpos;
  to.x = tab.xpos;
  if ((tab.ypos) != (tab.yposbase))
    {
      to.y = tab.ypos - tab.linelenght;
      my_draw_line(tab.buffer, center_wf(from, tab),
		   center_wf(to, tab), sfBlue);
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
  my_draw_line(tab.buffer, center_wf(from, tab), center_wf(to, tab), sfWhite);
}

void		draw_grid3d(t_int_tab tab)
{
  sfVector3f	from;
  sfVector3f	to;

  from.z = tab.zpos;
  to.z = tab.tab[tab.ysee][tab.xsee - 1];
  from.x = tab.xpos;
  from.y = tab.ypos;
  to.x = tab.xpos;
  if ((tab.xpos) != (tab.xposbase))
    {
      to.x = tab.xpos - tab.linelenght;
    }
  to.y = tab.ypos;
  if ((from.z != 0 || to.z != 0) || tab.affzero == 1)
    my_draw_line(tab.buffer, center_wf(from, tab), center_wf(to, tab), sfRed);
  from.x = tab.xpos;
  to.x = tab.xpos;
  if ((tab.ypos) != (tab.yposbase))
    {
      to.z = tab.tab[tab.ysee - 1][tab.xsee];
      to.y = tab.ypos - tab.linelenght;
      if ((from.z != 0 || to.z != 0) || tab.affzero == 1)
	my_draw_line(tab.buffer, center_wf(from, tab), center_wf(to, tab), sfRed);
    }
}

void		draw_it(t_int_tab tab)
{
  if (tab.affgrid == 1)
    draw_grid(tab);
  if (tab.affline == 1)
    draw_line(tab);
  if (tab.aff3dgrid == 1)
    draw_grid3d(tab);
}

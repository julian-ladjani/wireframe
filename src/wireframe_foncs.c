/*
** wireframe_foncs.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 22:54:48 2016 Julian Ladjani
** Last update Jan Dec 11 18:32:55 2016 Julian Ladjani
*/

#include "my.h"

int		draw_wireframe(t_int_tab tab)
{
  tab.xsee = 0;
  tab.ysee = 0;
  while (tab.ysee < tab.ylenght)
    {
      while (tab.xsee < tab.xlenght)
	{
	  tab.zpos = tab.tab[tab.ysee][tab.xsee];
	  draw_it(tab);
	  tab.xpos += tab.linelenght;
	  tab.xsee++;
	}
      tab.xpos = tab.xposbase;
      tab.ypos += tab.linelenght;
      tab.xsee = 0;
      tab.ysee++;
    }
  return (0);
}

/*
** check_bonus.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/calc
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Dec 11 22:14:41 2016 Julian Ladjani
** Last update Jan Dec 11 22:18:04 2016 Julian Ladjani
*/

#include "my.h"

t_int_tab	check_bonus(t_int_tab tab)
{
  if (tab.xtrans > 2000 || tab.xtrans < -2000)
    tab.xtrans = 0;
  if (tab.ytrans > 2000 || tab.ytrans < -2000)
    tab.ytrans = 0;
  if (tab.ztrans > 2000 || tab.ztrans < -2000)
    tab.ztrans = 0;
  if (tab.linelenght > 2000 || tab.linelenght < -2000)
    tab.linelenght = tab.linelenghtbase;
  return (tab);
}

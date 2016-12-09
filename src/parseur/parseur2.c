/*
** parseur2.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/parseur
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 14:41:15 2016 Julian Ladjani
** Last update Jun Dec 9 23:42:37 2016 Julian Ladjani
*/

#include "my.h"

int		my_strcmp(char *s1, char *s2, int n)
{
  int		c;
  int		c2;

  c = 0;
  c2 = 0;
  while (s1[c] != '\0' && s2[c] != '\0' && c < n)
    {
      if (s1[c] != s2[c])
	return (s1[c] - s2[c]);
      c++;
    }
  if (s1[c] != s2[c] && c < n)
    {
      return (s1[c] - s2[c]);
    }
  return (0);
}

int		tab_number(char *buff)
{
  int		i;
  int		nb_tab;

  i = 0;
  nb_tab = 1;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	nb_tab++;
      i++;
    }
  return (nb_tab);
}

int		*set_in_intab(char *buff, int *tab)
{
  int		j;

  j = 0;
  while (*buff != '\n' && *buff != '\0')
    {
      if (*buff == ',')
	buff++;
      else if ((*buff >= '0' && *buff <= '9') || *buff == '-')
	{
	  if ((*(buff + 1) < '0' || *(buff + 1) > '9') && *buff == '-')
	    return (NULL);
	  tab[j] = my_getnbrprintf(buff);
	  j++;
	  buff += char_number_dot(buff) + 1;
	}
      else
	return (NULL);
    }
  return (tab);
}

int		char_number(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
      i++;
  return (i);
}

int		check_buffer(char *buff)
{
  int		i;

  i = 0;

  while (buff[i] != '\0')
    {
      if ((buff[i] < '0' || buff[i] > '9') && (buff[i] != '-' &&
	   buff[i] != '\n' && buff[i] != ','))
	return (0);
      i++;
    }
  return (1);
}
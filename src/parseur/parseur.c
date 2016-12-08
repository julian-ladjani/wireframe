/*
** parseur.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/parseur
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 09:04:16 2016 Julian Ladjani
** Last update May Dec 8 09:51:18 2016 Julian Ladjani
*/

#include "my.h"

char		*read_it(char *path)
{
  char		*buff;
  int		offset;
  int		i;
  int		len;
  int		fd;

  offset = 0;
  if ((fd = open(file, O_RDONLY)) < 0)
    return (84);
  if ((buff = malloc(BUFF_SIZE + 1)) == NULL)
    return (84);
  while ((len = read(fd, buff + offset, BUFF_SIZE)) > 0)
    {
      offset = offset + len;
      my_realloc(buff, BUFF_SIZE + 1);
    }
  if (offset <= 0 || offset > BUFF_SIZE || len  < 0)
    return (84);
  parse_my_int(buff);
  return (0);
}

int		**parse_my_int(char *buff)
{

}

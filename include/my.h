/*
** my.h for my in /home/julian-ladjani/delivery/CGP/wireframe/include
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:39:54 2016 Julian Ladjani
** Last update Apr Dec 7 23:09:31 2016 Julian Ladjani
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <stdlib.h>
# include <math.h>

typedef struct		s_my_framebuffer
{
	sfUint8		*pixels;
	int		width;
	int		height;
}			t_my_framebuffer;

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle);

#endif /* !MY_H_ */

/*
** my.h for my in /home/julian-ladjani/delivery/CGP/wireframe/include
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:39:54 2016 Julian Ladjani
** Last update May Dec 8 10:05:53 2016 Julian Ladjani
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <stdlib.h>
# include <math.h>

# define BUFF_SIZE 2048

typedef struct		s_my_framebuffer
{
	sfUint8		*pixels;
	int		width;
	int		height;
}			t_my_framebuffer;

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle);
void		my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color);
void		my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
			     sfVector2i to, sfColor color);
void		my_draw_line_case_2(t_my_framebuffer *buffer, sfVector2i from,
				    sfVector2i to, sfColor color);
void		my_draw_line_case_1(t_my_framebuffer *buffer, sfVector2i from,
				    sfVector2i to, sfColor color);

#endif /* !MY_H_ */

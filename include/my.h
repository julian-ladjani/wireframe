/*
** my.h for my in /home/julian-ladjani/delivery/CGP/wireframe/include
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:39:54 2016 Julian Ladjani
** Last update Feb Dec 12 01:23:23 2016 Julian Ladjani
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>

# define BUFF_SIZE 2048
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 920
# define WIRE_WIDTH 500
# define WIRE_HEIGHT 500
# define ANGLE (M_PI/6)

typedef struct			s_my_framebuffer
{
	sfUint8			*pixels;
	int			width;
	int			height;
}				t_my_framebuffer;

typedef struct			s_int_tab
{
  	int			**tab;
  	int			xlenght;
  	int			ylenght;
  	int			linelenght;
	int			linelenghtbase;
  	int			zoom;
  	int			angle;
  	int			speed;
  	int			xpos;
  	int			ypos;
	int			zpos;
  	int			xsee;
  	int			ysee;
  	int			ytrans;
  	int			xtrans;
  	int			ztrans;
  	int			xposbase;
  	int			yposbase;
  	int			affzero;
  	int			affgrid;
  	int			affline;
  	int			aff3dgrid;
  	int			proj;
  	int			incre;
  	t_my_framebuffer	*buffer;
 	sfColor			color;
}				t_int_tab;

void				my_put_pixel(t_my_framebuffer *buffer, int x,
					     int y, sfColor color);
void				my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
					     sfVector2i to, sfColor color);
void				my_draw_line_case_2(t_my_framebuffer *buffer, sfVector2i from,
						    sfVector2i to, sfColor color);
void				my_draw_line_case_1(t_my_framebuffer *buffer, sfVector2i from,
						    sfVector2i to, sfColor color);
void				set_sprite(t_my_framebuffer *buffer,
					   sfSprite *sprite, sfTexture *texture);
void				my_window(sfRenderWindow *window, sfSprite *sprite,
					  t_int_tab tab, sfTexture *texture);
void				draw_it(t_int_tab tab);
void				init_framebuffer(t_my_framebuffer *buffer);

int				char_number_dot(char *buff);
int				check_char_number_line(char *buff);
int				char_number_line(char *buff);
int				tab_number(char *buff);
int				*set_in_intab(char *buff, int *tab);
int				char_number(char *buff);
t_int_tab			parse_my_int(char *buff);
t_int_tab			read_it(char *path);
int				my_getnbrprintf(char *str);
int				my_printf(char *str, ...);
int				draw_wireframe(t_int_tab tab);
int				check_buffer(char *buff);
int				windows(t_int_tab tab);
int				my_strcmp(char *s1, char *s2, int n);

char				*my_realloc(char *str, int lenght);

sfVector2i			my_parallel_projection(sfVector3f pos3d, float angle);
sfVector2i			center_wf(sfVector3f vec, t_int_tab tab);
sfVector2i 			my_isometric_projection(sfVector3f pos3d);
sfVector2i 			my_julian_projection(sfVector3f pos3d);

t_int_tab			calc_line_lenght(t_int_tab tab);
t_int_tab			parse_my_int(char *buff);
t_int_tab			read_it(char *path);
t_int_tab			action_bonus(t_int_tab tab, sfEvent event);
t_int_tab			check_bonus(t_int_tab tab);

t_my_framebuffer		*my_framebuffer_create(int width, int height);

#endif /* !MY_H_ */

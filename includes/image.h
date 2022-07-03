#ifndef INCLUDES_IMAGE_H
#define INCLUDES_IMAGE_H

#include <curses.h>

typedef struct s_image {
	char	**img;
	int		img_w;
	int		img_h;
	int		print_max;
} t_image;

t_image* init_middle_stick();
void delete_image(t_image *image);
void print_img(WINDOW *game_screen, t_image *img, int num, int y, int center);

#endif /* INCLUDES_IMAGE_H */

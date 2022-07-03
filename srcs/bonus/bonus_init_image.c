#include "image.h"
#include "libft.h"

#include <curses.h>
#include <unistd.h>

t_image* init_small_stick() {
	char* stick = " ,-, \\,-.| \\; |, \\'-'  ";

	t_image *res = malloc(sizeof(t_image));
	res->img = ft_split(stick, '\\');
	res->img_h = 4;
	res->img_w = 5;
	res->print_max = 10;
	return res;
}

t_image* init_middle_stick() {
	char* stick = " ,-, \\,-.| \\| || \\| || \\| || \\; |, \\'-'  ";

	t_image *res = malloc(sizeof(t_image));
	res->img = ft_split(stick, '\\');
	res->img_h = 7;
	res->img_w = 5;
	res->print_max = 10;
	return res;
}


t_image* init_big_stick() {
	char* stick = "  ,--, \\,--.'| \\|  : : \\:  | ' \\|  : | \\|  | ' \\'  : | \\;  |.' \\'--'   ";

	t_image *res = malloc(sizeof(t_image));
	res->img = ft_split(stick, '\\');
	res->img_h = 7;
	res->img_w = 7;
	res->print_max = 7;
	return res;
}

bool init_images(t_image** images) {
	t_image *res;
	res = init_small_stick();
	if (res == NULL) {
		return false;
	}
	images[0] = res;
	res = init_middle_stick();
	if (res == NULL) {
		return false;
	}
	images[1] = res;
	res = init_big_stick();
	if (res == NULL) {
		return false;
	}
	images[2] = res;
	return true;
}

void delete_image(t_image *image) {
	ft_free_split(image->img);
	free(image);
}

void delete_images(t_image** images) {
	delete_image(images[0]);
	delete_image(images[1]);
	delete_image(images[2]);
	return;
}

void print_img(WINDOW *game_screen, t_image *img, int num, int y, int center) {
	if (num > img->print_max) {
		num = img->print_max;
	}
	int start = center - img->img_w * num / 2;
	wmove(game_screen, y, start);
	for (int i = 0;  i < img->img_h; i++)
	{
		for (int j = 0; j < num; j++)
		{
			wprintw(game_screen, img->img[i]);
		}
		wmove(game_screen, y + (i + 1), start);
	}
}

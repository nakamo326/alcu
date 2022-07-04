#include "alcu.h"
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
	res->img_h = 9;
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

void print_img(WINDOW *game_screen, t_image *img, t_heap *heap, int y, int center) {
	int print_num = heap->num;
	if (heap->num > img->print_max) {
		print_num = img->print_max;
	}
	int start = center - img->img_w * print_num / 2;
	wmove(game_screen, y, start);
	for (int i = 0;  i < img->img_h; i++)
	{
		for (int j = 0; j < print_num; j++)
		{
			wprintw(game_screen, img->img[i]);
		}
		if (i == 0) {
			mvwprintw(game_screen, y, 70, "item size:");
		} else if (i == 1) {
			mvwprintw(game_screen, y + 1, 70, "  %d", heap->num);
		}
		wmove(game_screen, y + (i + 1), start);
	}
}

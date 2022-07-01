#include "get_next_line.h"

void free_gnl_buf(void)
{
	get_next_line(-1, NULL);
} 

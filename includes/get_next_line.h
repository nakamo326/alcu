#ifndef INCLUDES_GET_NEXT_LINE
#define INCLUDES_GET_NEXT_LINE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SUCCESS 1
#define ERROR -1
#define CONTINUE 3
#define END 0
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

int get_next_line(int fd, char **line);

#endif /* INCLUDES_GET_NEXT_LINE */

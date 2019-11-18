#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

static void read_message (int fd, fd_set set) {
  int bytes = 0;
  char buf[PIPE_BUF] = { 0 };

  FD_ZERO (&set);
  FD_SET (fd, &set);

  if ((select (fd + 1, &set, NULL, NULL, NULL)) < 1)
    exit (1);
  if (!FD_ISSET (fd, &set))
    return;

  if (read (fd, buf, PIPE_BUF) > 0)
    printf ("%s\n", buf);
}

int main (void) {
  fd_set set;
  char *fifo = "/tmp/wspipeout.fifo";
  int fd = 0;

  if ((fd = open (fifo, O_RDWR | O_NONBLOCK)) < 0)
    exit (1);
  while (1) 
    read_message(fd, set);
    printf("fd");
    printf(fd);

  return 0;
}
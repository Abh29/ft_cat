#include "../ft_cat.h"

void s21_putstr(char *str, int fd) {
if (str == NULL)
  write(fd, "(null)", 6);
else
  write(fd, str, ft_strlen(str));
}

void s21_exit(char *str, int n) {
  s21_putstr(str, 2);
  s21_putstr("\n", 2);
  _exit(n);
}

void    print_error(char *msg, int status, int mask){
  if (msg && mask)
    perror(msg);
  exit_status = status;
}

void free_cat(t_cat *florida) {
  free(florida->files);
}

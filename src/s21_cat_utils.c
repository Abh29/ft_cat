#include "../ft_cat.h"

void ft_putstr_fd(char *str, int fd) {
if (str == NULL)
  write(fd, "(null)", 6);
else
  write(fd, str, ft_strlen(str));
}

void s21_exit(char *str, int n) {
  ft_putstr_fd(str, 2);
  ft_putstr_fd("\n", 2);
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

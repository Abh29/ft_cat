#include "../ft_cat.h"

void print_str(char *str, t_cat *flags) {

  while (*str) {
    if (check_flag(flags, 'T') && *str == '\t')
      printf("^I");
    else if (check_flag(flags, 'v'))
      printf("%s", non_print[((*str )+ 256) % 256]);
    else 
      printf("%c", *str);
    str++;
  }
  if (check_flag(flags, 'E'))
    printf("$");
  printf("\n");
}

void  print_help(void) {
  int fd;
  char  *line;

  if ((fd = open("man.txt", O_RDONLY)) < 0) {
    printf("s21_cat - concatenate files and print on the standard output\n");
    exit(EXIT_SUCCESS);
  }
  while ((line = ft_get_next_line(fd)) != NULL) {
    printf("%s\n", line);
    free(line);
  }
  close(fd);
  exit(EXIT_SUCCESS);
}

void  print_version(void) {
  printf("s21_cat (school21 Unix Utility) 1.0\n");
  printf("Written by Emmitt Anjelica school21.\n");
  exit(EXIT_SUCCESS);
}

void  print_file(t_cat *flags, char *file_path){

  int   fd;
  char  *line;
  int   c_empty;

  if (flags == NULL || file_path == NULL)
    return ;
  if (ft_strcmp(file_path, "-") == 0 || ft_strcmp(file_path, "--") == 0)
    fd = 1;
  else if ((fd = open(file_path, O_RDONLY)) < 0) {
    print_error("ft_cat: ", 1, 1);
    return ;
  }
  
  c_empty = 0;
  while ((line = ft_get_next_line(fd))) {
      if (check_flag(flags, 's')) {
        if (*line == '\0')
          c_empty++;
        else
          c_empty = 0; }
      if (c_empty >= 2) {
        free(line);
        continue;
      }
      if (check_flag(flags, 'b') && *line != '\0')
        printf("%6d\t", flags->c_b++);
      else if (check_flag(flags, 'n') && check_flag(flags, 'b') == 0)
          printf("%6d\t", flags->c_n++);
      print_str(line, flags);
      free(line);
  }
  if (fd != 1)
    close(fd);
}

int print_files(t_cat *flags) {
  int i;

  if (check_flag(flags, F_HELP))
    print_help();
  if (check_flag(flags, F_VERSION))
    print_version();
  if (flags->files[0] == NULL)
    print_file(flags, "-");
  i = 0;
  while (flags->files[i] != NULL)
    print_file(flags, flags->files[i++]);
  return 0;
}

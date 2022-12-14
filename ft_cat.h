#ifndef S21_CAT
# define S21_CAT

#include "gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define F_HELP    300
#define F_VERSION 301



extern int  exit_status;
extern char *non_print[256];

typedef struct s_cat {
  char **files;
  int   flags;
  int   c_n;
  int   c_b;
} t_cat;

#ifndef __S_LIST__
#define __S_LIST__
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
#endif


void    ft_init_flags(t_cat *flags);
int     check_flag(t_cat *arg, int flag);
void    set_flag(t_cat *arg, int flag);
void    print_error(char *msg, int status, int mask);
void    print_str(char *str, t_cat *flags);
void    print_help(void);
void    print_version(void);
void    print_file(t_cat *flags, char *file_path);
int     print_files(t_cat *flags);
void    ft_set_long_flag(t_cat *arg, char *flag);
int     read_args(t_cat *flag, int argc, char **argv);
void    s21_putstr(char *str, int fd);
void    s21_exit(char *str, int n);
void    free_cat(t_cat *flags);
size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);

#endif
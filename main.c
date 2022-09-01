#include "ft_cat.h"

int exit_status = EXIT_SUCCESS;

char  *non_print[256] = {"^@","^A","^B","^C","^D","^E","^F","^G","^H","\t","","^K","^L","^M","^N","^O",\
                          "^P","^Q","^R","^S","^T","^U","^V","^W","^X","^Y","^Z","^[","^\\","^]","^^","^_",\
                          " ","!","\\","#","$","%","&","'","(",")","*","+",",","-",".","/","0","1","2","3",\
                          "4","5","6","7","8","9",":",";","<","=",">","?","@","A","B","C","D","E","F","G",\
                          "H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","[",\
                          "\\","]","^","_","`","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",\
                          "p","q","r","s","t","u","v","w","x","y","z","{","|","}","~","^?","M-^@","M-^A",\
                          "M-^B","M-^C","M-^D","M-^E","M-^F","M-^G","M-^H","M-^I","M-^J","M-^K","M-^L","M-^M",\
                          "M-^N","M-^O","M-^P","M-^Q","M-^R","M-^S","M-^T","M-^U","M-^V","M-^W","M-^X","M-^Y",\
                          "M-^Z","M-^[","M-^\\","M-^]","M-^^","M-^_","M- ","M-!","M-\\","M-#","M-$","M-%","M-&",\
                          "M-","M-(","M-)","M-*","M-+","M-,","M--","M-.","M-/","M-0","M-1","M-2","M-3","M-4","M-5",\
                          "M-6","M-7","M-8","M-9","M-:","M-;","M-<","M-=","M->","M-?","M-@","M-A","M-B","M-C","M-D",\
                          "M-E","M-F","M-G","M-H","M-I","M-J","M-K","M-L","M-M","M-N","M-O","M-P","M-Q","M-R","M-S",\
                          "M-T","M-U","M-V","M-W","M-X","M-Y","M-Z","M-[","M-\\","M-]","M-^","M-_","M-`","M-a","M-b",\
                          "M-c","M-d","M-e","M-f","M-g","M-h","M-i","M-j","M-k","M-l","M-m","M-n","M-o","M-p","M-q",\
                          "M-r","M-s","M-t","M-u","M-v","M-w","M-x","M-y","M-z","M-{","M-|","M-}","M-~","M-^?"};

int main(int argc, char **argv) {
  t_cat florida;

  if (argc < 1 && !*argv)
    s21_exit("cat: error first argument can't be null !\n", 1);
  
  ft_init_flags(&florida);
  read_args(&florida, argc, argv);
  print_files(&florida);
  free_cat(&florida);
  return 0;
}

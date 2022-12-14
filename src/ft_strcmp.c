#include "../ft_cat.h"

int ft_strcmp(const char *s1, const char *s2){
    if (s1 == NULL || s2 == NULL)
        return (-1);
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

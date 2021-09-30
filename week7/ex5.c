# include <stdio.h>
#include "stdlib.h"

int main () {
    char** s = (char **)malloc(sizeof((char *) malloc(sizeof(char) * 10)) * 10); //we need to allocate memory for s.

    char foo[] = "Hello World";
    *s = foo;
    printf ("s is %d\n", s);
    s[0] = foo;
    printf ("s [0] is %s\n", s[0]);
    return (0);
}
